#include "AvlTree.h"
#include "Point.h"

// This program implements the line sweep algorithm
//
int main(int argc, char* argv[])
{
	AvlTree<Point> t;

	cout << "**************************************************" << endl;
	cout << "Tree is empty at this point" << endl;
	t.printTree();
	cout << "**************************************************" << endl;

	cout << "Waiting for input" << endl;

	// Read in a bunch of points from the standard input
	//
	cin.exceptions( ios_base::eofbit | ios_base::failbit | ios_base::badbit );

	// Read the line segments
	//
	for (int i = 1; cin.good(); i++ )
	{
		Point p;

		try
		{
			// Read in a point from the input
			//
			cin >> p;

			cout << "Read in point " << p << " adding to the tree" << endl;

			// Add the point to our tree
			//
			t.insert(p);
		}
		catch (ios_base::failure& e)
		{
			// Most likely we've just hit the end of the file
			//
			if ( !cin.eof() )
			{
				cerr << e.what() << " on line " << i << endl;
			}
		}
	}
	cout << "Done reading input" << endl;
	cout << "**************************************************" << endl;
	t.printTree();
	cout << "**************************************************" << endl;

	// Perform a range query
	//
	vector<Point*> inRange;

	// Our operator< on Point only cares about y values, but we need
	// the same "types" for comparison
	//
	Point min(0, 150, 0);
	Point max(0, 350, 0);

	t.rangeQuery(inRange, min, max, false);

	cout << "Printing out points with y-coordinates between " << min.get_y() << " and " << max.get_y() << endl;
	for (vector<Point*>::const_iterator it = inRange.begin(); it != inRange.end(); it++ )
	{
		cout << *(*it) << endl;
	}
	cout << "**************************************************" << endl;
}
