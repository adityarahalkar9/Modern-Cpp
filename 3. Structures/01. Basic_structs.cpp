import std;
#include "struct_header.h"

/*
	A structure is a user-defined data type that groups together variable of different data
	types under a single name
*/

// Creating a structure
struct Point{
	int x{};
	int y{};
};

int runBasicStruct(){
	// Creating a Point instance 'p1' and inititalising it's variables
	Point p1{10,20};

	// Creating a Point instance 'p2'
	Point p2{};    // Initialise members to their default values(0)

	// Creating a Point instance with designated initialisers(C++20)
	Point p3{};					// Dummy instance
	Point p4{.x = 5, .y = 15};	// Designated initialisers

	std::cout << "Point p1: x = " << p1.x << ", y = " << p1.y << std::endl;
	std::cout << "Point p2: x = " << p2.x << ", y = " << p2.y << std::endl;
	std::cout << "Point p4: x = " << p4.x << ", y = " << p4.y << std::endl;

	return 0;
}



// Accessing struct members
struct Rectangle{
	int width{};
	int height{};
};

int accessStruct(){
	Rectangle rect1{5,10};

	// Accessing and printing the width and height members
	std::cout << "Rectangle width: " << rect1.width << std::endl;
	std::cout << "Rectangle height: " << rect1.height << std::endl;

	// Modifying a member's value
	rect1.width = 8;
	std::cout << "Updated Rectangle width: " << rect1.width << std::endl;

	return 0;
}



// Passing structures to functions (By value)
struct Circle{
	double radius{};
};
void printCircleInfo(Circle c){		// Paasing by value
	std::cout << "Circle radius: " << c.radius << std::endl;
}
int passingByValue(){
	Circle myCircle{5};
	printCircleInfo(myCircle);

	return 0;
}



// Passing structures to functions (By reference)
struct color{
	int red{};
	int green{};
	int blue{};
};

