#include "algos.hpp"

#include <vector>

namespace faun {
	std::vector<int> bubble_sort(std::vector<int> unsorted_vector) {
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
		return unsorted_vector;
	}

	std::vector<int> merge_sort(std::vector<int> unsorted_vector) { // To be implemented
		return std::vector<int>{ 0, 1, 2, 3 };
	}
}