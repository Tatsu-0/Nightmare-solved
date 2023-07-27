We are dealing with a 32-bit binary with no RELRO, STACK, NX, or PIE. <br>
When we run the binary it prompts us with an input and gives it back to us. <br>
But when we use '%x' we see that it has a format bug. <br>
When we go into main in Ghidra we see that it scans the contents of the flag file to a char array on the stack for main. <br>
At the end of main we see that the format bug runs in a loop indefinitely which is the while true loop. <br>
If we find the offset to the pointer to 'flag.txt', we can just print it with '%s' with the format string bug. <br>
For this to work we need the 'flag.txt' file in the same directory as the echo binary. <br>
We can now use gdb to leak a bunch of values, then check where the flag is in memory, and finally see if any of those values is a pointer to the flag. <br>
First we open gdb with ./echo. <br>
Then we run the file and leak a bunch of values as said before with typing a bunch of '%x.'. <br>
We can now end the file and get all the values we need. <br>
After that all we need to do is 'search-pattern' for the flag which is 'flag{flag}'. <br>
Now we see the flag is at '0xffffd02c' and reach it using the format bug at offset 8. <br>
Finally we can run the binary normally and input '%8$s' and get the flag. <br>
<br>
Flag = flag{flag}<br>
