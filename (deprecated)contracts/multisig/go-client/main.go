package main

import (
	"context"
	"fmt"
	"strings"
	"time"

	ethereumutil "../../go-client-common"
	"./contract"

	"github.com/ethereum/go-ethereum/accounts/abi"
	"github.com/ethereum/go-ethereum/accounts/abi/bind"
	"github.com/ethereum/go-ethereum/common"
	"github.com/ethereum/go-ethereum/core/types"
	"github.com/ethereum/go-ethereum/crypto"
	"github.com/ethereum/go-ethereum/ethclient"
)

//ganache-cli -m "era nuclear sand purpose swear profit lawn copy capable hour sentence lonely"
var rpcURL string = "http://127.0.0.1:8545"
var prvKey string = "0d298406c964635fd4199666559df70a30675d6d6dca2a63c9cc00f5e3b315fb"
var address string = "9B2bd9b82aa15BA2C3D33BAf9fcA02f6D484119D"
var admin1 string = "0d298406c964635fd4199666559df70a30675d6d6dca2a63c9cc00f5e3b315fb"
var admin2 string = "a4689636f4744069feb030515da17db870642107a321305e9446b587587e7b9e"
var admin3 string = "792c418f3c2b4289200abceac7bc3bcf2ace9cab0eab99fa0f50743af1d26fa7"

func main() {

	// get node instance
	client, err := ethereumutil.GetEthClient(rpcURL)
	if err != nil {
		fmt.Printf("get rpc client error: %s\n", err.Error())
		return
	}

	// get contract object
	obj, err := contract.NewContract(common.HexToAddress(address), client)
	if err != nil {
		fmt.Printf("failed to new contract obj: %s\n", err.Error())
		return
	}

	// call contract: update admins
	prvAdmin1, _ := crypto.HexToECDSA(admin1)
	auth1 := bind.NewKeyedTransactor(prvAdmin1)
	tx, err := obj.UpdateAdmins(auth1, []common.Address{
		ethereumutil.GetAddressFromPrivateKeyString(admin1),
		ethereumutil.GetAddressFromPrivateKeyString(admin2),
		ethereumutil.GetAddressFromPrivateKeyString(admin3)})
	if err != nil {
		fmt.Printf("call contract UpdateAdmins error: %s\n", err.Error())
		return
	}
	wait(client, tx)

	// call contract: approve with admin1
	tx, err = obj.Approve(auth1)
	if err != nil {
		fmt.Printf("call contract Approve error: %s\n", err.Error())
		return
	}
	wait(client, tx)

	// call contract: approve with admin2
	prvAdmin2, _ := crypto.HexToECDSA(admin2)
	auth2 := bind.NewKeyedTransactor(prvAdmin2)
	tx, err = obj.Approve(auth2)
	if err != nil {
		fmt.Printf("call contract Approve error: %s\n", err.Error())
		return
	}
	receipt := wait(client, tx)

	// get event id
	ensABI, err := abi.JSON(strings.NewReader(contract.ContractABI))
	if err != nil {
		fmt.Printf("read abi error: %s", err.Error())
		return
	}
	eventID := ensABI.Events["Finalized"].Id()

	// verify event
	if 0 == strings.Compare(eventID.String(), receipt.Logs[0].Topics[0].String()) {
		fmt.Println("Success!")
	} else {
		fmt.Println("Failed to update admins")
	}

}

func wait(client *ethclient.Client, tx *types.Transaction) *types.Receipt {
	receiptChan := make(chan *types.Receipt)
	go func() {
		fmt.Printf("wait transaction: %s\n", tx.Hash().Hex())
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
