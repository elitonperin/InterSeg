#include "Point.h"

ostream& operator<<(ostream& out, const Point &p)
{
	return out << "(" << p._x << "," << p._y << "," << p._z << ")";
}

istream& operator>>(istream& in, Point &p) throw (ios::failure)
{
	// This character is used for the formatting characters
	//
	char tmp;

	// Attempt to read the stream
	//
	in >> tmp;	// (
	in >> p._x;	// <x-value>
	in >> tmp;	// ,
	in >> p._y;	// <y-value>
	in >> tmp;	// ,
	in >> p._z;	// <z-value>
	in >> tmp;	// )

	// We've read successfully
	//
	return in;
}
