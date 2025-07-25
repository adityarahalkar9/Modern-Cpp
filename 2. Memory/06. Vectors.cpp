import std;
#include "memory_header.h"

/*
	std::vector is a dynamic array provided by the C++ standard library. It handles memory management
	for you, grows dynamically and offers rich interface for element access and modification
*/
int vectorDeclarationAndInitialisation(){
	// No initialisation i.e. empty vector
	std::vector<int> empty_vector{};

	// Zero initialisation i.e explicitly listing zero
	std::vector<int> zero_initialised{0,0,0,0,0};

	// Regular initialisation with values
	std::vector<int> numbers{1,2,3,4,5};
	std::vector<std::string> words{"Hello", "World", "C++23"};

	// Printing words array
	std::cout << "Declaration & Initialisation: " << std::endl;
	for (const std::string& word : words){
		std::cout << word << " ";
	}
	std::cout << "\n" << std::endl;

	// Printing numbers array
	std::cout << "Numbers are" << std::endl;
	for (const int num : numbers){
		std::cout << num << " ";
	}
	std::cout << "\n" << std::endl;

	// Printing zero_inititialised array
	std::cout << "Zero initiialised (Vector with 5 zeros)" << std::endl;
	for (const int num : zero_initialised){
		std::cout << num << " ";
	}
	std::cout << "\n" << std::endl;

	return 0;
}



/*
    Vector modification i.e. adding elements using push_back() and emplace_back()
		- push_back() function adds a copy of existing object to the vector.
		- emplace_back() function directly constructs the object at the end of vector.

	Both functions add elements at the end of the vector.
		=> Use push_back() when you have an existing object that you want to add to the vector.
		=> Use emplace_back() when you want to construct a new object directly into the vector especially,
		   if the object construction is expensive or it has no default constructor.

	- emplace_back() can offer performance advantages by constructing the object directly within the 
	  vector's storage
*/
int vectorModification(){
	std::vector<int> numbers{1,2,3};
	
	std::cout << "Initial Vector" << std::endl;
	for (const int num : numbers){
		std::cout << num << " ";
	}
	std::cout << "\n" << std::endl;

	numbers.push_back(4);
	numbers.emplace_back(5);

	std::cout << "Vector after modification" << std::endl;
	for (const int num : numbers){
		std::cout << num << " ";
	}
	std::cout << "\n" << std::endl;

	return 0;
}



// Removing elements using pop_back() and erase()
int vectorRemoval(){
	std::vector<int> numbers{10,20,30,40,50,60,70};

	// Removing last element
	numbers.pop_back();

	std::cout << "numbers array after using pop_back() is " << std::endl;
	for (const int num : numbers){
		std::cout << num << " ";
	}
	std::cout << "\n" << std::endl;

	// Using erase()
	numbers.erase(numbers.begin());

	std::cout << "numbers array after using erase() is " << std::endl;
	for (const int num : numbers){
		std::cout << num << " ";
	}
	std::cout << "\n" << std::endl;

	// Erasing 2nd number
	std::cout << "using erase() for removing 2nd number " << std::endl;
	numbers.erase(numbers.begin() + 1);
	for (const int num : numbers){
		std::cout << num << " ";
	}
	std::cout << "\n" << std::endl;

	return 0;
}



// Accessing vector elements
int vectorAccess(){
	std::vector<int> numbers{100,200,300,400,500};
	std::cout << "Element access" << std::endl;
	std::cout << "First element is: " << numbers.front() << std::endl;		// Using numbers.front()
	std::cout << "Second element: " << numbers[1] << std::endl;
	std::cout << "Third element: " << numbers[2] << std::endl;
	std::cout << "Last element is: " << numbers.back() << std::endl;		// Using numbers.back()

	return 0;
}



int vectorCapacityManagement(){
	// Initialise an empty vector
	std::vector<int> numbers{};
	std::cout << "Capacity management: " << "\n" << std::endl;

	// Display initial capacity of vector
	std::cout << "Initial capacity: " << numbers.capacity() << std::endl;

	// Reserve space for at least 100 elements
	numbers.reserve(100);
	std::cout << "Capacity after reserve(100): " << numbers.capacity() << std::endl;

	// Add 50 elements to the vector
	for (int i = 0; i < 50; ++i){
		numbers.push_back(i);
	}
	std::cout << "Vector after adding 50 elements is: " << std::endl;
	for (int num: numbers){
		std::cout << num << " ";
	}
	std::cout << std::endl;

	// Display the current size of the vector
	std::cout << "Size after rusing push_back(): " << numbers.size() << std::endl;

	// Display the capacity of the vector
	std::cout << "Capacity after using push_back(): " << numbers.capacity() << std::endl;

	// Reduce the capacity to fit the current size
	numbers.shrink_to_fit();
	std::cout << "Capacity after using shrink_to_fit() is: " << numbers.capacity() << std::endl;

	return 0;

	/*
		This fucntions shows us workings of
		- capacity()
		- reserve()
		- push_back()
		- size()
		- shrink_to_fit()
	*/
}


int vector(){
	// vectorDeclarationAndInitialisation();
	// vectorModification();
	// vectorRemoval();
	// vectorAccess();
	vectorCapacityManagement();

	return 0;
}