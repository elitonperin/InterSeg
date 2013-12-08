#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <math.h>
#include <float.h>

using namespace std;


// This class defines a 3-dimensional point
//
// Author: Hamid Badiozamani
//
class Point
{
	public:
		// The default initializer
		//
		Point():_x(0),_y(0),_z(0) { }

		// The initializer constructor
		//
		Point(double x, double y, double z):_x(x),_y(y),_z(z) {}

		// The copy constructor
		//
		Point(const Point& right):_x(right._x),_y(right._y),_z(right._z) {}

		// The accessor functions
		//
		double get_x() const { return _x; }
		double get_y() const { return _y; }
		double get_z() const { return _z; }

		// The rounder versions which use a multiplier. These should only
		// be used for comparisons
		//
		double get_intX() const { return roundPoint(_x); }
		double get_intY() const { return roundPoint(_y); }
		double get_intZ() const { return roundPoint(_z); }

		// The modifier functions
		//
		void set_x(double x) { _x = x; }
		void set_y(double y) { _y = y; }
		void set_z(double z) { _z = z; }

		// A point is "less than" another point if its y-coordinate is less or
		// if the y-coordinates are equal, the x-coordinate is less
		//
		bool operator<(const Point& p) const
		{
			if ( get_y() == p.get_y() )
			{
				if ( get_x() == p.get_x() )
				{
					return get_x() < p.get_x();
				}
				else
				{
					return get_z() < p.get_z();
				}
			}
			else
			{
				return get_y() < p.get_y();
			}
		}

		// Whether the two points are equal
		//
		bool operator==(const Point& p) const
		{
			return (get_x() == p.get_x() && get_y() == p.get_y() && get_z() == p.get_z() );
		}

		// Whether a point is greater than another point
		//
		bool operator>(const Point& p) const
		{
			// A point is greater than the other if it is not less than or equal
			//
			return !( (*this) < p || (*this)==p );
		}

		// Whether a point is less than or equal
		//
		bool operator<=(const Point& p) const
		{
			return ((*this) < p || (*this == p));
		}

		// Whether a point is greater than or equal
		//
		bool operator>=(const Point& p) const
		{
			// A point is greater-than or equal if it is NOT less than the other
			//
			return !((*this) < p);
		}

		friend ostream& operator<<(ostream& out, const Point& p);
		friend istream& operator>>(istream& in, Point& p) throw (ios::failure);

		// This is the number to multiply with to preserve precision before rounding the
		// double values into integers
		//
		static int roundPoint(double x) { return round(x * PRECISION_MULTIPLIER); }

		// The maximum/minimum values of a point coordinate
		//
		static const double MAX() { return DBL_MAX / PRECISION_MULTIPLIER; }
		static const double MIN() { return DBL_MIN / PRECISION_MULTIPLIER; }
	private:

		// The precision multiplier (how much to preserve when rounding into integers)
		//
		static const int PRECISION_MULTIPLIER = 10;

		// The x-coodinate
		//
		double _x;

		// The y-coodinate
		//
		double _y;

		// The z-coodinate
		//
		double _z;
};
#endif
