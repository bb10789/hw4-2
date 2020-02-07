
#include "Rectangle.h"

Rectangle::Rectangle(int frow, int fcol, int lrow, int lcol): frow(frow), fcol(fcol), lrow(lrow), lcol(lcol) {

}

int Rectangle::getfrow() const {
	return frow;
}
int Rectangle::getfcol() const {
	return fcol;
}
int Rectangle::getlrow() const {
	return lrow;
}
int Rectangle::getlcol() const {
	return lcol;
}

int Rectangle::setfrow(int value) {
	frow = value;
}
int Rectangle::setfcol(int value) {
	fcol = value;
}
int Rectangle::setlrow(int value) {
	lrow = value;
}
int Rectangle::setlcol(int value) {
	lcol = value;
}


 ostream& operator<<(ostream& os, const Rectangle& curr) {
	os << "The Rectangle object has a dimension of" << curr.lrow + 1 << " x " << curr.lcol + 1;
}

 bool Rectangle::operator==(const Rectangle& other) const {
	 if (frow == other.frow && fcol == other.fcol && lrow == other.lrow && lcol == other.lcol) {
		 return true;
	 }
	 else {
		 return false;
	 }
}
 bool Rectangle::operator!=(const Rectangle& other) const {
	 !(*this == other);
}