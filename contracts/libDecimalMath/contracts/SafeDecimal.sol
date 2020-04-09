pragma solidity ^0.6.0;
pragma experimental ABIEncoderV2;
import {SafeDecimalMath, SafeMath} from "./SafeDecimalMath.sol";


library SafeDecimal {
    using SafeDecimalMath for uint256;
    using SafeMath for uint256;

    struct decimal {
        uint256 d;
    }

    /// @dev tricky function to make decimalize looking better
    function Decimal(uint256 x) internal pure returns(decimal memory) {
        decimal memory t;
        t.d = x;
        return t;
    }

    /// @dev subtraction decimals
    function subD(decimal memory x, decimal memory y) internal pure returns (decimal memory) {
        return subUint(x.d, y.d);
    }

    function subUint(uint256 x, uint256 y) internal pure returns (decimal memory) {
        decimal memory t;
        t.d = x.subd(y);
        return t;
    }

    /// @dev multiple decimals
    function mulD(decimal memory x, decimal memory y) internal pure returns (decimal memory) {
        return mulUint(x.d, y.d);
    }

    /// @dev multiple a decimal by a scalar
    function mulScalar(decimal memory x, uint256 y) internal pure returns (decimal memory) {
        return mulUintScalar(x.d, y);
    }

    function mulUint(uint256 x, uint256 y) internal pure returns (decimal memory) {
        decimal memory t;
        t.d = x.muld(y);
        return t;
    }

    function mulUintScalar(uint256 x, uint256 y) internal pure returns (decimal memory) {
        decimal memory t;
        t.d = x.mul(y);
        return t;
    }
}