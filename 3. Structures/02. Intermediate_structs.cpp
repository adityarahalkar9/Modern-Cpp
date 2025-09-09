import std;
#include "struct_header.h"


/*
	This code demonstrates how to create an array where each element is a student structure. We declare
	an array of structs named students of size 3 and initialise each element using brace initialisation
	with the name, age and GPA of student. We can iterate through the array and print the information
	for each student.
*/
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



// Nested Structures
struct Date{
	int year{};
	int month{};
	int date{};
};
struct Employee{
	std::string name{};
	Date birthDate{};	// Nested structure
};
int nestedStructure(){
	Employee emp1{"David", {1995,10,25}};
	std::cout << "Employee: " << emp1.name << " born on " << emp1.birthDate.date << "-"
			  << emp1.birthDate.month << "-" << emp1.birthDate.year << std::endl;

	return 0;
}


/*
	This example shows how to work with pointers to structures.
	Book* bookptr = &book1; declares a pointer bookptr that stores the memory address of the book1 
	structure. To access the members of the structure through the pointer, we use the arrow operator(->).
	The bookptr->title is equal to (*bookptr).title, where (*bookptr) dereferences the pointer to get 
	the Book structure itself.
*/
// Pointers to structures
struct Book{
	std::string title{};
	std::string author{};
};
int pointerStructures(){
	Book book1{"Hitchhiker's guide", "Douglas adams"};

	// Declaring a pointer to a book structure
	Book* bookptr = &book1;

	// Accessing members using arrow operator
	std::cout << "Book Title: " << bookptr -> title << std::endl;
	std::cout << "Book Author: " << bookptr->author << std::endl;

	// Dereference the pointer using dot operator
	std::cout << "Book Title(Dereferenced): " << (*bookptr).title << std::endl;
	std::cout << "Book Author(Dereferenced): " << (*bookptr).author << std::endl;

	return 0;
}