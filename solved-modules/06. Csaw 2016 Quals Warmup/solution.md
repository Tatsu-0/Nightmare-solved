Before beginning to reverse engineer the warmup file we need to have the flag.txt in the same directory as the warmup file. <br>
Once we get our information about the file we know that it is a 64-bit binary and when we run it, it displays an address and prompts us with an input. <br>
When we go to main in Ghidra, we see that the address that it gave us is the address of the function easy. <br>
At the bottom of main we see that it calls the function gets, which is vulnerable due to it not limiting the the data input. <br>
So, to find how much data we need to send before overwriting the return address we need to use gdb. <br>
We find the offset is '0x48' with, hex(0x7fffffffde98 - 0x7fffffffde50). <br>
So now we know the amount of data we need to input before overwriting the address, which is '0x48', we can use the exploit.py script. <br>
Now once we run the exploit we get the flag. <br>
<br>
Flag=flag{g0ttem_b0yz}<br>
