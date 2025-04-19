#include "check_value.h"

int CheckValue(int target_value) {
	int current_value = 0;
	int attempts = 1;
	std::cout << "Enter your guess:" << std::endl;
	do {
		std::cin >> current_value;
		if (std::cin.fail()) {
			//std::cin.clear();
			//std::cin.ignore();
			std::cout << "Bad value!" << std::endl;
			return 0;
			//continue;
		}
		if (current_value > target_value) {
			std::cout << "less than " << current_value << std::endl;
		}
		else if (current_value < target_value) {
			std::cout << "greater than " << current_value << std::endl;
		}
		else {
			return attempts;
		}
		++attempts;
	} while(true);
}