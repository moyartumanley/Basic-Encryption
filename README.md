```
    --------------------------------------
    |xxxx|nnnnnnnnnnn|eee|vvvvvvvvv|xxxxx|
    --------------------------------------
    31-28   27-17    16-14   13-5    4-0
```
## Encryption:
The bits will be manipulated according to the following rules.
* The bits in the positions labeled x are not moved.
* The bit field labeled n swaps positions with the bit field labeled v: the
  rightmost bit of n moves to position 5 and the leftmost bit of v shifts to
  position 27.
* The field labeled e moves two positions to the left to make room for the swap
  of the n and v bits.

## Makefile:

Code can be ran as follows:**

    make clean
    make 

    ./scramble_bits
