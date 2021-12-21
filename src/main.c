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
		fprintf(stderr, "ERROR: First argument is not a valid or acceptable number.\n");
		return 1;
	}

	// We open /dev/urandom with fopen(), if the pointer returned by the function is NULL, we know
	// we couldn't open the file, so we halt the program.
	FILE* urandom = fopen("/dev/urandom", "rb");  // /dev/urandom file
	if (urandom == NULL)
	{
		fprintf(stderr, "ERROR: Could not open /dev/urandom.\n");
		return 3;
	}

	// We create an array in the heap, and we'll use a pointer to it's tail to stop the main loop
	// later.
	unsigned char *h, *t;
	h = malloc(length);
	t = h + length;

	// Bail out to prevent segfaults if malloc fails
	if (h == NULL)
	{
		fprintf(stderr, "ERROR: Could not allocate memory for the password.\n");
		return 2;
	}

	// Read all the random data at once, handle errors in reading by bailing out.
	if (fread(h, 1, length, urandom) != length)
	{
		fclose(urandom);
		urandom = NULL;
		free(h);
		h = NULL, t = NULL;

		fprintf(stderr, "ERROR: Problem reading from /dev/urandom.\n");
		return 4;
	}

	// Process all the data using a moving pointer
	for (unsigned char* p = h; p < t; ++p)
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
