include "../circomlib/circuits/sha256/sha256.circom"
include "../circomlib/circuits/bitify.circom"

template Example_Sha256() {
    signal private input in;
    signal output out;

    var numBits = 80;
    component inBits = Num2Bits(numBits);
    inBits.in <== in;

    component sha256 = Sha256(numBits);
    for (var i=0; i<numBits; i++) {
        sha256.in[i] <== inBits.out[i];
    }

    component outNum = Bits2Num(256);
    for (var i=0; i<256; i++) {
        outNum.in[i] <-- sha256.out[i];
    }
    out <== outNum.out;
}

component main = Example_Sha256();