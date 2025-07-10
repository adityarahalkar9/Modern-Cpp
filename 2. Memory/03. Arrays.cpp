import std;
#include "memory_header.h"

int arrays(){
	int arr[5];						// Uninitialised array
	int Balance[10]{};				// Zero initialised array of size 10
	int Example[5] = {1,2,3,4,5};	// Initialised array
	int ID[] = {1,2,3,4,5};			// Size inferred from initialiser
	int Partial[3] = {1,2};			// Partial array

	std::cout << "Balance array is declared with 10 elements as zero" << std::endl;
	for (int i = 0; i < std::size(Balance); ++i){
		std::cout << Balance[i] << " ";
	}
	std::cout << "\n" << std::endl;

	std::cout << "Example array is inititalized with 5 elements and assigned values" << std::endl;
	for (int i = 0; i < std::size(Example); ++i) {
		std::cout << Partial[i] << " ";
	}
	std::cout << "\n" << std::endl;

	std::cout << "ID Array is initialised with values without declaring its size" << std::endl;
	for (int i = 0; i < std::size(ID); ++i) {
		std::cout << ID[i] << " ";
	}
	std::cout << "\n" << std::endl;

	std::cout << "Partial array is given 3 size with 2 elements" << std::endl;
	for (int i = 0; i < std::size(Partial); ++i) {
		std::cout << Partial[i] << " ";
	}
	std::cout << "\n" << std::endl;

	return 0;
}

int multiDimensionalArrays(){
	return 0;
}