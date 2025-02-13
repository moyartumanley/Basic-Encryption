/*
 * scramble_bits
 * Author: Moyartu Manley
 */

/*
 * This function returns an int that has been scrambled according
 * to the rules set forth in the problem description.
 *
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>
int scramble(int input)
{
	int x1_AND_mask = 0xF0000000; // Bits 31-28
	int n_AND_mask = 0x0FFE0000;  // Bits 27-17
	int e_AND_mask = 0x0001C000;  // Bits 16-14
	int v_AND_mask = 0x00003FE0;  // Bits 13-5
	int x2_AND_mask = 0x0000001F; // Bits 4-0

	int X1 = input & x1_AND_mask;
	int N = input & n_AND_mask;
	int E = input & e_AND_mask;
	int V = input & v_AND_mask;
	int X2 = input & x2_AND_mask;

	int repositioned_N = (N >> 12);
	int repositioned_V = (V << 14);
	int repositioned_E = (E << 2);

	int scrambled_bits = X1 | repositioned_N | repositioned_E | repositioned_V | X2;

	return scrambled_bits; // !!!!!!!!!!! replace this- do not keep !!!!!
}
