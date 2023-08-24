After getting the basic info we can go into ghidra and look into the main function. <br>
We see some of the output but we mainly need to look into the select_func function. <br>
The first 31 bytes of our input is passed in as an argument that is copied to the char buffer (input), but it can only hold 30 bytes. <br>
So we have a one byte overflow which allows us to overwrite the least significant byte of functionCall. <br>
If we call the function print_flag at offset 0x6d8, we get the flag. <br>
To exploit this we need to set the address 0x565556ad to 0x565556d8. <br>
The we will overwrite the least significant byte to 0xd8 to get the flag. <br>
Putting it all together we get the flag. <br>
<br>
Flag = flag{g0ttem_b0yz} <br>
