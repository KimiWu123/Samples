pragma solidity ^0.5.8;

contract Relay {

    uint  public constant gas = 5**9;

    event Forwarded (bytes sig, address signer, address destination, uint value, bytes data);

    constructor() public {
    }
      // original forward function copied from https://github.com/uport-project/uport-identity/blob/develop/contracts/Proxy.sol
    function forward(bytes memory _sig, bytes memory _data, address _claimSigner, address _destination, uint _value)
    public {
        address signer = getSigner(keccak256(_data), _sig);
        require(signer == _claimSigner, "sender is not signer");

        //execute the transaction with all the given parameters
        require(executeCall(_destination, _value, _data), "execute Call failed.");
        emit Forwarded(_sig, signer, _destination, _value, _data);
    }


    // source from GnosisSafe
    // https://github.com/gnosis/gnosis-safe-contracts/blob/master/contracts/GnosisSafe.sol
    function executeCall(address to, uint256 value, bytes memory data) internal returns (bool success) {
        assembly {
            success := call(gas, to, value, add(data, 0x20), mload(data), 0, 0)
        }
    }


    function getSigner(bytes32 _hash, bytes memory _signature)
    internal pure
    returns (address) {
        bytes32 r;
        bytes32 s;
        uint8 v;
        // Check the signature length
        if (_signature.length != 65) {
            return address(0x0);
        }
        // Divide the signature in r, s and v variables
        // ecrecover takes the signature parameters, and the only way to get them
        // currently is to use assembly.
        // solium-disable-next-line security/no-inline-assembly
        assembly {
            r := mload(add(_signature, 32))
            s := mload(add(_signature, 64))
            v := byte(0, mload(add(_signature, 96)))
        }
        // Version of signature should be 27 or 28, but 0 and 1 are also possible versions
        if (v < 27) {
            v += 27;
        }
        // If the version is correct return the signer address
        if (v != 27 && v != 28) {
            return address(0x0);
        } else {
            // solium-disable-next-line arg-overflow
            return ecrecover(keccak256(
                abi.encodePacked("\x19Ethereum Signed Message:\n32", _hash)), v, r, s);
        }
    }

}