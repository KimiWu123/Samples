include "../../circomlib/circuits/mimcsponge.circom";

template example_MiMC() {
    var numInput = 2; // length of vector_inputs[]
    var rounds = 220; 
    var numOutput = 1;
   
    signal private input ins[numInput]; //[3, 5]
    signal output outs[numOutput];

    component mimc = MiMCSponge(numInput, rounds, numOutput);
    for(var i=0; i<numInput; i++) {
        mimc.ins[i] <== ins[i];
    }
    mimc.k <== 0;

    for(var i=0; i<numOutput; i++) {
        outs[i] <==  mimc.outs[i];
    }
    // outs[0] === 19645535825158629185678629142941397608692377887251128732177816409280704108750;
}

component main = example_MiMC();