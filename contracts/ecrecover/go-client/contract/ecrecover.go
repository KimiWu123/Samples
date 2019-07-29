// Code generated - DO NOT EDIT.
// This file is a generated binding and any manual changes will be lost.

package contract

import (
	"math/big"
	"strings"

	ethereum "github.com/ethereum/go-ethereum"
	"github.com/ethereum/go-ethereum/accounts/abi"
	"github.com/ethereum/go-ethereum/accounts/abi/bind"
	"github.com/ethereum/go-ethereum/common"
	"github.com/ethereum/go-ethereum/core/types"
	"github.com/ethereum/go-ethereum/event"
)

// Reference imports to suppress errors if they are not otherwise used.
var (
	_ = big.NewInt
	_ = strings.NewReader
	_ = ethereum.NotFound
	_ = abi.U256
	_ = bind.Bind
	_ = common.Big1
	_ = types.BloomLookup
	_ = event.NewSubscription
)

// ContractABI is the input ABI used to generate the binding from.
const ContractABI = "[{\"constant\":false,\"inputs\":[{\"name\":\"_message\",\"type\":\"bytes32\"},{\"name\":\"_v\",\"type\":\"uint8\"},{\"name\":\"_r\",\"type\":\"bytes32\"},{\"name\":\"_s\",\"type\":\"bytes32\"}],\"name\":\"verify_eip191\",\"outputs\":[{\"name\":\"\",\"type\":\"address\"}],\"payable\":false,\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"constant\":false,\"inputs\":[{\"name\":\"_message\",\"type\":\"bytes32\"},{\"name\":\"_v\",\"type\":\"uint8\"},{\"name\":\"_r\",\"type\":\"bytes32\"},{\"name\":\"_s\",\"type\":\"bytes32\"}],\"name\":\"verify\",\"outputs\":[{\"name\":\"\",\"type\":\"address\"}],\"payable\":false,\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[],\"payable\":false,\"stateMutability\":\"nonpayable\",\"type\":\"constructor\"},{\"anonymous\":false,\"inputs\":[{\"indexed\":false,\"name\":\"signer\",\"type\":\"address\"}],\"name\":\"Signer\",\"type\":\"event\"}]"

// ContractBin is the compiled bytecode used for deploying new contracts.
var ContractBin = "0x608060405234801561001057600080fd5b5061042b806100206000396000f3fe608060405234801561001057600080fd5b50600436106100365760003560e01c80635b7862061461003b578063f1835db7146100ca575b600080fd5b6100886004803603608081101561005157600080fd5b8101908080359060200190929190803560ff1690602001909291908035906020019092919080359060200190929190505050610159565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b610117600480360360808110156100e057600080fd5b8101908080359060200190929190803560ff16906020019092919080359060200190929190803590602001909291905050506102ef565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b600060606040518060400160405280601c81526020017f19457468657265756d205369676e6564204d6573736167653a0a3332000000008152509050600081876040516020018083805190602001908083835b602083106101cf57805182526020820191506020810190506020830392506101ac565b6001836020036101000a03801982511681845116808217855250505050505090500182815260200192505050604051602081830303815290604052805190602001209050600060018288888860405160008152602001604052604051808581526020018460ff1660ff1681526020018381526020018281526020019450505050506020604051602081039080840390855afa158015610272573d6000803e3d6000fd5b5050506020604051035190507ff4b0650db61027ac5b4ec7eb8ba223cf23715631228786676084b09a56b7786181604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390a1809350505050949350505050565b6000808560405160200180828152602001915050604051602081830303815290604052805190602001209050600060018287878760405160008152602001604052604051808581526020018460ff1660ff1681526020018381526020018281526020019450505050506020604051602081039080840390855afa15801561037a573d6000803e3d6000fd5b5050506020604051035190507ff4b0650db61027ac5b4ec7eb8ba223cf23715631228786676084b09a56b7786181604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390a1809250505094935050505056fea265627a7a72305820342deda3e028951729cd9a308bba9556acb3776965ccc1fc82d27e10c339c8ea64736f6c634300050a0032"

// DeployContract deploys a new Ethereum contract, binding an instance of Contract to it.
func DeployContract(auth *bind.TransactOpts, backend bind.ContractBackend) (common.Address, *types.Transaction, *Contract, error) {
	parsed, err := abi.JSON(strings.NewReader(ContractABI))
	if err != nil {
		return common.Address{}, nil, nil, err
	}

	address, tx, contract, err := bind.DeployContract(auth, parsed, common.FromHex(ContractBin), backend)
	if err != nil {
		return common.Address{}, nil, nil, err
	}
	return address, tx, &Contract{ContractCaller: ContractCaller{contract: contract}, ContractTransactor: ContractTransactor{contract: contract}, ContractFilterer: ContractFilterer{contract: contract}}, nil
}

// Contract is an auto generated Go binding around an Ethereum contract.
type Contract struct {
	ContractCaller     // Read-only binding to the contract
	ContractTransactor // Write-only binding to the contract
	ContractFilterer   // Log filterer for contract events
}

// ContractCaller is an auto generated read-only Go binding around an Ethereum contract.
type ContractCaller struct {
	contract *bind.BoundContract // Generic contract wrapper for the low level calls
}

// ContractTransactor is an auto generated write-only Go binding around an Ethereum contract.
type ContractTransactor struct {
	contract *bind.BoundContract // Generic contract wrapper for the low level calls
}

// ContractFilterer is an auto generated log filtering Go binding around an Ethereum contract events.
type ContractFilterer struct {
	contract *bind.BoundContract // Generic contract wrapper for the low level calls
}

// ContractSession is an auto generated Go binding around an Ethereum contract,
// with pre-set call and transact options.
type ContractSession struct {
	Contract     *Contract         // Generic contract binding to set the session for
	CallOpts     bind.CallOpts     // Call options to use throughout this session
	TransactOpts bind.TransactOpts // Transaction auth options to use throughout this session
}

// ContractCallerSession is an auto generated read-only Go binding around an Ethereum contract,
// with pre-set call options.
type ContractCallerSession struct {
	Contract *ContractCaller // Generic contract caller binding to set the session for
	CallOpts bind.CallOpts   // Call options to use throughout this session
}

// ContractTransactorSession is an auto generated write-only Go binding around an Ethereum contract,
// with pre-set transact options.
type ContractTransactorSession struct {
	Contract     *ContractTransactor // Generic contract transactor binding to set the session for
	TransactOpts bind.TransactOpts   // Transaction auth options to use throughout this session
}

// ContractRaw is an auto generated low-level Go binding around an Ethereum contract.
type ContractRaw struct {
	Contract *Contract // Generic contract binding to access the raw methods on
}

// ContractCallerRaw is an auto generated low-level read-only Go binding around an Ethereum contract.
type ContractCallerRaw struct {
	Contract *ContractCaller // Generic read-only contract binding to access the raw methods on
}

// ContractTransactorRaw is an auto generated low-level write-only Go binding around an Ethereum contract.
type ContractTransactorRaw struct {
	Contract *ContractTransactor // Generic write-only contract binding to access the raw methods on
}

// NewContract creates a new instance of Contract, bound to a specific deployed contract.
func NewContract(address common.Address, backend bind.ContractBackend) (*Contract, error) {
	contract, err := bindContract(address, backend, backend, backend)
	if err != nil {
		return nil, err
	}
	return &Contract{ContractCaller: ContractCaller{contract: contract}, ContractTransactor: ContractTransactor{contract: contract}, ContractFilterer: ContractFilterer{contract: contract}}, nil
}

// NewContractCaller creates a new read-only instance of Contract, bound to a specific deployed contract.
func NewContractCaller(address common.Address, caller bind.ContractCaller) (*ContractCaller, error) {
	contract, err := bindContract(address, caller, nil, nil)
	if err != nil {
		return nil, err
	}
	return &ContractCaller{contract: contract}, nil
}

// NewContractTransactor creates a new write-only instance of Contract, bound to a specific deployed contract.
func NewContractTransactor(address common.Address, transactor bind.ContractTransactor) (*ContractTransactor, error) {
	contract, err := bindContract(address, nil, transactor, nil)
	if err != nil {
		return nil, err
	}
	return &ContractTransactor{contract: contract}, nil
}

// NewContractFilterer creates a new log filterer instance of Contract, bound to a specific deployed contract.
func NewContractFilterer(address common.Address, filterer bind.ContractFilterer) (*ContractFilterer, error) {
	contract, err := bindContract(address, nil, nil, filterer)
	if err != nil {
		return nil, err
	}
	return &ContractFilterer{contract: contract}, nil
}

// bindContract binds a generic wrapper to an already deployed contract.
func bindContract(address common.Address, caller bind.ContractCaller, transactor bind.ContractTransactor, filterer bind.ContractFilterer) (*bind.BoundContract, error) {
	parsed, err := abi.JSON(strings.NewReader(ContractABI))
	if err != nil {
		return nil, err
	}
	return bind.NewBoundContract(address, parsed, caller, transactor, filterer), nil
}

// Call invokes the (constant) contract method with params as input values and
// sets the output to result. The result type might be a single field for simple
// returns, a slice of interfaces for anonymous returns and a struct for named
// returns.
func (_Contract *ContractRaw) Call(opts *bind.CallOpts, result interface{}, method string, params ...interface{}) error {
	return _Contract.Contract.ContractCaller.contract.Call(opts, result, method, params...)
}

// Transfer initiates a plain transaction to move funds to the contract, calling
// its default method if one is available.
func (_Contract *ContractRaw) Transfer(opts *bind.TransactOpts) (*types.Transaction, error) {
	return _Contract.Contract.ContractTransactor.contract.Transfer(opts)
}

// Transact invokes the (paid) contract method with params as input values.
func (_Contract *ContractRaw) Transact(opts *bind.TransactOpts, method string, params ...interface{}) (*types.Transaction, error) {
	return _Contract.Contract.ContractTransactor.contract.Transact(opts, method, params...)
}

// Call invokes the (constant) contract method with params as input values and
// sets the output to result. The result type might be a single field for simple
// returns, a slice of interfaces for anonymous returns and a struct for named
// returns.
func (_Contract *ContractCallerRaw) Call(opts *bind.CallOpts, result interface{}, method string, params ...interface{}) error {
	return _Contract.Contract.contract.Call(opts, result, method, params...)
}

// Transfer initiates a plain transaction to move funds to the contract, calling
// its default method if one is available.
func (_Contract *ContractTransactorRaw) Transfer(opts *bind.TransactOpts) (*types.Transaction, error) {
	return _Contract.Contract.contract.Transfer(opts)
}

// Transact invokes the (paid) contract method with params as input values.
func (_Contract *ContractTransactorRaw) Transact(opts *bind.TransactOpts, method string, params ...interface{}) (*types.Transaction, error) {
	return _Contract.Contract.contract.Transact(opts, method, params...)
}

// Verify is a paid mutator transaction binding the contract method 0xf1835db7.
//
// Solidity: function verify(bytes32 _message, uint8 _v, bytes32 _r, bytes32 _s) returns(address)
func (_Contract *ContractTransactor) Verify(opts *bind.TransactOpts, _message [32]byte, _v uint8, _r [32]byte, _s [32]byte) (*types.Transaction, error) {
	return _Contract.contract.Transact(opts, "verify", _message, _v, _r, _s)
}

// Verify is a paid mutator transaction binding the contract method 0xf1835db7.
//
// Solidity: function verify(bytes32 _message, uint8 _v, bytes32 _r, bytes32 _s) returns(address)
func (_Contract *ContractSession) Verify(_message [32]byte, _v uint8, _r [32]byte, _s [32]byte) (*types.Transaction, error) {
	return _Contract.Contract.Verify(&_Contract.TransactOpts, _message, _v, _r, _s)
}

// Verify is a paid mutator transaction binding the contract method 0xf1835db7.
//
// Solidity: function verify(bytes32 _message, uint8 _v, bytes32 _r, bytes32 _s) returns(address)
func (_Contract *ContractTransactorSession) Verify(_message [32]byte, _v uint8, _r [32]byte, _s [32]byte) (*types.Transaction, error) {
	return _Contract.Contract.Verify(&_Contract.TransactOpts, _message, _v, _r, _s)
}

// VerifyEip191 is a paid mutator transaction binding the contract method 0x5b786206.
//
// Solidity: function verify_eip191(bytes32 _message, uint8 _v, bytes32 _r, bytes32 _s) returns(address)
func (_Contract *ContractTransactor) VerifyEip191(opts *bind.TransactOpts, _message [32]byte, _v uint8, _r [32]byte, _s [32]byte) (*types.Transaction, error) {
	return _Contract.contract.Transact(opts, "verify_eip191", _message, _v, _r, _s)
}

// VerifyEip191 is a paid mutator transaction binding the contract method 0x5b786206.
//
// Solidity: function verify_eip191(bytes32 _message, uint8 _v, bytes32 _r, bytes32 _s) returns(address)
func (_Contract *ContractSession) VerifyEip191(_message [32]byte, _v uint8, _r [32]byte, _s [32]byte) (*types.Transaction, error) {
	return _Contract.Contract.VerifyEip191(&_Contract.TransactOpts, _message, _v, _r, _s)
}

// VerifyEip191 is a paid mutator transaction binding the contract method 0x5b786206.
//
// Solidity: function verify_eip191(bytes32 _message, uint8 _v, bytes32 _r, bytes32 _s) returns(address)
func (_Contract *ContractTransactorSession) VerifyEip191(_message [32]byte, _v uint8, _r [32]byte, _s [32]byte) (*types.Transaction, error) {
	return _Contract.Contract.VerifyEip191(&_Contract.TransactOpts, _message, _v, _r, _s)
}

// ContractSignerIterator is returned from FilterSigner and is used to iterate over the raw logs and unpacked data for Signer events raised by the Contract contract.
type ContractSignerIterator struct {
	Event *ContractSigner // Event containing the contract specifics and raw log

	contract *bind.BoundContract // Generic contract to use for unpacking event data
	event    string              // Event name to use for unpacking event data

	logs chan types.Log        // Log channel receiving the found contract events
	sub  ethereum.Subscription // Subscription for errors, completion and termination
	done bool                  // Whether the subscription completed delivering logs
	fail error                 // Occurred error to stop iteration
}

// Next advances the iterator to the subsequent event, returning whether there
// are any more events found. In case of a retrieval or parsing error, false is
// returned and Error() can be queried for the exact failure.
func (it *ContractSignerIterator) Next() bool {
	// If the iterator failed, stop iterating
	if it.fail != nil {
		return false
	}
	// If the iterator completed, deliver directly whatever's available
	if it.done {
		select {
		case log := <-it.logs:
			it.Event = new(ContractSigner)
			if err := it.contract.UnpackLog(it.Event, it.event, log); err != nil {
				it.fail = err
				return false
			}
			it.Event.Raw = log
			return true

		default:
			return false
		}
	}
	// Iterator still in progress, wait for either a data or an error event
	select {
	case log := <-it.logs:
		it.Event = new(ContractSigner)
		if err := it.contract.UnpackLog(it.Event, it.event, log); err != nil {
			it.fail = err
			return false
		}
		it.Event.Raw = log
		return true

	case err := <-it.sub.Err():
		it.done = true
		it.fail = err
		return it.Next()
	}
}

// Error returns any retrieval or parsing error occurred during filtering.
func (it *ContractSignerIterator) Error() error {
	return it.fail
}

// Close terminates the iteration process, releasing any pending underlying
// resources.
func (it *ContractSignerIterator) Close() error {
	it.sub.Unsubscribe()
	return nil
}

// ContractSigner represents a Signer event raised by the Contract contract.
type ContractSigner struct {
	Signer common.Address
	Raw    types.Log // Blockchain specific contextual infos
}

// FilterSigner is a free log retrieval operation binding the contract event 0xf4b0650db61027ac5b4ec7eb8ba223cf23715631228786676084b09a56b77861.
//
// Solidity: event Signer(address signer)
func (_Contract *ContractFilterer) FilterSigner(opts *bind.FilterOpts) (*ContractSignerIterator, error) {

	logs, sub, err := _Contract.contract.FilterLogs(opts, "Signer")
	if err != nil {
		return nil, err
	}
	return &ContractSignerIterator{contract: _Contract.contract, event: "Signer", logs: logs, sub: sub}, nil
}

// WatchSigner is a free log subscription operation binding the contract event 0xf4b0650db61027ac5b4ec7eb8ba223cf23715631228786676084b09a56b77861.
//
// Solidity: event Signer(address signer)
func (_Contract *ContractFilterer) WatchSigner(opts *bind.WatchOpts, sink chan<- *ContractSigner) (event.Subscription, error) {

	logs, sub, err := _Contract.contract.WatchLogs(opts, "Signer")
	if err != nil {
		return nil, err
	}
	return event.NewSubscription(func(quit <-chan struct{}) error {
		defer sub.Unsubscribe()
		for {
			select {
			case log := <-logs:
				// New log arrived, parse the event and forward to the user
				event := new(ContractSigner)
				if err := _Contract.contract.UnpackLog(event, "Signer", log); err != nil {
					return err
				}
				event.Raw = log

				select {
				case sink <- event:
				case err := <-sub.Err():
					return err
				case <-quit:
					return nil
				}
			case err := <-sub.Err():
				return err
			case <-quit:
				return nil
			}
		}
	}), nil
}

// ParseSigner is a log parse operation binding the contract event 0xf4b0650db61027ac5b4ec7eb8ba223cf23715631228786676084b09a56b77861.
//
// Solidity: event Signer(address signer)
func (_Contract *ContractFilterer) ParseSigner(log types.Log) (*ContractSigner, error) {
	event := new(ContractSigner)
	if err := _Contract.contract.UnpackLog(event, "Signer", log); err != nil {
		return nil, err
	}
	return event, nil
}
