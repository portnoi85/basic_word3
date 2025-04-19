#include <cstdlib>
#include <ctime>

int RandomValue() {
	static bool not_init = true;
	const int max_value = 100;
	if (not_init) {
		std::srand(std::time(nullptr)); // use current time as seed for random generator
		not_init = false;
	}
	return std::rand() % max_value;
}