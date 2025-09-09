import std;
#include "struct_header.h"

// Anonymous structs are structures without name
struct PointWithColor{
	int x{};
	int y{};
	// Anonymous structure for Color
	struct{		
		unsigned char red{};
		unsigned char green{};
		unsigned char blue{};
	}color{};	// Initialise the anonymous structure member
};
int anonymousStruct(){
	PointWithColor p1{10,20,{255,0,0}};    // Initialise the anonymous structure member
	std::cout << "Point x: " << p1.x << ", y:" << p1.y << std::endl;
	std::cout << "color: red = " << static_cast<int>(p1.color.red) << " color: green = " << static_cast<int>(p1.color.green)
			  << " color: blue = " << static_cast<int>(p1.color.blue) << std::endl;

	return 0;
}



// Structures tag names & Typedef/using
// Named structures with methods
struct Address{
	std::string street{};
	std::string city{};
	// A method to print address
	void print() const{
		std::cout << "Address is: " << street << "," << city << std::endl;
	}
};
struct PersonInfo{
	std::string name{};
	int age{};
};
// Typedef for PersonInfo Person
typedef struct PersonInfo Person;
// Modern style C++ Alias with using
using AddressAlias = Address;
int typedefStruct(){
	Person person1{"Eve", 30};
	AddressAlias addr1{"123 main street", " Anytown"};
	std::cout << "Person: " << person1.name << ", Age: " << person1.age << "\n";
	addr1.print();	// Call the print method from address struct

	return 0;
}