import std;
#include "memory_header.h"

/*
	Dynamic memory allocation is the process of allocating memory at the runtime of a program.
	This memory is allocated in the heap of the program instead of stack memory.
	It is useful when:
	=> You are not sure about the size of the array you need
	=> Implementing data structures such as linked lists, trees etc
	=> In complex programs that requires efficient memory management

	- The new operator
	  The new operator is used to allocate memory dynamically. It returns a pointer
	  to the allocated memory.
	  Syntax:
		pointer = new data_type;	// For a single variable
		pointer = new data_type;	// For array
	- The delete operator
	  The delete operator is used to deallocate memory that was previously used by new
	  Syntax:
		delete pointer;      // For single object
		delete[] pointer;    // For arrays of object

	- Memory is a situation where memory allocated for a particular task remains allocated even 
	  after it is no longer needed. Morever, if the address to the memory is lost, then it will 
	  remain allocated till the program runs. Hence use delete appropriately and use smart pointers 
	  whenever possible

    - Dangling pointers are created when memory pointed by the pointer is accessed after it is 
	  deallocated leading to undefined behaviour like crashes, garbage. Hence initialise pointer with 
	  nullptr and assign nullptr again after dealloacted
*/

void singleVariableExampleOne(){
	int* p{};		// Pointer initialisation to null
	p = new int;    // Requesting memory for variable using new keyword
	if (!p){
		std::cout << "Allocation failed" << std::endl;
	}
	else{
		// Store value at allocated address
		*p = 25;
		std::cout << "Value of p is: " << *p << std::endl;
	}
	delete p;		// Freeing the allocated memory
	p = nullptr;	// Avoid dangling pointer
}


void singleVariableExampleTwo(){
	// Declaring variable ptr, requesting memory for it and storing value 56
	int* ptr = new int{56};		
	std::cout << "Value of ptr is: " << *ptr << std::endl;
	delete ptr;		// Freeing allocated memory
	ptr = nullptr;	// Avoid dangling pointer
}


void singleVariableExampleThree(){
	// Declaring variable ptr, requesting memory and initialising to null
	int* ptr = new int{};
	std::cout << "Value of ptr is: " << *ptr << std::endl;
	delete ptr;		// Freeing allocated memory
	ptr = nullptr;	// Avoid dangling pointer
}


void arrayDynamicMemory(){
	// Request a block of memory of size n
	int n{5};
	int* arr = new int[n];
	if (!arr){
		std::cout << "Memory allocation failed" << std::endl;
	}
	else{
		for (int i = 0; i < n; ++i){
			arr[i] = i + 1;
		}
		std::cout << "Values in the block are" << std::endl;
		for (int i = 0; i < n; ++i){
			std::cout << "arr[" << i << "] = " << arr[i] << " " << std::endl;
		}
	}
	delete[] arr;	// Freeing allocated memory
	arr = nullptr;	// Avoid dangling pointer
}

// Using new and delete with single objects
class MyClass{
public:
	MyClass(){
		std::cout << "Constructor called" << std::endl;
	}
	~MyClass(){
		std::cout << "Destructor called" << std::endl;
	}
};
void singleObject(){
	// Allocating memory for single object of type MyClass
	MyClass *obj = new MyClass();

	// Deleting the object to call destructor
	delete obj;
}

int dynamic(){
	// singleVariableExampleOne();
	// singleVariableExampleTwo();
	// singleVariableExampleThree();
	// arrayDynamicMemory();
	singleObject();

	return 0;
}