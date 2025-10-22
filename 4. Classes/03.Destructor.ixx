import std;
export module Destructor;

/*
	Destructor is an instance member function that is invoked automatically whenever an object 
	is going to be destroyed. Meaning, a destructor is the last function that is going to be 
	called before an object is destroyed.
*/
class Test{
public:
	Test(){
		std::cout << "Constructor called" << std::endl;
	}
	~Test(){
		std::cout << "Destructor called" << std::endl;
	}
};
int basicDestructor(){
	Test t;

	return 0;
}



/*
	If we do not write our own destructor in class, the compiler creates a default 
	destructor for us. The default destructor works fine unless we have dynamically 
	allocated memory or pointer in class. When a class contains a pointer to memory 
	allocated in the class, we should write a destructor to release memory before the 
	class instance is destroyed. This must be done to avoid memory leaks.
*/
class SimpleHolder{
private:
	int* ptr{};
public:
	// Constructor
	SimpleHolder(int value){
		ptr = new int(value);    // Allocating int on the heap
		std::cout << "Constructor: ptr points to value = " << *ptr << std::endl;
	}

	// Destructor
	~SimpleHolder(){
		std::cout << "Destructor: deleting ptr which points to value = " << *ptr << std::endl;
		delete ptr;
		ptr = nullptr;
		std::cout << "Destructor called, ptr deleted" << std::endl;
	}

	void show() const {
		std::cout << "Value = " << *ptr << std::endl;
	}
};
int explicitDestrcutor(){
	SimpleHolder sh(99);
	sh.show();
	/*
		when explicitDestrcutor() ends (or `sh` goes out of scope), the destructor ~SimpleHolder() 
		is automatically called.
	*/

	return 0;
}



/*
	CHARACTERISTICS OF A DESTRUCTOR
	All the points mentioned below show the characteristics of a destructor:
	- Destructor has the same name as their class name preceded by a tilde (~) symbol.
	- It is not possible to define more than one destructor.
	- The destructor is only one way to destroy the object created by the constructor. 
	  Hence, destructor cannot be overloaded.
	- It cannot be declared static or const.
	- Destructor neither requires any argument nor returns any value.
	- It is automatically called when an object goes out of scope. 
	- Destructor release memory space occupied by the objects created by the constructor.
	- In destructor, objects are destroyed in the reverse of an object creation.

	When is the destructor called?
	A destructor function is called automatically when the object goes out of scope or is 
	deleted. Following are the cases where destructor is called:
	- Destructor is called when the function ends.
	- Destructor is called when the program ends.
	- Destructor is called when a block containing local variables ends.
	- Destructor is called when a delete operator is called.
*/


export int destructor(){
	// basicDestructor();
	// explicitDestrcutor();

	return 0;
}