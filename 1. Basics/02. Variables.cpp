import std;
#include "basicsheader.h"

/*
	Variable is a name given to a memory location. It is the basic unit of storage in a 
	program. The value stored in a variable can be accessed or changed during program execution.
	=> In C++, there are different types of variables (defined with different keywords)
		-> int - stores integers (whole numbers), without decimals, such as 123 or -123
		-> double - stores floating point numbers, with decimals, such as 19.99 or -19.99
		-> char - stores single characters, such as 'a' or 'B'. Char values are surrounded by single quotes
		-> string - stores text, such as "Hello World". String values are surrounded by double quotes
		-> bool - stores values with two states: true or false
*/

void variableDemo(){

	// Initialising a variable to value zero
	int age{};
	std::cout << "Variable age has value: " << age << std::endl;

	// Initialising and assigning value to variable
	double balance{23.75};

	// Different types of variable declaration
	std::string country_name{"India"};
	int states{28};

	std::cout << country_name << " has " << states << " states." << std::endl;
}