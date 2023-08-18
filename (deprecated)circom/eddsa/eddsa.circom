include "../circomlib/circuits/eddsa.circom"
include "../circomlib/circuits/bitify.circom"
include "../circomlib/circuits/pointbits.circom"

template Example_EdDSA (n) {

    signal private input msg;
    signal input Ax;
    signal input Ay;
    signal input R8x;
    signal input R8y;
    signal input S;

    var i;

    component msgBits = Num2Bits(n);
    msgBits.in <== msg;

    component ABits = Point2Bits_Strict()
    ABits.in[0] <== Ax;
    ABits.in[1] <== Ay;

    component R8Bits = Point2Bits_Strict()
    R8Bits.in[0] <== R8x;
    R8Bits.in[1] <== R8y;
    
    component SBits = Num2Bits(256)
    SBits.in <== S;

    component eddsaV = EdDSAVerifier(n)
    for(i=0; i<n; i++) {
        eddsaV.msg[i] <== msgBits.out[i];
    }
    for(i=0; i<256; i++) {
        eddsaV.A[i] <== ABits.out[i]; // public key
    }
    for(i=0; i<256; i++) {
        eddsaV.R8[i] <== R8Bits.out[i]; // R part of signature
    }
    for(i=0; i<256; i++) {
        eddsaV.S[i] <== SBits.out[i]; // S part of signature
    }
}

component main = Example_EdDSA(256)
