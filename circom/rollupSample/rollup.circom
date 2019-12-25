include "../circomlib/circuits/mimc.circom";
include "../circomlib/circuits/mimcsponge.circom"
include "../circomlib/circuits/eddsamimcsponge.circom"

template HashLeftRight() {
  signal input left;
  signal input right;

  signal output hash;

  component hasher = MiMCSponge(2, 220, 1);
  left ==> hasher.ins[0];
  right ==> hasher.ins[1];
  hasher.k <== 0;

  hash <== hasher.outs[0];
}

template Selector() {
  signal input input_elem;
  signal input path_elem;
  signal input path_index;

  signal output left;
  signal output right;

  signal left_selector_1;
  signal left_selector_2;
  signal right_selector_1;
  signal right_selector_2;

  path_index * (1-path_index) === 0

  left_selector_1 <== (1 - path_index)*input_elem;
  left_selector_2 <== (path_index)*path_elem;
  right_selector_1 <== (path_index)*input_elem;
  right_selector_2 <== (1 - path_index)*path_elem;

  left <== left_selector_1 + left_selector_2;
  right <== right_selector_1 + right_selector_2;
}

template GetMerkleRoot(levels) {

    signal input leaf;
    signal input path_index[levels];
    signal input path_elements[levels];

    signal output out;

    component selectors[levels];
    component hashers[levels];

    for (var i = 0; i < levels; i++) {
      selectors[i] = Selector();
      hashers[i] = HashLeftRight();

      path_index[i] ==> selectors[i].path_index;
      path_elements[i] ==> selectors[i].path_elem;

      selectors[i].left ==> hashers[i].left;
      selectors[i].right ==> hashers[i].right;
    }

    leaf ==> selectors[0].input_elem;

    for (var i = 1; i < levels; i++) {
      hashers[i-1].hash ==> selectors[i].input_elem;
    }

    out <== hashers[levels - 1].hash;
}


template HashedLeaf() {

    signal input pubkey[2];
    signal input balance;
    signal output out;

    component txLeaf = MiMCSponge(3, 220, 1);
    txLeaf.ins[0] <== pubkey[0];
    txLeaf.ins[1] <== pubkey[1];
    txLeaf.ins[2] <== balance;
    txLeaf.k <== 0;

    out <== txLeaf.outs[0];
}

template MessageHash(n) {
    signal input ins[n];
    signal output out;

    component msg_hasher = MiMCSponge(n, 220, 1);
    for (var i=0; i<n; i++) {
        msg_hasher.ins[i] <== ins[i];
    }
    msg_hasher.k <== 0;

    out <== msg_hasher.outs[0];
}
template rollup(levels) {

    // new account root after balance updated
    signal private input new_sender_account_root;

    // account
    signal input account_root;
    signal private input account_pubkey[2];
    signal private input account_balance;

    // tx
    signal private input tx_sender_pubkey[2]
    signal private input tx_sender_balance
    signal private input tx_amount
    signal private input tx_sender_sig_r[2]
    signal private input tx_sender_sig_s
    signal private input tx_sender_path_element[levels]
    signal private input tx_sender_path_idx[levels]

    signal private input tx_receiver_pubkey[2]
    signal private input tx_receiver_balance
    signal private input tx_receiver_path_element[levels]
    signal private input tx_receiver_path_idx[levels]

    signal output new_root;
    

    //__1. verify sender account existence
    component senderLeaf = HashedLeaf();
    senderLeaf.pubkey[0] <== tx_sender_pubkey[0];
    senderLeaf.pubkey[1] <== tx_sender_pubkey[1];
    senderLeaf.balance <== account_balance;

    component senderExistence = GetMerkleRoot(levels);
    senderExistence.leaf <== senderLeaf.out;
    for (var i=0; i<levels; i++) {
        senderExistence.path_index[i] <== tx_sender_path_idx[i];
        senderExistence.path_elements[i] <== tx_sender_path_element[i];
    }
    senderExistence.out === account_root;

    //__2. verify signature
    component msgHasher = MessageHash(5);
    msgHasher.ins[0] <== tx_sender_pubkey[0];
    msgHasher.ins[1] <== tx_sender_pubkey[1];
    msgHasher.ins[2] <== tx_receiver_pubkey[0];
    msgHasher.ins[3] <== tx_receiver_pubkey[1];
    msgHasher.ins[4] <== tx_amount

    component sigVerifier = EdDSAMiMCSpongeVerifier();
    sigVerifier.enabled <== 1;
    sigVerifier.Ax <== tx_sender_pubkey[0];
    sigVerifier.Ay <== tx_sender_pubkey[1];
    sigVerifier.R8x <== tx_sender_sig_r[0];
    sigVerifier.R8y <== tx_sender_sig_r[1];
    sigVerifier.S <== tx_sender_sig_s;
    sigVerifier.M <== msgHasher.out;

    //__3. Check the root of new tree is equivalent
    component newAccLeaf = HashedLeaf();
    newAccLeaf.pubkey[0] <== tx_sender_pubkey[0];
    newAccLeaf.pubkey[1] <== tx_sender_pubkey[1];
    newAccLeaf.balance <== account_balance - tx_amount;

    component newTreeExistence = GetMerkleRoot(levels);
    newTreeExistence.leaf <== newAccLeaf.out;
    for (var i=0; i<levels; i++) {
        newTreeExistence.path_index[i] <== tx_sender_path_idx[i];
        newTreeExistence.path_elements[i] <== tx_sender_path_element[i];
    }
    newTreeExistence.out === new_sender_account_root;

    //__4. skip checking receiver's existence
    // ...

    //__5. update the root of account tree
    component newReceiverLeaf = HashedLeaf();
    newReceiverLeaf.pubkey[0] <== tx_receiver_pubkey[0];
    newReceiverLeaf.pubkey[1] <== tx_receiver_pubkey[1];
    newReceiverLeaf.balance <== tx_receiver_balance + tx_amount;

    component newReceiverTreeExistence = GetMerkleRoot(levels);
    newReceiverTreeExistence.leaf <== newReceiverLeaf.out;
    for (var i=0; i<levels; i++) {
        newReceiverTreeExistence.path_index[i] <== tx_receiver_path_idx[i];
        newReceiverTreeExistence.path_elements[i] <== tx_receiver_path_element[i];
    }
    new_root <== newReceiverTreeExistence.out;

}

component main = rollup(4);