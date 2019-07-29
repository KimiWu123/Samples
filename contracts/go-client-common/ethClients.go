package ethereumutil

import (
	"context"
	"crypto/ecdsa"
	"encoding/hex"
	"fmt"
	"math/big"

	"github.com/ethereum/go-ethereum/common"
	"github.com/ethereum/go-ethereum/core/types"
	"github.com/ethereum/go-ethereum/crypto"
	"github.com/ethereum/go-ethereum/ethclient"
	"github.com/ethereum/go-ethereum/rlp"
	// "github.com/spf13/viper"
)

var gasLimit uint64 = 1e6
var gasPrice *big.Int = big.NewInt(1e9)

// GetEthClient ...
func GetEthClient(rpc string) (*ethclient.Client, error) {

	fmt.Printf("connect to %s\n", rpc)
	ethClient, err := ethclient.Dial(rpc)
	if err != nil {
		fmt.Printf("can NOT get ethclient object, <%s>, error: %s", rpc, err.Error())
		return nil, err
	}
	return ethClient, nil
}

// GetNonce ...
func GetNonce(client *ethclient.Client, address common.Address) uint64 {
	nonce, err := client.PendingNonceAt(context.Background(), address)
	if err != nil {
		fmt.Printf("can NOT get nonce of %s, error: %s", address.Hex(), err.Error())
		return 0
	}
	return nonce
}

// GetNonceFromPrivatekey ...
func GetNonceFromPrivatekey(client *ethclient.Client, key *ecdsa.PrivateKey) uint64 {
	publicKeyECDSA, ok := key.Public().(*ecdsa.PublicKey)
	if !ok {
		fmt.Printf("error to get public key from private key")
		return 0
	}
	return GetNonce(client, crypto.PubkeyToAddress(*publicKeyECDSA))
}

// GetBalance ...
func GetBalance(client *ethclient.Client, address common.Address) *big.Int {
	balance, err := client.BalanceAt(context.Background(), address, nil)
	if err != nil {
		fmt.Printf("can NOT get balance of %s, error: %s", address.Hex(), err.Error())
		return big.NewInt(0)
	}
	return balance
}

// SendTransaction ...
func SendTransaction(client *ethclient.Client, signTx string) (string, error) {
	var tx *types.Transaction
	rawTx, err := hex.DecodeString(signTx)
	err = rlp.DecodeBytes(rawTx, &tx)
	if err != nil {
		fmt.Printf("decode raw tx error: %s", err.Error())
		return "", err
	}

	err = client.SendTransaction(context.Background(), tx)
	if err != nil {
		fmt.Printf("send transaction error: %s", err.Error())
		return "", err
	}
	return tx.Hash().Hex(), err
}

// GetTransactionHash ...
func GetTransactionHash(signedTx string) (string, error) {
	var tx *types.Transaction
	rawTx, err := hex.DecodeString(signedTx)
	err = rlp.DecodeBytes(rawTx, &tx)
	if err != nil {
		fmt.Printf("decode raw tx error: %s", err.Error())
		return "", err
	}
	return tx.Hash().Hex(), err
}

// Transfer ...
func Transfer(client *ethclient.Client, prv *ecdsa.PrivateKey, toAddr common.Address, amount *big.Int) (string, error) {

	publicKey := prv.Public()
	publicKeyECDSA, ok := publicKey.(*ecdsa.PublicKey)
	if !ok {
		fmt.Printf("error casting public key to ECDSA")
		return "", nil
	}
	fromAddress := crypto.PubkeyToAddress(*publicKeyECDSA)
	nonce, err := client.PendingNonceAt(context.Background(), fromAddress)
	if err != nil {
		fmt.Printf("get nonce error: %s", err.Error())
		return "", err
	}
	return TransferWithNonce(client, prv, toAddr, amount, nonce, nil)
}

// TransferWithNonce ...
func TransferWithNonce(client *ethclient.Client, prv *ecdsa.PrivateKey, toAddr common.Address, amount *big.Int, nonce uint64, data []byte) (string, error) {

	tx := types.NewTransaction(nonce, toAddr, amount, gasLimit, gasPrice, data)
	signedTx, err := types.SignTx(tx, types.HomesteadSigner{}, prv)
	if err != nil {
		fmt.Printf("sign tx error: %s", err.Error())
		return "", err
	}

	err = client.SendTransaction(context.Background(), signedTx)
	if err != nil {
		fmt.Printf("send transaction error: %s", err.Error())
		return "", err
	}

	return tx.Hash().Hex(), err
}
