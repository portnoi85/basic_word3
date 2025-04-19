#include "argument.h"
#include "high_scores.h"

#include <iostream>

int argument(int argc, char** argv, int &max_value) {
	// argc - it is a count of arguments
	// But there is some detail - OS always pass one system argument - the name of the executable
	// So, is the application was executed without arguments at all, argc will be still == 1

	if (argc >= 2) {
		std::string arg1_value{ argv[1] };
		if (arg1_value == "-max") {
			// We've detected the '-max' argument. And we extect that after this argument there is a value:
			if (argc < 3) {
				std::cout << "Wrong usage! The argument '-max' requires some value!" << std::endl;
				return -1;
			}
			// We need to parse the string to the int value
			max_value = std::stoi(argv[2]);
		}
	}
	return 0;
}
