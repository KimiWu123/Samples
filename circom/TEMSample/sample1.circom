
template add() {
    signal private input x;
    signal private input y;
    signal input z;
    signal output out;

    out <== (x * y) + z;
}

component main = add();