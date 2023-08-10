This one is not too much work, we are working with a 64-bit, dynamically linked file. <br>
When using pwn checksec, we see that it has partial relro, stack canary is found and NX is enabled. <br>
But we dont need to worry about those too much once we see how the code works. <br>
To quickly go over the code, it creates a random number that is based on the seed value that has a certain time. <br>
It then compares the value you input with the random number, but of course its near impossible to guess. <br>
To exploit this we need to find what time the seed is based on which is: tVar1 = time((time_t *)0x0); srand((uint)tVar1); <br>
So all we need to do is write a c program that will use the current time as a seed, then output a digit and redirect it to the target. <br>
When we are done with the c program we need to use gcc to make it a executable and run it before the time file. ( ./solve | ./time ) <br>
When ran we should get a message that says "Flag file not found!  Contact an H3 admin for assistance." which means it worked. <br>
We know it worked because this message is from the giveFlag function but we dont have a flag downloaded in out local machine. <br>
To make it a little more fun, we can make a /home/h3/flag.txt and write whatever flag you want and it will output the flag you make. <br>
