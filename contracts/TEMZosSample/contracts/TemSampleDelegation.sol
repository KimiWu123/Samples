pragma solidity >=0.4.24 <0.6.0;

contract Calltest {
    address public second;
    address public first;

    function test() public returns (address a){
        second = address(this);
    }
}

contract SampleDelegation {
    address public first;
    address public second;
    address public testAddr;

    constructor(address _addr) public {
        testAddr = _addr;
    }

    function withdelegatecall() public {
        testAddr.delegatecall(abi.encodeWithSelector(bytes4(keccak256("test()"))));
    }
}