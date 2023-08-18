const Ecrecover = artifacts.require("Ecrecover");

module.exports = function(deployer) {
  deployer.deploy(Ecrecover);
};
