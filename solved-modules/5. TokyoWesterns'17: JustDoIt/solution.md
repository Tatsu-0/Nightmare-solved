Gather as much information as usual. <br>
We see that it is trying to open a file called flag.txt and that the value of PASSWORD is "P@SSW0RD". <br>
Since out input is being scanned through a fgets call, a newline character (0x0a) will be appended at the end. <br>
So we need to put a null byte after "P@SSW0RD". <br>
You may need to change python command but I used, (python -c 'print "P@SSW0RD" + "\x00"' | ./just_do_it). <br>
We passed the check but we need to get the flag. <br>
We can input 32 bytes worth of data in input but we want to see how many it can hold. <br>
It can hold 16 bytes of data, (0x28 - 0x18 = 16) so this is a buffer overflow vulnerability. <br>
We cant reach teh 'eip' register to get RCE but we can reach the output_message which is printed with the puts call. <br>
So by going the the output_message we can see that it opens the flag.txt and it scans in 48 bytes worth of data. <br>
This means if we can find the address of the flag then we can overwrite the value of output_message with the address and have it print the contents. <br>
We find the flag address in the bss wiht the address "0x0804a080". <br>
There are 20 bytes worth of data between input and output_message. (0x28 - 0x14 = 20) <br>
So knowing that we can make a payload that will have 20 null bytes followed by the flag address. <br>
We can make an exploit with (python -c 'print "\x00"*20 + "\x80\xa0\x04\x08"' | ./just_do_it).
After that we were able to read flag.txt but we can also write an exploit to use the same exploit against the server they have with the challenge running to get the flag. (Included) <br>
<br>
Flag.txt = flag{gottem_boyz} <br>
Flag from written exploit = TWCTF{pwnable_warmup_I_did_it!} <br>
