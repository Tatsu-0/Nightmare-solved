The bug we will be working on is on lines 19,20 in the main function and is the strcpy calls. <br>
They dont check if the space its writing to is big enough to hold the data. <br>
So we will do the same with heap 0 where we will first have the first strcpy call pointer be overwritten with 20 bytes which is at 0x0804b190 with the new pointer. <br>
Then the second write will be able to write a value we want, where we want. <br>
Finally, we will write to the got table so when it calls one function, it will actually call another. <br>
The command we will input is: <br>
./heap1 `python2 -c 'print "0"*20 + "\x18\xa0\x04\x08" + " " + "\xb6\x84\x04\x08"'` <br>
And like that we are the winner. <br>
