// predicate_2d.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "digital_segment.h"

int _tmain(int argc, _TCHAR* argv[])
{
	// Create dummy digital segment
	const size_t n = 9;
	DigitalSegment ds;
	std::cout << ds.length() << "\n";

	int x[n] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	int y[n] = {0, 0, 1, 2, 3, 3, 4, 4, 5};
	for(size_t i = 0; i < n; i++)
	{
		ds.push_back(Pixel(x[i], y[i]));
	}	
	std::cout << ds.length() << "\n";
	//std::cout<<ds;

	// Get m-b region of the segment (y = m*x + b)
	ds.constraint_mb_region();

	//std::cout << ds.mb_region();

	// Wait until user input
	char c;
	std::cin >> c;
	return 0;
}

