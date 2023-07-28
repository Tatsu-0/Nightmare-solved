In this CTF there is a lot that the author covers and a lot of work that needs to be put into this, I have added a pdf of the notes I took but this will be a quick summary. <br>
We are working with a 32-bit binary with stack canary and RWX segments. <br>
When we run the binary our input is taken and converted into doubles. <br>
We find out that we get a stack info leak and can verify it with gdb. <br>
In the main function all we need to look at is 'game()'. <br>
Once we go through all the different arrays and all the parameters we find a bug that we can overwrite the number of doubles which is stored in 'sortArray'. <br>
We also have a stack infoleak, an executable leak, and the ability to write data to the stack. <br>
To make things short for the exploit, we wiil essentially write a greater value to heapQt than 64, that way it will start sorting data past ptrArray. <br>
I go into detail with my notes. <br>
But when making the exploit we need to make sure that we leave the stack canary intact and in the correct order after it is sorted or it will crash the binary. <br>
We can finally run the exploit until the stack canary is in the right range and we then get the flag. <br>
<br>
Flag = flag{4_d0ub1e_d0ub1e_3ntr3ndr3}<br>
