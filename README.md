# BruteForce and Dictionary attacks in C

Part I: Brute-force attacks. (vijay.c)

There is a password system you want to break into. The system accepts hashes of alphanumeric passwords consisting of up to 16 bytes. This C program generates hashes of all possible passwords. That is, the program will create a new file (out.txt) output all passwords with corresponding hashes.

Part II: Dictionary attacks (prog.c and pass.txt)

This C program will use a dictionary to generate passwords and hashes. Here, I have used a small password dictionary. (A much larger dictionary can be used).The program will also display the entropy for each password based on the number of characters
