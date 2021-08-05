#How to use RPCView
1. Validate you're on the commit id 9f24017edb95ad5d35ad5ccec1df7c2d32b21c17 in the repo 
   [RpcView](https://github.com/silverf0x/RpcView)
2. open a CMD inside the folder RpcView 
3. Execute the command git am ../0001-Modifications-for-Back2theFuture.patch
4. Then you can execute it. 


## Troubleshooting
Q: I don't see anything inside RpcView folder 
A: there are 2 options:
1. `git clone --recurse-submodules` the path to the root git
2. execute the command `git submodule init` and `git submodule update`
