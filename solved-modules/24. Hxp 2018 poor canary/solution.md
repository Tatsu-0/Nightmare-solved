In main, it scans 0x60 bytes but can only hold 40, so there is the buffer overflow bug. <br>
We will use the buffer overflow to overwrite the return address, but we need to deal with the stack canary. <br>
WE will deal with it by leaking the stack canary using the "puts(acStack_3d+1)" which is the input. <br>
The main things we need to know is the system is miported to 0x16d90, /bin/sh is at 0x71eb0, and the canary is at a offset of -0x14. <br>
The exploit will have:<br>
40 bytes of filler data <br>
4 bytes stack canary <br>
12 bytes of filler data to return address <br>
4 byte rop gadget pop {r0, r4, pc} <br>
4 byte "/bin/sh" argument <br>
4 byte filler <br>
4 byte address of system <br>
With everything we know, we can make the exploit and get the shell. <br>
