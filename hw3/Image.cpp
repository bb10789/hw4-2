#include "Image.h"
#include <iostream>

// Class file for the Image class that has the ability to save and make changes to an image
// Kelvin Kam


// constructor: parameter is a string of the directory of the image
// precondition: filename must be an valid file name
Image::Image(string filename) {
	img = ReadGIF(filename);
}

// constructor:: parameter is the height and width of the blank image to be created
Image::Image(int height, int width) {
	img = CreateImage(height, width);
}

//constructor: parameter is an image object that will be copied as an instance of the new Image object
Image::Image(const Image& source) {
	img = CopyImage(source.img);
}

// destructor: Deallocate the image instance of the object, image value will be set to 
// col, row = 0 pixels = nullptr
Image::~Image() {
	DeallocateImage(img);
}

// Overloaded = Checks for self assignment. if not, set current iamge to input image
const Image& Image::operator=(const Image& input) {
	if (this != &input) {
		DeallocateImage(img);
		img = CopyImage(input.img);
	}
	return *this;
}

// getCol: return the number of column in the current Image object
// precondition: none
// postcondition: the number of columns will be returned
int Image::getCol() const {
	return img.cols;
}

// getRow: return the number of row in the current Image object
// precondition: none
// postcondition: the number of rows will be returned
int Image::getRow() const {
	return img.rows;
}

// getPixel: get the pixel with the given row and col parameters
// precondition: the given row and column values must not exceed the limit of the image dimension
// postcondition: return the pixel at the given position, the returned pixel can not be assigned 
// into a new value
const pixel Image::getPixel(int row, int col) const {
	return img.pixels[row][col];
}

// changePixel: change the RGB values of pixel 
// precondition: the given row and column values must not exceed the limit of the image dimension
// the given RGB values must not exceed 256 or less than 0
// postcondition: The pixel at the given position will be change accordingly with the given RGB values
void Image::changePixel(int row, int col,int red, int green, int blue) {
	pixel& changePixel = img.pixels[row][col];
	changePixel.red = red;
	changePixel.green = green;
	changePixel.blue = blue;
}

// outputToFile: output the current image as a GIF with the specified file name
// precondition: given filename must not be and the filename must be valid
// postcondition: An image will be created with the given file name
void Image::ouputToFile(string fileName) {
	WriteGIF(fileName, img);
}

// overloaded ==, the given Image must exactly match the current image pixel by pixel, the image dimensions
// must also be the same. If both requirements are met, return true, otherwise false
bool Image::operator==(const Image& img2) const {
	if (img.cols != img2.img.cols || img.rows != img2.img.rows) {
		return false;
	}
	for (int row = 0; row < img.rows; row++) {
		for (int col = 0; col < img.cols; col++) {
			pixel pixel1 = img.pixels[row][col];
			pixel pixel2 = img2.img.pixels[row][col];
			if (pixel1.red != pixel2.red || pixel1.green != pixel2.green || pixel1.blue != pixel2.blue) {
				return false;
			}
		}
	}
	return true;
}

// overloaded !=, Return true if there is any image pixel or dimension differences between the current image instance
// and the given Image object, otherwise, return true if both image is the same
bool Image::operator!=(const Image& img2) const {
	if (img.cols != img2.img.cols || img.rows != img2.img.rows) {
		return true;
	}

	for (int row = 0; row < img.rows; row++) {
		for (int col = 0; col < img.cols; col++) {
			pixel pixel1 = img.pixels[row][col];
			pixel pixel2 = img2.img.pixels[row][col];
			if (pixel1.red != pixel2.red || pixel1.green != pixel2.green || pixel1.blue != pixel2.blue) {
				return true;
			}
		}
	}
	return false;
}

// overloaded < Return true if the given Image has more pixels than the current image, otherwise return false
bool Image::operator<(const Image& img2) const {
	return ((img.cols * img.rows) - (img2.img.cols * img2.img.rows)) < 0;
}

// overloaded > Return true if the current image has more pixels than the given image, otherwise return false
bool Image::operator>(const Image& img2) const {
	return ((img.cols * img.rows) - (img2.img.cols * img2.img.rows)) > 0;
}

// overloaded << Output the number of column and rows of the current Image, ignoring the pixels
ostream& operator<<(ostream& os, const Image& gif1) {
	os << "The GIF image has a pixel size of " << gif1.img.rows << " x " << gif1.img.cols;
	return os;
}

// mirror: Return a mirrored image that has been reversed from left to right
// PreCondition: the input image x has x.rows * x.cols pixels allocated,
// the input image's width must be a even number
// postCondition: A new image object is returned that is based on the mirror of the input image
Image Image::mirror() {
	Image mirrored(*this);
	pixel temp;
	image& mirroredRef = mirrored.img;
	for (int row = 0; row < mirroredRef.rows; row++) {
		for (int col = 0; col < mirroredRef.cols / 2; col++) {
			temp = mirroredRef.pixels[row][col];
			mirroredRef.pixels[row][col] = mirroredRef.pixels[row][mirroredRef.cols - col - 1];
			mirroredRef.pixels[row][mirroredRef.cols - col - 1] = temp;
		}
	}
	return mirrored;
}