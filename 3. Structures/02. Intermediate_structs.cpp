import std;
#include "struct_header.h"


// Array Structures
struct Student{
	std::string name{};
	int age{};
	double gpa{};
};
int arrayStructure(){
	Student students[3]{
		{"Alice", 20, 3.9},
		{"Bob", 22, 4.3},
		{"Charlie", 24, 4.5}
	};

	for (int i = 0; i < 3; ++i){
		std::cout << "Name: " << students[i].name << ", Age: " << students[i].age << ", GPA: "
				  << students[i].gpa << std::endl;
	}
	return 0;
}
/*
	This code demonstrates how to create an array where each element is a student structure. We declare
	an array of structs named students of size 3 and initialise each element using brace initialisation
	with the name, age and GPA of student. We can iterate through the array and print the information 
	for each student.
*/



// Nested Structures