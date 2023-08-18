pragma solidity ^0.6.0;
pragma experimental ABIEncoderV2;

import {SafeDecimal} from "./SafeDecimal.sol";

contract Sample {
    using SafeDecimal for SafeDecimal.decimal;

    SafeDecimal.decimal public x;

    constructor() public {
        x = SafeDecimal.Decimal(1000e18);
    }


    function subDec(SafeDecimal.decimal memory y) public {
        x = x.subD(y);
    }

    function mulDec(SafeDecimal.decimal memory y) public {
        x = x.mulD(y);
    }

    function mulDecScalar(uint256 y) public {
        x = x.mulScalar(y);
    }
}