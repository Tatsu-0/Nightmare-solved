(you will have to change the libc file in the exploit to 2.19 and use python2 to run the exploit or make the exploit into python3.)<br>
We essentially have a heap overflow bug in case 1 which is the function FUN_00400f75 or the menu function. <br>
As well, we have the ability to allocate 4 chunks and free them as well as view their content. <br>
There is also an array that stores all the heap pointers which is at 0x602120. <br>
The way we will exploit all of this is with a heap unlink attack. <br>
And we have popped the shell. <br>
