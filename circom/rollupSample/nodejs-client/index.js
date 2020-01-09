const snarkjs = require("snarkjs");
const eddsa = require("circomlib/src/eddsa.js");
const mimcsponge = require("circomlib/src/mimcsponge.js")
const {stringifyBigInts} = require('snarkjs/src/stringifybigint.js');

const prvSeedS = "0001020304050607080900010203040506070809000102030405060708090001";
const prvSeedR = "00010203040506070809000102030405060708090001020304050607080900AA";
const bigInt = snarkjs.bigInt;

const balance = 10 * 10**18
const amount = 10**18
const level = 4

function getAccount(seed, balance) {
    const prvKey = Buffer.from(seed, "hex");
    const pubKey = eddsa.prv2pub(prvKey);

    return {
        "prvkey": prvKey,
        "pubkey": pubKey,
        "balance": bigInt(balance)
    }
}

function hashedLeaf(account) {
    return mimcsponge.multiHash([account.pubkey[0], account.pubkey[1], account.balance]);
}

function hashMessage(pubA, pubB, amount) {
    return mimcsponge.multiHash([pubA[0], pubA[1], pubB[0], pubB[1], amount]);
}

function rollup_sample()
{
    //
    // init merkle trre
    //
    var tree = init_merkle_tree(level)

    const accS = getAccount(prvSeedS, balance)
    const accR = getAccount(prvSeedR, balance)
    tree = insert_merkle_tree(level, tree.tree, 0, hashedLeaf(accS))
    tree = insert_merkle_tree(level, tree.tree, 1, hashedLeaf(accR))
    const initRoot = tree.root;

    const treeS = get_inter_elements(level, tree.tree, 0)
    const treeR = get_inter_elements(level, tree.tree, 1)

    //
    // sign message
    //
    const msg = hashMessage(accS.pubkey, accR.pubkey, bigInt(amount))
    const signature = eddsa.signMiMCSponge(accS.prvkey, msg);
    if(!eddsa.verifyMiMCSponge(msg, signature, accS.pubkey)){
        console.log("\nsignature not matched\n");
    }

    //
    // calculate sender's new root
    //
    const accS_new = getAccount(prvSeedS, balance-amount)
    const interTree = insert_merkle_tree(level, tree.tree, 0, hashedLeaf(accS_new))


    //
    // calculate final root
    // 
    const accR_new = getAccount(prvSeedR, balance+amount)
    const finalTree = insert_merkle_tree(level, interTree.tree, 1, hashedLeaf(accR_new))
    console.log("final root: ", finalTree.root)

    return {
        "account_root": initRoot, 
        "account_pubkey": accS.pubkey,
        "account_balance": accS.balance,
        "new_sender_account_root": interTree.root, 

        "tx_sender_pubkey": accS.pubkey,
        "tx_sender_balance": accS.balance,
        "tx_amount": amount, 
        "tx_sender_sig_r": signature.R8, 
        "tx_sender_sig_s": signature.S, 
        "tx_sender_path_element": treeS.path_elements, 
        "tx_sender_path_idx": treeS.path_index, 

        "tx_receiver_pubkey": accR.pubkey, 
        "tx_receiver_balance": accR.balance, 
        "tx_receiver_path_element": finalTree.path_elements, 
        "tx_receiver_path_idx": finalTree.path_index
    }
}

const inputs = rollup_sample()
console.log(JSON.parse(JSON.stringify(stringifyBigInts(inputs))))

///
/// merkle tree
///
function init_merkle_tree(n_levels) {
    let tree = [];
    for (let i = 0; i < n_levels; i++) {
      let tree_level = [];
      for (let j = 0; j < Math.pow(2, n_levels - i); j++) {
        if (i == 0) {
            tree_level.push(bigInt(0));
        } else {
            tree_level.push(mimcsponge.multiHash([ tree[i-1][2*j], tree[i-1][2*j+1] ]));
        }
      }
      tree.push(tree_level);
    }
    const root = mimcsponge.multiHash([ tree[n_levels - 1][0], tree[n_levels - 1][1] ]);

    return {"tree": tree, "root":root}
}

function get_inter_elements(n_levels, tree, index) {
    let current_index = index;
    let path_index = [];
    let path_elements = [];

    for (let i = 0; i < n_levels; i++) {
      if (current_index % 2 == 0) {
        path_elements.push(tree[i][current_index + 1])
      } else {
        path_elements.push(tree[i][current_index - 1])
      }

      path_index.push(current_index % 2);
      current_index = Math.floor(current_index / 2);
    }
    const root = mimcsponge.multiHash([ tree[n_levels - 1][0], tree[n_levels - 1][1] ]);

    return {
        "root":root,  
        "path_elements": path_elements, 
        "path_index": path_index
    };
}

function insert_merkle_tree(n_levels, tree, index, leaf) {
    let current_index = index;
    let path_index = [];
    let path_elements = [];
    let localTree = [];

    for (let i = 0; i < n_levels; i++) {
      let tree_level = [];
      path_index.push(current_index % 2);
      for (let j = 0; j < Math.pow(2, n_levels - i); j++) {
        if (i == 0) {
          if (j == index) {
            tree_level.push(bigInt(leaf));
          } else {
            tree_level.push(tree[0][j])
          }
        } else {
            tree_level.push(mimcsponge.multiHash([ localTree[i-1][2*j], localTree[i-1][2*j+1] ]));
        }
      }

      if (current_index % 2 == 0) {
        path_elements.push(tree_level[current_index + 1]);
      } else {
        path_elements.push(tree_level[current_index - 1]);
      }

      localTree.push(tree_level)
      current_index = Math.floor(current_index / 2);
    }

    const root = mimcsponge.multiHash([ localTree[n_levels - 1][0], localTree[n_levels - 1][1] ]);

    return {
        "root":root,
        "tree" :localTree, 
        "path_elements": path_elements, 
        "path_index": path_index
    };
};

