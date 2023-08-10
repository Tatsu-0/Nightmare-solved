This challenge is not too much different than the previous one we did. <br>
It does have PIE enabled though which h3_time did not have, but we dont need to worry too much on that. <br>
The main parts we need to look at in the main function is the time as a seed, the array values, and where the flag.txt is being scanned to. <br>
At the start of the code it scans the flag.txt (0x1020b0) to local_228. <br>
Then it uses the same time as a seed as the previous challenge we did. <br>
Scrolling down a little after the outputs, we see all of the array values. <br>
If you dont see it in the decompilation then you can find it in the assembly code if you press on one of the values and scroll down. <br>
What the code does is that it generates random numbers that uses time as a seed, then edits the values of the array. <br>
It then accumulates all of those values that were made which is supposed to be the number we are supposed to guess. <br>
So now that we know and have everything we need, all we need to do now is write a c program. <br>
The program needs to use time as a seed, then generate the same number that the target wants us to guess. <br>
Once the c program is written, all we need to do is compile it with gcc and have the flag.txt file in the same directory. <br>
Once ran we get the flag.txt. <br>
<br>
Flag = flag{i_need_to_think_of_better_flags} <br>
