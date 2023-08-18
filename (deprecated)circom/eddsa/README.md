What I learned here,

- The length of keypair in EdDSA is also `32 bytes`.(32 or 64 bytes depends on implementation, here is 32bytes. Check [here](https://cryptobook.nakov.com/digital-signatures/eddsa-and-ed25519) and [here](https://blog.mozilla.org/warner/2011/11/29/ed25519-keys/) for more details) 
- in circom
  - `A` means public key. 
  
    `A[0]` means x axis of A (symbol `Ax` in circom). `A[1]` means y of A (symbol `Ay` in circom).
  - `R8` means `R` in ECDSA. 
  
    `R8[0]` means x axis of R8 (symbol `R8x` in circom). `R8[1]` means y of R8 (symbol `R8y` in circom).
  - `S` means `S` in ECDSA.
- in js
  - using little-endian to convert between bigInt and buffer
- The followings took me couple of days...  
  - using double quote `"` in `input.json` if the value is bigInt.
  - `msg`, the input value of this sample, is better to be 32 bytes (always fails with 10 bytes).
  - `Num2Bits` has some issues or limitations
  
    It fails all the time,
    ```
    signal input A;
    signal input R8;
    
    component ABits =  Num2Bits(256);
    ABits.in <== A;
    component R8Bits =  Num2Bits(256);
    R8Bits.in <== R8;
    ```
    suggest to use
    ```
    signal input Ax;
    signal input Ay;
    signal input R8x;
    signal input R8y; 
    
    component ABits = Point2Bits_Strict()
    ABits.in[0] <== Ax;
    ABits.in[1] <== Ay;

    component R8Bits = Point2Bits_Strict()
    R8Bits.in[0] <== R8x;
    R8Bits.in[1] <== R8y;
    ```
