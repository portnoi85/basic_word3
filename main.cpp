#include "main.h"

int main(int argc, char** argv) {

	// argc - it is a count of arguments
	// But there is some detail - OS always pass one system argument - the name of the executable
	// So, is the application was executed without arguments at all, argc will be still == 1
	int max_value = 100;
	if (argument(argc, argv, max_value) < 0) {
		help(std::string(argv[0]));
		return -1;
	}
	const int target_value = RandomValue(max_value);
	int attempts_count = 0;
	
	std::string user_name;
	//bool not_win = true;
	// Ask about name
	std::cout << "Hi! Enter your name, please:" << std::endl;
	std::cin >> user_name;
	attempts_count = CheckValue(target_value);
	if (attempts_count == 0) {
		return -1;
	}
	std::cout << "you win! attempts = " << attempts_count << std::endl;
    WriteNewHighScore(user_name, attempts_count);
    ReadTheHighScore();
	return 0;
}