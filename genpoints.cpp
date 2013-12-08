#include "Point.h"

#include <iostream>

using namespace std;

// This program generates random points
//

void generatePoint(Point& a, int maxx, int maxy, int maxz)
{
	long randx = random() % maxx;
	long randy = random() % maxy;
	long randz = random() % maxy;

	a.set_x(randx);
	a.set_y(randy);
	a.set_z(randz);
}

int main(int argc, char* argv[])
{
	if ( argc == 1 )
	{
		cout << "Usage: " << argv[0] << " <number of points> [<max x> <max y> <max z>] " << endl;
	}
	else
	{
		// Initialize the random number generator
		//
		srandom(time(NULL));

		// Number of points to generate
		//
		int n = atoi(argv[1]);

		int maxx, maxy, maxz;
		if ( argc > 2 ) { maxx = atoi(argv[2]); } else { maxx = 1000; }
		if ( argc > 3 ) { maxy = atoi(argv[3]); } else { maxy = 1000; }
		if ( argc > 4 ) { maxz = atoi(argv[3]); } else { maxz = 1000; }

		for (int i = 0; i < n; i++ )
		{
			Point p;
			generatePoint(p, maxx, maxy, maxz);

			cout << p << endl;
		}
	}
}
