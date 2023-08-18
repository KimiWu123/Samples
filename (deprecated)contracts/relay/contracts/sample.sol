pragma solidity ^0.5.8;

contract Sample {

    event Run(uint somevalue, uint timestamp);

    constructor() public {
    }

    function run(uint somevalue) public{
        emit Run(somevalue, now);
    }

}