import std;
#include "class_header.h"

// A class is a user-defined type (blueprint). An object is an instance of a class.
class Point{
public:
	int x{};
	int y{};
};
int basicClass(){
	Point p;
	p.x = 12;
	p.y = 13;
	std::cout << "P = " << p.x << "," << p.y << std::endl;

	// Another way
	Point p1{.x = 5,.y = 7};
	std::cout << "P = " << p1.x << "," << p1.y << std::endl;

	return 0;
}



/*
	Access specifiers
	- public — visible to everyone
	- private — visible only inside the class (default for class)
	- protected — visible in derived classes
*/
class Example {
public:
	void pub(){ 
		std::cout << "public\n"; 
	}
protected:
	void prot(){ 
		std::cout << "protected\n"; 
	}
private:
	void priv(){ 
		std::cout << "private\n"; 
	}
};




// Constructors initialize objects. Destructors clean up.