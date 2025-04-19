#include "main.h"

int main() {
	const int target_value = RandomValue();
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