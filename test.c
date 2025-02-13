/*
 * Test of scramble function as defined in scramble.c
 */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "scramble.h"
#include "binary_convert.h"
// function declarations

int main(int argc, char *argv[])
{
	int input;
	int scrambled_input;
	char *input_bin_str;
	char *scrambled_bin_str;
	int expected;

	// Test Case 1: Binary string of all zeros
	input = 0x00000000;
	input_bin_str = int_to_bin_str(input);

	scrambled_input = scramble(input);
	scrambled_bin_str = int_to_bin_str(scrambled_input);

	// Expected outcome:
	expected = 0x00000000;

	// Testing print-statments:
	printf("Input value:     %x | Binary: %s \n", input, input_bin_str);
	printf("Scrambled value: %x | Binary: %s \n\n", scrambled_input, scrambled_bin_str);
	assert(expected == scrambled_input);

	// Freeing memory:
	free(input_bin_str);
	free(scrambled_bin_str);


	// Test Case 2: Binary string of all ones
	input = 0xFFFFFFFF;
	input_bin_str = int_to_bin_str(input);

	scrambled_input = scramble(input); //masks should be the same as their original due to input consisting of ones
	scrambled_bin_str = int_to_bin_str(scrambled_input);

	// Expected outcome:
	expected = 0xFFFFFFFF;

	// Testing print-statments:
	printf("Input value:     %x | Binary: %s \n", input, input_bin_str);
	printf("Scrambled value: %x | Binary: %s \n\n", scrambled_input, scrambled_bin_str);
	assert(expected == scrambled_input);

	// Freeing memory:
	free(input_bin_str);
	free(scrambled_bin_str);


	// Test Case 3: Alternating bits (1 first)
	input = 0xAAAAAAAA;
	input_bin_str = int_to_bin_str(input);

	scrambled_input = scramble(input);
	scrambled_bin_str = int_to_bin_str(scrambled_input);

	// Expected outcome:
	expected = 0xAAAAAAAA;

	// Testing print-statments:
	printf("Input value:     %x | Binary: %s \n", input, input_bin_str);
	printf("Scrambled value: %x | Binary: %s \n\n", scrambled_input, scrambled_bin_str);
	assert(expected == scrambled_input);

	// Freeing memory:
	free(input_bin_str);
	free(scrambled_bin_str);

	// Test Case 4: Alternating bits (0 first)
	input = 0x55555555;
	input_bin_str = int_to_bin_str(input);

	scrambled_input = scramble(input);
	scrambled_bin_str = int_to_bin_str(scrambled_input);

	// Expected outcome:
	expected = 0x55555555;

	// Testing print-statments:
	printf("Input value:     %x | Binary: %s \n", input, input_bin_str);
	printf("Scrambled value: %x | Binary: %s \n\n", scrambled_input, scrambled_bin_str);
	assert(expected == scrambled_input);

	// Freeing memory:
	free(input_bin_str);
	free(scrambled_bin_str);

	// Test Case 5: Non-repeating nibbles
	input = 0xABCD1234;
	input_bin_str = int_to_bin_str(input);

	scrambled_input = scramble(input);
	scrambled_bin_str = int_to_bin_str(scrambled_input);

	// Expected outcome:
	expected = 0xa48cbcd4;

	// Testing print-statments:
	printf("Input value:     %x | Binary: %s \n", input, input_bin_str);
	printf("Scrambled value: %x | Binary: %s \n\n", scrambled_input, scrambled_bin_str);
	assert(expected == scrambled_input);

	// Freeing memory:
	free(input_bin_str);
	free(scrambled_bin_str);
	return 0;

}
