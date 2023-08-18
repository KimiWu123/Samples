pragma solidity 0.5.8;


contract Ballot {

    event Proposed(uint id, Action action, address voter);
    event Voted(address voter, bool approve);
    event ProposalRejected(uint id);
    event VoterAdded(address newVoter);
    event VoterRemoved(address removedVoter);

    enum Action {NONE, ADD, REMOVE}

    struct Proposal {
        address[] approver;
        address[] rejector;
        bool finished;

        // data
        Action action;
        address voterAddr;
    }

    address[] public voters;
    mapping(uint => Proposal) public proposals;
    uint public proposalNum=0;

    modifier onlyVoters() {
        require(isVoter(msg.sender), "only voters");
        _;
    }

    constructor(address[] memory _voters) public {
        for (uint i=0; i<_voters.length; i++) {
            voters.push(_voters[i]);
        }
    }

    function changeVoter(address _voter) public onlyVoters {
        require(isFinished(), "Not finished yet.");
        if (!isVoter(_voter)){
            newProposal(Action.ADD, _voter);
        } else {
            newProposal(Action.REMOVE, _voter);
        }
    }

    function newProposal(Action _action, address _addr) internal {
        Proposal storage p = proposals[++proposalNum];
        p.action = _action;
        p.voterAddr = _addr;
        p.finished = false;

        emit Proposed(proposalNum, _action, _addr);
    }

    function vote(bool _approve) public onlyVoters  {
        require(!isVoted(msg.sender), "Already voted");

        emit Voted(msg.sender, _approve);

        Proposal storage p = proposals[proposalNum];
        if (_approve) {
            p.approver.push(msg.sender);
            if (isPass(p.approver.length)) {
                execute();
            }
        } else {
            p.rejector.push(msg.sender);
            if (isPass(p.rejector.length)) {
                p.finished = true;
                emit ProposalRejected(proposalNum);
            }
        }
    }

    function execute() internal {
        Proposal storage p = proposals[proposalNum];
        p.finished = true;
        if (p.action == Action.ADD) {
            voters.push(p.voterAddr);
            emit VoterAdded(p.voterAddr);
        }
        else if (p.action == Action.REMOVE) {
            for (uint i=0; i<voters.length; i++) {
                if (voters[i] == p.voterAddr) {
                    voters[i] = voters[voters.length-1];
                    delete voters[voters.length-1];
                    emit VoterRemoved(p.voterAddr);
                    break;
                }
            }
        }
    }


    function isPass(uint _numVotes) internal view returns(bool) {
        uint criteria = voters.length/2 + 1;
        if (_numVotes >= criteria){
            return true;
        }
        return false;
    }

    function isVoted(address _voter) internal view returns(bool) {
        Proposal storage p = proposals[proposalNum];
        for (uint i=0; i<p.approver.length; i++) {
            if (p.approver[i] == _voter) {
                return true;
            }
        }
        for (uint i=0; i<p.rejector.length; i++) {
            if (p.rejector[i] == _voter) {
                return true;
            }
        }
        return false;
    }

    function isVoter(address _voter) internal view returns(bool) {
        for(uint i=0; i<voters.length; i++) {
            if (voters[i] == _voter) {
                return true;
            }
        }
        return false;
    }

    function isFinished() public view returns(bool) {
        return proposals[proposalNum].finished;
    }
}