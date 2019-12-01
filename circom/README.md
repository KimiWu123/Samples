[circom](https://github.com/iden3/circom) is a special language designed for generating zero knowledge proofs.

So far, circom doesn't have many documentations and examples. This repo is trying to implement more examples to get more sense to use circom.

### How to build
1. Generate circuits
   ```
   circom xxx.circom
   ```
   `circuit.json` is generated.

2. Setup
   ```
   snarkjs setup
   ```
   `proving_key.json` and `verification_key.json` are generated.
   
3. Calculate witness
   `input.json` is required. It looks like, 
   ```
   {
    "msg":"2011755993131582822579525647814080917196892913887505229026576278180248827965", 
    "Ax": "13277427435165878497778222415993513565335242147425444199013288855685581939618", 
    "Ay": "13622229784656158136036771217484571176836296686641868549125388198837476602820",
    "R8x":"358675281353740370026158910395792965054291524487564871845974728113110876343",
    "R8y":"2855312677603809296705636740621876580577580834868432035953147562033263672140",
    "S":  "2221307763761861486259370796128686387693261093272825174391592561130550991789"
   }
   ```
   The keys of json are the variable name of `signal` in `.circom` file.
   
   ```
   snarkjs calculatewitness
   ```
   `witness.json` is generated.

4. Generate proof
   ```
   snarkjs proof
   ```
   `proof.json` and `public.json` are generated.

Check Iden3 [tutorial](https://github.com/iden3/circom/blob/master/TUTORIAL.md) for more details.

Step 2 ~ 6, you can use `build.sh` to run automatically.
```
bash ./build.sh <relative path of circuit.json> 

eg.
bash ./build.sh ./eddsaMiMCSponge
```
