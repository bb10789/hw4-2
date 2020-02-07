#pragma once

#include <iostream>
using namespace std;

class Rectangle {
public:
	Rectangle(int frow, int fcol, int lrow, int lcol);
	int getfrow() const;
	int getfcol() const;
	int getlrow() const;
	int getlcol() const;
	int setfrow(int value);
	int setfcol(int value);
	int setlrow(int value);
	int setlcol(int value);
	friend ostream& operator<<(ostream& os, const Rectangle&);
	bool operator==(const Rectangle&) const;
	bool operator!=(const Rectangle&) const;	

private:
	int frow;
	int fcol;
	int lrow;
	int lcol;
};