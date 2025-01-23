# Scrambling Bits

Suppose you wish to use an encryption mechanism in which every four bytes of a
data stream will be scrambled. We label the bits like this:

```
    --------------------------------------
    |xxxx|nnnnnnnnnnn|eee|vvvvvvvvv|xxxxx|
    --------------------------------------
    31-28   27-17    16-14   13-5    4-0
```

The bits will be manipulated according to the following rules.


* The bits in the positions labeled x are not moved.
* The bit field labeled n swaps positions with the bit field labeled v: the
  rightmost bit of n moves to position 5 and the leftmost bit of v shifts to
  position 27.
* The field labeled e moves two positions to the left to make room for the swap
  of the n and v bits.

Here is an outline of how to get this done:

1. Define four AND masks to isolate the bit fields x, n, e, and v
2. Write four AND instructions to decompose the 32-bit word, isolating the four
   sets of bits and storing them in variables named X, N, E, and V.
3. Write three shift instructions required to reposition the bits of N, E, and
   V.
4. Write an OR instruction to put the parts together in the shuffled
   orientation.

## Your Task
Write a C function `scramble` in the file `scramble.c` that will take an
unsigned 32-bit integer as a parameter and return an unsigned 32-bit integer
with the rules described above applied. 

Testing your function requires careful choice of test cases. Finish the
basically empty file called `test.c` that contains your main program. Use
comments in the `main` program that describe your test cases and why you chose
them. Create your test bit patterns as hexadecimal values that get sent to your
`scramble` function.

You will create the Makefile yourself. Use the ones from activities as your
guide. **You must provide a makefile so that we can compile and run your code
as follows:**

    make clean
    make 

    ./scramble_bits

Use the functions from the class activities to print the bit pattern of the
values input to and returned from the scramble function to verify its
correctness.

Once you are fairly certain that you have it correct, then use `assert` calls
to verify that the returned value is what you expect for the test cases that
you devise. **You must have a range of tests that are thorough enough to insure
the correctness of your function.** Learning how to do this is important and is
a significant part of your grade for this problem.
