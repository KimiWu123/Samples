var ballot = artifacts.require("Ballot")
const truffleAssert = require('truffle-assertions');

contract('Ballot', async function(accounts) {

    let instance;
    // before(async () => {
    //     console.log(accounts)
    // })
    beforeEach(async function() {
        instance = await ballot.new([accounts[0], accounts[1], accounts[2]]);
    });

    // afterEach(async function() {
    // });

    it("change voters - approve", async function() {
        let tx = await instance.updateAdmins([accounts[0], accounts[3], accounts[4]], {from:accounts[0]})
        
        assert.equal(tx.logs[0].event, "Initilized")
        assert.equal(tx.logs[1].event, "PendingAdmins")

        tx = await instance.approve({from:accounts[0]})
        tx = await instance.approve({from:accounts[1]})

        assert.equal(tx.logs[0].event, "Finalized")
    });
})