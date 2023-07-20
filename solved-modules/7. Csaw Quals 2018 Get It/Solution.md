Once we get our information, we see that it is a 64-bit binary with a non-executable stack. <br>
When we go into main on ghidra it shows that it uses a gets call which is a vulnerability just like the previous module. <br>
Now we can go into gdb and go through the memory. <br>
We set a breakpoint right before the gets call and run the file. <br>
We do the same steps as the previous module but before we search-patterns of out input, we add "x/g $rbp+0x8". <br>
We do this so we can the return address that we stored. <br>
The address that you get may be different but the byte offset is "0x28" which is 40 bytes. <br>
So that means that we need to input 40 bytes and then we can overwrite the return address. <br>
If we go back into ghidra we see that there is a function that is called "give_shell". <br>
So we can use the exploit that will call the "give_shell" function by writing over the return address. <br>
When you run the exploit you get a shell. <br>
