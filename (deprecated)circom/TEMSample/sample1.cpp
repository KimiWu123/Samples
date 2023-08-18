#include "circom.hpp"
#include "calcwit.hpp"
#define NSignals 5
#define NComponents 1
#define NOutputs 1
#define NInputs 3
#define NVars 5
#define NPublic 2
#define __P__ "21888242871839275222246405745257275088548364400416034343698204186575808495617"

/*
add
*/
void add_e70bc3190530e654(Circom_CalcWit *ctx, int __cIdx) {
    FrElement _sigValue[1];
    FrElement _sigValue_1[1];
    FrElement _tmp[1];
    FrElement _sigValue_2[1];
    FrElement _sigValue_3[1];
    FrElement _tmp_1[1];
    FrElement _sigValue_4[1];
    FrElement _tmp_2[1];
    int _x_sigIdx_;
    int _y_sigIdx_;
    int _z_sigIdx_;
    int _out_sigIdx_;
    _x_sigIdx_ = ctx->getSignalOffset(__cIdx, 0xaf63f54c86021707LL /* x */);
    _y_sigIdx_ = ctx->getSignalOffset(__cIdx, 0xaf63f44c86021554LL /* y */);
    _z_sigIdx_ = ctx->getSignalOffset(__cIdx, 0xaf63f74c86021a6dLL /* z */);
    _out_sigIdx_ = ctx->getSignalOffset(__cIdx, 0x19f79b1921bbcfffLL /* out */);
    /* signal private input x */
    /* signal private input y */
    /* signal input z */
    /* signal output out */
    /* z <== x + y */
    ctx->multiGetSignal(__cIdx, __cIdx, _x_sigIdx_, _sigValue, 1);
    ctx->multiGetSignal(__cIdx, __cIdx, _y_sigIdx_, _sigValue_1, 1);
    Fr_add(_tmp, _sigValue, _sigValue_1);
    ctx->setSignal(__cIdx, __cIdx, _z_sigIdx_, _tmp);
    /* out <== (z + x) * y */
    ctx->multiGetSignal(__cIdx, __cIdx, _z_sigIdx_, _sigValue_2, 1);
    ctx->multiGetSignal(__cIdx, __cIdx, _x_sigIdx_, _sigValue_3, 1);
    Fr_add(_tmp_1, _sigValue_2, _sigValue_3);
    ctx->multiGetSignal(__cIdx, __cIdx, _y_sigIdx_, _sigValue_4, 1);
    Fr_mul(_tmp_2, _tmp_1, _sigValue_4);
    ctx->setSignal(__cIdx, __cIdx, _out_sigIdx_, _tmp_2);
    ctx->finished(__cIdx);
}
// Function Table
Circom_ComponentFunction _functionTable[1] = {
     add_e70bc3190530e654
};
