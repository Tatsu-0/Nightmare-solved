After getting the basic information about the file we can go into ghidra. <br>
Looking into the FUN_080485ab function, we see it first scas 0x21 bytes into local_35. <br>
Then it will run local_35 through 4 different functions. <br>
After it has gone through the 4 functions it will use strcmp to comapre our data with PTR_DAT_0804a038. <br>
If they are both equal, then we pass the challenge. <br>
Once we go through all of the 4 functions, we can see what we need to do to solve the challenge. <br>
The 4 functions do:<br>
1. Replaces the newline character (oxa) with a null byte. <br>
2. Takes out input (newline character stripped) and reverses it. <br>
3. A for loop that will run once per each character of our input. <br>
It takes the hex value of each character of our input and alters it, but it will only take the first 8 bits worth of data. <br>
4. Runs a loop that iterates for each character of the input and takes the binary value and converts 0 to 1 and 1 to 0. <br>
After finding out what the functions do, all we need is to write a script that will undo the binary not. <br>
Then we need another script to figure out the input needed. <br>
<br>
flag = TWCTF{qpzisyDnbmboz76oglxpzYdk}
