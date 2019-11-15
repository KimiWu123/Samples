// Code generated - DO NOT EDIT.
// This file is a generated binding and any manual changes will be lost.

package sample

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

// SampleABI is the input ABI used to generate the binding from.
const SampleABI = "[{\"constant\":false,\"inputs\":[{\"internalType\":\"uint256\",\"name\":\"somevalue\",\"type\":\"uint256\"}],\"name\":\"run\",\"outputs\":[],\"payable\":false,\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[],\"payable\":false,\"stateMutability\":\"nonpayable\",\"type\":\"constructor\"},{\"anonymous\":false,\"inputs\":[{\"indexed\":false,\"internalType\":\"uint256\",\"name\":\"somevalue\",\"type\":\"uint256\"},{\"indexed\":false,\"internalType\":\"uint256\",\"name\":\"timestamp\",\"type\":\"uint256\"}],\"name\":\"Run\",\"type\":\"event\"}]"

// Sample is an auto generated Go binding around an Ethereum contract.
type Sample struct {
	SampleCaller     // Read-only binding to the contract
	SampleTransactor // Write-only binding to the contract
	SampleFilterer   // Log filterer for contract events
}

// SampleCaller is an auto generated read-only Go binding around an Ethereum contract.
type SampleCaller struct {
	contract *bind.BoundContract // Generic contract wrapper for the low level calls
}

// SampleTransactor is an auto generated write-only Go binding around an Ethereum contract.
type SampleTransactor struct {
	contract *bind.BoundContract // Generic contract wrapper for the low level calls
}

// SampleFilterer is an auto generated log filtering Go binding around an Ethereum contract events.
type SampleFilterer struct {
	contract *bind.BoundContract // Generic contract wrapper for the low level calls
}

// SampleSession is an auto generated Go binding around an Ethereum contract,
// with pre-set call and transact options.
type SampleSession struct {
	Contract     *Sample           // Generic contract binding to set the session for
	CallOpts     bind.CallOpts     // Call options to use throughout this session
	TransactOpts bind.TransactOpts // Transaction auth options to use throughout this session
}

// SampleCallerSession is an auto generated read-only Go binding around an Ethereum contract,
// with pre-set call options.
type SampleCallerSession struct {
	Contract *SampleCaller // Generic contract caller binding to set the session for
	CallOpts bind.CallOpts // Call options to use throughout this session
}

// SampleTransactorSession is an auto generated write-only Go binding around an Ethereum contract,
// with pre-set transact options.
type SampleTransactorSession struct {
	Contract     *SampleTransactor // Generic contract transactor binding to set the session for
	TransactOpts bind.TransactOpts // Transaction auth options to use throughout this session
}

// SampleRaw is an auto generated low-level Go binding around an Ethereum contract.
type SampleRaw struct {
	Contract *Sample // Generic contract binding to access the raw methods on
}

// SampleCallerRaw is an auto generated low-level read-only Go binding around an Ethereum contract.
type SampleCallerRaw struct {
	Contract *SampleCaller // Generic read-only contract binding to access the raw methods on
}

// SampleTransactorRaw is an auto generated low-level write-only Go binding around an Ethereum contract.
type SampleTransactorRaw struct {
	Contract *SampleTransactor // Generic write-only contract binding to access the raw methods on
}

// NewSample creates a new instance of Sample, bound to a specific deployed contract.
func NewSample(address common.Address, backend bind.ContractBackend) (*Sample, error) {
	contract, err := bindSample(address, backend, backend, backend)
	if err != nil {
		return nil, err
	}
	return &Sample{SampleCaller: SampleCaller{contract: contract}, SampleTransactor: SampleTransactor{contract: contract}, SampleFilterer: SampleFilterer{contract: contract}}, nil
}

// NewSampleCaller creates a new read-only instance of Sample, bound to a specific deployed contract.
func NewSampleCaller(address common.Address, caller bind.ContractCaller) (*SampleCaller, error) {
	contract, err := bindSample(address, caller, nil, nil)
	if err != nil {
		return nil, err
	}
	return &SampleCaller{contract: contract}, nil
}

// NewSampleTransactor creates a new write-only instance of Sample, bound to a specific deployed contract.
func NewSampleTransactor(address common.Address, transactor bind.ContractTransactor) (*SampleTransactor, error) {
	contract, err := bindSample(address, nil, transactor, nil)
	if err != nil {
		return nil, err
	}
	return &SampleTransactor{contract: contract}, nil
}

// NewSampleFilterer creates a new log filterer instance of Sample, bound to a specific deployed contract.
func NewSampleFilterer(address common.Address, filterer bind.ContractFilterer) (*SampleFilterer, error) {
	contract, err := bindSample(address, nil, nil, filterer)
	if err != nil {
		return nil, err
	}
	return &SampleFilterer{contract: contract}, nil
}

// bindSample binds a generic wrapper to an already deployed contract.
func bindSample(address common.Address, caller bind.ContractCaller, transactor bind.ContractTransactor, filterer bind.ContractFilterer) (*bind.BoundContract, error) {
	parsed, err := abi.JSON(strings.NewReader(SampleABI))
	if err != nil {
		return nil, err
	}
	return bind.NewBoundContract(address, parsed, caller, transactor, filterer), nil
}

// Call invokes the (constant) contract method with params as input values and
// sets the output to result. The result type might be a single field for simple
// returns, a slice of interfaces for anonymous returns and a struct for named
// returns.
func (_Sample *SampleRaw) Call(opts *bind.CallOpts, result interface{}, method string, params ...interface{}) error {
	return _Sample.Contract.SampleCaller.contract.Call(opts, result, method, params...)
}

// Transfer initiates a plain transaction to move funds to the contract, calling
// its default method if one is available.
func (_Sample *SampleRaw) Transfer(opts *bind.TransactOpts) (*types.Transaction, error) {
	return _Sample.Contract.SampleTransactor.contract.Transfer(opts)
}

// Transact invokes the (paid) contract method with params as input values.
func (_Sample *SampleRaw) Transact(opts *bind.TransactOpts, method string, params ...interface{}) (*types.Transaction, error) {
	return _Sample.Contract.SampleTransactor.contract.Transact(opts, method, params...)
}

// Call invokes the (constant) contract method with params as input values and
// sets the output to result. The result type might be a single field for simple
// returns, a slice of interfaces for anonymous returns and a struct for named
// returns.
func (_Sample *SampleCallerRaw) Call(opts *bind.CallOpts, result interface{}, method string, params ...interface{}) error {
	return _Sample.Contract.contract.Call(opts, result, method, params...)
}

// Transfer initiates a plain transaction to move funds to the contract, calling
// its default method if one is available.
func (_Sample *SampleTransactorRaw) Transfer(opts *bind.TransactOpts) (*types.Transaction, error) {
	return _Sample.Contract.contract.Transfer(opts)
}

// Transact invokes the (paid) contract method with params as input values.
func (_Sample *SampleTransactorRaw) Transact(opts *bind.TransactOpts, method string, params ...interface{}) (*types.Transaction, error) {
	return _Sample.Contract.contract.Transact(opts, method, params...)
}

// Run is a paid mutator transaction binding the contract method 0xa444f5e9.
//
// Solidity: function run(uint256 somevalue) returns()
func (_Sample *SampleTransactor) Run(opts *bind.TransactOpts, somevalue *big.Int) (*types.Transaction, error) {
	return _Sample.contract.Transact(opts, "run", somevalue)
}

// Run is a paid mutator transaction binding the contract method 0xa444f5e9.
//
// Solidity: function run(uint256 somevalue) returns()
func (_Sample *SampleSession) Run(somevalue *big.Int) (*types.Transaction, error) {
	return _Sample.Contract.Run(&_Sample.TransactOpts, somevalue)
}

// Run is a paid mutator transaction binding the contract method 0xa444f5e9.
//
// Solidity: function run(uint256 somevalue) returns()
func (_Sample *SampleTransactorSession) Run(somevalue *big.Int) (*types.Transaction, error) {
	return _Sample.Contract.Run(&_Sample.TransactOpts, somevalue)
}

// SampleRunIterator is returned from FilterRun and is used to iterate over the raw logs and unpacked data for Run events raised by the Sample contract.
type SampleRunIterator struct {
	Event *SampleRun // Event containing the contract specifics and raw log

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
func (it *SampleRunIterator) Next() bool {
	// If the iterator failed, stop iterating
	if it.fail != nil {
		return false
	}
	// If the iterator completed, deliver directly whatever's available
	if it.done {
		select {
		case log := <-it.logs:
			it.Event = new(SampleRun)
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
		it.Event = new(SampleRun)
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
func (it *SampleRunIterator) Error() error {
	return it.fail
}

// Close terminates the iteration process, releasing any pending underlying
// resources.
func (it *SampleRunIterator) Close() error {
	it.sub.Unsubscribe()
	return nil
}

// SampleRun represents a Run event raised by the Sample contract.
type SampleRun struct {
	Somevalue *big.Int
	Timestamp *big.Int
	Raw       types.Log // Blockchain specific contextual infos
}

// FilterRun is a free log retrieval operation binding the contract event 0xd480bdbada73a9e65d48539d1b6a1bd7fba9623aa0ef4f5e2915382c5b71e154.
//
// Solidity: event Run(uint256 somevalue, uint256 timestamp)
func (_Sample *SampleFilterer) FilterRun(opts *bind.FilterOpts) (*SampleRunIterator, error) {

	logs, sub, err := _Sample.contract.FilterLogs(opts, "Run")
	if err != nil {
		return nil, err
	}
	return &SampleRunIterator{contract: _Sample.contract, event: "Run", logs: logs, sub: sub}, nil
}

// WatchRun is a free log subscription operation binding the contract event 0xd480bdbada73a9e65d48539d1b6a1bd7fba9623aa0ef4f5e2915382c5b71e154.
//
// Solidity: event Run(uint256 somevalue, uint256 timestamp)
func (_Sample *SampleFilterer) WatchRun(opts *bind.WatchOpts, sink chan<- *SampleRun) (event.Subscription, error) {

	logs, sub, err := _Sample.contract.WatchLogs(opts, "Run")
	if err != nil {
		return nil, err
	}
	return event.NewSubscription(func(quit <-chan struct{}) error {
		defer sub.Unsubscribe()
		for {
			select {
			case log := <-logs:
				// New log arrived, parse the event and forward to the user
				event := new(SampleRun)
				if err := _Sample.contract.UnpackLog(event, "Run", log); err != nil {
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

// ParseRun is a log parse operation binding the contract event 0xd480bdbada73a9e65d48539d1b6a1bd7fba9623aa0ef4f5e2915382c5b71e154.
//
// Solidity: event Run(uint256 somevalue, uint256 timestamp)
func (_Sample *SampleFilterer) ParseRun(log types.Log) (*SampleRun, error) {
	event := new(SampleRun)
	if err := _Sample.contract.UnpackLog(event, "Run", log); err != nil {
		return nil, err
	}
	return event, nil
}
