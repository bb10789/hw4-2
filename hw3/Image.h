#pragma once

// Header file for the Image class that has the ability to save and make changes to an image
// Kelvin Kam
#include <iostream>
#include "ImageLib.h"
using namespace std;

class Image {
public:
	// constructor: parameter is a string of the directory of the image
	// precondition: filename must be an valid file name
	Image(string filename);

	// constructor:: parameter is the height and width of the blank image to be created
	Image(int height = 0, int width = 0);

	//constructor: parameter is an image object that will be copied as an instance of the new Image object
	Image(const Image& source);

	// destructor: Deallocate the image instance of the object, image value will be set to 
	// col, row = 0 pixels = nullptr
	~Image();

	// Overloaded = Checks for self assignment. if not, set current iamge to input image
	const Image& operator=(const Image&);

	// getCol: return the number of column in the current Image object
	// precondition: none
	// postcondition: the number of columns will be returned
	int getCol() const;

	// getRow: return the number of row in the current Image object
	// precondition: none
	// postcondition: the number of rows will be returned
	int getRow() const;

	// getPixel: get the pixel with the given row and col parameters
	// precondition: the given row and column values must not exceed the limit of the image dimension
	// postcondition: return the pixel at the given position
	const pixel getPixel(int x, int y) const;

	// changePixel: change the RGB values of pixel 
	// precondition: the given row and column values must not exceed the limit of the image dimension
	// the given RGB values must not exceed 256 or less than 0
	// postcondition: The pixel at the given position will be change accordingly with the given RGB values
	void changePixel(int row, int col, int red, int green, int blue);

	// outputToFile: output the current image as a GIF with the specified file name
	// precondition: given filename must not be and the filename must be valid
	// postcondition: An image will be created with the given file name
	void ouputToFile(string fileName);

	// comparison operators
	// overloaded ==, the given Image must exactly match the current image pixel by pixel, the image dimensions
	// must also be the same. If both requirements are met, return true, otherwise false
	bool operator==(const Image&) const;

	// overloaded !=, Return true if there is any image pixel or dimension differences between the current image instance
	// and the given Image object, otherwise, return true if both image is the same
	bool operator!=(const Image&) const;

	// overloaded < Return true if the given Image has more pixels than the current image, otherwise return false
	bool operator<(const Image&) const;

	// overloaded > Return true if the current image has more pixels than the given image, otherwise return false
	bool operator>(const Image&) const;

	// overloaded << Output the number of column and rows of the current Image, ignoring the pixels
	friend ostream& operator<<(ostream& os, const Image&);
	ostream& operator<<(const Image&);

	// mirror: Return a mirrored image that has been reversed from left to right
	// PreCondition: the input image x has x.rows * x.cols pixels allocated,
	// the input image's width must be a even number
	// postCondition: A new image object is returned that is based on the mirror of the input image
	Image mirror();
private:
	image img;


};