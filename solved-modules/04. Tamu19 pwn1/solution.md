Gather as much information as you can as usual. <br>
When you go into the main function you can get the first two strings that it wants which is: <br>
"Sir Lancelot of Camelot" and "To seek the Holy Grail". <br>
The secret is the one that we need to find. <br>
We see that it compares local_18 to '0xdea110c8' and if we click on the 'print_flag function we see that it prints out the flag.txt. <br>
We can use the gets call to overwrite the contents of local_18 to '0xdea110c8' so we can get the flag. <br>
(If you are doing this on your own you need to download the flag.txt file and have it in the same directory as the binary file) <br>
We need to find the offset of out input and local_18 and to do that we can click on the main function and it takes us to the top of the function in assemby code. <br>
It shows that our input is -0x43 and local_18 is -0x18, 0x43 - 0x18 = 0x2b. <br>
So now we know the offset of out input and local_18 and we can just overflow it. <br>
We make an exploit that will overwrite local_18 with '0xdea110c8'. (I have attached the exploit) <br>
When we run the exploit it will give us the flag: <br>
<br>
flag{g0ttem_b0yz}
