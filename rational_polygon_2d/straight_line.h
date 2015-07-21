#pragma once
#include<complex>
#include<fstream>
#include<iostream>
#include<vector>

/* 
Generate pixels for a straight line b*y = a*x + c, where c = 0.
n is the cardinality of digitale straight line i.e. number of pixels in its representation
*/
void generate_straight_line(int a, int b, int n) {
	std::vector<std::complex<int>> straight_line;
	straight_line.reserve(n);
	// Generate straight line (refer to course notes "Droites_Transparents")
	int x = 0, y = 0, r = 0;
	for(size_t i = 0; i < (n - 1); i++) {
		if(r < b - a) {
			r += a;
			x++;
			std::complex<int> xy(x, y);
			straight_line.push_back(xy);
		} else {
			r = r - b + a;
			x++; y++;
			std::complex<int> xy(x, y);
			straight_line.push_back(xy);
		}
		std::cout << x << " " << y << std::endl;
	}

	// Save segment to a text file
	std::ofstream fileToSave;
	fileToSave.open("segments/segment.txt");
	for(size_t i = 0; i < straight_line.size(); i++) {
		fileToSave << straight_line[i].real() << " " << straight_line[i].imag() << std::endl;
	}
	fileToSave.close();
}