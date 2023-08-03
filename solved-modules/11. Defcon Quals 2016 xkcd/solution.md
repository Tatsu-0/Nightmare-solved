We are working with a 64-bit statically compiled binary with NX enabled. <br>
The challenge also provides a webiste: https://xkcd.com/1354/. <br>
This challenge is mainly reverse engineering the code instead of pwning it. <br>
In the beginning it clears a space at 'globals' and then it will open the flag file with the name 'flag'. <br>
Meaning that we will need to create a flag file that will be in the same directory as the binary. <br>
Next, our input is scanned with 'fgetln' call then split it with 'strtok' function using '?'. <br>
Then it will use 'strcmp' to compare the output of 'strtok' with the string "SERVER, ARE YOU STILL THERE" and return if they dont match. <br>
The next section is similar to the last but it will compare the string " IF SO, REPLY ". <br>
At the end of the program, it passes the address of 'globals' to puts so it will print out. <br>
But before it gets printed out, it will null terminate a value at some offset we specify. <br>
If the offset is between the start of our input and the start of the flag, we wont get the flag. <br>
Once covering what main has to offer we can find the offset. <br>
The offset of out input is '0x6b7540' and the flag offset is '0x6b7340' and subtracting those will give us 0x200. <br>
To leak the flag we will need to have a string length of 0x200 copied over to 'globals'. <br>
This is all based off of the heartbleed exploit which was also part of the website that we got in the beginning. <br>
Once we run the exploit it will leak the flag locally. <br>
<br>
Flag = flag{g0ttem_b0yz} <br>
