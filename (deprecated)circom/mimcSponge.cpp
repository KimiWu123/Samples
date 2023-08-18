#include "circom.hpp"
#include "calcwit.hpp"
#define NSignals 1774
#define NComponents 4
#define NOutputs 1
#define NInputs 2
#define NVars 1323
#define NPublic 1
#define __P__ "21888242871839275222246405745257275088548364400416034343698204186575808495617"

/*
example_MiMC
*/
void example_MiMC_17b177f17a0555e8(Circom_CalcWit *ctx, int __cIdx) {
    FrElement _sigValue[1];
    FrElement _tmp_3[1];
    FrElement i[1];
    FrElement _sigValue_1[1];
    FrElement _tmp_5[1];
    FrElement _tmp_4[1];
    FrElement _tmp_6[1];
    FrElement _sigValue_2[1];
    FrElement _tmp_10[1];
    FrElement i_1[1];
    FrElement _sigValue_3[1];
    FrElement _tmp_12[1];
    FrElement _tmp_11[1];
    FrElement _tmp_13[1];
    int _compIdx;
    int _ins_sigIdx_;
    int _offset_9;
    int _ins_sigIdx__1;
    int _offset_11;
    int _compIdx_1;
    int _ins_sigIdx__2;
    int _offset_17;
    int _offset_19;
    int _compIdx_2;
    int _k_sigIdx_;
    int _compIdx_3;
    int _outs_sigIdx_;
    int _offset_28;
    int _outs_sigIdx__1;
    int _offset_30;
    int _compIdx_4;
    int _outs_sigIdx__2;
    int _offset_36;
    int _offset_38;
    Circom_Sizes _sigSizes_ins;
    Circom_Sizes _sigSizes_ins_1;
    Circom_Sizes _sigSizes_ins_2;
    Circom_Sizes _sigSizes_outs;
    Circom_Sizes _sigSizes_outs_1;
    Circom_Sizes _sigSizes_outs_2;
    PFrElement _loopCond;
    PFrElement _loopCond_1;
    Fr_copy(&(_tmp_3[0]), ctx->circuit->constants +1);
    Fr_copy(&(i[0]), ctx->circuit->constants +1);
    Fr_copy(&(_tmp_10[0]), ctx->circuit->constants +0);
    Fr_copy(&(i_1[0]), ctx->circuit->constants +1);
    _ins_sigIdx__1 = ctx->getSignalOffset(__cIdx, 0x2ba002192bd4cd57LL /* ins */);
    _outs_sigIdx__1 = ctx->getSignalOffset(__cIdx, 0xdb8c17b45221aae4LL /* outs */);
    _sigSizes_ins_1 = ctx->getSignalSizes(__cIdx, 0x2ba002192bd4cd57LL /* ins */);
    _sigSizes_outs_1 = ctx->getSignalSizes(__cIdx, 0xdb8c17b45221aae4LL /* outs */);
    /* var numInput = 2 */
    /* var rounds = 220 */
    /* var numOutput = 1 */
    /* signal private input ins[numInput] */
    /* signal output outs[numOutput] */
    /* component mimc = MiMCSponge(numInput, rounds, numOutput) */
    /* for (var i=0;i<numInput;i++) */
    /* mimc.ins[i] <== ins[i] */
    _compIdx = ctx->getSubComponentOffset(__cIdx, 0xda51ffa2a792a20bLL /* mimc */);
    _ins_sigIdx_ = ctx->getSignalOffset(_compIdx, 0x2ba002192bd4cd57LL /* ins */);
    _sigSizes_ins = ctx->getSignalSizes(_compIdx, 0x2ba002192bd4cd57LL /* ins */);
    _offset_9 = _ins_sigIdx_;
    _offset_11 = _ins_sigIdx__1;
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_11, _sigValue, 1);
    ctx->setSignal(__cIdx, _compIdx, _offset_9, _sigValue);
    _loopCond = _tmp_3;
    while (Fr_isTrue(_loopCond)) {
        /* mimc.ins[i] <== ins[i] */
        _compIdx_1 = ctx->getSubComponentOffset(__cIdx, 0xda51ffa2a792a20bLL /* mimc */);
        _ins_sigIdx__2 = ctx->getSignalOffset(_compIdx_1, 0x2ba002192bd4cd57LL /* ins */);
        _sigSizes_ins_2 = ctx->getSignalSizes(_compIdx_1, 0x2ba002192bd4cd57LL /* ins */);
        _offset_17 = _ins_sigIdx__2 + Fr_toInt(i)*_sigSizes_ins_2[1];
        _offset_19 = _ins_sigIdx__1 + Fr_toInt(i)*_sigSizes_ins_1[1];
        ctx->multiGetSignal(__cIdx, __cIdx, _offset_19, _sigValue_1, 1);
        ctx->setSignal(__cIdx, _compIdx_1, _offset_17, _sigValue_1);
        Fr_copyn(_tmp_5, i, 1);
        Fr_add(_tmp_4, i, (ctx->circuit->constants + 1));
        Fr_copyn(i, _tmp_4, 1);
        Fr_lt(_tmp_6, i, (ctx->circuit->constants + 2));
        _loopCond = _tmp_6;
    }
    /* mimc.k <== 0 */
    _compIdx_2 = ctx->getSubComponentOffset(__cIdx, 0xda51ffa2a792a20bLL /* mimc */);
    _k_sigIdx_ = ctx->getSignalOffset(_compIdx_2, 0xaf63e64c8601fd8aLL /* k */);
    ctx->setSignal(__cIdx, _compIdx_2, _k_sigIdx_, (ctx->circuit->constants + 0));
    /* for (var i=0;i<numOutput;i++) */
    /* outs[i] <==  mimc.outs[i] */
    _compIdx_3 = ctx->getSubComponentOffset(__cIdx, 0xda51ffa2a792a20bLL /* mimc */);
    _outs_sigIdx_ = ctx->getSignalOffset(_compIdx_3, 0xdb8c17b45221aae4LL /* outs */);
    _sigSizes_outs = ctx->getSignalSizes(_compIdx_3, 0xdb8c17b45221aae4LL /* outs */);
    _offset_28 = _outs_sigIdx_;
    ctx->multiGetSignal(__cIdx, _compIdx_3, _offset_28, _sigValue_2, 1);
    _offset_30 = _outs_sigIdx__1;
    ctx->setSignal(__cIdx, __cIdx, _offset_30, _sigValue_2);
    _loopCond_1 = _tmp_10;
    while (Fr_isTrue(_loopCond_1)) {
        /* outs[i] <==  mimc.outs[i] */
        _compIdx_4 = ctx->getSubComponentOffset(__cIdx, 0xda51ffa2a792a20bLL /* mimc */);
        _outs_sigIdx__2 = ctx->getSignalOffset(_compIdx_4, 0xdb8c17b45221aae4LL /* outs */);
        _sigSizes_outs_2 = ctx->getSignalSizes(_compIdx_4, 0xdb8c17b45221aae4LL /* outs */);
        _offset_36 = _outs_sigIdx__2 + Fr_toInt(i_1)*_sigSizes_outs_2[1];
        ctx->multiGetSignal(__cIdx, _compIdx_4, _offset_36, _sigValue_3, 1);
        _offset_38 = _outs_sigIdx__1 + Fr_toInt(i_1)*_sigSizes_outs_1[1];
        ctx->setSignal(__cIdx, __cIdx, _offset_38, _sigValue_3);
        Fr_copyn(_tmp_12, i_1, 1);
        Fr_add(_tmp_11, i_1, (ctx->circuit->constants + 1));
        Fr_copyn(i_1, _tmp_11, 1);
        Fr_lt(_tmp_13, i_1, (ctx->circuit->constants + 1));
        _loopCond_1 = _tmp_13;
    }
    ctx->finished(__cIdx);
}
/*
MiMCSponge
k=0
nInputs=2
nOutputs=1
nRounds=220
*/
void MiMCSponge_9ec0aed9ecb0041f(Circom_CalcWit *ctx, int __cIdx) {
    FrElement _sigValue[1];
    FrElement _sigValue_1[1];
    FrElement _tmp_4[1];
    FrElement i[1];
    FrElement _sigValue_2[1];
    FrElement _tmp_5[1];
    FrElement _sigValue_3[1];
    FrElement _tmp_6[1];
    FrElement _sigValue_4[1];
    FrElement _sigValue_5[1];
    FrElement _tmp_7[1];
    FrElement _tmp_8[1];
    FrElement _sigValue_6[1];
    FrElement _tmp_10[1];
    FrElement _tmp_9[1];
    FrElement _tmp_11[1];
    FrElement _sigValue_7[1];
    FrElement _num_11[1];
    FrElement _tmp_14[1];
    FrElement _tmp_15[1];
    FrElement _sigValue_8[1];
    FrElement _tmp_16[1];
    FrElement _tmp_17[1];
    FrElement _tmp_18[1];
    FrElement _sigValue_9[1];
    FrElement _tmp_19[1];
    FrElement _tmp_20[1];
    FrElement _tmp_21[1];
    FrElement _sigValue_10[1];
    FrElement _tmp_22[1];
    FrElement _sigValue_11[1];
    FrElement _tmp_23[1];
    FrElement _tmp_25[1];
    FrElement _tmp_24[1];
    FrElement _tmp_27[1];
    int _compIdx;
    int _offset_6;
    int _k_sigIdx_;
    int _k_sigIdx__1;
    int _compIdx_1;
    int _offset_9;
    int _xL_in_sigIdx_;
    int _ins_sigIdx_;
    int _offset_10;
    int _compIdx_2;
    int _offset_12;
    int _xR_in_sigIdx_;
    int _compIdx_3;
    int _offset_18;
    int _k_sigIdx__2;
    int _compIdx_4;
    int _offset_21;
    int _xL_in_sigIdx__1;
    int _offset_22;
    int _compIdx_5;
    int _offset_24;
    int _xR_in_sigIdx__1;
    int _compIdx_6;
    int _offset_26;
    int _xL_in_sigIdx__2;
    int _compIdx_7;
    int _offset_28;
    int _xL_out_sigIdx_;
    int _offset_30;
    int _compIdx_8;
    int _offset_32;
    int _xR_in_sigIdx__2;
    int _compIdx_9;
    int _offset_34;
    int _xR_out_sigIdx_;
    int _compIdx_10;
    int _offset_40;
    int _xL_out_sigIdx__1;
    int _outs_sigIdx_;
    int _offset_41;
    int _compIdx_11;
    int _offset_47;
    int _k_sigIdx__3;
    int _compIdx_12;
    int _offset_50;
    int _xL_in_sigIdx__3;
    int _compIdx_13;
    int _offset_53;
    int _xL_out_sigIdx__2;
    int _compIdx_14;
    int _offset_56;
    int _xR_in_sigIdx__3;
    int _compIdx_15;
    int _offset_59;
    int _xR_out_sigIdx__1;
    int _compIdx_16;
    int _offset_62;
    int _xL_out_sigIdx__3;
    int _offset_64;
    Circom_Sizes _compSizes;
    Circom_Sizes _compSizes_1;
    Circom_Sizes _sigSizes_ins;
    Circom_Sizes _compSizes_2;
    Circom_Sizes _compSizes_3;
    Circom_Sizes _compSizes_4;
    Circom_Sizes _compSizes_5;
    Circom_Sizes _compSizes_6;
    Circom_Sizes _compSizes_7;
    Circom_Sizes _compSizes_8;
    Circom_Sizes _compSizes_9;
    Circom_Sizes _compSizes_10;
    Circom_Sizes _sigSizes_outs;
    Circom_Sizes _compSizes_11;
    Circom_Sizes _compSizes_12;
    Circom_Sizes _compSizes_13;
    Circom_Sizes _compSizes_14;
    Circom_Sizes _compSizes_15;
    Circom_Sizes _compSizes_16;
    PFrElement _loopCond;
    PFrElement _loopCond_1;
    Fr_copy(&(_tmp_4[0]), ctx->circuit->constants +1);
    Fr_copy(&(i[0]), ctx->circuit->constants +1);
    Fr_copy(&(_num_11[0]), ctx->circuit->constants +0);
    _k_sigIdx__1 = ctx->getSignalOffset(__cIdx, 0xaf63e64c8601fd8aLL /* k */);
    _ins_sigIdx_ = ctx->getSignalOffset(__cIdx, 0x2ba002192bd4cd57LL /* ins */);
    _outs_sigIdx_ = ctx->getSignalOffset(__cIdx, 0xdb8c17b45221aae4LL /* outs */);
    _sigSizes_ins = ctx->getSignalSizes(__cIdx, 0x2ba002192bd4cd57LL /* ins */);
    _sigSizes_outs = ctx->getSignalSizes(__cIdx, 0xdb8c17b45221aae4LL /* outs */);
    /* signal input ins[nInputs] */
    /* signal input k */
    /* signal output outs[nOutputs] */
    /* var i */
    /* component S[nInputs + nOutputs - 1] */
    /* for (i = 0;i < nInputs;i++) */
    /* S[i] = MiMCFeistel(nRounds) */
    /* S[i].k <== k */
    _compIdx = ctx->getSubComponentOffset(__cIdx, 0xaf640e4c86024182LL /* S */);
    _compSizes = ctx->getSubComponentSizes(__cIdx, 0xaf640e4c86024182LL /* S */);
    _offset_6 = _compIdx;
    _k_sigIdx_ = ctx->getSignalOffset(_offset_6, 0xaf63e64c8601fd8aLL /* k */);
    ctx->multiGetSignal(__cIdx, __cIdx, _k_sigIdx__1, _sigValue, 1);
    ctx->setSignal(__cIdx, _offset_6, _k_sigIdx_, _sigValue);
    /* if (i == 0) */
    /* S[i].xL_in <== ins[0] */
    _compIdx_1 = ctx->getSubComponentOffset(__cIdx, 0xaf640e4c86024182LL /* S */);
    _compSizes_1 = ctx->getSubComponentSizes(__cIdx, 0xaf640e4c86024182LL /* S */);
    _offset_9 = _compIdx_1;
    _xL_in_sigIdx_ = ctx->getSignalOffset(_offset_9, 0xe58d565a2c6193f5LL /* xL_in */);
    _offset_10 = _ins_sigIdx_;
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_10, _sigValue_1, 1);
    ctx->setSignal(__cIdx, _offset_9, _xL_in_sigIdx_, _sigValue_1);
    /* S[i].xR_in <== 0 */
    _compIdx_2 = ctx->getSubComponentOffset(__cIdx, 0xaf640e4c86024182LL /* S */);
    _compSizes_2 = ctx->getSubComponentSizes(__cIdx, 0xaf640e4c86024182LL /* S */);
    _offset_12 = _compIdx_2;
    _xR_in_sigIdx_ = ctx->getSignalOffset(_offset_12, 0x490e56ad9f02bbcfLL /* xR_in */);
    ctx->setSignal(__cIdx, _offset_12, _xR_in_sigIdx_, (ctx->circuit->constants + 0));
    _loopCond = _tmp_4;
    while (Fr_isTrue(_loopCond)) {
        /* S[i] = MiMCFeistel(nRounds) */
        /* S[i].k <== k */
        _compIdx_3 = ctx->getSubComponentOffset(__cIdx, 0xaf640e4c86024182LL /* S */);
        _compSizes_3 = ctx->getSubComponentSizes(__cIdx, 0xaf640e4c86024182LL /* S */);
        _offset_18 = _compIdx_3 + Fr_toInt(i)*_compSizes_3[1];
        _k_sigIdx__2 = ctx->getSignalOffset(_offset_18, 0xaf63e64c8601fd8aLL /* k */);
        ctx->multiGetSignal(__cIdx, __cIdx, _k_sigIdx__1, _sigValue_2, 1);
        ctx->setSignal(__cIdx, _offset_18, _k_sigIdx__2, _sigValue_2);
        /* if (i == 0) */
        Fr_eq(_tmp_5, i, (ctx->circuit->constants + 0));
        if (Fr_isTrue(_tmp_5)) {
            /* S[i].xL_in <== ins[0] */
            _compIdx_4 = ctx->getSubComponentOffset(__cIdx, 0xaf640e4c86024182LL /* S */);
            _compSizes_4 = ctx->getSubComponentSizes(__cIdx, 0xaf640e4c86024182LL /* S */);
            _offset_21 = _compIdx_4 + Fr_toInt(i)*_compSizes_4[1];
            _xL_in_sigIdx__1 = ctx->getSignalOffset(_offset_21, 0xe58d565a2c6193f5LL /* xL_in */);
            _offset_22 = _ins_sigIdx_;
            ctx->multiGetSignal(__cIdx, __cIdx, _offset_22, _sigValue_3, 1);
            ctx->setSignal(__cIdx, _offset_21, _xL_in_sigIdx__1, _sigValue_3);
            /* S[i].xR_in <== 0 */
            _compIdx_5 = ctx->getSubComponentOffset(__cIdx, 0xaf640e4c86024182LL /* S */);
            _compSizes_5 = ctx->getSubComponentSizes(__cIdx, 0xaf640e4c86024182LL /* S */);
            _offset_24 = _compIdx_5 + Fr_toInt(i)*_compSizes_5[1];
            _xR_in_sigIdx__1 = ctx->getSignalOffset(_offset_24, 0x490e56ad9f02bbcfLL /* xR_in */);
            ctx->setSignal(__cIdx, _offset_24, _xR_in_sigIdx__1, (ctx->circuit->constants + 0));
        } else {
            /* S[i].xL_in <== S[i-1].xL_out + ins[i] */
            _compIdx_6 = ctx->getSubComponentOffset(__cIdx, 0xaf640e4c86024182LL /* S */);
            _compSizes_6 = ctx->getSubComponentSizes(__cIdx, 0xaf640e4c86024182LL /* S */);
            _offset_26 = _compIdx_6 + Fr_toInt(i)*_compSizes_6[1];
            _xL_in_sigIdx__2 = ctx->getSignalOffset(_offset_26, 0xe58d565a2c6193f5LL /* xL_in */);
            _compIdx_7 = ctx->getSubComponentOffset(__cIdx, 0xaf640e4c86024182LL /* S */);
            _compSizes_7 = ctx->getSubComponentSizes(__cIdx, 0xaf640e4c86024182LL /* S */);
            Fr_sub(_tmp_6, i, (ctx->circuit->constants + 1));
            _offset_28 = _compIdx_7 + Fr_toInt(_tmp_6)*_compSizes_7[1];
            _xL_out_sigIdx_ = ctx->getSignalOffset(_offset_28, 0x82a9a0397420693eLL /* xL_out */);
            ctx->multiGetSignal(__cIdx, _offset_28, _xL_out_sigIdx_, _sigValue_4, 1);
            _offset_30 = _ins_sigIdx_ + Fr_toInt(i)*_sigSizes_ins[1];
            ctx->multiGetSignal(__cIdx, __cIdx, _offset_30, _sigValue_5, 1);
            Fr_add(_tmp_7, _sigValue_4, _sigValue_5);
            ctx->setSignal(__cIdx, _offset_26, _xL_in_sigIdx__2, _tmp_7);
            /* S[i].xR_in <== S[i-1].xR_out */
            _compIdx_8 = ctx->getSubComponentOffset(__cIdx, 0xaf640e4c86024182LL /* S */);
            _compSizes_8 = ctx->getSubComponentSizes(__cIdx, 0xaf640e4c86024182LL /* S */);
            _offset_32 = _compIdx_8 + Fr_toInt(i)*_compSizes_8[1];
            _xR_in_sigIdx__2 = ctx->getSignalOffset(_offset_32, 0x490e56ad9f02bbcfLL /* xR_in */);
            _compIdx_9 = ctx->getSubComponentOffset(__cIdx, 0xaf640e4c86024182LL /* S */);
            _compSizes_9 = ctx->getSubComponentSizes(__cIdx, 0xaf640e4c86024182LL /* S */);
            Fr_sub(_tmp_8, i, (ctx->circuit->constants + 1));
            _offset_34 = _compIdx_9 + Fr_toInt(_tmp_8)*_compSizes_9[1];
            _xR_out_sigIdx_ = ctx->getSignalOffset(_offset_34, 0x5898f4054dd4f254LL /* xR_out */);
            ctx->multiGetSignal(__cIdx, _offset_34, _xR_out_sigIdx_, _sigValue_6, 1);
            ctx->setSignal(__cIdx, _offset_32, _xR_in_sigIdx__2, _sigValue_6);
        }
        Fr_copyn(_tmp_10, i, 1);
        Fr_add(_tmp_9, i, (ctx->circuit->constants + 1));
        Fr_copyn(i, _tmp_9, 1);
        Fr_lt(_tmp_11, i, (ctx->circuit->constants + 2));
        _loopCond = _tmp_11;
    }
    /* outs[0] <== S[nInputs - 1].xL_out */
    _compIdx_10 = ctx->getSubComponentOffset(__cIdx, 0xaf640e4c86024182LL /* S */);
    _compSizes_10 = ctx->getSubComponentSizes(__cIdx, 0xaf640e4c86024182LL /* S */);
    _offset_40 = _compIdx_10 + 1*_compSizes_10[1];
    _xL_out_sigIdx__1 = ctx->getSignalOffset(_offset_40, 0x82a9a0397420693eLL /* xL_out */);
    ctx->multiGetSignal(__cIdx, _offset_40, _xL_out_sigIdx__1, _sigValue_7, 1);
    _offset_41 = _outs_sigIdx_;
    ctx->setSignal(__cIdx, __cIdx, _offset_41, _sigValue_7);
    /* for (i = 0;i < nOutputs - 1;i++) */
    Fr_copyn(i, _num_11, 1);
    Fr_lt(_tmp_14, i, (ctx->circuit->constants + 0));
    _loopCond_1 = _tmp_14;
    while (Fr_isTrue(_loopCond_1)) {
        /* S[nInputs + i] = MiMCFeistel(nRounds) */
        /* S[nInputs + i].k <== k */
        _compIdx_11 = ctx->getSubComponentOffset(__cIdx, 0xaf640e4c86024182LL /* S */);
        _compSizes_11 = ctx->getSubComponentSizes(__cIdx, 0xaf640e4c86024182LL /* S */);
        Fr_add(_tmp_15, (ctx->circuit->constants + 2), i);
        _offset_47 = _compIdx_11 + Fr_toInt(_tmp_15)*_compSizes_11[1];
        _k_sigIdx__3 = ctx->getSignalOffset(_offset_47, 0xaf63e64c8601fd8aLL /* k */);
        ctx->multiGetSignal(__cIdx, __cIdx, _k_sigIdx__1, _sigValue_8, 1);
        ctx->setSignal(__cIdx, _offset_47, _k_sigIdx__3, _sigValue_8);
        /* S[nInputs + i].xL_in <== S[nInputs + i - 1].xL_out */
        _compIdx_12 = ctx->getSubComponentOffset(__cIdx, 0xaf640e4c86024182LL /* S */);
        _compSizes_12 = ctx->getSubComponentSizes(__cIdx, 0xaf640e4c86024182LL /* S */);
        Fr_add(_tmp_16, (ctx->circuit->constants + 2), i);
        _offset_50 = _compIdx_12 + Fr_toInt(_tmp_16)*_compSizes_12[1];
        _xL_in_sigIdx__3 = ctx->getSignalOffset(_offset_50, 0xe58d565a2c6193f5LL /* xL_in */);
        _compIdx_13 = ctx->getSubComponentOffset(__cIdx, 0xaf640e4c86024182LL /* S */);
        _compSizes_13 = ctx->getSubComponentSizes(__cIdx, 0xaf640e4c86024182LL /* S */);
        Fr_add(_tmp_17, (ctx->circuit->constants + 2), i);
        Fr_sub(_tmp_18, _tmp_17, (ctx->circuit->constants + 1));
        _offset_53 = _compIdx_13 + Fr_toInt(_tmp_18)*_compSizes_13[1];
        _xL_out_sigIdx__2 = ctx->getSignalOffset(_offset_53, 0x82a9a0397420693eLL /* xL_out */);
        ctx->multiGetSignal(__cIdx, _offset_53, _xL_out_sigIdx__2, _sigValue_9, 1);
        ctx->setSignal(__cIdx, _offset_50, _xL_in_sigIdx__3, _sigValue_9);
        /* S[nInputs + i].xR_in <== S[nInputs + i - 1].xR_out */
        _compIdx_14 = ctx->getSubComponentOffset(__cIdx, 0xaf640e4c86024182LL /* S */);
        _compSizes_14 = ctx->getSubComponentSizes(__cIdx, 0xaf640e4c86024182LL /* S */);
        Fr_add(_tmp_19, (ctx->circuit->constants + 2), i);
        _offset_56 = _compIdx_14 + Fr_toInt(_tmp_19)*_compSizes_14[1];
        _xR_in_sigIdx__3 = ctx->getSignalOffset(_offset_56, 0x490e56ad9f02bbcfLL /* xR_in */);
        _compIdx_15 = ctx->getSubComponentOffset(__cIdx, 0xaf640e4c86024182LL /* S */);
        _compSizes_15 = ctx->getSubComponentSizes(__cIdx, 0xaf640e4c86024182LL /* S */);
        Fr_add(_tmp_20, (ctx->circuit->constants + 2), i);
        Fr_sub(_tmp_21, _tmp_20, (ctx->circuit->constants + 1));
        _offset_59 = _compIdx_15 + Fr_toInt(_tmp_21)*_compSizes_15[1];
        _xR_out_sigIdx__1 = ctx->getSignalOffset(_offset_59, 0x5898f4054dd4f254LL /* xR_out */);
        ctx->multiGetSignal(__cIdx, _offset_59, _xR_out_sigIdx__1, _sigValue_10, 1);
        ctx->setSignal(__cIdx, _offset_56, _xR_in_sigIdx__3, _sigValue_10);
        /* outs[i + 1] <== S[nInputs + i].xL_out */
        _compIdx_16 = ctx->getSubComponentOffset(__cIdx, 0xaf640e4c86024182LL /* S */);
        _compSizes_16 = ctx->getSubComponentSizes(__cIdx, 0xaf640e4c86024182LL /* S */);
        Fr_add(_tmp_22, (ctx->circuit->constants + 2), i);
        _offset_62 = _compIdx_16 + Fr_toInt(_tmp_22)*_compSizes_16[1];
        _xL_out_sigIdx__3 = ctx->getSignalOffset(_offset_62, 0x82a9a0397420693eLL /* xL_out */);
        ctx->multiGetSignal(__cIdx, _offset_62, _xL_out_sigIdx__3, _sigValue_11, 1);
        Fr_add(_tmp_23, i, (ctx->circuit->constants + 1));
        _offset_64 = _outs_sigIdx_ + Fr_toInt(_tmp_23)*_sigSizes_outs[1];
        ctx->setSignal(__cIdx, __cIdx, _offset_64, _sigValue_11);
        Fr_copyn(_tmp_25, i, 1);
        Fr_add(_tmp_24, i, (ctx->circuit->constants + 1));
        Fr_copyn(i, _tmp_24, 1);
        Fr_lt(_tmp_27, i, (ctx->circuit->constants + 0));
        _loopCond_1 = _tmp_27;
    }
    ctx->finished(__cIdx);
}
/*
MiMCFeistel
nrounds=220
xR_in=0
*/
void MiMCFeistel_4721f7651191669c(Circom_CalcWit *ctx, int __cIdx) {
    FrElement _sigValue[1];
    FrElement _sigValue_1[1];
    FrElement _tmp_8[1];
    FrElement t[1];
    FrElement _tmp_9[1];
    FrElement _sigValue_2[1];
    FrElement _sigValue_3[1];
    FrElement _tmp_10[1];
    FrElement _sigValue_4[1];
    FrElement _sigValue_5[1];
    FrElement _tmp_14[1];
    FrElement _tmp_15[1];
    FrElement _sigValue_6[1];
    FrElement _tmp_19[1];
    FrElement i[1];
    FrElement c[1];
    FrElement _tmp_20[1];
    FrElement _tmp_22[1];
    FrElement _tmp_23[1];
    FrElement _num_231[1];
    FrElement _tmp_24[1];
    FrElement c_partial[218];
    FrElement _tmp_25[1];
    FrElement _sigValue_7[1];
    FrElement _sigValue_8[1];
    FrElement _tmp_26[1];
    FrElement _sigValue_9[1];
    FrElement _tmp_27[1];
    FrElement _sigValue_10[1];
    FrElement _tmp_28[1];
    FrElement _tmp_29[1];
    FrElement _tmp_30[1];
    FrElement _sigValue_11[1];
    FrElement _sigValue_12[1];
    FrElement _tmp_31[1];
    FrElement _tmp_33[1];
    FrElement _tmp_34[1];
    FrElement _sigValue_13[1];
    FrElement _tmp_35[1];
    FrElement _sigValue_14[1];
    FrElement _sigValue_15[1];
    FrElement _tmp_36[1];
    FrElement _tmp_37[1];
    FrElement _tmp_38[1];
    FrElement _sigValue_16[1];
    FrElement _tmp_39[1];
    FrElement _sigValue_17[1];
    FrElement _tmp_40[1];
    FrElement _sigValue_18[1];
    FrElement _sigValue_19[1];
    FrElement _tmp_41[1];
    FrElement _tmp_42[1];
    FrElement _tmp_43[1];
    FrElement _sigValue_20[1];
    FrElement _tmp_45[1];
    FrElement _tmp_44[1];
    FrElement _tmp_46[1];
    int _k_sigIdx_;
    int _xL_in_sigIdx_;
    int _t2_sigIdx_;
    int _offset_17;
    int _offset_19;
    int _offset_21;
    int _t4_sigIdx_;
    int _offset_23;
    int _xR_in_sigIdx_;
    int _offset_28;
    int _xL_sigIdx_;
    int _offset_31;
    int _xR_sigIdx_;
    int _offset_34;
    int _offset_44;
    int _offset_48;
    int _offset_54;
    int _offset_56;
    int _offset_58;
    int _offset_60;
    int _offset_65;
    int _offset_67;
    int _offset_70;
    int _offset_73;
    int _offset_75;
    int _offset_77;
    int _offset_79;
    int _xR_out_sigIdx_;
    int _offset_82;
    int _xL_out_sigIdx_;
    Circom_Sizes _sigSizes_t2;
    Circom_Sizes _sigSizes_t4;
    Circom_Sizes _sigSizes_xL;
    Circom_Sizes _sigSizes_xR;
    PFrElement _loopCond;
    PFrElement _v_25;
    PFrElement _ter;
    PFrElement _ter_1;
    PFrElement _ter_2;
    Fr_copy(&(_tmp_19[0]), ctx->circuit->constants +1);
    Fr_copy(&(i[0]), ctx->circuit->constants +1);
    Fr_copy(&(c[0]), ctx->circuit->constants +0);
    Fr_copy(&(_num_231[0]), ctx->circuit->constants +0);
    Fr_copy(&(c_partial[0]), ctx->circuit->constants +4);
    Fr_copy(&(c_partial[1]), ctx->circuit->constants +5);
    Fr_copy(&(c_partial[2]), ctx->circuit->constants +6);
    Fr_copy(&(c_partial[3]), ctx->circuit->constants +7);
    Fr_copy(&(c_partial[4]), ctx->circuit->constants +8);
    Fr_copy(&(c_partial[5]), ctx->circuit->constants +9);
    Fr_copy(&(c_partial[6]), ctx->circuit->constants +10);
    Fr_copy(&(c_partial[7]), ctx->circuit->constants +11);
    Fr_copy(&(c_partial[8]), ctx->circuit->constants +12);
    Fr_copy(&(c_partial[9]), ctx->circuit->constants +13);
    Fr_copy(&(c_partial[10]), ctx->circuit->constants +14);
    Fr_copy(&(c_partial[11]), ctx->circuit->constants +15);
    Fr_copy(&(c_partial[12]), ctx->circuit->constants +16);
    Fr_copy(&(c_partial[13]), ctx->circuit->constants +17);
    Fr_copy(&(c_partial[14]), ctx->circuit->constants +18);
    Fr_copy(&(c_partial[15]), ctx->circuit->constants +19);
    Fr_copy(&(c_partial[16]), ctx->circuit->constants +20);
    Fr_copy(&(c_partial[17]), ctx->circuit->constants +21);
    Fr_copy(&(c_partial[18]), ctx->circuit->constants +22);
    Fr_copy(&(c_partial[19]), ctx->circuit->constants +23);
    Fr_copy(&(c_partial[20]), ctx->circuit->constants +24);
    Fr_copy(&(c_partial[21]), ctx->circuit->constants +25);
    Fr_copy(&(c_partial[22]), ctx->circuit->constants +26);
    Fr_copy(&(c_partial[23]), ctx->circuit->constants +27);
    Fr_copy(&(c_partial[24]), ctx->circuit->constants +28);
    Fr_copy(&(c_partial[25]), ctx->circuit->constants +29);
    Fr_copy(&(c_partial[26]), ctx->circuit->constants +30);
    Fr_copy(&(c_partial[27]), ctx->circuit->constants +31);
    Fr_copy(&(c_partial[28]), ctx->circuit->constants +32);
    Fr_copy(&(c_partial[29]), ctx->circuit->constants +33);
    Fr_copy(&(c_partial[30]), ctx->circuit->constants +34);
    Fr_copy(&(c_partial[31]), ctx->circuit->constants +35);
    Fr_copy(&(c_partial[32]), ctx->circuit->constants +36);
    Fr_copy(&(c_partial[33]), ctx->circuit->constants +37);
    Fr_copy(&(c_partial[34]), ctx->circuit->constants +38);
    Fr_copy(&(c_partial[35]), ctx->circuit->constants +39);
    Fr_copy(&(c_partial[36]), ctx->circuit->constants +40);
    Fr_copy(&(c_partial[37]), ctx->circuit->constants +41);
    Fr_copy(&(c_partial[38]), ctx->circuit->constants +42);
    Fr_copy(&(c_partial[39]), ctx->circuit->constants +43);
    Fr_copy(&(c_partial[40]), ctx->circuit->constants +44);
    Fr_copy(&(c_partial[41]), ctx->circuit->constants +45);
    Fr_copy(&(c_partial[42]), ctx->circuit->constants +46);
    Fr_copy(&(c_partial[43]), ctx->circuit->constants +47);
    Fr_copy(&(c_partial[44]), ctx->circuit->constants +48);
    Fr_copy(&(c_partial[45]), ctx->circuit->constants +49);
    Fr_copy(&(c_partial[46]), ctx->circuit->constants +50);
    Fr_copy(&(c_partial[47]), ctx->circuit->constants +51);
    Fr_copy(&(c_partial[48]), ctx->circuit->constants +52);
    Fr_copy(&(c_partial[49]), ctx->circuit->constants +53);
    Fr_copy(&(c_partial[50]), ctx->circuit->constants +54);
    Fr_copy(&(c_partial[51]), ctx->circuit->constants +55);
    Fr_copy(&(c_partial[52]), ctx->circuit->constants +56);
    Fr_copy(&(c_partial[53]), ctx->circuit->constants +57);
    Fr_copy(&(c_partial[54]), ctx->circuit->constants +58);
    Fr_copy(&(c_partial[55]), ctx->circuit->constants +59);
    Fr_copy(&(c_partial[56]), ctx->circuit->constants +60);
    Fr_copy(&(c_partial[57]), ctx->circuit->constants +61);
    Fr_copy(&(c_partial[58]), ctx->circuit->constants +62);
    Fr_copy(&(c_partial[59]), ctx->circuit->constants +63);
    Fr_copy(&(c_partial[60]), ctx->circuit->constants +64);
    Fr_copy(&(c_partial[61]), ctx->circuit->constants +65);
    Fr_copy(&(c_partial[62]), ctx->circuit->constants +66);
    Fr_copy(&(c_partial[63]), ctx->circuit->constants +67);
    Fr_copy(&(c_partial[64]), ctx->circuit->constants +68);
    Fr_copy(&(c_partial[65]), ctx->circuit->constants +69);
    Fr_copy(&(c_partial[66]), ctx->circuit->constants +70);
    Fr_copy(&(c_partial[67]), ctx->circuit->constants +71);
    Fr_copy(&(c_partial[68]), ctx->circuit->constants +72);
    Fr_copy(&(c_partial[69]), ctx->circuit->constants +73);
    Fr_copy(&(c_partial[70]), ctx->circuit->constants +74);
    Fr_copy(&(c_partial[71]), ctx->circuit->constants +75);
    Fr_copy(&(c_partial[72]), ctx->circuit->constants +76);
    Fr_copy(&(c_partial[73]), ctx->circuit->constants +77);
    Fr_copy(&(c_partial[74]), ctx->circuit->constants +78);
    Fr_copy(&(c_partial[75]), ctx->circuit->constants +79);
    Fr_copy(&(c_partial[76]), ctx->circuit->constants +80);
    Fr_copy(&(c_partial[77]), ctx->circuit->constants +81);
    Fr_copy(&(c_partial[78]), ctx->circuit->constants +82);
    Fr_copy(&(c_partial[79]), ctx->circuit->constants +83);
    Fr_copy(&(c_partial[80]), ctx->circuit->constants +84);
    Fr_copy(&(c_partial[81]), ctx->circuit->constants +85);
    Fr_copy(&(c_partial[82]), ctx->circuit->constants +86);
    Fr_copy(&(c_partial[83]), ctx->circuit->constants +87);
    Fr_copy(&(c_partial[84]), ctx->circuit->constants +88);
    Fr_copy(&(c_partial[85]), ctx->circuit->constants +89);
    Fr_copy(&(c_partial[86]), ctx->circuit->constants +90);
    Fr_copy(&(c_partial[87]), ctx->circuit->constants +91);
    Fr_copy(&(c_partial[88]), ctx->circuit->constants +92);
    Fr_copy(&(c_partial[89]), ctx->circuit->constants +93);
    Fr_copy(&(c_partial[90]), ctx->circuit->constants +94);
    Fr_copy(&(c_partial[91]), ctx->circuit->constants +95);
    Fr_copy(&(c_partial[92]), ctx->circuit->constants +96);
    Fr_copy(&(c_partial[93]), ctx->circuit->constants +97);
    Fr_copy(&(c_partial[94]), ctx->circuit->constants +98);
    Fr_copy(&(c_partial[95]), ctx->circuit->constants +99);
    Fr_copy(&(c_partial[96]), ctx->circuit->constants +100);
    Fr_copy(&(c_partial[97]), ctx->circuit->constants +101);
    Fr_copy(&(c_partial[98]), ctx->circuit->constants +102);
    Fr_copy(&(c_partial[99]), ctx->circuit->constants +103);
    Fr_copy(&(c_partial[100]), ctx->circuit->constants +104);
    Fr_copy(&(c_partial[101]), ctx->circuit->constants +105);
    Fr_copy(&(c_partial[102]), ctx->circuit->constants +106);
    Fr_copy(&(c_partial[103]), ctx->circuit->constants +107);
    Fr_copy(&(c_partial[104]), ctx->circuit->constants +108);
    Fr_copy(&(c_partial[105]), ctx->circuit->constants +109);
    Fr_copy(&(c_partial[106]), ctx->circuit->constants +110);
    Fr_copy(&(c_partial[107]), ctx->circuit->constants +111);
    Fr_copy(&(c_partial[108]), ctx->circuit->constants +112);
    Fr_copy(&(c_partial[109]), ctx->circuit->constants +113);
    Fr_copy(&(c_partial[110]), ctx->circuit->constants +114);
    Fr_copy(&(c_partial[111]), ctx->circuit->constants +115);
    Fr_copy(&(c_partial[112]), ctx->circuit->constants +116);
    Fr_copy(&(c_partial[113]), ctx->circuit->constants +117);
    Fr_copy(&(c_partial[114]), ctx->circuit->constants +118);
    Fr_copy(&(c_partial[115]), ctx->circuit->constants +119);
    Fr_copy(&(c_partial[116]), ctx->circuit->constants +120);
    Fr_copy(&(c_partial[117]), ctx->circuit->constants +121);
    Fr_copy(&(c_partial[118]), ctx->circuit->constants +122);
    Fr_copy(&(c_partial[119]), ctx->circuit->constants +123);
    Fr_copy(&(c_partial[120]), ctx->circuit->constants +124);
    Fr_copy(&(c_partial[121]), ctx->circuit->constants +125);
    Fr_copy(&(c_partial[122]), ctx->circuit->constants +126);
    Fr_copy(&(c_partial[123]), ctx->circuit->constants +127);
    Fr_copy(&(c_partial[124]), ctx->circuit->constants +128);
    Fr_copy(&(c_partial[125]), ctx->circuit->constants +129);
    Fr_copy(&(c_partial[126]), ctx->circuit->constants +130);
    Fr_copy(&(c_partial[127]), ctx->circuit->constants +131);
    Fr_copy(&(c_partial[128]), ctx->circuit->constants +132);
    Fr_copy(&(c_partial[129]), ctx->circuit->constants +133);
    Fr_copy(&(c_partial[130]), ctx->circuit->constants +134);
    Fr_copy(&(c_partial[131]), ctx->circuit->constants +135);
    Fr_copy(&(c_partial[132]), ctx->circuit->constants +136);
    Fr_copy(&(c_partial[133]), ctx->circuit->constants +137);
    Fr_copy(&(c_partial[134]), ctx->circuit->constants +138);
    Fr_copy(&(c_partial[135]), ctx->circuit->constants +139);
    Fr_copy(&(c_partial[136]), ctx->circuit->constants +140);
    Fr_copy(&(c_partial[137]), ctx->circuit->constants +141);
    Fr_copy(&(c_partial[138]), ctx->circuit->constants +142);
    Fr_copy(&(c_partial[139]), ctx->circuit->constants +143);
    Fr_copy(&(c_partial[140]), ctx->circuit->constants +144);
    Fr_copy(&(c_partial[141]), ctx->circuit->constants +145);
    Fr_copy(&(c_partial[142]), ctx->circuit->constants +146);
    Fr_copy(&(c_partial[143]), ctx->circuit->constants +147);
    Fr_copy(&(c_partial[144]), ctx->circuit->constants +148);
    Fr_copy(&(c_partial[145]), ctx->circuit->constants +149);
    Fr_copy(&(c_partial[146]), ctx->circuit->constants +150);
    Fr_copy(&(c_partial[147]), ctx->circuit->constants +151);
    Fr_copy(&(c_partial[148]), ctx->circuit->constants +152);
    Fr_copy(&(c_partial[149]), ctx->circuit->constants +153);
    Fr_copy(&(c_partial[150]), ctx->circuit->constants +154);
    Fr_copy(&(c_partial[151]), ctx->circuit->constants +155);
    Fr_copy(&(c_partial[152]), ctx->circuit->constants +156);
    Fr_copy(&(c_partial[153]), ctx->circuit->constants +157);
    Fr_copy(&(c_partial[154]), ctx->circuit->constants +158);
    Fr_copy(&(c_partial[155]), ctx->circuit->constants +159);
    Fr_copy(&(c_partial[156]), ctx->circuit->constants +160);
    Fr_copy(&(c_partial[157]), ctx->circuit->constants +161);
    Fr_copy(&(c_partial[158]), ctx->circuit->constants +162);
    Fr_copy(&(c_partial[159]), ctx->circuit->constants +163);
    Fr_copy(&(c_partial[160]), ctx->circuit->constants +164);
    Fr_copy(&(c_partial[161]), ctx->circuit->constants +165);
    Fr_copy(&(c_partial[162]), ctx->circuit->constants +166);
    Fr_copy(&(c_partial[163]), ctx->circuit->constants +167);
    Fr_copy(&(c_partial[164]), ctx->circuit->constants +168);
    Fr_copy(&(c_partial[165]), ctx->circuit->constants +169);
    Fr_copy(&(c_partial[166]), ctx->circuit->constants +170);
    Fr_copy(&(c_partial[167]), ctx->circuit->constants +171);
    Fr_copy(&(c_partial[168]), ctx->circuit->constants +172);
    Fr_copy(&(c_partial[169]), ctx->circuit->constants +173);
    Fr_copy(&(c_partial[170]), ctx->circuit->constants +174);
    Fr_copy(&(c_partial[171]), ctx->circuit->constants +175);
    Fr_copy(&(c_partial[172]), ctx->circuit->constants +176);
    Fr_copy(&(c_partial[173]), ctx->circuit->constants +177);
    Fr_copy(&(c_partial[174]), ctx->circuit->constants +178);
    Fr_copy(&(c_partial[175]), ctx->circuit->constants +179);
    Fr_copy(&(c_partial[176]), ctx->circuit->constants +180);
    Fr_copy(&(c_partial[177]), ctx->circuit->constants +181);
    Fr_copy(&(c_partial[178]), ctx->circuit->constants +182);
    Fr_copy(&(c_partial[179]), ctx->circuit->constants +183);
    Fr_copy(&(c_partial[180]), ctx->circuit->constants +184);
    Fr_copy(&(c_partial[181]), ctx->circuit->constants +185);
    Fr_copy(&(c_partial[182]), ctx->circuit->constants +186);
    Fr_copy(&(c_partial[183]), ctx->circuit->constants +187);
    Fr_copy(&(c_partial[184]), ctx->circuit->constants +188);
    Fr_copy(&(c_partial[185]), ctx->circuit->constants +189);
    Fr_copy(&(c_partial[186]), ctx->circuit->constants +190);
    Fr_copy(&(c_partial[187]), ctx->circuit->constants +191);
    Fr_copy(&(c_partial[188]), ctx->circuit->constants +192);
    Fr_copy(&(c_partial[189]), ctx->circuit->constants +193);
    Fr_copy(&(c_partial[190]), ctx->circuit->constants +194);
    Fr_copy(&(c_partial[191]), ctx->circuit->constants +195);
    Fr_copy(&(c_partial[192]), ctx->circuit->constants +196);
    Fr_copy(&(c_partial[193]), ctx->circuit->constants +197);
    Fr_copy(&(c_partial[194]), ctx->circuit->constants +198);
    Fr_copy(&(c_partial[195]), ctx->circuit->constants +199);
    Fr_copy(&(c_partial[196]), ctx->circuit->constants +200);
    Fr_copy(&(c_partial[197]), ctx->circuit->constants +201);
    Fr_copy(&(c_partial[198]), ctx->circuit->constants +202);
    Fr_copy(&(c_partial[199]), ctx->circuit->constants +203);
    Fr_copy(&(c_partial[200]), ctx->circuit->constants +204);
    Fr_copy(&(c_partial[201]), ctx->circuit->constants +205);
    Fr_copy(&(c_partial[202]), ctx->circuit->constants +206);
    Fr_copy(&(c_partial[203]), ctx->circuit->constants +207);
    Fr_copy(&(c_partial[204]), ctx->circuit->constants +208);
    Fr_copy(&(c_partial[205]), ctx->circuit->constants +209);
    Fr_copy(&(c_partial[206]), ctx->circuit->constants +210);
    Fr_copy(&(c_partial[207]), ctx->circuit->constants +211);
    Fr_copy(&(c_partial[208]), ctx->circuit->constants +212);
    Fr_copy(&(c_partial[209]), ctx->circuit->constants +213);
    Fr_copy(&(c_partial[210]), ctx->circuit->constants +214);
    Fr_copy(&(c_partial[211]), ctx->circuit->constants +215);
    Fr_copy(&(c_partial[212]), ctx->circuit->constants +216);
    Fr_copy(&(c_partial[213]), ctx->circuit->constants +217);
    Fr_copy(&(c_partial[214]), ctx->circuit->constants +218);
    Fr_copy(&(c_partial[215]), ctx->circuit->constants +219);
    Fr_copy(&(c_partial[216]), ctx->circuit->constants +220);
    Fr_copy(&(c_partial[217]), ctx->circuit->constants +221);
    _k_sigIdx_ = ctx->getSignalOffset(__cIdx, 0xaf63e64c8601fd8aLL /* k */);
    _xL_in_sigIdx_ = ctx->getSignalOffset(__cIdx, 0xe58d565a2c6193f5LL /* xL_in */);
    _t2_sigIdx_ = ctx->getSignalOffset(__cIdx, 0x08c7fe07b56a5c63LL /* t2 */);
    _t4_sigIdx_ = ctx->getSignalOffset(__cIdx, 0x08c80407b56a6695LL /* t4 */);
    _xR_in_sigIdx_ = ctx->getSignalOffset(__cIdx, 0x490e56ad9f02bbcfLL /* xR_in */);
    _xL_sigIdx_ = ctx->getSignalOffset(__cIdx, 0x08f11c07b58d9471LL /* xL */);
    _xR_sigIdx_ = ctx->getSignalOffset(__cIdx, 0x08f12607b58da56fLL /* xR */);
    _xR_out_sigIdx_ = ctx->getSignalOffset(__cIdx, 0x5898f4054dd4f254LL /* xR_out */);
    _xL_out_sigIdx_ = ctx->getSignalOffset(__cIdx, 0x82a9a0397420693eLL /* xL_out */);
    _sigSizes_t2 = ctx->getSignalSizes(__cIdx, 0x08c7fe07b56a5c63LL /* t2 */);
    _sigSizes_t4 = ctx->getSignalSizes(__cIdx, 0x08c80407b56a6695LL /* t4 */);
    _sigSizes_xL = ctx->getSignalSizes(__cIdx, 0x08f11c07b58d9471LL /* xL */);
    _sigSizes_xR = ctx->getSignalSizes(__cIdx, 0x08f12607b58da56fLL /* xR */);
    /* signal input xL_in */
    /* signal input xR_in */
    /* signal input k */
    /* signal output xL_out */
    /* signal output xR_out */
    /* var c_partial[218] = [
          7120861356467848435263064379192047478074060781135320967663101236819528304084,
          5024705281721889198577876690145313457398658950011302225525409148828000436681,
          17980351014018068290387269214713820287804403312720763401943303895585469787384,
          19886576439381707240399940949310933992335779767309383709787331470398675714258,
          1213715278223786725806155661738676903520350859678319590331207960381534602599,
          18162138253399958831050545255414688239130588254891200470934232514682584734511,
          7667462281466170157858259197976388676420847047604921256361474169980037581876,
          7207551498477838452286210989212982851118089401128156132319807392460388436957,
          9864183311657946807255900203841777810810224615118629957816193727554621093838,
          4798196928559910300796064665904583125427459076060519468052008159779219347957,
          17387238494588145257484818061490088963673275521250153686214197573695921400950,
          10005334761930299057035055370088813230849810566234116771751925093634136574742,
          11897542014760736209670863723231849628230383119798486487899539017466261308762,
          16771780563523793011283273687253985566177232886900511371656074413362142152543,
          749264854018824809464168489785113337925400687349357088413132714480582918506,
          3683645737503705042628598550438395339383572464204988015434959428676652575331,
          7556750851783822914673316211129907782679509728346361368978891584375551186255,
          20391289379084797414557439284689954098721219201171527383291525676334308303023,
          18146517657445423462330854383025300323335289319277199154920964274562014376193,
          8080173465267536232534446836148661251987053305394647905212781979099916615292,
          10796443006899450245502071131975731672911747129805343722228413358507805531141,
          5404287610364961067658660283245291234008692303120470305032076412056764726509,
          4623894483395123520243967718315330178025957095502546813929290333264120223168,
          16845753148201777192406958674202574751725237939980634861948953189320362207797,
          4622170486584704769521001011395820886029808520586507873417553166762370293671,
          16688277490485052681847773549197928630624828392248424077804829676011512392564,
          11878652861183667748838188993669912629573713271883125458838494308957689090959,
          2436445725746972287496138382764643208791713986676129260589667864467010129482,
          1888098689545151571063267806606510032698677328923740058080630641742325067877,
          148924106504065664829055598316821983869409581623245780505601526786791681102,
          18875020877782404439294079398043479420415331640996249745272087358069018086569,
          15189693413320228845990326214136820307649565437237093707846682797649429515840,
          19669450123472657781282985229369348220906547335081730205028099210442632534079,
          5521922218264623411380547905210139511350706092570900075727555783240701821773,
          4144769320246558352780591737261172907511489963810975650573703217887429086546,
          10097732913112662248360143041019433907849917041759137293018029019134392559350,
          1720059427972723034107765345743336447947522473310069975142483982753181038321,
          6302388219880227251325608388535181451187131054211388356563634768253301290116,
          6745410632962119604799318394592010194450845483518862700079921360015766217097,
          10858157235265583624235850660462324469799552996870780238992046963007491306222,
          20241898894740093733047052816576694435372877719072347814065227797906130857593,
          10165780782761211520836029617746977303303335603838343292431760011576528327409,
          2832093654883670345969792724123161241696170611611744759675180839473215203706,
          153011722355526826233082383360057587249818749719433916258246100068258954737,
          20196970640587451358539129330170636295243141659030208529338914906436009086943,
          3180973917010545328313139835982464870638521890385603025657430208141494469656,
          17198004293191777441573635123110935015228014028618868252989374962722329283022,
          7642160509228669138628515458941659189680509753651629476399516332224325757132,
          19346204940546791021518535594447257347218878114049998691060016493806845179755,
          11501810868606870391127866188394535330696206817602260610801897042898616817272,
          3113973447392053821824427670386252797811804954746053461397972968381571297505,
          6545064306297957002139416752334741502722251869537551068239642131448768236585,
          5203908808704813498389265425172875593837960384349653691918590736979872578408,
          2246692432011290582160062129070762007374502637007107318105405626910313810224,
          11760570435432189127645691249600821064883781677693087773459065574359292849137,
          5543749482491340532547407723464609328207990784853381797689466144924198391839,
          8837549193990558762776520822018694066937602576881497343584903902880277769302,
          12855514863299373699594410385788943772765811961581749194183533625311486462501,
          5363660674689121676875069134269386492382220935599781121306637800261912519729,
          13162342403579303950549728848130828093497701266240457479693991108217307949435,
          916941639326869583414469202910306428966657806899788970948781207501251816730,
          15618589556584434434009868216186115416835494805174158488636000580759692174228,
          8959562060028569701043973060670353733575345393653685776974948916988033453971,
          16390754464333401712265575949874369157699293840516802426621216808905079127650,
          168282396747788514908709091757591226095443902501365500003618183905496160435,
          8327443473179334761744301768309008451162322941906921742120510244986704677004,
          17213012626801210615058753489149961717422101711567228037597150941152495100640,
          10394369641533736715250242399198097296122982486516256408681925424076248952280,
          17784386835392322654196171115293700800825771210400152504776806618892170162248,
          16533189939837087893364000390641148516479148564190420358849587959161226782982,
          18725396114211370207078434315900726338547621160475533496863298091023511945076,
          7132325028834551397904855671244375895110341505383911719294705267624034122405,
          148317947440800089795933930720822493695520852448386394775371401743494965187,
          19001050671757720352890779127693793630251266879994702723636759889378387053056,
          18824274411769830274877839365728651108434404855803844568234862945613766611460,
          12771414330193951156383998390424063470766226667986423961689712557338777174205,
          11332046574800279729678603488745295198038913503395629790213378101166488244657,
          9607550223176946388146938069307456967842408600269548190739947540821716354749,
          8756385288462344550200229174435953103162307705310807828651304665320046782583,
          176061952957067086877570020242717222844908281373122372938833890096257042779,
          12200212977482648306758992405065921724409841940671166017620928947866825250857,
          10868453624107875516866146499877130701929063632959660262366632833504750028858,
          2016095394399807253596787752134573207202567875457560571095586743878953450738,
          21815578223768330433802113452339488275704145896544481092014911825656390567514,
          4923772847693564777744725640710197015181591950368494148029046443433103381621,
          1813584943682214789802230765734821149202472893379265320098816901270224589984,
          10810123816265612772922113403831964815724109728287572256602010709288980656498,
          1153669123397255702524721206511185557982017410156956216465120456256288427021,
          5007518659266430200134478928344522649876467369278722765097865662497773767152,
          2511432546938591792036639990606464315121646668029252285288323664350666551637,
          32883284540320451295484135704808083452381176816565850047310272290579727564,
          10484856914279112612610993418405543310546746652738541161791501150994088679557,
          2026733759645519472558796412979210009170379159866522399881566309631434814953,
          14731806221235869882801331463708736361296174006732553130708107037190460654379,
          14740327483193277147065845135561988641238516852487657117813536909482068950652,
          18787428285295558781869865751953016580493190547148386433580291216673009884554,
          3804047064713122820157099453648459188816376755739202017447862327783289895072,
          16709604795697901641948603019242067672006293290826991671766611326262532802914,
          11061717085931490100602849654034280576915102867237101935487893025907907250695,
          2821730726367472966906149684046356272806484545281639696873240305052362149654,
          17467794879902895769410571945152708684493991588672014763135370927880883292655,
          1571520786233540988201616650622796363168031165456869481368085474420849243232,
          10041051776251223165849354194892664881051125330236567356945669006147134614302,
          3981753758468103976812813304477670033098707002886030847251581853700311567551,
          4365864398105436789177703571412645548020537580493599380018290523813331678900,
          2391801327305361293476178683853802679507598622000359948432171562543560193350,
          214219368547551689972421167733597094823289857206402800635962137077096090722,
          18192064100315141084242006659317257023098826945893371479835220462302399655674,
          15487549757142039139328911515400805508248576685795694919457041092150651939253,
          10142447197759703415402259672441315777933858467700579946665223821199077641122,
          11246573086260753259993971254725613211193686683988426513880826148090811891866,
          6574066859860991369704567902211886840188702386542112593710271426704432301235,
          11311085442652291634822798307831431035776248927202286895207125867542470350078,
          20977948360215259915441258687649465618185769343138135384346964466965010873779,
          792781492853909872425531014397300057232399608769451037135936617996830018501,
          5027602491523497423798779154966735896562099398367163998686335127580757861872,
          14595204575654316237672764823862241845410365278802914304953002937313300553572,
          13973538843621261113924259058427434053808430378163734641175100160836376897004,
          16395063164993626722686882727042150241125309409717445381854913964674649318585,
          8465768840047024550750516678171433288207841931251654898809033371655109266663,
          21345603324471810861925019445720576814602636473739003852898308205213912255830,
          21171984405852590343970239018692870799717057961108910523876770029017785940991,
          10761027113757988230637066281488532903174559953630210849190212601991063767647,
          6678298831065390834922566306988418588227382406175769592902974103663687992230,
          4993662582188632374202316265508850988596880036291765531885657575099537176757,
          18364168158495573675698600238443218434246806358811328083953887470513967121206,
          3506345610354615013737144848471391553141006285964325596214723571988011984829,
          248732676202643792226973868626360612151424823368345645514532870586234380100,
          10090204501612803176317709245679152331057882187411777688746797044706063410969,
          21297149835078365363970699581821844234354988617890041296044775371855432973500,
          16729368143229828574342820060716366330476985824952922184463387490091156065099,
          4467191506765339364971058668792642195242197133011672559453028147641428433293,
          8677548159358013363291014307402600830078662555833653517843708051504582990832,
          1022951765127126818581466247360193856197472064872288389992480993218645055345,
          1888195070251580606973417065636430294417895423429240431595054184472931224452,
          4221265384902749246920810956363310125115516771964522748896154428740238579824,
          2825393571154632139467378429077438870179957021959813965940638905853993971879,
          19171031072692942278056619599721228021635671304612437350119663236604712493093,
          10780807212297131186617505517708903709488273075252405602261683478333331220733,
          18230936781133176044598070768084230333433368654744509969087239465125979720995,
          16901065971871379877929280081392692752968612240624985552337779093292740763381,
          146494141603558321291767829522948454429758543710648402457451799015963102253,
          2492729278659146790410698334997955258248120870028541691998279257260289595548,
          2204224910006646535594933495262085193210692406133533679934843341237521233504,
          16062117410185840274616925297332331018523844434907012275592638570193234893570,
          5894928453677122829055071981254202951712129328678534592916926069506935491729,
          4947482739415078212217504789923078546034438919537985740403824517728200332286,
          16143265650645676880461646123844627780378251900510645261875867423498913438066,
          397690828254561723549349897112473766901585444153303054845160673059519614409,
          11272653598912269895509621181205395118899451234151664604248382803490621227687,
          15566927854306879444693061574322104423426072650522411176731130806720753591030,
          14222898219492484180162096141564251903058269177856173968147960855133048449557,
          16690275395485630428127725067513114066329712673106153451801968992299636791385,
          3667030990325966886479548860429670833692690972701471494757671819017808678584,
          21280039024501430842616328642522421302481259067470872421086939673482530783142,
          15895485136902450169492923978042129726601461603404514670348703312850236146328,
          7733050956302327984762132317027414325566202380840692458138724610131603812560,
          438123800976401478772659663183448617575635636575786782566035096946820525816,
          814913922521637742587885320797606426167962526342166512693085292151314976633,
          12368712287081330853637674140264759478736012797026621876924395982504369598764,
          2494806857395134874309386694756263421445039103814920780777601708371037591569,
          16101132301514338989512946061786320637179843435886825102406248183507106312877,
          6252650284989960032925831409804233477770646333900692286731621844532438095656,
          9277135875276787021836189566799935097400042171346561246305113339462708861695,
          10493603554686607050979497281838644324893776154179810893893660722522945589063,
          8673089750662709235894359384294076697329948991010184356091130382437645649279,
          9558393272910366944245875920138649617479779893610128634419086981339060613250,
          19012287860122586147374214541764572282814469237161122489573881644994964647218,
          9783723818270121678386992630754842961728702994964214799008457449989291229500,
          15550788416669474113213749561488122552422887538676036667630838378023479382689,
          15016165746156232864069722572047169071786333815661109750860165034341572904221,
          6506225705710197163670556961299945987488979904603689017479840649664564978574,
          10796631184889302076168355684722130903785890709107732067446714470783437829037,
          19871836214837460419845806980869387567383718044439891735114283113359312279540,
          20871081766843466343749609089986071784031203517506781251203251608363835140622,
          5100105771517691442278432864090229416166996183792075307747582375962855820797,
          8777887112076272395250620301071581171386440850451972412060638225741125310886,
          5300440870136391278944213332144327695659161151625757537632832724102670898756,
          1205448543652932944633962232545707633928124666868453915721030884663332604536,
          5542499997310181530432302492142574333860449305424174466698068685590909336771,
          11028094245762332275225364962905938096659249161369092798505554939952525894293,
          19187314764836593118404597958543112407224947638377479622725713735224279297009,
          17047263688548829001253658727764731047114098556534482052135734487985276987385,
          19914849528178967155534624144358541535306360577227460456855821557421213606310,
          2929658084700714257515872921366736697080475676508114973627124569375444665664,
          15092262360719700162343163278648422751610766427236295023221516498310468956361,
          21578580340755653236050830649990190843552802306886938815497471545814130084980,
          1258781501221760320019859066036073675029057285507345332959539295621677296991,
          3819598418157732134449049289585680301176983019643974929528867686268702720163,
          8653175945487997845203439345797943132543211416447757110963967501177317426221,
          6614652990340435611114076169697104582524566019034036680161902142028967568142,
          19212515502973904821995111796203064175854996071497099383090983975618035391558,
          18664315914479294273286016871365663486061896605232511201418576829062292269769,
          11498264615058604317482574216318586415670903094838791165247179252175768794889,
          10814026414212439999107945133852431304483604215416531759535467355316227331774,
          17566185590731088197064706533119299946752127014428399631467913813769853431107,
          14016139747289624978792446847000951708158212463304817001882956166752906714332,
          8242601581342441750402731523736202888792436665415852106196418942315563860366,
          9244680976345080074252591214216060854998619670381671198295645618515047080988,
          12216779172735125538689875667307129262237123728082657485828359100719208190116,
          10702811721859145441471328511968332847175733707711670171718794132331147396634,
          6479667912792222539919362076122453947926362746906450079329453150607427372979,
          15117544653571553820496948522381772148324367479772362833334593000535648316185,
          6842203153996907264167856337497139692895299874139131328642472698663046726780,
          12732823292801537626009139514048596316076834307941224506504666470961250728055,
          6936272626871035740815028148058841877090860312517423346335878088297448888663,
          17297554111853491139852678417579991271009602631577069694853813331124433680030,
          16641596134749940573104316021365063031319260205559553673368334842484345864859,
          7400481189785154329569470986896455371037813715804007747228648863919991399081,
          2273205422216987330510475127669563545720586464429614439716564154166712854048,
          15162538063742142685306302282127534305212832649282186184583465569986719234456,
          5628039096440332922248578319648483863204530861778160259559031331287721255522,
          16085392195894691829567913404182676871326863890140775376809129785155092531260,
          14227467863135365427954093998621993651369686288941275436795622973781503444257,
          18224457394066545825553407391290108485121649197258948320896164404518684305122,
          274945154732293792784580363548970818611304339008964723447672490026510689427,
          11050822248291117548220126630860474473945266276626263036056336623671308219529,
          2119542016932434047340813757208803962484943912710204325088879681995922344971
        ] */
    /* var t */
    /* signal t2[nrounds] */
    /* signal t4[nrounds] */
    /* signal xL[nrounds-1] */
    /* signal xR[nrounds-1] */
    /* var c */
    /* for (var i=0;i<nrounds;i++) */
    /* if ((i == 0) || (i == nrounds - 1)) */
    /* c = 0 */
    /* t = (i==0) ? k+xL_in : k + xL[i-1] + c */
    ctx->multiGetSignal(__cIdx, __cIdx, _k_sigIdx_, _sigValue, 1);
    ctx->multiGetSignal(__cIdx, __cIdx, _xL_in_sigIdx_, _sigValue_1, 1);
    Fr_add(_tmp_8, _sigValue, _sigValue_1);
    Fr_copyn(t, _tmp_8, 1);
    /* t2[i] <== t*t */
    Fr_mul(_tmp_9, t, t);
    _offset_17 = _t2_sigIdx_;
    ctx->setSignal(__cIdx, __cIdx, _offset_17, _tmp_9);
    /* t4[i] <== t2[i]*t2[i] */
    _offset_19 = _t2_sigIdx_;
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_19, _sigValue_2, 1);
    _offset_21 = _t2_sigIdx_;
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_21, _sigValue_3, 1);
    Fr_mul(_tmp_10, _sigValue_2, _sigValue_3);
    _offset_23 = _t4_sigIdx_;
    ctx->setSignal(__cIdx, __cIdx, _offset_23, _tmp_10);
    /* if (i<nrounds-1) */
    /* xL[i] <== ((i==0) ? xR_in : xR[i-1]) + t4[i]*t */
    ctx->multiGetSignal(__cIdx, __cIdx, _xR_in_sigIdx_, _sigValue_4, 1);
    _offset_28 = _t4_sigIdx_;
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_28, _sigValue_5, 1);
    Fr_mul(_tmp_14, _sigValue_5, t);
    Fr_add(_tmp_15, _sigValue_4, _tmp_14);
    _offset_31 = _xL_sigIdx_;
    ctx->setSignal(__cIdx, __cIdx, _offset_31, _tmp_15);
    /* xR[i] <== (i==0) ? xL_in : xL[i-1] */
    ctx->multiGetSignal(__cIdx, __cIdx, _xL_in_sigIdx_, _sigValue_6, 1);
    _offset_34 = _xR_sigIdx_;
    ctx->setSignal(__cIdx, __cIdx, _offset_34, _sigValue_6);
    _loopCond = _tmp_19;
    while (Fr_isTrue(_loopCond)) {
        /* if ((i == 0) || (i == nrounds - 1)) */
        Fr_eq(_tmp_20, i, (ctx->circuit->constants + 0));
        Fr_eq(_tmp_22, i, (ctx->circuit->constants + 3));
        Fr_lor(_tmp_23, _tmp_20, _tmp_22);
        if (Fr_isTrue(_tmp_23)) {
            /* c = 0 */
            Fr_copyn(c, _num_231, 1);
        } else {
            /* c = c_partial[i - 1] */
            Fr_sub(_tmp_24, i, (ctx->circuit->constants + 1));
            _offset_44 = Fr_toInt(_tmp_24);
            _v_25 = c_partial + _offset_44;
            Fr_copyn(c, _v_25, 1);
        }
        /* t = (i==0) ? k+xL_in : k + xL[i-1] + c */
        Fr_eq(_tmp_25, i, (ctx->circuit->constants + 0));
        if (Fr_isTrue(_tmp_25)) {
            ctx->multiGetSignal(__cIdx, __cIdx, _k_sigIdx_, _sigValue_7, 1);
            ctx->multiGetSignal(__cIdx, __cIdx, _xL_in_sigIdx_, _sigValue_8, 1);
            Fr_add(_tmp_26, _sigValue_7, _sigValue_8);
            _ter = _tmp_26;
        } else {
            ctx->multiGetSignal(__cIdx, __cIdx, _k_sigIdx_, _sigValue_9, 1);
            Fr_sub(_tmp_27, i, (ctx->circuit->constants + 1));
            _offset_48 = _xL_sigIdx_ + Fr_toInt(_tmp_27)*_sigSizes_xL[1];
            ctx->multiGetSignal(__cIdx, __cIdx, _offset_48, _sigValue_10, 1);
            Fr_add(_tmp_28, _sigValue_9, _sigValue_10);
            Fr_add(_tmp_29, _tmp_28, c);
            _ter = _tmp_29;
        }
        Fr_copyn(t, _ter, 1);
        /* t2[i] <== t*t */
        Fr_mul(_tmp_30, t, t);
        _offset_54 = _t2_sigIdx_ + Fr_toInt(i)*_sigSizes_t2[1];
        ctx->setSignal(__cIdx, __cIdx, _offset_54, _tmp_30);
        /* t4[i] <== t2[i]*t2[i] */
        _offset_56 = _t2_sigIdx_ + Fr_toInt(i)*_sigSizes_t2[1];
        ctx->multiGetSignal(__cIdx, __cIdx, _offset_56, _sigValue_11, 1);
        _offset_58 = _t2_sigIdx_ + Fr_toInt(i)*_sigSizes_t2[1];
        ctx->multiGetSignal(__cIdx, __cIdx, _offset_58, _sigValue_12, 1);
        Fr_mul(_tmp_31, _sigValue_11, _sigValue_12);
        _offset_60 = _t4_sigIdx_ + Fr_toInt(i)*_sigSizes_t4[1];
        ctx->setSignal(__cIdx, __cIdx, _offset_60, _tmp_31);
        /* if (i<nrounds-1) */
        Fr_lt(_tmp_33, i, (ctx->circuit->constants + 3));
        if (Fr_isTrue(_tmp_33)) {
            /* xL[i] <== ((i==0) ? xR_in : xR[i-1]) + t4[i]*t */
            Fr_eq(_tmp_34, i, (ctx->circuit->constants + 0));
            if (Fr_isTrue(_tmp_34)) {
                ctx->multiGetSignal(__cIdx, __cIdx, _xR_in_sigIdx_, _sigValue_13, 1);
                _ter_1 = _sigValue_13;
            } else {
                Fr_sub(_tmp_35, i, (ctx->circuit->constants + 1));
                _offset_65 = _xR_sigIdx_ + Fr_toInt(_tmp_35)*_sigSizes_xR[1];
                ctx->multiGetSignal(__cIdx, __cIdx, _offset_65, _sigValue_14, 1);
                _ter_1 = _sigValue_14;
            }
            _offset_67 = _t4_sigIdx_ + Fr_toInt(i)*_sigSizes_t4[1];
            ctx->multiGetSignal(__cIdx, __cIdx, _offset_67, _sigValue_15, 1);
            Fr_mul(_tmp_36, _sigValue_15, t);
            Fr_add(_tmp_37, _ter_1, _tmp_36);
            _offset_70 = _xL_sigIdx_ + Fr_toInt(i)*_sigSizes_xL[1];
            ctx->setSignal(__cIdx, __cIdx, _offset_70, _tmp_37);
            /* xR[i] <== (i==0) ? xL_in : xL[i-1] */
            Fr_eq(_tmp_38, i, (ctx->circuit->constants + 0));
            if (Fr_isTrue(_tmp_38)) {
                ctx->multiGetSignal(__cIdx, __cIdx, _xL_in_sigIdx_, _sigValue_16, 1);
                _ter_2 = _sigValue_16;
            } else {
                Fr_sub(_tmp_39, i, (ctx->circuit->constants + 1));
                _offset_73 = _xL_sigIdx_ + Fr_toInt(_tmp_39)*_sigSizes_xL[1];
                ctx->multiGetSignal(__cIdx, __cIdx, _offset_73, _sigValue_17, 1);
                _ter_2 = _sigValue_17;
            }
            _offset_75 = _xR_sigIdx_ + Fr_toInt(i)*_sigSizes_xR[1];
            ctx->setSignal(__cIdx, __cIdx, _offset_75, _ter_2);
        } else {
            /* xR_out <== xR[i-1] + t4[i]*t */
            Fr_sub(_tmp_40, i, (ctx->circuit->constants + 1));
            _offset_77 = _xR_sigIdx_ + Fr_toInt(_tmp_40)*_sigSizes_xR[1];
            ctx->multiGetSignal(__cIdx, __cIdx, _offset_77, _sigValue_18, 1);
            _offset_79 = _t4_sigIdx_ + Fr_toInt(i)*_sigSizes_t4[1];
            ctx->multiGetSignal(__cIdx, __cIdx, _offset_79, _sigValue_19, 1);
            Fr_mul(_tmp_41, _sigValue_19, t);
            Fr_add(_tmp_42, _sigValue_18, _tmp_41);
            ctx->setSignal(__cIdx, __cIdx, _xR_out_sigIdx_, _tmp_42);
            /* xL_out <== xL[i-1] */
            Fr_sub(_tmp_43, i, (ctx->circuit->constants + 1));
            _offset_82 = _xL_sigIdx_ + Fr_toInt(_tmp_43)*_sigSizes_xL[1];
            ctx->multiGetSignal(__cIdx, __cIdx, _offset_82, _sigValue_20, 1);
            ctx->setSignal(__cIdx, __cIdx, _xL_out_sigIdx_, _sigValue_20);
        }
        Fr_copyn(_tmp_45, i, 1);
        Fr_add(_tmp_44, i, (ctx->circuit->constants + 1));
        Fr_copyn(i, _tmp_44, 1);
        Fr_lt(_tmp_46, i, (ctx->circuit->constants + 222));
        _loopCond = _tmp_46;
    }
    ctx->finished(__cIdx);
}
/*
MiMCFeistel
nrounds=220
*/
void MiMCFeistel_44ce17afd3121bdf(Circom_CalcWit *ctx, int __cIdx) {
    FrElement _sigValue[1];
    FrElement _sigValue_1[1];
    FrElement _tmp_8[1];
    FrElement t[1];
    FrElement _tmp_9[1];
    FrElement _sigValue_2[1];
    FrElement _sigValue_3[1];
    FrElement _tmp_10[1];
    FrElement _sigValue_4[1];
    FrElement _sigValue_5[1];
    FrElement _tmp_14[1];
    FrElement _tmp_15[1];
    FrElement _sigValue_6[1];
    FrElement _tmp_19[1];
    FrElement i[1];
    FrElement c[1];
    FrElement _tmp_20[1];
    FrElement _tmp_22[1];
    FrElement _tmp_23[1];
    FrElement _num_231[1];
    FrElement _tmp_24[1];
    FrElement c_partial[218];
    FrElement _tmp_25[1];
    FrElement _sigValue_7[1];
    FrElement _sigValue_8[1];
    FrElement _tmp_26[1];
    FrElement _sigValue_9[1];
    FrElement _tmp_27[1];
    FrElement _sigValue_10[1];
    FrElement _tmp_28[1];
    FrElement _tmp_29[1];
    FrElement _tmp_30[1];
    FrElement _sigValue_11[1];
    FrElement _sigValue_12[1];
    FrElement _tmp_31[1];
    FrElement _tmp_33[1];
    FrElement _tmp_34[1];
    FrElement _sigValue_13[1];
    FrElement _tmp_35[1];
    FrElement _sigValue_14[1];
    FrElement _sigValue_15[1];
    FrElement _tmp_36[1];
    FrElement _tmp_37[1];
    FrElement _tmp_38[1];
    FrElement _sigValue_16[1];
    FrElement _tmp_39[1];
    FrElement _sigValue_17[1];
    FrElement _tmp_40[1];
    FrElement _sigValue_18[1];
    FrElement _sigValue_19[1];
    FrElement _tmp_41[1];
    FrElement _tmp_42[1];
    FrElement _tmp_43[1];
    FrElement _sigValue_20[1];
    FrElement _tmp_45[1];
    FrElement _tmp_44[1];
    FrElement _tmp_46[1];
    int _k_sigIdx_;
    int _xL_in_sigIdx_;
    int _t2_sigIdx_;
    int _offset_17;
    int _offset_19;
    int _offset_21;
    int _t4_sigIdx_;
    int _offset_23;
    int _xR_in_sigIdx_;
    int _offset_28;
    int _xL_sigIdx_;
    int _offset_31;
    int _xR_sigIdx_;
    int _offset_34;
    int _offset_44;
    int _offset_48;
    int _offset_54;
    int _offset_56;
    int _offset_58;
    int _offset_60;
    int _offset_65;
    int _offset_67;
    int _offset_70;
    int _offset_73;
    int _offset_75;
    int _offset_77;
    int _offset_79;
    int _xR_out_sigIdx_;
    int _offset_82;
    int _xL_out_sigIdx_;
    Circom_Sizes _sigSizes_t2;
    Circom_Sizes _sigSizes_t4;
    Circom_Sizes _sigSizes_xL;
    Circom_Sizes _sigSizes_xR;
    PFrElement _loopCond;
    PFrElement _v_25;
    PFrElement _ter;
    PFrElement _ter_1;
    PFrElement _ter_2;
    Fr_copy(&(_tmp_19[0]), ctx->circuit->constants +1);
    Fr_copy(&(i[0]), ctx->circuit->constants +1);
    Fr_copy(&(c[0]), ctx->circuit->constants +0);
    Fr_copy(&(_num_231[0]), ctx->circuit->constants +0);
    Fr_copy(&(c_partial[0]), ctx->circuit->constants +4);
    Fr_copy(&(c_partial[1]), ctx->circuit->constants +5);
    Fr_copy(&(c_partial[2]), ctx->circuit->constants +6);
    Fr_copy(&(c_partial[3]), ctx->circuit->constants +7);
    Fr_copy(&(c_partial[4]), ctx->circuit->constants +8);
    Fr_copy(&(c_partial[5]), ctx->circuit->constants +9);
    Fr_copy(&(c_partial[6]), ctx->circuit->constants +10);
    Fr_copy(&(c_partial[7]), ctx->circuit->constants +11);
    Fr_copy(&(c_partial[8]), ctx->circuit->constants +12);
    Fr_copy(&(c_partial[9]), ctx->circuit->constants +13);
    Fr_copy(&(c_partial[10]), ctx->circuit->constants +14);
    Fr_copy(&(c_partial[11]), ctx->circuit->constants +15);
    Fr_copy(&(c_partial[12]), ctx->circuit->constants +16);
    Fr_copy(&(c_partial[13]), ctx->circuit->constants +17);
    Fr_copy(&(c_partial[14]), ctx->circuit->constants +18);
    Fr_copy(&(c_partial[15]), ctx->circuit->constants +19);
    Fr_copy(&(c_partial[16]), ctx->circuit->constants +20);
    Fr_copy(&(c_partial[17]), ctx->circuit->constants +21);
    Fr_copy(&(c_partial[18]), ctx->circuit->constants +22);
    Fr_copy(&(c_partial[19]), ctx->circuit->constants +23);
    Fr_copy(&(c_partial[20]), ctx->circuit->constants +24);
    Fr_copy(&(c_partial[21]), ctx->circuit->constants +25);
    Fr_copy(&(c_partial[22]), ctx->circuit->constants +26);
    Fr_copy(&(c_partial[23]), ctx->circuit->constants +27);
    Fr_copy(&(c_partial[24]), ctx->circuit->constants +28);
    Fr_copy(&(c_partial[25]), ctx->circuit->constants +29);
    Fr_copy(&(c_partial[26]), ctx->circuit->constants +30);
    Fr_copy(&(c_partial[27]), ctx->circuit->constants +31);
    Fr_copy(&(c_partial[28]), ctx->circuit->constants +32);
    Fr_copy(&(c_partial[29]), ctx->circuit->constants +33);
    Fr_copy(&(c_partial[30]), ctx->circuit->constants +34);
    Fr_copy(&(c_partial[31]), ctx->circuit->constants +35);
    Fr_copy(&(c_partial[32]), ctx->circuit->constants +36);
    Fr_copy(&(c_partial[33]), ctx->circuit->constants +37);
    Fr_copy(&(c_partial[34]), ctx->circuit->constants +38);
    Fr_copy(&(c_partial[35]), ctx->circuit->constants +39);
    Fr_copy(&(c_partial[36]), ctx->circuit->constants +40);
    Fr_copy(&(c_partial[37]), ctx->circuit->constants +41);
    Fr_copy(&(c_partial[38]), ctx->circuit->constants +42);
    Fr_copy(&(c_partial[39]), ctx->circuit->constants +43);
    Fr_copy(&(c_partial[40]), ctx->circuit->constants +44);
    Fr_copy(&(c_partial[41]), ctx->circuit->constants +45);
    Fr_copy(&(c_partial[42]), ctx->circuit->constants +46);
    Fr_copy(&(c_partial[43]), ctx->circuit->constants +47);
    Fr_copy(&(c_partial[44]), ctx->circuit->constants +48);
    Fr_copy(&(c_partial[45]), ctx->circuit->constants +49);
    Fr_copy(&(c_partial[46]), ctx->circuit->constants +50);
    Fr_copy(&(c_partial[47]), ctx->circuit->constants +51);
    Fr_copy(&(c_partial[48]), ctx->circuit->constants +52);
    Fr_copy(&(c_partial[49]), ctx->circuit->constants +53);
    Fr_copy(&(c_partial[50]), ctx->circuit->constants +54);
    Fr_copy(&(c_partial[51]), ctx->circuit->constants +55);
    Fr_copy(&(c_partial[52]), ctx->circuit->constants +56);
    Fr_copy(&(c_partial[53]), ctx->circuit->constants +57);
    Fr_copy(&(c_partial[54]), ctx->circuit->constants +58);
    Fr_copy(&(c_partial[55]), ctx->circuit->constants +59);
    Fr_copy(&(c_partial[56]), ctx->circuit->constants +60);
    Fr_copy(&(c_partial[57]), ctx->circuit->constants +61);
    Fr_copy(&(c_partial[58]), ctx->circuit->constants +62);
    Fr_copy(&(c_partial[59]), ctx->circuit->constants +63);
    Fr_copy(&(c_partial[60]), ctx->circuit->constants +64);
    Fr_copy(&(c_partial[61]), ctx->circuit->constants +65);
    Fr_copy(&(c_partial[62]), ctx->circuit->constants +66);
    Fr_copy(&(c_partial[63]), ctx->circuit->constants +67);
    Fr_copy(&(c_partial[64]), ctx->circuit->constants +68);
    Fr_copy(&(c_partial[65]), ctx->circuit->constants +69);
    Fr_copy(&(c_partial[66]), ctx->circuit->constants +70);
    Fr_copy(&(c_partial[67]), ctx->circuit->constants +71);
    Fr_copy(&(c_partial[68]), ctx->circuit->constants +72);
    Fr_copy(&(c_partial[69]), ctx->circuit->constants +73);
    Fr_copy(&(c_partial[70]), ctx->circuit->constants +74);
    Fr_copy(&(c_partial[71]), ctx->circuit->constants +75);
    Fr_copy(&(c_partial[72]), ctx->circuit->constants +76);
    Fr_copy(&(c_partial[73]), ctx->circuit->constants +77);
    Fr_copy(&(c_partial[74]), ctx->circuit->constants +78);
    Fr_copy(&(c_partial[75]), ctx->circuit->constants +79);
    Fr_copy(&(c_partial[76]), ctx->circuit->constants +80);
    Fr_copy(&(c_partial[77]), ctx->circuit->constants +81);
    Fr_copy(&(c_partial[78]), ctx->circuit->constants +82);
    Fr_copy(&(c_partial[79]), ctx->circuit->constants +83);
    Fr_copy(&(c_partial[80]), ctx->circuit->constants +84);
    Fr_copy(&(c_partial[81]), ctx->circuit->constants +85);
    Fr_copy(&(c_partial[82]), ctx->circuit->constants +86);
    Fr_copy(&(c_partial[83]), ctx->circuit->constants +87);
    Fr_copy(&(c_partial[84]), ctx->circuit->constants +88);
    Fr_copy(&(c_partial[85]), ctx->circuit->constants +89);
    Fr_copy(&(c_partial[86]), ctx->circuit->constants +90);
    Fr_copy(&(c_partial[87]), ctx->circuit->constants +91);
    Fr_copy(&(c_partial[88]), ctx->circuit->constants +92);
    Fr_copy(&(c_partial[89]), ctx->circuit->constants +93);
    Fr_copy(&(c_partial[90]), ctx->circuit->constants +94);
    Fr_copy(&(c_partial[91]), ctx->circuit->constants +95);
    Fr_copy(&(c_partial[92]), ctx->circuit->constants +96);
    Fr_copy(&(c_partial[93]), ctx->circuit->constants +97);
    Fr_copy(&(c_partial[94]), ctx->circuit->constants +98);
    Fr_copy(&(c_partial[95]), ctx->circuit->constants +99);
    Fr_copy(&(c_partial[96]), ctx->circuit->constants +100);
    Fr_copy(&(c_partial[97]), ctx->circuit->constants +101);
    Fr_copy(&(c_partial[98]), ctx->circuit->constants +102);
    Fr_copy(&(c_partial[99]), ctx->circuit->constants +103);
    Fr_copy(&(c_partial[100]), ctx->circuit->constants +104);
    Fr_copy(&(c_partial[101]), ctx->circuit->constants +105);
    Fr_copy(&(c_partial[102]), ctx->circuit->constants +106);
    Fr_copy(&(c_partial[103]), ctx->circuit->constants +107);
    Fr_copy(&(c_partial[104]), ctx->circuit->constants +108);
    Fr_copy(&(c_partial[105]), ctx->circuit->constants +109);
    Fr_copy(&(c_partial[106]), ctx->circuit->constants +110);
    Fr_copy(&(c_partial[107]), ctx->circuit->constants +111);
    Fr_copy(&(c_partial[108]), ctx->circuit->constants +112);
    Fr_copy(&(c_partial[109]), ctx->circuit->constants +113);
    Fr_copy(&(c_partial[110]), ctx->circuit->constants +114);
    Fr_copy(&(c_partial[111]), ctx->circuit->constants +115);
    Fr_copy(&(c_partial[112]), ctx->circuit->constants +116);
    Fr_copy(&(c_partial[113]), ctx->circuit->constants +117);
    Fr_copy(&(c_partial[114]), ctx->circuit->constants +118);
    Fr_copy(&(c_partial[115]), ctx->circuit->constants +119);
    Fr_copy(&(c_partial[116]), ctx->circuit->constants +120);
    Fr_copy(&(c_partial[117]), ctx->circuit->constants +121);
    Fr_copy(&(c_partial[118]), ctx->circuit->constants +122);
    Fr_copy(&(c_partial[119]), ctx->circuit->constants +123);
    Fr_copy(&(c_partial[120]), ctx->circuit->constants +124);
    Fr_copy(&(c_partial[121]), ctx->circuit->constants +125);
    Fr_copy(&(c_partial[122]), ctx->circuit->constants +126);
    Fr_copy(&(c_partial[123]), ctx->circuit->constants +127);
    Fr_copy(&(c_partial[124]), ctx->circuit->constants +128);
    Fr_copy(&(c_partial[125]), ctx->circuit->constants +129);
    Fr_copy(&(c_partial[126]), ctx->circuit->constants +130);
    Fr_copy(&(c_partial[127]), ctx->circuit->constants +131);
    Fr_copy(&(c_partial[128]), ctx->circuit->constants +132);
    Fr_copy(&(c_partial[129]), ctx->circuit->constants +133);
    Fr_copy(&(c_partial[130]), ctx->circuit->constants +134);
    Fr_copy(&(c_partial[131]), ctx->circuit->constants +135);
    Fr_copy(&(c_partial[132]), ctx->circuit->constants +136);
    Fr_copy(&(c_partial[133]), ctx->circuit->constants +137);
    Fr_copy(&(c_partial[134]), ctx->circuit->constants +138);
    Fr_copy(&(c_partial[135]), ctx->circuit->constants +139);
    Fr_copy(&(c_partial[136]), ctx->circuit->constants +140);
    Fr_copy(&(c_partial[137]), ctx->circuit->constants +141);
    Fr_copy(&(c_partial[138]), ctx->circuit->constants +142);
    Fr_copy(&(c_partial[139]), ctx->circuit->constants +143);
    Fr_copy(&(c_partial[140]), ctx->circuit->constants +144);
    Fr_copy(&(c_partial[141]), ctx->circuit->constants +145);
    Fr_copy(&(c_partial[142]), ctx->circuit->constants +146);
    Fr_copy(&(c_partial[143]), ctx->circuit->constants +147);
    Fr_copy(&(c_partial[144]), ctx->circuit->constants +148);
    Fr_copy(&(c_partial[145]), ctx->circuit->constants +149);
    Fr_copy(&(c_partial[146]), ctx->circuit->constants +150);
    Fr_copy(&(c_partial[147]), ctx->circuit->constants +151);
    Fr_copy(&(c_partial[148]), ctx->circuit->constants +152);
    Fr_copy(&(c_partial[149]), ctx->circuit->constants +153);
    Fr_copy(&(c_partial[150]), ctx->circuit->constants +154);
    Fr_copy(&(c_partial[151]), ctx->circuit->constants +155);
    Fr_copy(&(c_partial[152]), ctx->circuit->constants +156);
    Fr_copy(&(c_partial[153]), ctx->circuit->constants +157);
    Fr_copy(&(c_partial[154]), ctx->circuit->constants +158);
    Fr_copy(&(c_partial[155]), ctx->circuit->constants +159);
    Fr_copy(&(c_partial[156]), ctx->circuit->constants +160);
    Fr_copy(&(c_partial[157]), ctx->circuit->constants +161);
    Fr_copy(&(c_partial[158]), ctx->circuit->constants +162);
    Fr_copy(&(c_partial[159]), ctx->circuit->constants +163);
    Fr_copy(&(c_partial[160]), ctx->circuit->constants +164);
    Fr_copy(&(c_partial[161]), ctx->circuit->constants +165);
    Fr_copy(&(c_partial[162]), ctx->circuit->constants +166);
    Fr_copy(&(c_partial[163]), ctx->circuit->constants +167);
    Fr_copy(&(c_partial[164]), ctx->circuit->constants +168);
    Fr_copy(&(c_partial[165]), ctx->circuit->constants +169);
    Fr_copy(&(c_partial[166]), ctx->circuit->constants +170);
    Fr_copy(&(c_partial[167]), ctx->circuit->constants +171);
    Fr_copy(&(c_partial[168]), ctx->circuit->constants +172);
    Fr_copy(&(c_partial[169]), ctx->circuit->constants +173);
    Fr_copy(&(c_partial[170]), ctx->circuit->constants +174);
    Fr_copy(&(c_partial[171]), ctx->circuit->constants +175);
    Fr_copy(&(c_partial[172]), ctx->circuit->constants +176);
    Fr_copy(&(c_partial[173]), ctx->circuit->constants +177);
    Fr_copy(&(c_partial[174]), ctx->circuit->constants +178);
    Fr_copy(&(c_partial[175]), ctx->circuit->constants +179);
    Fr_copy(&(c_partial[176]), ctx->circuit->constants +180);
    Fr_copy(&(c_partial[177]), ctx->circuit->constants +181);
    Fr_copy(&(c_partial[178]), ctx->circuit->constants +182);
    Fr_copy(&(c_partial[179]), ctx->circuit->constants +183);
    Fr_copy(&(c_partial[180]), ctx->circuit->constants +184);
    Fr_copy(&(c_partial[181]), ctx->circuit->constants +185);
    Fr_copy(&(c_partial[182]), ctx->circuit->constants +186);
    Fr_copy(&(c_partial[183]), ctx->circuit->constants +187);
    Fr_copy(&(c_partial[184]), ctx->circuit->constants +188);
    Fr_copy(&(c_partial[185]), ctx->circuit->constants +189);
    Fr_copy(&(c_partial[186]), ctx->circuit->constants +190);
    Fr_copy(&(c_partial[187]), ctx->circuit->constants +191);
    Fr_copy(&(c_partial[188]), ctx->circuit->constants +192);
    Fr_copy(&(c_partial[189]), ctx->circuit->constants +193);
    Fr_copy(&(c_partial[190]), ctx->circuit->constants +194);
    Fr_copy(&(c_partial[191]), ctx->circuit->constants +195);
    Fr_copy(&(c_partial[192]), ctx->circuit->constants +196);
    Fr_copy(&(c_partial[193]), ctx->circuit->constants +197);
    Fr_copy(&(c_partial[194]), ctx->circuit->constants +198);
    Fr_copy(&(c_partial[195]), ctx->circuit->constants +199);
    Fr_copy(&(c_partial[196]), ctx->circuit->constants +200);
    Fr_copy(&(c_partial[197]), ctx->circuit->constants +201);
    Fr_copy(&(c_partial[198]), ctx->circuit->constants +202);
    Fr_copy(&(c_partial[199]), ctx->circuit->constants +203);
    Fr_copy(&(c_partial[200]), ctx->circuit->constants +204);
    Fr_copy(&(c_partial[201]), ctx->circuit->constants +205);
    Fr_copy(&(c_partial[202]), ctx->circuit->constants +206);
    Fr_copy(&(c_partial[203]), ctx->circuit->constants +207);
    Fr_copy(&(c_partial[204]), ctx->circuit->constants +208);
    Fr_copy(&(c_partial[205]), ctx->circuit->constants +209);
    Fr_copy(&(c_partial[206]), ctx->circuit->constants +210);
    Fr_copy(&(c_partial[207]), ctx->circuit->constants +211);
    Fr_copy(&(c_partial[208]), ctx->circuit->constants +212);
    Fr_copy(&(c_partial[209]), ctx->circuit->constants +213);
    Fr_copy(&(c_partial[210]), ctx->circuit->constants +214);
    Fr_copy(&(c_partial[211]), ctx->circuit->constants +215);
    Fr_copy(&(c_partial[212]), ctx->circuit->constants +216);
    Fr_copy(&(c_partial[213]), ctx->circuit->constants +217);
    Fr_copy(&(c_partial[214]), ctx->circuit->constants +218);
    Fr_copy(&(c_partial[215]), ctx->circuit->constants +219);
    Fr_copy(&(c_partial[216]), ctx->circuit->constants +220);
    Fr_copy(&(c_partial[217]), ctx->circuit->constants +221);
    _k_sigIdx_ = ctx->getSignalOffset(__cIdx, 0xaf63e64c8601fd8aLL /* k */);
    _xL_in_sigIdx_ = ctx->getSignalOffset(__cIdx, 0xe58d565a2c6193f5LL /* xL_in */);
    _t2_sigIdx_ = ctx->getSignalOffset(__cIdx, 0x08c7fe07b56a5c63LL /* t2 */);
    _t4_sigIdx_ = ctx->getSignalOffset(__cIdx, 0x08c80407b56a6695LL /* t4 */);
    _xR_in_sigIdx_ = ctx->getSignalOffset(__cIdx, 0x490e56ad9f02bbcfLL /* xR_in */);
    _xL_sigIdx_ = ctx->getSignalOffset(__cIdx, 0x08f11c07b58d9471LL /* xL */);
    _xR_sigIdx_ = ctx->getSignalOffset(__cIdx, 0x08f12607b58da56fLL /* xR */);
    _xR_out_sigIdx_ = ctx->getSignalOffset(__cIdx, 0x5898f4054dd4f254LL /* xR_out */);
    _xL_out_sigIdx_ = ctx->getSignalOffset(__cIdx, 0x82a9a0397420693eLL /* xL_out */);
    _sigSizes_t2 = ctx->getSignalSizes(__cIdx, 0x08c7fe07b56a5c63LL /* t2 */);
    _sigSizes_t4 = ctx->getSignalSizes(__cIdx, 0x08c80407b56a6695LL /* t4 */);
    _sigSizes_xL = ctx->getSignalSizes(__cIdx, 0x08f11c07b58d9471LL /* xL */);
    _sigSizes_xR = ctx->getSignalSizes(__cIdx, 0x08f12607b58da56fLL /* xR */);
    /* signal input xL_in */
    /* signal input xR_in */
    /* signal input k */
    /* signal output xL_out */
    /* signal output xR_out */
    /* var c_partial[218] = [
          7120861356467848435263064379192047478074060781135320967663101236819528304084,
          5024705281721889198577876690145313457398658950011302225525409148828000436681,
          17980351014018068290387269214713820287804403312720763401943303895585469787384,
          19886576439381707240399940949310933992335779767309383709787331470398675714258,
          1213715278223786725806155661738676903520350859678319590331207960381534602599,
          18162138253399958831050545255414688239130588254891200470934232514682584734511,
          7667462281466170157858259197976388676420847047604921256361474169980037581876,
          7207551498477838452286210989212982851118089401128156132319807392460388436957,
          9864183311657946807255900203841777810810224615118629957816193727554621093838,
          4798196928559910300796064665904583125427459076060519468052008159779219347957,
          17387238494588145257484818061490088963673275521250153686214197573695921400950,
          10005334761930299057035055370088813230849810566234116771751925093634136574742,
          11897542014760736209670863723231849628230383119798486487899539017466261308762,
          16771780563523793011283273687253985566177232886900511371656074413362142152543,
          749264854018824809464168489785113337925400687349357088413132714480582918506,
          3683645737503705042628598550438395339383572464204988015434959428676652575331,
          7556750851783822914673316211129907782679509728346361368978891584375551186255,
          20391289379084797414557439284689954098721219201171527383291525676334308303023,
          18146517657445423462330854383025300323335289319277199154920964274562014376193,
          8080173465267536232534446836148661251987053305394647905212781979099916615292,
          10796443006899450245502071131975731672911747129805343722228413358507805531141,
          5404287610364961067658660283245291234008692303120470305032076412056764726509,
          4623894483395123520243967718315330178025957095502546813929290333264120223168,
          16845753148201777192406958674202574751725237939980634861948953189320362207797,
          4622170486584704769521001011395820886029808520586507873417553166762370293671,
          16688277490485052681847773549197928630624828392248424077804829676011512392564,
          11878652861183667748838188993669912629573713271883125458838494308957689090959,
          2436445725746972287496138382764643208791713986676129260589667864467010129482,
          1888098689545151571063267806606510032698677328923740058080630641742325067877,
          148924106504065664829055598316821983869409581623245780505601526786791681102,
          18875020877782404439294079398043479420415331640996249745272087358069018086569,
          15189693413320228845990326214136820307649565437237093707846682797649429515840,
          19669450123472657781282985229369348220906547335081730205028099210442632534079,
          5521922218264623411380547905210139511350706092570900075727555783240701821773,
          4144769320246558352780591737261172907511489963810975650573703217887429086546,
          10097732913112662248360143041019433907849917041759137293018029019134392559350,
          1720059427972723034107765345743336447947522473310069975142483982753181038321,
          6302388219880227251325608388535181451187131054211388356563634768253301290116,
          6745410632962119604799318394592010194450845483518862700079921360015766217097,
          10858157235265583624235850660462324469799552996870780238992046963007491306222,
          20241898894740093733047052816576694435372877719072347814065227797906130857593,
          10165780782761211520836029617746977303303335603838343292431760011576528327409,
          2832093654883670345969792724123161241696170611611744759675180839473215203706,
          153011722355526826233082383360057587249818749719433916258246100068258954737,
          20196970640587451358539129330170636295243141659030208529338914906436009086943,
          3180973917010545328313139835982464870638521890385603025657430208141494469656,
          17198004293191777441573635123110935015228014028618868252989374962722329283022,
          7642160509228669138628515458941659189680509753651629476399516332224325757132,
          19346204940546791021518535594447257347218878114049998691060016493806845179755,
          11501810868606870391127866188394535330696206817602260610801897042898616817272,
          3113973447392053821824427670386252797811804954746053461397972968381571297505,
          6545064306297957002139416752334741502722251869537551068239642131448768236585,
          5203908808704813498389265425172875593837960384349653691918590736979872578408,
          2246692432011290582160062129070762007374502637007107318105405626910313810224,
          11760570435432189127645691249600821064883781677693087773459065574359292849137,
          5543749482491340532547407723464609328207990784853381797689466144924198391839,
          8837549193990558762776520822018694066937602576881497343584903902880277769302,
          12855514863299373699594410385788943772765811961581749194183533625311486462501,
          5363660674689121676875069134269386492382220935599781121306637800261912519729,
          13162342403579303950549728848130828093497701266240457479693991108217307949435,
          916941639326869583414469202910306428966657806899788970948781207501251816730,
          15618589556584434434009868216186115416835494805174158488636000580759692174228,
          8959562060028569701043973060670353733575345393653685776974948916988033453971,
          16390754464333401712265575949874369157699293840516802426621216808905079127650,
          168282396747788514908709091757591226095443902501365500003618183905496160435,
          8327443473179334761744301768309008451162322941906921742120510244986704677004,
          17213012626801210615058753489149961717422101711567228037597150941152495100640,
          10394369641533736715250242399198097296122982486516256408681925424076248952280,
          17784386835392322654196171115293700800825771210400152504776806618892170162248,
          16533189939837087893364000390641148516479148564190420358849587959161226782982,
          18725396114211370207078434315900726338547621160475533496863298091023511945076,
          7132325028834551397904855671244375895110341505383911719294705267624034122405,
          148317947440800089795933930720822493695520852448386394775371401743494965187,
          19001050671757720352890779127693793630251266879994702723636759889378387053056,
          18824274411769830274877839365728651108434404855803844568234862945613766611460,
          12771414330193951156383998390424063470766226667986423961689712557338777174205,
          11332046574800279729678603488745295198038913503395629790213378101166488244657,
          9607550223176946388146938069307456967842408600269548190739947540821716354749,
          8756385288462344550200229174435953103162307705310807828651304665320046782583,
          176061952957067086877570020242717222844908281373122372938833890096257042779,
          12200212977482648306758992405065921724409841940671166017620928947866825250857,
          10868453624107875516866146499877130701929063632959660262366632833504750028858,
          2016095394399807253596787752134573207202567875457560571095586743878953450738,
          21815578223768330433802113452339488275704145896544481092014911825656390567514,
          4923772847693564777744725640710197015181591950368494148029046443433103381621,
          1813584943682214789802230765734821149202472893379265320098816901270224589984,
          10810123816265612772922113403831964815724109728287572256602010709288980656498,
          1153669123397255702524721206511185557982017410156956216465120456256288427021,
          5007518659266430200134478928344522649876467369278722765097865662497773767152,
          2511432546938591792036639990606464315121646668029252285288323664350666551637,
          32883284540320451295484135704808083452381176816565850047310272290579727564,
          10484856914279112612610993418405543310546746652738541161791501150994088679557,
          2026733759645519472558796412979210009170379159866522399881566309631434814953,
          14731806221235869882801331463708736361296174006732553130708107037190460654379,
          14740327483193277147065845135561988641238516852487657117813536909482068950652,
          18787428285295558781869865751953016580493190547148386433580291216673009884554,
          3804047064713122820157099453648459188816376755739202017447862327783289895072,
          16709604795697901641948603019242067672006293290826991671766611326262532802914,
          11061717085931490100602849654034280576915102867237101935487893025907907250695,
          2821730726367472966906149684046356272806484545281639696873240305052362149654,
          17467794879902895769410571945152708684493991588672014763135370927880883292655,
          1571520786233540988201616650622796363168031165456869481368085474420849243232,
          10041051776251223165849354194892664881051125330236567356945669006147134614302,
          3981753758468103976812813304477670033098707002886030847251581853700311567551,
          4365864398105436789177703571412645548020537580493599380018290523813331678900,
          2391801327305361293476178683853802679507598622000359948432171562543560193350,
          214219368547551689972421167733597094823289857206402800635962137077096090722,
          18192064100315141084242006659317257023098826945893371479835220462302399655674,
          15487549757142039139328911515400805508248576685795694919457041092150651939253,
          10142447197759703415402259672441315777933858467700579946665223821199077641122,
          11246573086260753259993971254725613211193686683988426513880826148090811891866,
          6574066859860991369704567902211886840188702386542112593710271426704432301235,
          11311085442652291634822798307831431035776248927202286895207125867542470350078,
          20977948360215259915441258687649465618185769343138135384346964466965010873779,
          792781492853909872425531014397300057232399608769451037135936617996830018501,
          5027602491523497423798779154966735896562099398367163998686335127580757861872,
          14595204575654316237672764823862241845410365278802914304953002937313300553572,
          13973538843621261113924259058427434053808430378163734641175100160836376897004,
          16395063164993626722686882727042150241125309409717445381854913964674649318585,
          8465768840047024550750516678171433288207841931251654898809033371655109266663,
          21345603324471810861925019445720576814602636473739003852898308205213912255830,
          21171984405852590343970239018692870799717057961108910523876770029017785940991,
          10761027113757988230637066281488532903174559953630210849190212601991063767647,
          6678298831065390834922566306988418588227382406175769592902974103663687992230,
          4993662582188632374202316265508850988596880036291765531885657575099537176757,
          18364168158495573675698600238443218434246806358811328083953887470513967121206,
          3506345610354615013737144848471391553141006285964325596214723571988011984829,
          248732676202643792226973868626360612151424823368345645514532870586234380100,
          10090204501612803176317709245679152331057882187411777688746797044706063410969,
          21297149835078365363970699581821844234354988617890041296044775371855432973500,
          16729368143229828574342820060716366330476985824952922184463387490091156065099,
          4467191506765339364971058668792642195242197133011672559453028147641428433293,
          8677548159358013363291014307402600830078662555833653517843708051504582990832,
          1022951765127126818581466247360193856197472064872288389992480993218645055345,
          1888195070251580606973417065636430294417895423429240431595054184472931224452,
          4221265384902749246920810956363310125115516771964522748896154428740238579824,
          2825393571154632139467378429077438870179957021959813965940638905853993971879,
          19171031072692942278056619599721228021635671304612437350119663236604712493093,
          10780807212297131186617505517708903709488273075252405602261683478333331220733,
          18230936781133176044598070768084230333433368654744509969087239465125979720995,
          16901065971871379877929280081392692752968612240624985552337779093292740763381,
          146494141603558321291767829522948454429758543710648402457451799015963102253,
          2492729278659146790410698334997955258248120870028541691998279257260289595548,
          2204224910006646535594933495262085193210692406133533679934843341237521233504,
          16062117410185840274616925297332331018523844434907012275592638570193234893570,
          5894928453677122829055071981254202951712129328678534592916926069506935491729,
          4947482739415078212217504789923078546034438919537985740403824517728200332286,
          16143265650645676880461646123844627780378251900510645261875867423498913438066,
          397690828254561723549349897112473766901585444153303054845160673059519614409,
          11272653598912269895509621181205395118899451234151664604248382803490621227687,
          15566927854306879444693061574322104423426072650522411176731130806720753591030,
          14222898219492484180162096141564251903058269177856173968147960855133048449557,
          16690275395485630428127725067513114066329712673106153451801968992299636791385,
          3667030990325966886479548860429670833692690972701471494757671819017808678584,
          21280039024501430842616328642522421302481259067470872421086939673482530783142,
          15895485136902450169492923978042129726601461603404514670348703312850236146328,
          7733050956302327984762132317027414325566202380840692458138724610131603812560,
          438123800976401478772659663183448617575635636575786782566035096946820525816,
          814913922521637742587885320797606426167962526342166512693085292151314976633,
          12368712287081330853637674140264759478736012797026621876924395982504369598764,
          2494806857395134874309386694756263421445039103814920780777601708371037591569,
          16101132301514338989512946061786320637179843435886825102406248183507106312877,
          6252650284989960032925831409804233477770646333900692286731621844532438095656,
          9277135875276787021836189566799935097400042171346561246305113339462708861695,
          10493603554686607050979497281838644324893776154179810893893660722522945589063,
          8673089750662709235894359384294076697329948991010184356091130382437645649279,
          9558393272910366944245875920138649617479779893610128634419086981339060613250,
          19012287860122586147374214541764572282814469237161122489573881644994964647218,
          9783723818270121678386992630754842961728702994964214799008457449989291229500,
          15550788416669474113213749561488122552422887538676036667630838378023479382689,
          15016165746156232864069722572047169071786333815661109750860165034341572904221,
          6506225705710197163670556961299945987488979904603689017479840649664564978574,
          10796631184889302076168355684722130903785890709107732067446714470783437829037,
          19871836214837460419845806980869387567383718044439891735114283113359312279540,
          20871081766843466343749609089986071784031203517506781251203251608363835140622,
          5100105771517691442278432864090229416166996183792075307747582375962855820797,
          8777887112076272395250620301071581171386440850451972412060638225741125310886,
          5300440870136391278944213332144327695659161151625757537632832724102670898756,
          1205448543652932944633962232545707633928124666868453915721030884663332604536,
          5542499997310181530432302492142574333860449305424174466698068685590909336771,
          11028094245762332275225364962905938096659249161369092798505554939952525894293,
          19187314764836593118404597958543112407224947638377479622725713735224279297009,
          17047263688548829001253658727764731047114098556534482052135734487985276987385,
          19914849528178967155534624144358541535306360577227460456855821557421213606310,
          2929658084700714257515872921366736697080475676508114973627124569375444665664,
          15092262360719700162343163278648422751610766427236295023221516498310468956361,
          21578580340755653236050830649990190843552802306886938815497471545814130084980,
          1258781501221760320019859066036073675029057285507345332959539295621677296991,
          3819598418157732134449049289585680301176983019643974929528867686268702720163,
          8653175945487997845203439345797943132543211416447757110963967501177317426221,
          6614652990340435611114076169697104582524566019034036680161902142028967568142,
          19212515502973904821995111796203064175854996071497099383090983975618035391558,
          18664315914479294273286016871365663486061896605232511201418576829062292269769,
          11498264615058604317482574216318586415670903094838791165247179252175768794889,
          10814026414212439999107945133852431304483604215416531759535467355316227331774,
          17566185590731088197064706533119299946752127014428399631467913813769853431107,
          14016139747289624978792446847000951708158212463304817001882956166752906714332,
          8242601581342441750402731523736202888792436665415852106196418942315563860366,
          9244680976345080074252591214216060854998619670381671198295645618515047080988,
          12216779172735125538689875667307129262237123728082657485828359100719208190116,
          10702811721859145441471328511968332847175733707711670171718794132331147396634,
          6479667912792222539919362076122453947926362746906450079329453150607427372979,
          15117544653571553820496948522381772148324367479772362833334593000535648316185,
          6842203153996907264167856337497139692895299874139131328642472698663046726780,
          12732823292801537626009139514048596316076834307941224506504666470961250728055,
          6936272626871035740815028148058841877090860312517423346335878088297448888663,
          17297554111853491139852678417579991271009602631577069694853813331124433680030,
          16641596134749940573104316021365063031319260205559553673368334842484345864859,
          7400481189785154329569470986896455371037813715804007747228648863919991399081,
          2273205422216987330510475127669563545720586464429614439716564154166712854048,
          15162538063742142685306302282127534305212832649282186184583465569986719234456,
          5628039096440332922248578319648483863204530861778160259559031331287721255522,
          16085392195894691829567913404182676871326863890140775376809129785155092531260,
          14227467863135365427954093998621993651369686288941275436795622973781503444257,
          18224457394066545825553407391290108485121649197258948320896164404518684305122,
          274945154732293792784580363548970818611304339008964723447672490026510689427,
          11050822248291117548220126630860474473945266276626263036056336623671308219529,
          2119542016932434047340813757208803962484943912710204325088879681995922344971
        ] */
    /* var t */
    /* signal t2[nrounds] */
    /* signal t4[nrounds] */
    /* signal xL[nrounds-1] */
    /* signal xR[nrounds-1] */
    /* var c */
    /* for (var i=0;i<nrounds;i++) */
    /* if ((i == 0) || (i == nrounds - 1)) */
    /* c = 0 */
    /* t = (i==0) ? k+xL_in : k + xL[i-1] + c */
    ctx->multiGetSignal(__cIdx, __cIdx, _k_sigIdx_, _sigValue, 1);
    ctx->multiGetSignal(__cIdx, __cIdx, _xL_in_sigIdx_, _sigValue_1, 1);
    Fr_add(_tmp_8, _sigValue, _sigValue_1);
    Fr_copyn(t, _tmp_8, 1);
    /* t2[i] <== t*t */
    Fr_mul(_tmp_9, t, t);
    _offset_17 = _t2_sigIdx_;
    ctx->setSignal(__cIdx, __cIdx, _offset_17, _tmp_9);
    /* t4[i] <== t2[i]*t2[i] */
    _offset_19 = _t2_sigIdx_;
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_19, _sigValue_2, 1);
    _offset_21 = _t2_sigIdx_;
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_21, _sigValue_3, 1);
    Fr_mul(_tmp_10, _sigValue_2, _sigValue_3);
    _offset_23 = _t4_sigIdx_;
    ctx->setSignal(__cIdx, __cIdx, _offset_23, _tmp_10);
    /* if (i<nrounds-1) */
    /* xL[i] <== ((i==0) ? xR_in : xR[i-1]) + t4[i]*t */
    ctx->multiGetSignal(__cIdx, __cIdx, _xR_in_sigIdx_, _sigValue_4, 1);
    _offset_28 = _t4_sigIdx_;
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_28, _sigValue_5, 1);
    Fr_mul(_tmp_14, _sigValue_5, t);
    Fr_add(_tmp_15, _sigValue_4, _tmp_14);
    _offset_31 = _xL_sigIdx_;
    ctx->setSignal(__cIdx, __cIdx, _offset_31, _tmp_15);
    /* xR[i] <== (i==0) ? xL_in : xL[i-1] */
    ctx->multiGetSignal(__cIdx, __cIdx, _xL_in_sigIdx_, _sigValue_6, 1);
    _offset_34 = _xR_sigIdx_;
    ctx->setSignal(__cIdx, __cIdx, _offset_34, _sigValue_6);
    _loopCond = _tmp_19;
    while (Fr_isTrue(_loopCond)) {
        /* if ((i == 0) || (i == nrounds - 1)) */
        Fr_eq(_tmp_20, i, (ctx->circuit->constants + 0));
        Fr_eq(_tmp_22, i, (ctx->circuit->constants + 3));
        Fr_lor(_tmp_23, _tmp_20, _tmp_22);
        if (Fr_isTrue(_tmp_23)) {
            /* c = 0 */
            Fr_copyn(c, _num_231, 1);
        } else {
            /* c = c_partial[i - 1] */
            Fr_sub(_tmp_24, i, (ctx->circuit->constants + 1));
            _offset_44 = Fr_toInt(_tmp_24);
            _v_25 = c_partial + _offset_44;
            Fr_copyn(c, _v_25, 1);
        }
        /* t = (i==0) ? k+xL_in : k + xL[i-1] + c */
        Fr_eq(_tmp_25, i, (ctx->circuit->constants + 0));
        if (Fr_isTrue(_tmp_25)) {
            ctx->multiGetSignal(__cIdx, __cIdx, _k_sigIdx_, _sigValue_7, 1);
            ctx->multiGetSignal(__cIdx, __cIdx, _xL_in_sigIdx_, _sigValue_8, 1);
            Fr_add(_tmp_26, _sigValue_7, _sigValue_8);
            _ter = _tmp_26;
        } else {
            ctx->multiGetSignal(__cIdx, __cIdx, _k_sigIdx_, _sigValue_9, 1);
            Fr_sub(_tmp_27, i, (ctx->circuit->constants + 1));
            _offset_48 = _xL_sigIdx_ + Fr_toInt(_tmp_27)*_sigSizes_xL[1];
            ctx->multiGetSignal(__cIdx, __cIdx, _offset_48, _sigValue_10, 1);
            Fr_add(_tmp_28, _sigValue_9, _sigValue_10);
            Fr_add(_tmp_29, _tmp_28, c);
            _ter = _tmp_29;
        }
        Fr_copyn(t, _ter, 1);
        /* t2[i] <== t*t */
        Fr_mul(_tmp_30, t, t);
        _offset_54 = _t2_sigIdx_ + Fr_toInt(i)*_sigSizes_t2[1];
        ctx->setSignal(__cIdx, __cIdx, _offset_54, _tmp_30);
        /* t4[i] <== t2[i]*t2[i] */
        _offset_56 = _t2_sigIdx_ + Fr_toInt(i)*_sigSizes_t2[1];
        ctx->multiGetSignal(__cIdx, __cIdx, _offset_56, _sigValue_11, 1);
        _offset_58 = _t2_sigIdx_ + Fr_toInt(i)*_sigSizes_t2[1];
        ctx->multiGetSignal(__cIdx, __cIdx, _offset_58, _sigValue_12, 1);
        Fr_mul(_tmp_31, _sigValue_11, _sigValue_12);
        _offset_60 = _t4_sigIdx_ + Fr_toInt(i)*_sigSizes_t4[1];
        ctx->setSignal(__cIdx, __cIdx, _offset_60, _tmp_31);
        /* if (i<nrounds-1) */
        Fr_lt(_tmp_33, i, (ctx->circuit->constants + 3));
        if (Fr_isTrue(_tmp_33)) {
            /* xL[i] <== ((i==0) ? xR_in : xR[i-1]) + t4[i]*t */
            Fr_eq(_tmp_34, i, (ctx->circuit->constants + 0));
            if (Fr_isTrue(_tmp_34)) {
                ctx->multiGetSignal(__cIdx, __cIdx, _xR_in_sigIdx_, _sigValue_13, 1);
                _ter_1 = _sigValue_13;
            } else {
                Fr_sub(_tmp_35, i, (ctx->circuit->constants + 1));
                _offset_65 = _xR_sigIdx_ + Fr_toInt(_tmp_35)*_sigSizes_xR[1];
                ctx->multiGetSignal(__cIdx, __cIdx, _offset_65, _sigValue_14, 1);
                _ter_1 = _sigValue_14;
            }
            _offset_67 = _t4_sigIdx_ + Fr_toInt(i)*_sigSizes_t4[1];
            ctx->multiGetSignal(__cIdx, __cIdx, _offset_67, _sigValue_15, 1);
            Fr_mul(_tmp_36, _sigValue_15, t);
            Fr_add(_tmp_37, _ter_1, _tmp_36);
            _offset_70 = _xL_sigIdx_ + Fr_toInt(i)*_sigSizes_xL[1];
            ctx->setSignal(__cIdx, __cIdx, _offset_70, _tmp_37);
            /* xR[i] <== (i==0) ? xL_in : xL[i-1] */
            Fr_eq(_tmp_38, i, (ctx->circuit->constants + 0));
            if (Fr_isTrue(_tmp_38)) {
                ctx->multiGetSignal(__cIdx, __cIdx, _xL_in_sigIdx_, _sigValue_16, 1);
                _ter_2 = _sigValue_16;
            } else {
                Fr_sub(_tmp_39, i, (ctx->circuit->constants + 1));
                _offset_73 = _xL_sigIdx_ + Fr_toInt(_tmp_39)*_sigSizes_xL[1];
                ctx->multiGetSignal(__cIdx, __cIdx, _offset_73, _sigValue_17, 1);
                _ter_2 = _sigValue_17;
            }
            _offset_75 = _xR_sigIdx_ + Fr_toInt(i)*_sigSizes_xR[1];
            ctx->setSignal(__cIdx, __cIdx, _offset_75, _ter_2);
        } else {
            /* xR_out <== xR[i-1] + t4[i]*t */
            Fr_sub(_tmp_40, i, (ctx->circuit->constants + 1));
            _offset_77 = _xR_sigIdx_ + Fr_toInt(_tmp_40)*_sigSizes_xR[1];
            ctx->multiGetSignal(__cIdx, __cIdx, _offset_77, _sigValue_18, 1);
            _offset_79 = _t4_sigIdx_ + Fr_toInt(i)*_sigSizes_t4[1];
            ctx->multiGetSignal(__cIdx, __cIdx, _offset_79, _sigValue_19, 1);
            Fr_mul(_tmp_41, _sigValue_19, t);
            Fr_add(_tmp_42, _sigValue_18, _tmp_41);
            ctx->setSignal(__cIdx, __cIdx, _xR_out_sigIdx_, _tmp_42);
            /* xL_out <== xL[i-1] */
            Fr_sub(_tmp_43, i, (ctx->circuit->constants + 1));
            _offset_82 = _xL_sigIdx_ + Fr_toInt(_tmp_43)*_sigSizes_xL[1];
            ctx->multiGetSignal(__cIdx, __cIdx, _offset_82, _sigValue_20, 1);
            ctx->setSignal(__cIdx, __cIdx, _xL_out_sigIdx_, _sigValue_20);
        }
        Fr_copyn(_tmp_45, i, 1);
        Fr_add(_tmp_44, i, (ctx->circuit->constants + 1));
        Fr_copyn(i, _tmp_44, 1);
        Fr_lt(_tmp_46, i, (ctx->circuit->constants + 222));
        _loopCond = _tmp_46;
    }
    ctx->finished(__cIdx);
}
// Function Table
Circom_ComponentFunction _functionTable[4] = {
     example_MiMC_17b177f17a0555e8
    ,MiMCSponge_9ec0aed9ecb0041f
    ,MiMCFeistel_4721f7651191669c
    ,MiMCFeistel_44ce17afd3121bdf
};
