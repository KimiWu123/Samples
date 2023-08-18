pragma solidity ^0.5.8;



contract MultiSig {

    // vote status
    enum VOTE_RESULT {NONE, PASS, ABANDONED}

    // events
    event PendingAdmins(address[] pendingsNew);
    event Finalized();
    event Initilized();
    event AbandonChange();

    // modifiers
    modifier whenFinalized {
        require(finalized, "Not finalized");
        _;
    }

    // variabels
    address[] public admins;
    address[] public pendingAdmins;
    VOTE_RESULT public result;
    bool public finalized;

    struct votes {
        address voter;
        bool opinion;
    }
    votes[] public votedUsers;


    constructor(address[] memory initAdmins)
    public {
        updatePendingAdmins(initAdmins);
        finalizeAdmins();
    }

    // To reject the ballot
    function reject()
    public {
        require(isAdmin(msg.sender), "Not ADMIN");
        require(!isVoted(msg.sender), "voted");

        votedUsers.push(votes(msg.sender, false));
        if (getResult(false)) {
            correctChange();
        }
    }

    // To approve the ballot
    function approve()
    public {
        require(isAdmin(msg.sender), "Not ADMIN");
        require(!isVoted(msg.sender), "voted");

        votedUsers.push(votes(msg.sender, true));
        if (getResult(true)) {
            finalizeAdmins();
        }
    }

    // To update new admins, needs to update whole admin list.
    function updateAdmins(address[] memory _newAdmins)
    public
    whenFinalized {
        require(isAdmin(msg.sender), "Not ADMIN");
        setInitial();
        updatePendingAdmins(_newAdmins);
    }

//*********************************/
//  private / internal methods     /
//*********************************/

    // The ballot is failed, recover the status
    function correctChange()
    private {
        result = VOTE_RESULT.ABANDONED;
        setFinalize();
        emit AbandonChange();
    }

    // The ballot is success, update admins
    function finalizeAdmins()
    private {
        admins = pendingAdmins;
        result = VOTE_RESULT.PASS;
        setFinalize();
    }

    // To update pending admin list
    function updatePendingAdmins(address[] memory _newAdmins)
    private {
        for (uint i = 0; i < _newAdmins.length; i++) {
            require(address(0x0) != _newAdmins[i], "empty addr");
            pendingAdmins.push(_newAdmins[i]);
        }
        emit PendingAdmins(pendingAdmins);
    }


    function setInitial() private {
        finalized = false;
        result = VOTE_RESULT.NONE;
        delete votedUsers;
        emit Initilized();
    }
    function setFinalize() private {
        finalized = true;
        delete pendingAdmins;
        emit Finalized();
    }

//*********************************/
//          view methods           /
//*********************************/

    function isAdmin(address _admin)
    public
    view
    returns(bool) {
        for (uint8 i = 0; i < admins.length; i++) {
            if(admins[i] == _admin) {
                return true;
            }
        }
        return false;
    }

    function isVoted(address voter)
    private
    view
    returns(bool) {
        for (uint8 i = 0; i < votedUsers.length; i++) {
            if(votedUsers[i].voter == voter) {
                return true;
            }
        }
        return false;
    }

    // ballot criteria:
    // 1. Votes should be over half voters.
    // 2. If only two voters, pass criteria should be two of two.
    function getResult(bool opinion)
    private
    view
    returns(bool) {
        uint8 threshold;
        uint8 vote;
        if (admins.length == 2)
            threshold = 1;
        else
            threshold = uint8(admins.length/2);

        for (uint i = 0; i<votedUsers.length; i++) {
            if (votedUsers[i].opinion == opinion)
                vote++;
        }

        return vote > threshold;
    }
}