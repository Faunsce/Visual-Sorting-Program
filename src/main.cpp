#include <iostream>
#include <vector>
#include <algorithm> // std::shuffle
#include <random> // std::random_device, std::mt19937_64
#include <stdexcept> // std::exception

int main() {
	try {
		const short int SET_RANGE = 1000;

		// Create randomized number generator
		std::random_device rd;
		std::mt19937_64 engine(rd());

		// Create vector
		std::vector<int> unsorted_vector;
		for (int i = 0; i < SET_RANGE; i++) {
			unsorted_vector.emplace_back(i);
		}

		// Randomize
		std::shuffle(unsorted_vector.begin(), unsorted_vector.end(), engine);

		// Read randomized results
		std::cout << "BEGINNING OF RANDOMIZED RESULTS" << std::endl << std::endl;
		for (const auto& index : unsorted_vector) {
			std::cout << index << std::endl;
		}
		std::cout << std::endl << "END OF RANDOMIZED RESULTS" << std::endl;

		// Sort the vector

		// Bubble Sort
		bool clean = false; // Flag
		while (!clean) {
			for (int i = unsorted_vector.size() - 1; i >= 0 - 1; i--) {
				clean = true; // Temporarily set flag to clean
				for (int j = 0; j < i; j++) {
					if (unsorted_vector[j] > unsorted_vector[j + 1]) { // Comparison adjacent values
						clean = false; // Array is not clean, reset flag
						int temp = unsorted_vector[j]; // Store higher number
						unsorted_vector[j] = unsorted_vector[j + 1]; // Swap lower number thats ahead into higher numbers lower index in vector
						unsorted_vector[j + 1] = temp; // Re-introduce store higher value to position ahead of now-moved lower number
					}
				}
			}
		}

		// Check array to validate sorting
		for (int i = 0; i < unsorted_vector.size() - 2; i++) {
			if (unsorted_vector[i] > unsorted_vector[i + 1]) {
				throw std::logic_error("Sorting Failure");
			}
		}

		// Read to show finished sorting
		std::cout << "BEGINNING OF SORTED RESULTS" << std::endl << std::endl;
		for (const auto& index : unsorted_vector) {
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