This CTF is very information dense and the author gives multiple steps on what to do. <br>
I go into detail with my notes that I have added but this will be the basics on what to do. <br>
We are dealing with a 32-bit binary with stack canary and RWX segments. <br>
We focus on the 'game()' function in main and once we go through all the different arrays we find that 'findArray' has this line "*heapQt = v5;". <br>
This will let us change the value of 'heapQt' which can be passed as an argument to 'sortArray'. <br>
There is a lot to cover for the exploitation part of this CTF but we essentially write a greater value to heapQt than 64, that way it will start sorting data past ptrArray. <br>
But we specifically need to make sure that the sorting algorithm for the exploit leaves the stack canary in the correct order or it will crash the binary when we run it. <br>
After running the exploit until the stack canary is in the right range we finally get the flag. <br>
<br>
Flag = flag{4_d0ub1e_d0ub1e_3ntr3ndr3} <br>
