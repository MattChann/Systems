# Work 04: /dev[ise a]/random plan

Write a c program with the following features:
1. A function that generates a random number by reading in the correct number of bytes from /dev/random.
2. A main function that:
    1. Populates an array with 10 random numbers generated by your random function (print out each value)
        - If your program seems to stall at this step, it's possible that your computer doesn't have enough entropy and is waiting, you can read from /dev/urandom instead.
    2. Writes the array to a file
        - **Do not use a loop** when writing to the file
    3. Reads that file into a different array
        - **Do not use a loop** when reading from the file
    4. Prints out the contents of the second array to verify the random numbers are the same from step 1

- Remember to use good practices, like checking return values for errors
- Also remember to include a makefile that includes a separate run target

github clone links
https://github.com/mks65/randfile.git
 
Sample output:
```
Generating random numbers:
        random 0: 198116400
        random 1: 2592608753
        random 2: 2833624368
        random 3: 3273750590
        random 4: 3548697368
        random 5: 3876828898
        random 6: 2617393183
        random 7: 1720936907
        random 8: 682596330
        random 9: 2411695830

Writing numbers to file...

Reading numbers from file...

Verification that written values were the same:
        random 0: 198116400
        random 1: 2592608753
        random 2: 2833624368
        random 3: 3273750590
        random 4: 3548697368
        random 5: 3876828898
        random 6: 2617393183
        random 7: 1720936907
        random 8: 682596330
        random 9: 2411695830
```
