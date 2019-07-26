`ecrecover` used to recover signer's address with signed and original message.


## Description

This smart contract supports ecrecover w/o [EIP191](https://github.com/ethereum/EIPs/blob/master/EIPS/eip-191.md).


With EIP191, message would be prepended 
<pre>
"\x19Ethereum Signed Message:\n" + len(message).
</pre>



**Remind!** Not every client implemented EIP191 in their "sign message"  function. As I know Web3js implemented but Web3j not. Be careful when you implement it.
