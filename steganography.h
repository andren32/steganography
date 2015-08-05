#ifndef _STEGANOGRAPHY_
#define _STEGANOGRAPHY_

#include <iostream>
#include "lodepng.h"

/**
	Class for naive steganography.
	Can read and write messages to png files.
	
	Messages are stored by breaking down the characters into
	bits and saving each bit in the red channel of a pixel
*/
class SteganoReaderWriter {
private:
	std::vector<unsigned char> img;
	unsigned int width, height;
	bool imgError();
public:
	SteganoReaderWriter();
	~SteganoReaderWriter();
	void decode_img(std::string);
	void encode_img(std::string);
	void write_data(std::vector<char>);
	std::vector<char> read_data();
};

#endif