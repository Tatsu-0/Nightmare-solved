After gathring the basic info, we can go to ghidra. <br>
We see that its a custom assembled binary and there isnt much C code to look at. <br>
It sets up a write syscall to stdout and sets up a read syscall which will allow us to scan 0x200 bytes via stdin <br>
It will then pop off several registers which makes us able to control all of them due to the syscall. <br>
So to exploit this we will use the syscall that is preceeded by a bunch of the pop instructions to execute a sigreturn. <br>
Then we will have to remap the binary segment (0x400000 - 0x401000) to the perms rwx which will be done using mprotect syscall. <br>
The syscall that is going to be used is 0x400104 and after that we will set rsp equal to 0x40011a. <br>
When everything is put together, we run the exploit and get the shell. <br>
