#pragma once

#include<complex>
#include<fstream>
#include<iostream>
#include<string>
#include<vector>

// FIXME: add boost lib to the project
#include"boost\numeric\ublas\matrix.hpp"
#include <boost\rational.hpp>

using namespace boost::numeric::ublas;

/* 
Generate pixels for a straight line b*y = a*x + c, where c = 0.
n is the cardinality of digitale straight line i.e. number of pixels in its representation
*/
void generate_straight_line(float a, float b, int n) {
	std::vector<std::complex<int>> straight_line;
	straight_line.reserve(n);
	// Generate straight line (refer to course notes "Droites_Transparents")
	int x = 0, y = 0;
	float r = 0.0f;
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
	fileToSave << straight_line.size() << std::endl;
	for(size_t i = 0; i < straight_line.size(); i++) {
		fileToSave << straight_line[i].real() << " " << straight_line[i].imag() << std::endl;
	}
	fileToSave.close();
}

matrix<int> *build_straight_line_from_file(std::string S) {
	std::ifstream fileToRead;
	fileToRead.open(S);
	size_t numOfLines = 0;
	fileToRead >> numOfLines;
	
	matrix<int> *M = new matrix<int>(numOfLines, 2);
	//numOfLines++;

	int x = 0, y = 0;
	for(size_t i = 0; i < numOfLines; i++) {
		fileToRead >> x >> y;
		M->insert_element(i, 0, x);
		M->insert_element(i, 1, y);
	}

	fileToRead.close();

	return M;
}