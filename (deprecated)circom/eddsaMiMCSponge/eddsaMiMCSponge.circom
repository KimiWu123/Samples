include "../circomlib/circuits/mimcsponge.circom";
include "../circomlib/circuits/eddsamimcsponge.circom";


template Example_EdDSAMiMCSponge() {
    signal private input msg;
    signal input Ax;
    signal input Ay;
    signal input R8x;
    signal input R8y;
    signal input S;

    component verifier = EdDSAMiMCSpongeVerifier();
    verifier.enabled <== 1;
    verifier.Ax <== Ax;
    verifier.Ay <== Ay;
    verifier.R8x <== R8x;
    verifier.R8y <== R8y;
    verifier.S <== S;
    verifier.M <== msg;
}

component main = Example_EdDSAMiMCSponge();