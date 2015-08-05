#include <iostream>
#include "steganography.h"

void output_help() {
	std::cout << std::endl
			  << "******** How to use ********" << std::endl
			  << "Writing" << std::endl
			  << "steganography input.png \"A super secret message\"" << std::endl
			  << "****************************" << std::endl
			  << "Reading " << std::endl
			  << "steganography input.png -r" << std::endl
			  << "****************************" << std::endl << std::endl
			  << "Output will be saved as output.png" << std::endl;
}

int main(int argc, char *argv[])
{
	SteganoReaderWriter rw;

	if (argc < 2) {
		output_help();
		exit(1);
	}

	rw.decode_img(argv[1]);

	if (argc == 3) {
		if(strcmp(argv[2], "-r") == 0) {
			std::vector<char> data = rw.read_data();
			std::cout << std::string(data.begin(), data.end());
			exit(0);
		}
		std::string msg = argv[2];
		rw.write_data(std::vector<char>(msg.begin(), msg.end()));
		rw.encode_img("output.png");
	} else {
		output_help();
	}
	
	return 0;
}


