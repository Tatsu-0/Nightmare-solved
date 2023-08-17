When all of the basic information has been gathered we can run the file and see that it asks for a pssword. <br>
When looking into the FUN_004007e8 function, we see that there are only 0xff bytes being scanned into local_118. <br>
If the fgets call scans any bytes, it will run local_118 through FUN_004006fd function and if it returns 0, then we solve the challenge. <br>
In the function, there is a while(true) loop that in each iteration, it will take out input and evaluate it. <br>
If it passes the check, it will move onto the next iteration and if there are 0xc iterations of the loop, we solve the challenge. <br>
To solve this we will use Angr and we need to know three things: <br>
1. What input we have control over. <br>
0xff bytes or less via stdin. <br>
2. Instruction address we want to hit. <br>
0x4007a1, sets EAX equal to 0x0. <br>
3. Instruction address to know if our input is incorrect. <br>
0x400790, moves 1 into EAX. <br>
<br>
After that we can now make out Angr script and solve the challenge. <br>
<br>
password = Code_Talkers <br>
*make sure to do pip install angr*
