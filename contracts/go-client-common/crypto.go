package goclientcommon

import (
	"crypto/ecdsa"

	"github.com/ethereum/go-ethereum/crypto"
)

type Signature struct {
	Raw  []byte
	Hash [32]byte
	R    [32]byte
	S    [32]byte
	V    uint8
}

func SignWithBytes(message []byte, key *ecdsa.PrivateKey) (Signature, error) {
	hashRaw := crypto.Keccak256(message)
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

func SignWithString(message string, key *ecdsa.PrivateKey) (Signature, error) {
	return SignWithBytes([]byte(message), key)
}
