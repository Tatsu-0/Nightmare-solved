After gathering the basic info, we can look into the pwnme function from main. <br>
It allows us to scan 0x60 (176) bytes of data into a 32 byte space which means we have another buffer overflow bug. <br>
We need to call ret2win with rdx which is equal to 0xdeadcafebabebeef. <br>
To do this we will use the ret_2_csu technique which means that we will have to pull ROP gadgets from the function __libc_csu_init_. <br>
We will have to satisfy three conditions which are:
1. Ensure that [R12 + RBX * 0x8] reolves to a pointer to a valid instruction pointer.
2. Ensure that RBP and RBX are equal to each other.
3. Ensure there are values on the stack for the POP instructions.
The function that we will call is _init (0x400560). <br>
R12 = 0x600e38 | RBX = 0 | RBP = 1 <br>
Once everything is put together we can run the exploit and get the flag. <br>
<br>
Flag = ROPE{a_placeholder_32byte_flag!} <br>
