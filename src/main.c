#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// MIT License - Copyright (c) 2021 Nicolás Castellán <cnicolas.developer@gmail.com>
// SPDX License identifier: MIT
// THE SOFTWARE IS PROVIDED "AS IS"
// Read the included LICENSE file for more information

// Use ASCII characters between 32 and 126
#define MIN_ASCII 32
#define DIFF_ASCII 95

int main(int argc, char* argv[])
{
	unsigned long long length = 8;

	if (argc > 1)
		length = atoll(argv[1]);

	// Keep the array in a "reasonable" size, no more than 4GiB because it has to be allocated in
	// memory to get crazy fast read speeds.
	if (0 >= length || length > 4294967296)
	{
		fprintf(stderr, "ERROR: First argument is not a valid number\n");
		return 1;
	}

	// Prepare reception of random data
	FILE* urandom = fopen("/dev/urandom", "rb");  // /dev/urandom file

	unsigned char *h, *t;                                  // Pointers to head and tail of the array
	int size_diff = (length + 1) * sizeof(unsigned char);  // Get the size in bytes of the array
	h = malloc(size_diff);                                 // Allocate memory for the array
	t = h + size_diff;                                     // Point t to the tail of the array

	// Bail out to prevent segfaults if malloc fails
	if (h == NULL)
	{
		fprintf(stderr, "ERROR: Could not allocate memory for the password.\n");
		return 2;
	}

	// Read all the random data at once
	fgets((char*)h, size_diff / sizeof(unsigned char), urandom);

	// Process all the data using a moving pointer
	for (unsigned char* p = h; p < t; p += sizeof(unsigned char))
	{
		*p = *p % DIFF_ASCII;
		*p = *p + MIN_ASCII;
	}

	printf("%s", h);
	if (isatty(fileno(stdout)))
		printf("\n");

	// Clean up
	fclose(urandom);
	urandom = NULL;
	free(h);
	h = NULL, t = NULL;

	return 0;
}
