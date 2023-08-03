Looking into the binary we see that it is 32-bit and has stack canary as well as NX. <br>
When we look into main in ghidra, the printf call doesnt specify a format to print the input which is a format string bug. <br>
With '%n' flag with printf we can write to memory. <br>
We can write to the GOT table and since PIE isnt enabled we know the adresses. <br>
Then find the system and its address right above the __gmon_start__ function or use objdump. <br>
So now we know the system address which is '0x8048490' which was in the in the plt table. <br> 
Since we have the system address we can overwrite a got entry of a function with system to call it. <br>
We will use 'fini_array' which contains an array of functions that are executed after main returns. <br>
To find 'fini_array' well use gdb while running the program. <br>
Now that we have the address which is '0x8049934', we need to find an address to loop back to which the author chooses '0x8048614'. <br>
As for an address to loop back to we need a function to overwrite which the author chooses 'strlen'. <br>
To find the got address of 'strlen' we can look at the memory region of '.got.plt', which is '0x8049a54'. <br>
All we need to do now is to exploit the format string bug which we can first start by inputting the following '0000111122223333.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x'. <br>
We need to do this so we can find out input in refrence to the printf call. <br>
We see out input being '3030202c.31313030.32323131.33333232'which means the format string will be 'xx0000111122223333'. <br>
The last thing we need to do is change the byte values which all we need to do is print an additinal byte. <br>
But since we are working with two sets of bytes, the higher bytes need to write to a byte that is smaller '0x0804'. <br>
All we need to do is to print '33652'bytes which will overflow into the following dwords which wont affect us. <br>
Finally, all we need to do is to run the exploit to get the shell. <br>
