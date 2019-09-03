package main

import (
	"context"
	"fmt"
	"math/big"
	"strings"
	"time"

	ethereumutil "../../go-client-common"
	"./relay"
	"./sample"

	"github.com/ethereum/go-ethereum/accounts/abi"
	"github.com/ethereum/go-ethereum/accounts/abi/bind"
	"github.com/ethereum/go-ethereum/common"
	"github.com/ethereum/go-ethereum/core/types"
	"github.com/ethereum/go-ethereum/crypto"
	"github.com/ethereum/go-ethereum/ethclient"
)

//ganache-cli -m "era nuclear sand purpose swear profit lawn copy capable hour sentence lonely"
var rpcURL string = "http://127.0.0.1:8545"
var prvKey string = "8d6ef9fe1308d206babcda4a9f60623eb7a9b130d759df9a99de1c3ee5be5e1c"
var prvUserKey string = "432603bc824dede3504a419dbc31054c79f0437cc445c80ec9cc1ad84e19bbf8"
var address string = "825E3f2220bAD9383065143Ff51C9C33e4900406"
var sampleAddr string = "A311Bde49f06fE26aDF71199cD910f348C760742"

func main() {

	// get node instance
	client, err := ethereumutil.GetEthClient(rpcURL)
	if err != nil {
		fmt.Printf("get rpc client error: %s\n", err.Error())
		return
	}
	prvRelayer, _ := crypto.HexToECDSA(prvKey)
	fmt.Printf("relayer:%s\n", ethereumutil.GetAddressFromPrivateKey(prvRelayer).Hex())
	prvUser, _ := crypto.HexToECDSA(prvUserKey)
	userAddr := ethereumutil.GetAddressFromPrivateKey(prvUser)
	fmt.Printf("user:%s, \n", userAddr.Hex())

	// encode function call and sign raw tx
	//
	sampleABI, err := abi.JSON(strings.NewReader(sample.SampleABI))
	if err != nil {
		fmt.Printf("read sample abi error: %s", err.Error())
		return
	}
	eventRunID := sampleABI.Events["Run"].ID()
	// encode function call
	encFunc, err := sampleABI.Pack("run", big.NewInt(9911))
	if err != nil {
		fmt.Printf("failed to pack smart contract func: %s\n", err.Error())
		return
	}
	// create a raw tx
	// tx := types.NewTransaction(ethereumutil.GetNonceFromPrivatekey(client, prvUser),
	// 	common.HexToAddress(sampleAddr), big.NewInt(0), 1e6, big.NewInt(10e9), encFunc)
	// signedTx, err := types.SignTx(tx, types.HomesteadSigner{}, prvUser)
	// if err != nil {
	// 	fmt.Printf("failed to sign tx: %s\n", err.Error())
	// 	return
	// }

	// sign encoded function
	sig, err := ethereumutil.SignWithBytes(encFunc, prvUser)
	if err != nil {
		fmt.Printf("failed to sign siged tx: %s\n", err.Error())
		return
	}

	// submit to relay contract
	// get contract object
	obj, err := relay.NewRelay(common.HexToAddress(address), client)
	if err != nil {
		fmt.Printf("failed to new contract obj: %s\n", err.Error())
		return
	}

	// call contract: Forward
	auth := bind.NewKeyedTransactor(prvRelayer)
	tx, err := obj.Forward(auth, sig.Raw, encFunc, userAddr, common.HexToAddress(sampleAddr), big.NewInt(0))
	if err != nil {
		fmt.Printf("call contract Forward error: %s\n", err.Error())
		return
	}
	receipt := wait(client, tx)

	// get event id
	relayABI, err := abi.JSON(strings.NewReader(relay.RelayABI))
	if err != nil {
		fmt.Printf("read abi error: %s", err.Error())
		return
	}
	eventForwardedID := relayABI.Events["Forwarded"].ID()

	// verify event
	for _, aLog := range receipt.Logs {
		if 0 == strings.Compare(aLog.Topics[0].String(), eventForwardedID.String()) {
			fmt.Println("*** Got \"Forwarded\" event")
			var evObj relay.RelayForwarded
			relayABI.Unpack(&evObj, "Forwarded", aLog.Data)
			fmt.Printf("signer:%v, destination:%v\n", evObj.Signer.Hex(), evObj.Destination.Hex())
		}
		if 0 == strings.Compare(aLog.Topics[0].String(), eventRunID.String()) {
			fmt.Println("*** Got \"Run\" event")
			var evObj sample.SampleRun
			sampleABI.Unpack(&evObj, "Run", aLog.Data)
			fmt.Printf("msg.sender:%v, somevalue:%v, timestamp:%v\n", evObj.Sender.Hex(), evObj.Somevalue, evObj.Timestamp)
		}
	}

}

func wait(client *ethclient.Client, tx *types.Transaction) *types.Receipt {
	receiptChan := make(chan *types.Receipt)
	go func() {
		fmt.Printf("wait transaction: %s...\n\n", tx.Hash().Hex())
		for {
			receipt, _ := client.TransactionReceipt(context.Background(), tx.Hash())
			if receipt != nil {
				receiptChan <- receipt
				break
			} else {
				fmt.Printf("Retry after i second")
				time.Sleep(1 * time.Second)
			}
		}
	}()
	receipt := <-receiptChan
	return receipt
}
