const Relay = artifacts.require("relay");
const Sample = artifacts.require("sample");

module.exports = function(deployer, network, accounts) {
  deployer.deploy(Sample);
  deployer.deploy(Relay);
};