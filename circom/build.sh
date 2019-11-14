cd $1

if [ ! -f "circuit.json" ]; then
    echo -e "\ncircuit.json not existed, please execute 'circom <your circuit>' first."
    exit 1;
fi 

echo -e "\ncalculating witness..."
if [ ! -f "input.json" ]; then
    echo -e "\ninput.json not existed, please create 'input.json' first."
    cd -
    exit 1;
fi
snarkjs calculatewitness
if [ ! -f "witness.json" ]; then
    echo -e "\nwitness.json not existed, some error happens at 'snarkjs calculatewitness'."
    cd -
    exit 1;
fi

echo "setting up..."
snarkjs setup 
if [ ! -f "proving_key.json" ]; then
    echo -e "\nproving_key.json not existed, some error happens at 'snarkjs setup'."
    cd -
    exit 1;
fi

echo "generating proof..."
snarkjs proof
if [ ! -f "proof.json" ]; then
    echo -e "\nproof.json not existed, some error happens at 'snarkjs proof'."
    cd -
    exit 1;
fi

echo -e "verifying...\n"
snarkjs verify

cd -