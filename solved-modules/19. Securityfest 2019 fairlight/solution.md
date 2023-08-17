After we have gathered all the basic information, we see that it needs a code along with the file when running. <br>
Looking into the main function it checks the input (code) if its 0xe characters. <br>
It will then copy our input to the bss variable called 'code'. <br>
When double clicking the code variable we see it is located at 006030b8. <br>
We see that it runs a series of check functions that refrence our input which is stored in the code variable and evalute it to see if its correct. <br>
So to solve this challenge we will use Angr and like last time we need three things: <br>
1. What input we have and how it gets passed to the binary. <br>
0xe (14) byte char cahracters passed in a single argument. <br>
2. Instruction address we want Angr to reach. <br>
00401a6e, right above the Printf("%s" ,&local_1b8); <br>
3. Instruction address to tell Angr that the input is incorrect. <br>
0040074d, start of the denied_access function that is in all the check functions. <br>
<br>
Now that we have everything we need, we can now make out Angr script and get the code. <br>
<br>
password = 4ngrman4gem3nt <br>
Flag = CODE{4ngrman4gem3nt}
