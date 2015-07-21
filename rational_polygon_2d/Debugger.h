#pragma once
#include <fstream>
#include <string>
#include "DigitalSegment.h"

class Debugger {
	static const std::string& log_filename() {
		static const std::string log_filename_str = "log.txt";
		return log_filename_str;
	}

	static void matlab_fill_poly() {
		std::ofstream log_file;
		log_file.open(log_filename());
		log_file.close();
	};
};