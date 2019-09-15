pragma solidity >=0.4.24 <0.6.0;

import "@openzeppelin/upgrades/contracts/Initializable.sol";

contract Counter is Initializable {
    uint256 public value;

    function initialize(uint256 initValue) initializer public {
        value = initValue;
    }


    function increase() public {
        value++;
    }

    function increase2(uint256 amount) public {
        value += amount;
    }
}