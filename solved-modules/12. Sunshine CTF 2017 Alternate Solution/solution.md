We are working with a 64-bit binary with full relro, canary, NX, and PIE. <br>
When running the file we are prompted for an input and it checks if the number is too high or low. <br>
When we look into ghidra we see that the program will exit if its greater than or less than '37.35929'. <br>
But the number has more decimal places than a float can handle so it wont pass. <br>
However, floats have a special value named "nan" which means not a number. <br>
So if we input "nan" it will qualify as not a number which means it is not greater or less than '37.35929' <br>
<br>
flag = sun{50m3times yoU_h@v3_t0 get cr3@t1v3} <br>
