const Multisig = artifacts.require("MultiSig");

module.exports = function(deployer, network, accounts) {
  
  deployer.deploy(Multisig, [accounts[0], accounts[1], accounts[2]]);
};
