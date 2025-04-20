#include "high_scores.h"
#include "map"

const std::string high_scores_filename = "high_scores.txt";

// Write new high score to the records table
int WriteNewHighScore(std:: string user_name, int attempts_count) {
	// We should open the output file in the append mode - we don't want
	// to erase previous results.
	std::ofstream out_file{high_scores_filename, std::ios_base::app};
	if (!out_file.is_open()) {
		std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
		return -1;
	}
	// Append new results to the table:
	out_file << user_name << ' ';
	out_file << attempts_count;
	out_file << std::endl;
	return 0;
}

// Read the high score file and print all results
int ReadTheHighScore() {
	std::ifstream in_file{high_scores_filename};
	std::map<std::string, int> results;
	if (!in_file.is_open()) {
		std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
		return -1;
	}
	std::cout << "High scores table:" << std::endl;
	std::string username;
	int high_score = 0;
	while (true) {
		// Read the username first
		in_file >> username;
		// Read the high score next
		in_file >> high_score;
		// Ignore the end of line symbol
		in_file.ignore();

		if (in_file.fail()) {
			break;
		}
		auto i = results.find(username);
		if ( (i == results.end()) || (i->second > high_score)) {
			results[username]=high_score;
		}
		// Print the information to the screen
	}
	auto i = results.begin();
	while (i != results.end()) {
		std::cout << i->first << '\t' << i->second << std::endl;
		++i;
	}
	return 0;
}