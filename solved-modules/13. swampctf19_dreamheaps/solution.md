WIP
We are first given the libc-2.27.so file and the dreamheaps file is 64-bit with partial RELRO with canary and NX enabled. <br>
When runnning the program there are 4 different options, write, read, edit, and delete dream. <br>
So when we go into ghidra and look into the each function we see there are some vulnerbilites in them. <br>
In the read function there is a bug where it checks that we gave it an index smaller than or equal to 'INDEX'. <br>
But it doesnt check to see if we gave it and index smaller than one. <br>
This will allow us to read something from memory before the start of the HEAP_PTRS array. <br>
The edit function also has the same vulnerable index check from the read function. <br>
After going through the delete function we see all three, read, edit, and delete functions have the same vulnerable check on the index. <br>
If the check passes it will free the pointer in 'HEAP_PTRS' stored at the index and set it to 0 but leaves the value in 'SIZES'. <br>
We can now use gdb to find what we need to exploit to get the flag. <br>
For the libc infoleak we need a pointer to a pointer to a libc address. <br>
After digging we find the '0x400538' will work and will need to read the dream offset at '-263021'. <br>
For the got overwrite we will need to make enough dreams to overflow into the sizes. <br>
The function we will be overwriting for the got address will be 'free' at '0x601fb0' due to it not causing us any issues. <br>
Now we can put everything into an exploit and run it to get the flag. <br>
