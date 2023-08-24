After gathring the basic information, we can look into the vul function. <br>
The vul function is inside the main function but it is the only thing in main other then the return. <br>
We see it scans in 0x32 (50) bytes worth of data into a 32 byte buffer which means we have a 18 byte buffer overflow. <br>
So with this we can overwrite the return address which the offset is 0x24. <br>
Due to PIE not being enabled, we can call gadgets which the first will be stack pivot and then jmp esp. <br>
The stack pivot gadget will move the stack pointer down to our own input which will leave off by executing the first DWORD of our input as an instruction pointer. <br>
That pointer will be the jmp esp gadget and when that pointer is executed, the esp pointer will point to the new DWORD which will be the second 4 bytes of our input. <br>
We will store our shellcode there and will be executed by the jmp esp gadget. <br>
After putting everything together in an exploit, we get the shell. <br>
