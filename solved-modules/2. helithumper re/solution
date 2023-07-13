Gain information by using 'file rev' and './rev'.
Open 'rev' in ghidra and go to the main function.
There is a 'validate' function in main.
Once you go to that function there are several 'checkValues' each having a value that looks like '0x66'.
There should be 14 values and after finding this you need to open python so you can convert the values into ascii.
The python script should look like this:
>>> x = [0x66, 0x6c, 0x61, 0x67, 0x7b, 0x48, 0x75, 0x43, 0x66, 0x5f, 0x6c, 0x41, 0x62, 0x7d]
>>> input = ""
>>> for i in x:
...     input += chr(i)
...
>>> input

Flag = flag{HuCf_lAb}
