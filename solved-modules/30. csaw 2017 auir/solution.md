After gathering the basic info, we can look into ghidra <br>
When looking into the code, we see that it has been obfuscated but after awhile we can find out what the 5 options do. <br>
MAKE ZEALOTS:	Prompts you for a size, allocates that size in the heap with malloc, then allows you to scan in the amount of bytes allocated into the heap chunk. <br>
DESTROY ZEALOTS: It frees the heap chunk for the zealot you give it. <br>
FIX ZEALOTS: Allows you to scan in data into a Zealot. Does not check for an overflow. <br>
DISPLAY SKILLS: Prints the first 8 bytes of data from the Zealot you provide it with. <br>
GO HOME: Exits the program <br>
There are also two addresses that stores pointers and the zealots: <br>
0x605310:	Stores pointers for all of the Zealots allocated <br>
0x605630:	Integer that stores the amount of Zealots allocated <br>
At the end we have three bugs to work with: <br>
1. Heap overflow big in fix zealots
2. Use after free bug in destroy zealots
3. Double free bug in destroy zealots
2 and 3 leaves behind a pointer in frees <br>
------- <br>
The use after free bug will be used to get a libc infoleak. <br>
This will be done by allocating several chunks when freeing them. <br>
Then we will use the same bug to execute a fastbin attack. <br>
Well then allocate 2 chunks of a similar fastbin size, and free them. <br>
Finally we will edit the chunk that is on the top of the fastbin. <br>
Putting everything together into an exploit, we get the shell. <br>
