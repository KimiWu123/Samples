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
const ContractABI = "[{\"constant\":false,\"inputs\":[],\"name\":\"approve\",\"outputs\":[],\"payable\":false,\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"constant\":true,\"inputs\":[{\"name\":\"\",\"type\":\"uint256\"}],\"name\":\"admins\",\"outputs\":[{\"name\":\"\",\"type\":\"address\"}],\"payable\":false,\"stateMutability\":\"view\",\"type\":\"function\"},{\"constant\":true,\"inputs\":[{\"name\":\"_admin\",\"type\":\"address\"}],\"name\":\"isAdmin\",\"outputs\":[{\"name\":\"\",\"type\":\"bool\"}],\"payable\":false,\"stateMutability\":\"view\",\"type\":\"function\"},{\"constant\":false,\"inputs\":[],\"name\":\"reject\",\"outputs\":[],\"payable\":false,\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"constant\":true,\"inputs\":[],\"name\":\"result\",\"outputs\":[{\"name\":\"\",\"type\":\"uint8\"}],\"payable\":false,\"stateMutability\":\"view\",\"type\":\"function\"},{\"constant\":true,\"inputs\":[{\"name\":\"\",\"type\":\"uint256\"}],\"name\":\"votedUsers\",\"outputs\":[{\"name\":\"voter\",\"type\":\"address\"},{\"name\":\"opinion\",\"type\":\"bool\"}],\"payable\":false,\"stateMutability\":\"view\",\"type\":\"function\"},{\"constant\":true,\"inputs\":[{\"name\":\"\",\"type\":\"uint256\"}],\"name\":\"pendingAdmins\",\"outputs\":[{\"name\":\"\",\"type\":\"address\"}],\"payable\":false,\"stateMutability\":\"view\",\"type\":\"function\"},{\"constant\":false,\"inputs\":[{\"name\":\"_newAdmins\",\"type\":\"address[]\"}],\"name\":\"updateAdmins\",\"outputs\":[],\"payable\":false,\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"constant\":true,\"inputs\":[],\"name\":\"finalized\",\"outputs\":[{\"name\":\"\",\"type\":\"bool\"}],\"payable\":false,\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[{\"name\":\"initAdmins\",\"type\":\"address[]\"}],\"payable\":false,\"stateMutability\":\"nonpayable\",\"type\":\"constructor\"},{\"anonymous\":false,\"inputs\":[{\"indexed\":false,\"name\":\"pendingsNew\",\"type\":\"address[]\"}],\"name\":\"PendingAdmins\",\"type\":\"event\"},{\"anonymous\":false,\"inputs\":[],\"name\":\"Finalized\",\"type\":\"event\"},{\"anonymous\":false,\"inputs\":[],\"name\":\"Initilized\",\"type\":\"event\"},{\"anonymous\":false,\"inputs\":[],\"name\":\"AbandonChange\",\"type\":\"event\"}]"

// ContractBin is the compiled bytecode used for deploying new contracts.
var ContractBin = "0x60806040523480156200001157600080fd5b50604051620013cc380380620013cc833981810160405260208110156200003757600080fd5b8101908080516401000000008111156200005057600080fd5b828101905060208101848111156200006757600080fd5b81518560208202830111640100000000821117156200008557600080fd5b50509291905050506200009e81620000b560201b60201c565b620000ae620002b760201b60201c565b5062000444565b60008090505b81518110156200020557818181518110620000d257fe5b602002602001015173ffffffffffffffffffffffffffffffffffffffff16600073ffffffffffffffffffffffffffffffffffffffff1614156200017d576040517f08c379a000000000000000000000000000000000000000000000000000000000815260040180806020018281038252600a8152602001807f656d70747920616464720000000000000000000000000000000000000000000081525060200191505060405180910390fd5b60018282815181106200018c57fe5b602002602001015190806001815401808255809150509060018203906000526020600020016000909192909190916101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff160217905550508080600101915050620000bb565b507f55ab0f0ce1c6e8860e5a8155123057a22b761acbc93887ad90f5e70441680a55600160405180806020018281038252838181548152602001915080548015620002a657602002820191906000526020600020905b8160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190600101908083116200025b575b50509250505060405180910390a150565b60016000908054620002cb9291906200035c565b506001600260006101000a81548160ff02191690836002811115620002ec57fe5b0217905550620003016200030360201b60201c565b565b6001600260016101000a81548160ff021916908315150217905550600160006200032e9190620003b3565b7f6823b073d48d6e3a7d385eeb601452d680e74bb46afe3255a7d778f3a9b1768160405160405180910390a1565b828054828255906000526020600020908101928215620003a05760005260206000209182015b828111156200039f57825482559160010191906001019062000382565b5b509050620003af9190620003d6565b5090565b5080546000825590600052602060002090810190620003d391906200041c565b50565b6200041991905b808211156200041557600081816101000a81549073ffffffffffffffffffffffffffffffffffffffff021916905550600101620003dd565b5090565b90565b6200044191905b808211156200043d57600081600090555060010162000423565b5090565b90565b610f7880620004546000396000f3fe608060405234801561001057600080fd5b50600436106100935760003560e01c806365372147116100665780636537214714610176578063a143a5f2146101a2578063a58edf091461021b578063acf1f20f14610289578063b3f05b971461034157610093565b806312424e3f1461009857806314bfd6d0146100a257806324d7806c146101105780634dc415de1461016c575b600080fd5b6100a0610363565b005b6100ce600480360360208110156100b857600080fd5b8101908080359060200190929190505050610535565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b6101526004803603602081101561012657600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff169060200190929190505050610571565b604051808215151515815260200191505060405180910390f35b610174610619565b005b61017e6107eb565b6040518082600281111561018e57fe5b60ff16815260200191505060405180910390f35b6101ce600480360360208110156101b857600080fd5b81019080803590602001909291905050506107fe565b604051808373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001821515151581526020019250505060405180910390f35b6102476004803603602081101561023157600080fd5b8101908080359060200190929190505050610858565b604051808273ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200191505060405180910390f35b61033f6004803603602081101561029f57600080fd5b81019080803590602001906401000000008111156102bc57600080fd5b8201836020820111156102ce57600080fd5b803590602001918460208302840111640100000000831117156102f057600080fd5b919080806020026020016040519081016040528093929190818152602001838360200280828437600081840152601f19601f820116905080830192505050505050509192919290505050610894565b005b61034961092a565b604051808215151515815260200191505060405180910390f35b61036c33610571565b6103de576040517f08c379a00000000000000000000000000000000000000000000000000000000081526004018080602001828103825260098152602001807f4e6f742041444d494e000000000000000000000000000000000000000000000081525060200191505060405180910390fd5b6103e73361093d565b1561045a576040517f08c379a00000000000000000000000000000000000000000000000000000000081526004018080602001828103825260058152602001807f766f74656400000000000000000000000000000000000000000000000000000081525060200191505060405180910390fd5b600360405180604001604052803373ffffffffffffffffffffffffffffffffffffffff1681526020016001151581525090806001815401808255809150509060018203906000526020600020016000909192909190915060008201518160000160006101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff16021790555060208201518160000160146101000a81548160ff02191690831515021790555050505061052560016109e8565b1561053357610532610a86565b5b565b6000818154811061054257fe5b906000526020600020016000915054906101000a900473ffffffffffffffffffffffffffffffffffffffff1681565b600080600090505b6000805490508160ff16101561060e578273ffffffffffffffffffffffffffffffffffffffff1660008260ff16815481106105b057fe5b9060005260206000200160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff161415610601576001915050610614565b8080600101915050610579565b50600090505b919050565b61062233610571565b610694576040517f08c379a00000000000000000000000000000000000000000000000000000000081526004018080602001828103825260098152602001807f4e6f742041444d494e000000000000000000000000000000000000000000000081525060200191505060405180910390fd5b61069d3361093d565b15610710576040517f08c379a00000000000000000000000000000000000000000000000000000000081526004018080602001828103825260058152602001807f766f74656400000000000000000000000000000000000000000000000000000081525060200191505060405180910390fd5b600360405180604001604052803373ffffffffffffffffffffffffffffffffffffffff1681526020016000151581525090806001815401808255809150509060018203906000526020600020016000909192909190915060008201518160000160006101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff16021790555060208201518160000160146101000a81548160ff0219169083151502179055505050506107db60006109e8565b156107e9576107e8610ac7565b5b565b600260009054906101000a900460ff1681565b6003818154811061080b57fe5b906000526020600020016000915090508060000160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff16908060000160149054906101000a900460ff16905082565b6001818154811061086557fe5b906000526020600020016000915054906101000a900473ffffffffffffffffffffffffffffffffffffffff1681565b600260019054906101000a900460ff16610916576040517f08c379a000000000000000000000000000000000000000000000000000000000815260040180806020018281038252600d8152602001807f4e6f742066696e616c697a65640000000000000000000000000000000000000081525060200191505060405180910390fd5b61091e610b20565b61092781610b9b565b50565b600260019054906101000a900460ff1681565b600080600090505b6003805490508160ff1610156109dd578273ffffffffffffffffffffffffffffffffffffffff1660038260ff168154811061097c57fe5b9060005260206000200160000160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1614156109d05760019150506109e3565b8080600101915050610945565b50600090505b919050565b600080600060026000805490501415610a045760019150610a17565b600260008054905081610a1357fe5b0491505b60008090505b600380549050811015610a735784151560038281548110610a3a57fe5b9060005260206000200160000160149054906101000a900460ff1615151415610a665781806001019250505b8080600101915050610a1d565b508160ff168160ff161192505050919050565b60016000908054610a98929190610ded565b506001600260006101000a81548160ff02191690836002811115610ab857fe5b0217905550610ac5610d96565b565b60028060006101000a81548160ff02191690836002811115610ae557fe5b0217905550610af2610d96565b7fbbc4d527949f6d7133c1e4cd55cb12cbf629444cb7efcecc5e2e5ad35e0539c760405160405180910390a1565b6000600260016101000a81548160ff0219169083151502179055506000600260006101000a81548160ff02191690836002811115610b5a57fe5b021790555060036000610b6d9190610e3f565b7f136a97475f0483b5c3d2731a0a81ae36f650ca81e632e19a50fcafad3a8e6f1460405160405180910390a1565b60008090505b8151811015610ce657818181518110610bb657fe5b602002602001015173ffffffffffffffffffffffffffffffffffffffff16600073ffffffffffffffffffffffffffffffffffffffff161415610c60576040517f08c379a000000000000000000000000000000000000000000000000000000000815260040180806020018281038252600a8152602001807f656d70747920616464720000000000000000000000000000000000000000000081525060200191505060405180910390fd5b6001828281518110610c6e57fe5b602002602001015190806001815401808255809150509060018203906000526020600020016000909192909190916101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff160217905550508080600101915050610ba1565b507f55ab0f0ce1c6e8860e5a8155123057a22b761acbc93887ad90f5e70441680a55600160405180806020018281038252838181548152602001915080548015610d8557602002820191906000526020600020905b8160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020019060010190808311610d3b575b50509250505060405180910390a150565b6001600260016101000a81548160ff02191690831515021790555060016000610dbf9190610e60565b7f6823b073d48d6e3a7d385eeb601452d680e74bb46afe3255a7d778f3a9b1768160405160405180910390a1565b828054828255906000526020600020908101928215610e2e5760005260206000209182015b82811115610e2d578254825591600101919060010190610e12565b5b509050610e3b9190610e81565b5090565b5080546000825590600052602060002090810190610e5d9190610ec4565b50565b5080546000825590600052602060002090810190610e7e9190610f1e565b50565b610ec191905b80821115610ebd57600081816101000a81549073ffffffffffffffffffffffffffffffffffffffff021916905550600101610e87565b5090565b90565b610f1b91905b80821115610f1757600080820160006101000a81549073ffffffffffffffffffffffffffffffffffffffff02191690556000820160146101000a81549060ff021916905550600101610eca565b5090565b90565b610f4091905b80821115610f3c576000816000905550600101610f24565b5090565b9056fea265627a7a72305820e5d63050f27b7119943f24ef4a73cf49f5f55b378f62628b6b8be5dc41cd20ae64736f6c634300050a0032"

// DeployContract deploys a new Ethereum contract, binding an instance of Contract to it.
func DeployContract(auth *bind.TransactOpts, backend bind.ContractBackend, initAdmins []common.Address) (common.Address, *types.Transaction, *Contract, error) {
	parsed, err := abi.JSON(strings.NewReader(ContractABI))
	if err != nil {
		return common.Address{}, nil, nil, err
	}

	address, tx, contract, err := bind.DeployContract(auth, parsed, common.FromHex(ContractBin), backend, initAdmins)
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

// Admins is a free data retrieval call binding the contract method 0x14bfd6d0.
//
// Solidity: function admins(uint256 ) constant returns(address)
func (_Contract *ContractCaller) Admins(opts *bind.CallOpts, arg0 *big.Int) (common.Address, error) {
	var (
		ret0 = new(common.Address)
	)
	out := ret0
	err := _Contract.contract.Call(opts, out, "admins", arg0)
	return *ret0, err
}

// Admins is a free data retrieval call binding the contract method 0x14bfd6d0.
//
// Solidity: function admins(uint256 ) constant returns(address)
func (_Contract *ContractSession) Admins(arg0 *big.Int) (common.Address, error) {
	return _Contract.Contract.Admins(&_Contract.CallOpts, arg0)
}

// Admins is a free data retrieval call binding the contract method 0x14bfd6d0.
//
// Solidity: function admins(uint256 ) constant returns(address)
func (_Contract *ContractCallerSession) Admins(arg0 *big.Int) (common.Address, error) {
	return _Contract.Contract.Admins(&_Contract.CallOpts, arg0)
}

// Finalized is a free data retrieval call binding the contract method 0xb3f05b97.
//
// Solidity: function finalized() constant returns(bool)
func (_Contract *ContractCaller) Finalized(opts *bind.CallOpts) (bool, error) {
	var (
		ret0 = new(bool)
	)
	out := ret0
	err := _Contract.contract.Call(opts, out, "finalized")
	return *ret0, err
}

// Finalized is a free data retrieval call binding the contract method 0xb3f05b97.
//
// Solidity: function finalized() constant returns(bool)
func (_Contract *ContractSession) Finalized() (bool, error) {
	return _Contract.Contract.Finalized(&_Contract.CallOpts)
}

// Finalized is a free data retrieval call binding the contract method 0xb3f05b97.
//
// Solidity: function finalized() constant returns(bool)
func (_Contract *ContractCallerSession) Finalized() (bool, error) {
	return _Contract.Contract.Finalized(&_Contract.CallOpts)
}

// IsAdmin is a free data retrieval call binding the contract method 0x24d7806c.
//
// Solidity: function isAdmin(address _admin) constant returns(bool)
func (_Contract *ContractCaller) IsAdmin(opts *bind.CallOpts, _admin common.Address) (bool, error) {
	var (
		ret0 = new(bool)
	)
	out := ret0
	err := _Contract.contract.Call(opts, out, "isAdmin", _admin)
	return *ret0, err
}

// IsAdmin is a free data retrieval call binding the contract method 0x24d7806c.
//
// Solidity: function isAdmin(address _admin) constant returns(bool)
func (_Contract *ContractSession) IsAdmin(_admin common.Address) (bool, error) {
	return _Contract.Contract.IsAdmin(&_Contract.CallOpts, _admin)
}

// IsAdmin is a free data retrieval call binding the contract method 0x24d7806c.
//
// Solidity: function isAdmin(address _admin) constant returns(bool)
func (_Contract *ContractCallerSession) IsAdmin(_admin common.Address) (bool, error) {
	return _Contract.Contract.IsAdmin(&_Contract.CallOpts, _admin)
}

// PendingAdmins is a free data retrieval call binding the contract method 0xa58edf09.
//
// Solidity: function pendingAdmins(uint256 ) constant returns(address)
func (_Contract *ContractCaller) PendingAdmins(opts *bind.CallOpts, arg0 *big.Int) (common.Address, error) {
	var (
		ret0 = new(common.Address)
	)
	out := ret0
	err := _Contract.contract.Call(opts, out, "pendingAdmins", arg0)
	return *ret0, err
}

// PendingAdmins is a free data retrieval call binding the contract method 0xa58edf09.
//
// Solidity: function pendingAdmins(uint256 ) constant returns(address)
func (_Contract *ContractSession) PendingAdmins(arg0 *big.Int) (common.Address, error) {
	return _Contract.Contract.PendingAdmins(&_Contract.CallOpts, arg0)
}

// PendingAdmins is a free data retrieval call binding the contract method 0xa58edf09.
//
// Solidity: function pendingAdmins(uint256 ) constant returns(address)
func (_Contract *ContractCallerSession) PendingAdmins(arg0 *big.Int) (common.Address, error) {
	return _Contract.Contract.PendingAdmins(&_Contract.CallOpts, arg0)
}

// Result is a free data retrieval call binding the contract method 0x65372147.
//
// Solidity: function result() constant returns(uint8)
func (_Contract *ContractCaller) Result(opts *bind.CallOpts) (uint8, error) {
	var (
		ret0 = new(uint8)
	)
	out := ret0
	err := _Contract.contract.Call(opts, out, "result")
	return *ret0, err
}

// Result is a free data retrieval call binding the contract method 0x65372147.
//
// Solidity: function result() constant returns(uint8)
func (_Contract *ContractSession) Result() (uint8, error) {
	return _Contract.Contract.Result(&_Contract.CallOpts)
}

// Result is a free data retrieval call binding the contract method 0x65372147.
//
// Solidity: function result() constant returns(uint8)
func (_Contract *ContractCallerSession) Result() (uint8, error) {
	return _Contract.Contract.Result(&_Contract.CallOpts)
}

// VotedUsers is a free data retrieval call binding the contract method 0xa143a5f2.
//
// Solidity: function votedUsers(uint256 ) constant returns(address voter, bool opinion)
func (_Contract *ContractCaller) VotedUsers(opts *bind.CallOpts, arg0 *big.Int) (struct {
	Voter   common.Address
	Opinion bool
}, error) {
	ret := new(struct {
		Voter   common.Address
		Opinion bool
	})
	out := ret
	err := _Contract.contract.Call(opts, out, "votedUsers", arg0)
	return *ret, err
}

// VotedUsers is a free data retrieval call binding the contract method 0xa143a5f2.
//
// Solidity: function votedUsers(uint256 ) constant returns(address voter, bool opinion)
func (_Contract *ContractSession) VotedUsers(arg0 *big.Int) (struct {
	Voter   common.Address
	Opinion bool
}, error) {
	return _Contract.Contract.VotedUsers(&_Contract.CallOpts, arg0)
}

// VotedUsers is a free data retrieval call binding the contract method 0xa143a5f2.
//
// Solidity: function votedUsers(uint256 ) constant returns(address voter, bool opinion)
func (_Contract *ContractCallerSession) VotedUsers(arg0 *big.Int) (struct {
	Voter   common.Address
	Opinion bool
}, error) {
	return _Contract.Contract.VotedUsers(&_Contract.CallOpts, arg0)
}

// Approve is a paid mutator transaction binding the contract method 0x12424e3f.
//
// Solidity: function approve() returns()
func (_Contract *ContractTransactor) Approve(opts *bind.TransactOpts) (*types.Transaction, error) {
	return _Contract.contract.Transact(opts, "approve")
}

// Approve is a paid mutator transaction binding the contract method 0x12424e3f.
//
// Solidity: function approve() returns()
func (_Contract *ContractSession) Approve() (*types.Transaction, error) {
	return _Contract.Contract.Approve(&_Contract.TransactOpts)
}

// Approve is a paid mutator transaction binding the contract method 0x12424e3f.
//
// Solidity: function approve() returns()
func (_Contract *ContractTransactorSession) Approve() (*types.Transaction, error) {
	return _Contract.Contract.Approve(&_Contract.TransactOpts)
}

// Reject is a paid mutator transaction binding the contract method 0x4dc415de.
//
// Solidity: function reject() returns()
func (_Contract *ContractTransactor) Reject(opts *bind.TransactOpts) (*types.Transaction, error) {
	return _Contract.contract.Transact(opts, "reject")
}

// Reject is a paid mutator transaction binding the contract method 0x4dc415de.
//
// Solidity: function reject() returns()
func (_Contract *ContractSession) Reject() (*types.Transaction, error) {
	return _Contract.Contract.Reject(&_Contract.TransactOpts)
}

// Reject is a paid mutator transaction binding the contract method 0x4dc415de.
//
// Solidity: function reject() returns()
func (_Contract *ContractTransactorSession) Reject() (*types.Transaction, error) {
	return _Contract.Contract.Reject(&_Contract.TransactOpts)
}

// UpdateAdmins is a paid mutator transaction binding the contract method 0xacf1f20f.
//
// Solidity: function updateAdmins(address[] _newAdmins) returns()
func (_Contract *ContractTransactor) UpdateAdmins(opts *bind.TransactOpts, _newAdmins []common.Address) (*types.Transaction, error) {
	return _Contract.contract.Transact(opts, "updateAdmins", _newAdmins)
}

// UpdateAdmins is a paid mutator transaction binding the contract method 0xacf1f20f.
//
// Solidity: function updateAdmins(address[] _newAdmins) returns()
func (_Contract *ContractSession) UpdateAdmins(_newAdmins []common.Address) (*types.Transaction, error) {
	return _Contract.Contract.UpdateAdmins(&_Contract.TransactOpts, _newAdmins)
}

// UpdateAdmins is a paid mutator transaction binding the contract method 0xacf1f20f.
//
// Solidity: function updateAdmins(address[] _newAdmins) returns()
func (_Contract *ContractTransactorSession) UpdateAdmins(_newAdmins []common.Address) (*types.Transaction, error) {
	return _Contract.Contract.UpdateAdmins(&_Contract.TransactOpts, _newAdmins)
}

// ContractAbandonChangeIterator is returned from FilterAbandonChange and is used to iterate over the raw logs and unpacked data for AbandonChange events raised by the Contract contract.
type ContractAbandonChangeIterator struct {
	Event *ContractAbandonChange // Event containing the contract specifics and raw log

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
func (it *ContractAbandonChangeIterator) Next() bool {
	// If the iterator failed, stop iterating
	if it.fail != nil {
		return false
	}
	// If the iterator completed, deliver directly whatever's available
	if it.done {
		select {
		case log := <-it.logs:
			it.Event = new(ContractAbandonChange)
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
		it.Event = new(ContractAbandonChange)
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
func (it *ContractAbandonChangeIterator) Error() error {
	return it.fail
}

// Close terminates the iteration process, releasing any pending underlying
// resources.
func (it *ContractAbandonChangeIterator) Close() error {
	it.sub.Unsubscribe()
	return nil
}

// ContractAbandonChange represents a AbandonChange event raised by the Contract contract.
type ContractAbandonChange struct {
	Raw types.Log // Blockchain specific contextual infos
}

// FilterAbandonChange is a free log retrieval operation binding the contract event 0xbbc4d527949f6d7133c1e4cd55cb12cbf629444cb7efcecc5e2e5ad35e0539c7.
//
// Solidity: event AbandonChange()
func (_Contract *ContractFilterer) FilterAbandonChange(opts *bind.FilterOpts) (*ContractAbandonChangeIterator, error) {

	logs, sub, err := _Contract.contract.FilterLogs(opts, "AbandonChange")
	if err != nil {
		return nil, err
	}
	return &ContractAbandonChangeIterator{contract: _Contract.contract, event: "AbandonChange", logs: logs, sub: sub}, nil
}

// WatchAbandonChange is a free log subscription operation binding the contract event 0xbbc4d527949f6d7133c1e4cd55cb12cbf629444cb7efcecc5e2e5ad35e0539c7.
//
// Solidity: event AbandonChange()
func (_Contract *ContractFilterer) WatchAbandonChange(opts *bind.WatchOpts, sink chan<- *ContractAbandonChange) (event.Subscription, error) {

	logs, sub, err := _Contract.contract.WatchLogs(opts, "AbandonChange")
	if err != nil {
		return nil, err
	}
	return event.NewSubscription(func(quit <-chan struct{}) error {
		defer sub.Unsubscribe()
		for {
			select {
			case log := <-logs:
				// New log arrived, parse the event and forward to the user
				event := new(ContractAbandonChange)
				if err := _Contract.contract.UnpackLog(event, "AbandonChange", log); err != nil {
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

// ParseAbandonChange is a log parse operation binding the contract event 0xbbc4d527949f6d7133c1e4cd55cb12cbf629444cb7efcecc5e2e5ad35e0539c7.
//
// Solidity: event AbandonChange()
func (_Contract *ContractFilterer) ParseAbandonChange(log types.Log) (*ContractAbandonChange, error) {
	event := new(ContractAbandonChange)
	if err := _Contract.contract.UnpackLog(event, "AbandonChange", log); err != nil {
		return nil, err
	}
	return event, nil
}

// ContractFinalizedIterator is returned from FilterFinalized and is used to iterate over the raw logs and unpacked data for Finalized events raised by the Contract contract.
type ContractFinalizedIterator struct {
	Event *ContractFinalized // Event containing the contract specifics and raw log

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
func (it *ContractFinalizedIterator) Next() bool {
	// If the iterator failed, stop iterating
	if it.fail != nil {
		return false
	}
	// If the iterator completed, deliver directly whatever's available
	if it.done {
		select {
		case log := <-it.logs:
			it.Event = new(ContractFinalized)
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
		it.Event = new(ContractFinalized)
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
func (it *ContractFinalizedIterator) Error() error {
	return it.fail
}

// Close terminates the iteration process, releasing any pending underlying
// resources.
func (it *ContractFinalizedIterator) Close() error {
	it.sub.Unsubscribe()
	return nil
}

// ContractFinalized represents a Finalized event raised by the Contract contract.
type ContractFinalized struct {
	Raw types.Log // Blockchain specific contextual infos
}

// FilterFinalized is a free log retrieval operation binding the contract event 0x6823b073d48d6e3a7d385eeb601452d680e74bb46afe3255a7d778f3a9b17681.
//
// Solidity: event Finalized()
func (_Contract *ContractFilterer) FilterFinalized(opts *bind.FilterOpts) (*ContractFinalizedIterator, error) {

	logs, sub, err := _Contract.contract.FilterLogs(opts, "Finalized")
	if err != nil {
		return nil, err
	}
	return &ContractFinalizedIterator{contract: _Contract.contract, event: "Finalized", logs: logs, sub: sub}, nil
}

// WatchFinalized is a free log subscription operation binding the contract event 0x6823b073d48d6e3a7d385eeb601452d680e74bb46afe3255a7d778f3a9b17681.
//
// Solidity: event Finalized()
func (_Contract *ContractFilterer) WatchFinalized(opts *bind.WatchOpts, sink chan<- *ContractFinalized) (event.Subscription, error) {

	logs, sub, err := _Contract.contract.WatchLogs(opts, "Finalized")
	if err != nil {
		return nil, err
	}
	return event.NewSubscription(func(quit <-chan struct{}) error {
		defer sub.Unsubscribe()
		for {
			select {
			case log := <-logs:
				// New log arrived, parse the event and forward to the user
				event := new(ContractFinalized)
				if err := _Contract.contract.UnpackLog(event, "Finalized", log); err != nil {
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

// ParseFinalized is a log parse operation binding the contract event 0x6823b073d48d6e3a7d385eeb601452d680e74bb46afe3255a7d778f3a9b17681.
//
// Solidity: event Finalized()
func (_Contract *ContractFilterer) ParseFinalized(log types.Log) (*ContractFinalized, error) {
	event := new(ContractFinalized)
	if err := _Contract.contract.UnpackLog(event, "Finalized", log); err != nil {
		return nil, err
	}
	return event, nil
}

// ContractInitilizedIterator is returned from FilterInitilized and is used to iterate over the raw logs and unpacked data for Initilized events raised by the Contract contract.
type ContractInitilizedIterator struct {
	Event *ContractInitilized // Event containing the contract specifics and raw log

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
func (it *ContractInitilizedIterator) Next() bool {
	// If the iterator failed, stop iterating
	if it.fail != nil {
		return false
	}
	// If the iterator completed, deliver directly whatever's available
	if it.done {
		select {
		case log := <-it.logs:
			it.Event = new(ContractInitilized)
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
		it.Event = new(ContractInitilized)
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
func (it *ContractInitilizedIterator) Error() error {
	return it.fail
}

// Close terminates the iteration process, releasing any pending underlying
// resources.
func (it *ContractInitilizedIterator) Close() error {
	it.sub.Unsubscribe()
	return nil
}

// ContractInitilized represents a Initilized event raised by the Contract contract.
type ContractInitilized struct {
	Raw types.Log // Blockchain specific contextual infos
}

// FilterInitilized is a free log retrieval operation binding the contract event 0x136a97475f0483b5c3d2731a0a81ae36f650ca81e632e19a50fcafad3a8e6f14.
//
// Solidity: event Initilized()
func (_Contract *ContractFilterer) FilterInitilized(opts *bind.FilterOpts) (*ContractInitilizedIterator, error) {

	logs, sub, err := _Contract.contract.FilterLogs(opts, "Initilized")
	if err != nil {
		return nil, err
	}
	return &ContractInitilizedIterator{contract: _Contract.contract, event: "Initilized", logs: logs, sub: sub}, nil
}

// WatchInitilized is a free log subscription operation binding the contract event 0x136a97475f0483b5c3d2731a0a81ae36f650ca81e632e19a50fcafad3a8e6f14.
//
// Solidity: event Initilized()
func (_Contract *ContractFilterer) WatchInitilized(opts *bind.WatchOpts, sink chan<- *ContractInitilized) (event.Subscription, error) {

	logs, sub, err := _Contract.contract.WatchLogs(opts, "Initilized")
	if err != nil {
		return nil, err
	}
	return event.NewSubscription(func(quit <-chan struct{}) error {
		defer sub.Unsubscribe()
		for {
			select {
			case log := <-logs:
				// New log arrived, parse the event and forward to the user
				event := new(ContractInitilized)
				if err := _Contract.contract.UnpackLog(event, "Initilized", log); err != nil {
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

// ParseInitilized is a log parse operation binding the contract event 0x136a97475f0483b5c3d2731a0a81ae36f650ca81e632e19a50fcafad3a8e6f14.
//
// Solidity: event Initilized()
func (_Contract *ContractFilterer) ParseInitilized(log types.Log) (*ContractInitilized, error) {
	event := new(ContractInitilized)
	if err := _Contract.contract.UnpackLog(event, "Initilized", log); err != nil {
		return nil, err
	}
	return event, nil
}

// ContractPendingAdminsIterator is returned from FilterPendingAdmins and is used to iterate over the raw logs and unpacked data for PendingAdmins events raised by the Contract contract.
type ContractPendingAdminsIterator struct {
	Event *ContractPendingAdmins // Event containing the contract specifics and raw log

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
func (it *ContractPendingAdminsIterator) Next() bool {
	// If the iterator failed, stop iterating
	if it.fail != nil {
		return false
	}
	// If the iterator completed, deliver directly whatever's available
	if it.done {
		select {
		case log := <-it.logs:
			it.Event = new(ContractPendingAdmins)
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
		it.Event = new(ContractPendingAdmins)
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
func (it *ContractPendingAdminsIterator) Error() error {
	return it.fail
}

// Close terminates the iteration process, releasing any pending underlying
// resources.
func (it *ContractPendingAdminsIterator) Close() error {
	it.sub.Unsubscribe()
	return nil
}

// ContractPendingAdmins represents a PendingAdmins event raised by the Contract contract.
type ContractPendingAdmins struct {
	PendingsNew []common.Address
	Raw         types.Log // Blockchain specific contextual infos
}

// FilterPendingAdmins is a free log retrieval operation binding the contract event 0x55ab0f0ce1c6e8860e5a8155123057a22b761acbc93887ad90f5e70441680a55.
//
// Solidity: event PendingAdmins(address[] pendingsNew)
func (_Contract *ContractFilterer) FilterPendingAdmins(opts *bind.FilterOpts) (*ContractPendingAdminsIterator, error) {

	logs, sub, err := _Contract.contract.FilterLogs(opts, "PendingAdmins")
	if err != nil {
		return nil, err
	}
	return &ContractPendingAdminsIterator{contract: _Contract.contract, event: "PendingAdmins", logs: logs, sub: sub}, nil
}

// WatchPendingAdmins is a free log subscription operation binding the contract event 0x55ab0f0ce1c6e8860e5a8155123057a22b761acbc93887ad90f5e70441680a55.
//
// Solidity: event PendingAdmins(address[] pendingsNew)
func (_Contract *ContractFilterer) WatchPendingAdmins(opts *bind.WatchOpts, sink chan<- *ContractPendingAdmins) (event.Subscription, error) {

	logs, sub, err := _Contract.contract.WatchLogs(opts, "PendingAdmins")
	if err != nil {
		return nil, err
	}
	return event.NewSubscription(func(quit <-chan struct{}) error {
		defer sub.Unsubscribe()
		for {
			select {
			case log := <-logs:
				// New log arrived, parse the event and forward to the user
				event := new(ContractPendingAdmins)
				if err := _Contract.contract.UnpackLog(event, "PendingAdmins", log); err != nil {
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

// ParsePendingAdmins is a log parse operation binding the contract event 0x55ab0f0ce1c6e8860e5a8155123057a22b761acbc93887ad90f5e70441680a55.
//
// Solidity: event PendingAdmins(address[] pendingsNew)
func (_Contract *ContractFilterer) ParsePendingAdmins(log types.Log) (*ContractPendingAdmins, error) {
	event := new(ContractPendingAdmins)
	if err := _Contract.contract.UnpackLog(event, "PendingAdmins", log); err != nil {
		return nil, err
	}
	return event, nil
}
