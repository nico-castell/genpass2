#include <fstream>
#include <iostream>

const int maxASCII = 127;
const int minASCII = 32;
const int differenceASCII = maxASCII - minASCII;

int main(int argc, char* argv[])
{
	// Process arguments
	int64_t length = 8;

	if (argc > 1)
		length = strtol(argv[1], NULL, 10);

	if (length <= 0)
	{
		fprintf(stderr, "ERROR: First argument is not a valid number\n");
		return 1;
	}

	// Get the random data
	std::ifstream f("/dev/urandom");
	uint8_t* sentence = new uint8_t[length + 1] { 0 };
	f.read((char*)sentence, length);

	// Process the data into readable characters
	for (int64_t i = 0; i < length; i++)
	{
		sentence[i] = sentence[i] % differenceASCII;
		sentence[i] = sentence[i] + minASCII;
		std::cout << sentence[i];
	}

	std::cout << std::endl;

	// Clean up
	delete[] sentence;
	f.close();

	return 0;
}
