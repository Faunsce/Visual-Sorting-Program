#include <iostream>
#include <vector>
#include <random>

const short int SET_RANGE = 1000;
int main() {
	std::vector<int> unsorted_vector;
	for (int i = 0; i < SET_RANGE; i++) {
		unsorted_vector.emplace_back(i);
	}
	for (const auto& index : unsorted_vector) {
		std::cout << index << std::endl;
	}
	std::cin.ignore(1);
}