#include "argument.h"
#include "high_scores.h"

#include <iostream>

static int levels[] = {10, 50, 100};

int argument(int argc, char** argv, int &max_value) {
	int level = -1;
	// argc - it is a count of arguments
	// But there is some detail - OS always pass one system argument - the name of the executable
	// So, is the application was executed without arguments at all, argc will be still == 1
	int i = 1;
	while (argc > i) {
		std::string arg_value{argv[i]};
		++i;
		if (arg_value == "-max") {
			if (level > 0 ) {
				return -1;
			}
			// We've detected the '-max' argument. And we extect that after this argument there is a value:
			if (argc < i + 1) {
				return -1;
			}
			// We need to parse the string to the int value
			max_value = std::stoi(argv[i]);
			++i;
			if (max_value <= 0) {
				std::cout << "the maximum value must be greater than 0!" << std::endl;
				return -1;
			}
			level = 0;
			continue;
		}
		if (arg_value == "-level") {
			if ( level == 0) {
				return -1;
			}
			if (argc < i + 1) {
				return -1;
			}
			level = std::stoi(argv[i]);
			++i;
			int max_level = sizeof(levels)/sizeof(levels[0]);
			if ((level <= 0) || (level > max_level)) {
				return -1;
			}
			max_value = levels[level - 1];
			std::cout << "max_value = " << max_value << std::endl;
			continue;
		}
		if (arg_value == "-table") {
			ReadTheHighScore();
			exit(0);
		}
		return -1;
	}
	return 0;
}

void help(std::string name) {
	std::cout << "usage: guess_the_number [-max <max_value>]" << std::endl;
	std::cout << "                        [-levet <num>] " << std::endl;
	std::cout << "                        [-table]" << std::endl;
	int max_level = sizeof(levels)/sizeof(levels[0]);
	for (int i = 0; i < max_level; ++i) {
		std::cout << "level " << i+1 << ": ";
		std::cout << "max_value = " << levels[i] << std::endl;
	}
	return;
}