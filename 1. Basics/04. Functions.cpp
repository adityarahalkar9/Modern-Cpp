import std;
#include "basics_header.h"

/*
	-> A function is a block of code which only runs when it is called.
	-> You can pass data, known as parameters, into a function.
	-> Functions are used to perform certain actions, and they are important for
	   reusing code. Define the code once, and use it many times.
*/

// Function add which takes 2 parameters and returns a+b
int add(int a, int b) {
	return a + b;
}

// Function subtract also takes 2 parameters and prints value a-b
int subtract(int a, int b) {
	std::cout << a - b << std::endl;
	return 0;
}

// Both the above funnctions are called here
int function() {
	std::cout << add(2, 3) << std::endl;
	subtract(3, 2);

	return 0;
}