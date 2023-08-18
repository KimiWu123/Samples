var multisig = artifacts.require("MultiSig")
const truffleAssert = require('truffle-assertions');

contract('MultiSig', async function(accounts) {

    let instance;
    // before(async () => {
    //     console.log(accounts)
    // })
    beforeEach(async function() {
        instance = await multisig.new([accounts[0], accounts[1], accounts[2]]);
    });

    // afterEach(async function() {
    // });

    it("update admins - approve", async function() {
        let tx = await instance.updateAdmins([accounts[0], accounts[3], accounts[4]], {from:accounts[0]})
        
        assert.equal(tx.logs[0].event, "Initilized")
        assert.equal(tx.logs[1].event, "PendingAdmins")

        tx = await instance.approve({from:accounts[0]})
        tx = await instance.approve({from:accounts[1]})

        assert.equal(tx.logs[0].event, "Finalized")
    });

    it("update admins - reject", async function() {
        let tx = await instance.updateAdmins([accounts[0], accounts[3], accounts[4]], {from:accounts[0]})
        
        assert.equal(tx.logs[0].event, "Initilized")
        assert.equal(tx.logs[1].event, "PendingAdmins")

        tx = await instance.approve({from:accounts[0]})
        tx = await instance.reject({from:accounts[1]})
        tx = await instance.reject({from:accounts[2]})

        assert.equal(tx.logs[0].event, "Finalized")
        assert.equal(tx.logs[1].event, "AbandonChange")
    });

    it("FE - double voting", async function() {
        let tx = await instance.updateAdmins([accounts[0], accounts[3], accounts[4]], {from:accounts[0]})

        assert.equal(tx.logs[0].event, "Initilized")
        assert.equal(tx.logs[1].event, "PendingAdmins")

        tx = await instance.approve({from:accounts[0]})
        await truffleAssert.reverts(
            instance.approve({from:accounts[0]}),
            "voted", "vote once only"
        )
    })


    it("FE - update once at at time", async() => {
        let tx = await instance.updateAdmins([accounts[0], accounts[3], accounts[4]], {from:accounts[0]})

        assert.equal(tx.logs[0].event, "Initilized")
        assert.equal(tx.logs[1].event, "PendingAdmins")

        await truffleAssert.reverts(
            instance.updateAdmins([accounts[0], accounts[3], accounts[4]], {from:accounts[0]}),
            "Not finalized", "update once at a time only"
        )
    });


    it("FE - update admins", async function() {
        await truffleAssert.reverts(
            instance.updateAdmins([accounts[0], accounts[3], accounts[4]], {from:accounts[3]}),
            "Not ADMIN", "only admins"
        );
    });

});
