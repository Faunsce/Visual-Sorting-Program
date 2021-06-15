#include <iostream>
#include <vector>
#include <algorithm> // std::shuffle
#include <random> // std::random_device, std::mt19937_64
#include <stdexcept> // std::exception
#include "algos.hpp" // 

int main() {
	try {
		const short int SET_RANGE = 1000;

		// Create randomized number generator
		std::random_device rd;
		std::mt19937_64 engine(rd());

		// Create unsorted and sorted vector
		std::vector<int> unsorted_vector;
		for (int i = 0; i < SET_RANGE; i++) {
			unsorted_vector.emplace_back(i);
		}
		std::vector<int> sorted_vector;

		// Randomize
		std::shuffle(unsorted_vector.begin(), unsorted_vector.end(), engine);

		// Read randomized results
		std::cout << "BEGINNING OF RANDOMIZED RESULTS" << std::endl << std::endl;
		for (const auto& index : unsorted_vector) {
			std::cout << index << std::endl;
		}
		std::cout << std::endl << "END OF RANDOMIZED RESULTS" << std::endl;

		// Sort the vector
		std::cout	<< "Please select an option"	<< std::endl 
					<< "[1] : Bubble Sort"			<< std::endl
					<< "[2] : Merge Sort"			<< std::endl;
		int answer = []() {
			int temp;
			std::cin >> temp;
			return temp;
		}();

		switch (answer)
		{
		case 1:
			sorted_vector = faun::bubble_sort(unsorted_vector);
			break;
		case 2:
			sorted_vector = faun::merge_sort(unsorted_vector);
			break;
		default:
			throw std::runtime_error("INVALID INPUT FOR SORTING METHOD");
			break;
		}

		// Check array to validate sorting
		for (int i = 0; i < sorted_vector.size() - 2; i++) {
			if (sorted_vector[i] > sorted_vector[i + 1]) {
				throw std::logic_error("Sorting Failure");
			}
		}

		// Read to show finished sorting
		std::cout << "BEGINNING OF SORTED RESULTS" << std::endl << std::endl;
		for (const auto& index : sorted_vector) {
			std::cout << index << std::endl;
		}
		std::cout << std::endl << "END OF SORTED RESULTS" << std::endl;
		std::cin.ignore(1);
	} catch (const std::exception& e) {
		std::cout << "////////////////// CRITICAL ERROR //////////////////" << std::endl;
		std::cout << e.what() << std::endl;
		std::cout << "////////////////// CRITICAL ERROR //////////////////" << std::endl;
	}
}

// DEVELOPER'S NOTES
/*
Add function to port into multiple algorithm's

Add visualizer

Allow mid sort visualization

Allow mid randomization visualization
*/