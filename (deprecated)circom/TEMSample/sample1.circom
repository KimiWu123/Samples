
template add() {
    signal private input x;
    signal private input y;
    signal input z;
    signal output out;


    z <== x + y;
    out <== (z + x) * y;
}

component main = add();
