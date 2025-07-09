import std;
#include "memory_header.h"

/*
	A reference is somewhat safer version of a pointer. A reference works as an alias 
	for an existing variable, providing an alternative name for it and allowing you to work 
	with the orignal data directly.
*/

int references(){
	int var{70};
	int& r_var = var;

	std::cout << "var is: " << var << std::endl;         // var is : 70
	std::cout << "&var is: " << &var << std::endl;		 // &var is : 0000001AC2EFF5F4
	std::cout << "r_var is: " << r_var << std::endl;	 // r_var is : 70
	std::cout << "&r_var is: " << &r_var << std::endl;	 // &r_var is : 0000001AC2EFF5F4

	// &var = &r_var showing that both variables share the same memory address.

	return 0;
}