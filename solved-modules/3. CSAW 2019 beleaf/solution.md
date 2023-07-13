Gather information about the file, you can also use 'pwn checksec' to get additinal information as well. <br>
To get to main it is a little bit more work, you need to find 'FUN_001006f0' and then main would be 'FUN_001008a1' inside of that. <br>
It shows that it scans our input and will exit if its less than 0x21 or also known as 33 bytes. 'if (sVar1 < 0x21)' <br>
Then it runs it into a for loop and goes through the 'FUN_001007fa' function. <br>
If we go to that function we see that it takes a character and looks at what its index is in the 'DAT_00301020' bss array. <br>
To know what order we need to look up each character we can go back into the main function (FUN_001008a1) and go into 'DAT_003014e0'. <br>
We see the first character has to equal 0x1, then the second needing to equal 0x9 and then 0x11 and so on. <br>
Going back into 'DAT_00301020' we can start to find the order of each character. <br>
The characters are stored at offsets of 4 bytes and by knowing the flag format we can start at the character 'f'. <br>
'f' is stored at '00301024' and it will output '1' since ((00301024 - 00301020) / 4) = 1. <br>
The second byte is 0x9 and '00301020' is the start of the array so we can just do (00301020 + (4*9)) = 00301044 and that equals to the character 'l'. <br>
Going through the list we can get the flag which will be: <br>
<br>
flag{we_beleaf_in_your_re_future}
