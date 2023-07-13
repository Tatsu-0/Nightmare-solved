Gain information by using 'file rev' and './rev'. <br>
Open 'rev' in ghidra and go to the main function. <br>
There is a 'validate' function in main. <br>
Once you go to that function there are several 'checkValues' each having a value that looks like '0x66'. <br>
There should be 14 values and after finding this you need to open python so you can convert the values into ascii. <br>
The python script should look like this: <br>
>>> x = [0x66, 0x6c, 0x61, 0x67, 0x7b, 0x48, 0x75, 0x43, 0x66, 0x5f, 0x6c, 0x41, 0x62, 0x7d] <br>
>>> input = "" <br>
>>> for i in x: <br>
...     input += chr(i) <br>
... <br>
>>> input <br>
<br>
Flag = flag{HuCf_lAb} <br>
