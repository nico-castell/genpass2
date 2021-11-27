#include <fstream>
#include <iostream>
#include <unistd.h>

const int maxASCII = 127;
const int minASCII = 32;
const int differenceASCII = maxASCII - minASCII;

int main(int argc, char* argv[])
{
	// Process arguments
	unsigned long length = 8;

	// The sentence array must be between 1 byte and 4 GiB, so if the number obtained from the srtol
	// function is outside the bounds, the program must exit before attempting to allocate that much
	// memory to the array.
	if (argc > 1)
		length = strtoul(argv[1], NULL, 10);

	if (0 >= length || length > 4294967296)
	{
		std::cerr << "ERROR: First argument is not a valid number\n";
		return 1;
	}

	// Create the sentence array and get the random data
	std::ifstream f("/dev/urandom");
	uint8_t* sentence = new uint8_t[length] { 0 };
	f.read((char*)sentence, length);

	// Process the data into readable characters
	for (unsigned long i = 0; i < length; i++)
	{
		sentence[i] = sentence[i] % differenceASCII;
		sentence[i] = sentence[i] + minASCII;
		std::cout << sentence[i];
	}
	// Do not send the newline character down a pipeline
	if (isatty(fileno(stdout)))
		std::cout << '\n';

	// Clean up
	delete[] sentence;
	f.close();

	return 0;
}
