#steganography
Simple naive steganography in c++

Can write and read strings in a png file

Works by breaking every character in the string into bits and writing
each bit into the least significant bit in the red channel of the pixels

Uses lodepng for encoding and decoding png
http://lodev.org/lodepng/
