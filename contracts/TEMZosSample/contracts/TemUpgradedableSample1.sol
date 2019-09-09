pragma solidity ^0.5.0;


contract Counter  {
    uint256 public value;

    function increase() public {
        value++;
    }

    function increase2(uint256 amount) public {
        value += amount;
    }
}