const Ballot = artifacts.require("Ballot");

module.exports = function(deployer, network, accounts) {
  
  deployer.deploy(Ballot, accounts[0], accounts[1], accounts[2]);
};
