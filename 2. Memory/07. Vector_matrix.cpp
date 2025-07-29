import std;
#include "memory_header.h"

int vectorMatrix(){
	int rows{}, cols{};
	std::cout << "Enter number of rows: ";
	std::cin >> rows;
	std::cout << "Enter number of columns: ";
	std::cin >> cols;
	std::cout << std::endl;

	// Create a matrix using comventional constructor syntax
	std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols,0));

	// Input matrix elements from user
	for (int i = 0; i < rows; ++i){
		for (int j = 0; j < cols; ++j){
			std::cout << "Enter element [" << i + 1 << "][" << j + 1 << "]: ";
			std::cin >> matrix[i][j];
		}
	}

	// Output the matrix
	std::cout << "\nThe matrix is: \n";
	for (int i = 0; i < rows; ++i){
		for (int j = 0; j < cols; ++j){
			std::cout << matrix[i][j] << " ";
		}
		std::cout << "\n";
	}

	return 0;
}