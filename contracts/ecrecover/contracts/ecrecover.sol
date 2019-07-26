pragma solidity 0.5.8;

contract Ecrecover {

  event Signer(address signer);

  constructor() public {
  }

  function verify_eip191(bytes32 _message, uint8 _v, bytes32 _r, bytes32 _s) public returns (address) {
    bytes memory prefix = "\x19Ethereum Signed Message:\n32";
    bytes32 prefixedHash = keccak256(abi.encodePacked(prefix, _message));
    address signer = ecrecover(prefixedHash, _v, _r, _s);
    emit Signer(signer);
    return signer;
  }

  function verify(bytes32 _message, uint8 _v, bytes32 _r, bytes32 _s) public returns (address) {
    address signer = ecrecover(_message, _v, _r, _s);
    emit Signer(signer);
    return signer;
  }

}
