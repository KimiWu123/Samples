package main

import (
	"crypto/ecdsa"
	"strings"

	"./contract"
	"./ethereumutil"
	"github.com/ethereum/go-ethereum/accounts/abi"
	"github.com/ethereum/go-ethereum/accounts/abi/bind"
	"github.com/ethereum/go-ethereum/common"
	"github.com/ethereum/go-ethereum/core/types"
	"github.com/ethereum/go-ethereum/crypto"
	"github.com/ethereum/go-ethereum/ethclient"

	"context"
	"fmt"
	"time"
)

var rpcURL string = "http://127.0.0.1:8545"
var prvKey string = "28872518f6306ecf79598d4829d5711089f6317da9eb6c781712ccc035259b11"
var address string = "102ff16D60c292D7A79c44E042d69694594a3AdD"
var message string = "hello!"

type Signature struct {
	Raw  []byte
	Hash [32]byte
	R    [32]byte
	S    [32]byte
	V    uint8
}

func main() {

	// get private key
	prvKey, _ := crypto.HexToECDSA(prvKey)
	publicKey := prvKey.Public()
	publicKeyECDSA, ok := publicKey.(*ecdsa.PublicKey)
	if !ok {
		fmt.Println("cannot assert type: publicKey is not of type *ecdsa.PublicKey")
		return
	}
	addr := crypto.PubkeyToAddress(*publicKeyECDSA)
	fmt.Printf("signer address: %s\n", addr.Hex())

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

	// sign message
	sig, err := Sign(message, prvKey)
	if err != nil {
		fmt.Printf("sign error: %s\n", err.Error())
		return
	}
	// Verify signed message
	// recoverSigner := Recover(sig)
	// fmt.Printf("recovered signer: %s", recoverSigner)

	// call contract verify function
	auth := bind.NewKeyedTransactor(prvKey)
	tx, err := obj.Verify(auth, sig.Hash, sig.V, sig.R, sig.S)
	if err != nil {
		fmt.Printf("call contract verify error: %s\n", err.Error())
		return
	}

	receipt := wait(client, tx)
	signer := getSigner(receipt.Logs[0])
	fmt.Printf("Got signer address: %s\n", signer)

}

func Recover(sig Signature) string {
	sigPublicKey, err := crypto.Ecrecover(sig.Hash[:], sig.Raw)
	if err != nil {
		fmt.Printf("recover error: %s", err.Error())
	}

	ecdsaPubKey, err := crypto.UnmarshalPubkey(sigPublicKey)
	addr := crypto.PubkeyToAddress(*ecdsaPubKey)
	return addr.Hex()
}

func Sign(message string, key *ecdsa.PrivateKey) (Signature, error) {
	hashRaw := crypto.Keccak256([]byte(message))
	signature, err := crypto.Sign(hashRaw, key)
	if err != nil {
		return Signature{}, err
	}
	// fmt.Printf("signature 0x%x\n", string(signature))

	var hash, r, s [32]byte
	copy(hash[:], hashRaw[:32])
	copy(r[:], signature[:32])
	copy(s[:], signature[32:64])
	return Signature{
		signature,
		hash,
		r,
		s,
		uint8(int(signature[64])) + 27, // Yes add 27, weird Ethereum quirk
	}, nil
}

func getSigner(log *types.Log) string {
	abi, err := abi.JSON(strings.NewReader(string(contract.ContractABI)))
	if err != nil {
		fmt.Printf("failed to get private dao contract ABI, error: %s", err.Error())
		return ""
	}

	var eventObj contract.ContractSigner
	abi.Unpack(&eventObj, "Signer", log.Data)
	return eventObj.Signer.Hex()
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
