include "../circomlib/circuits/pedersen.circom"

template Example_Perserden() {
    signal private input msg;
    signal output out[2];

    component bits = Num2Bits(256);
    bits.in <== msg;

    component pedersenHasher = Pedersen(256);
    for (var i=0; i<256; i++) {
        pedersenHasher.in[i] <== bits.out[i];
    }
    out[0] <== pedersenHasher.out[0];
    out[1] <== pedersenHasher.out[1];
}

component main = Example_Perserden();