[circom](https://github.com/iden3/circom) is a special language designed for generating zero knowledge proofs.

So far, circom doesn't have many documentations and examples. This repo is trying to implement more examples to get more sense to use circom.

### How to build
1. Generate circuits
   ```
   circom xxx.circom
   ```
   `circuit.json` is generated.

2. Calculate witness
   `input.json` is required.
   ```
   snarkjs calculatewitness
   ```
   `witness.json` is generated.

3. Setup
   ```
   snarkjs setup
   ```
   `proving_key.json` and `verification_key.json` are generated.

4. Generate proof
   ```
   snarkjs proof
   ```
   `proof.json` and `public.json` are generated.

Check Iden3 [tutorial](https://github.com/iden3/circom/blob/master/TUTORIAL.md) for more details.
