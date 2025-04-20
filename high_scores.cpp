#include "high_scores.h"
#include "map"
const std::string high_scores_filename = "high_scores.txt";

// Write new high score to the records table
int WriteNewHighScore(std:: string current_name, int score) {
	std::ofstream out_file{high_scores_filename, std::ios_base::app};
	if (!out_file.is_open()) {
		std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
		return -1;
	}
	out_file.close();
	std::ifstream in_file{high_scores_filename};
	if (!in_file.is_open()) {
		std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
		return -1;
	}
	std::string user_name;
	int high_score = 0;
	std::map<std::string, int> results;
	while (true) {
		// Read the user name first
		in_file >> user_name;
		// Read the high score next
		in_file >> high_score;
		// Ignore the end of line symbol
		in_file.ignore();
		if (in_file.fail()) {
			break;
		}
		auto i = results.find(user_name);
		if ((i == results.end()) || (i->second > high_score)) {
			results[user_name] = high_score;
		}
		// Print the information to the screen
	}
	in_file.close();

	auto i = results.find(current_name);
	if ((i == results.end()) || (i->second > score)) {
		results[current_name] = score;
	}
	// We should open the output file in the append mode - we don't want
	// to erase previous results.
	out_file.open(high_scores_filename, std::ios_base::trunc);
	if (!out_file.is_open()) {
		std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
		return -1;
	}
	i = results.begin();
	while (i !=results.end()) {
		out_file << i->first << ' ';
		out_file << i->second;
		out_file << std::endl;
		++i;
	}
	// Append new results to the table:
	return 0;
}

// Read the high score file and print all results
int ReadTheHighScore() {
	std::ifstream in_file{high_scores_filename};
	if (!in_file.is_open()) {
		std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
		return -1;
	}
	std::cout << "High scores table:" << std::endl;
	std::string user_name;
	int high_score = 0;
	while (true) {
		// Read the user name first
		in_file >> user_name;
		// Read the high score next
		in_file >> high_score;
		// Ignore the end of line symbol
		in_file.ignore();

		if (in_file.fail()) {
			break;
		}

		// Print the information to the screen
		std::cout << user_name << '\t' << high_score << std::endl;
	}
	return 0;
}