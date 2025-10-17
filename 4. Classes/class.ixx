export module Beginnerclass;
import std;

/*
	A class is a user-defined type that encapsulates data (members) and behavior (functions). 
	It's a blueprint for objects. In C++, class and struct are similar; the difference 
	is default access: class defaults to private, struct to public. Use class for OOP with 
	encapsulation.
*/
class Point{
private:
	int x{};
	int y{};
public:
	void setCordinates(int newX, int newY){
		x = newX;
		y = newY;
	}
	void print() const {   // Const member function: doesn't modify object
		std::cout << "Point is: " << x << ", " << y << std::endl;
	}
};
int basicClass(){
	Point p{};
	p.setCordinates(3, 4);
	p.print();

	return 0;
}
/*
	=> Objects: Instances of classes, like p above. Created on stack (Point p{};) or 
			    heap (auto* p = new Point{};).
	=> Access Specifiers: public (accessible everywhere), private (only within class), 
					      protected (within class and derived classes).
	=> Data Members
	   Variables inside a class. Can be initialized in-class with brace syntax (C++11+).
	   - Instance Members: Per-object (e.g., x, y above).
	   - Static Members: Shared across objects, declared static.
*/



// Member function definitions outside the class
class Person{
private:
	std::string name{};
	int age{};
	double height{};
public:
	// Member function declaration
	void displayInfo() const;
	void setName(std::string_view newName);
	void setAge(int newAge);

	// Getters - const member functions that dont modify the object
	std::string getName() const {
		return name;
	}
	int getAge() const {
		return age;
	}
	double getHeight() const {
		return height;
	}
};
void Person::displayInfo() const {
	std::println("Name: {} , Age: {}, Height: {:.2f}", name, age, height);
}
void Person::setName(std::string_view newName){
	name = newName;
}
void Person::setAge(int newAge){
	if (newAge >= 0 && newAge <= 150){
		age = newAge;
	}
}
int basicClass2(){
	Person person1;
	person1.setName("Alice");
	person1.setAge(25);
	person1.displayInfo();
	std::println("From getter -> Name: {}, Age: {}, Height: {:.2f}",
		person1.getName(), person1.getAge(), person1.getHeight());

	return 0;
}



// Access Specifiers Deep Dive
class AccessExample{
private:					
	int privateVar{};		// Only accessible within class member functions
protected:
	int protectedVar{};     // Accessible within class and derived classes
public:
	int publicVar{};		// Accessible from anywhere

	// Public interface to access private members
	void setPrivateVar(int value){
		privateVar = value;
	}
	int getPrivateVar() const {
		return privateVar;
	}
};
class Derived : public AccessExample{
public:
	void accessProtected(){
		protectedVar = 42;    // OK - protected members accessible int derived class
		// privateVar = 10;	  // Error - private members not accessible
	}
};
int accessSpecifier(){
	AccessExample obj;
	obj.publicVar = 10;		  // OK - public access
	// obj.privateVar = 20;   // Error - private access
	obj.setPrivateVar(30);	  // OK - through public interface
	std::cout << obj.getPrivateVar() << std::endl;

	return 0;
}



// Constructors and Destructors
/*
	=> A constructor is a member function of a class that has the same name as the class name. It 
	   helps to initialize the object of a class. It can either accept the arguments or not. It 
	   is used to allocate the memory to an object of the class. It is called whenever an instance 
	   of the class is created. It can be defined manually with arguments or without arguments. 
	   There can be many constructors in a class. It can be overloaded but it can not be inherited 
	   or virtual. There is a concept of copy constructor which is used to initialize an object 
	   from another object. 

	=> Like a constructor, Destructor is also a member function of a class that has the same name as 
	the class name preceded by a tilde(~) operator. It helps to deallocate the memory of an object. 
	It is called while the object of the class is freed or deleted. In a class, there is always a 
	single destructor without any parameters so it can't be overloaded. It is always called in the 
	reverse order of the constructor. if a class is inherited by another class and both the classes 
	have a destructor then the destructor of the child class is called first, followed by the 
	destructor of the parent or base class. 
*/ 
class Resource{
private:
	std::string name{};
	int* data{nullptr};
	std::size_t size{};
public:
	// 1. Default constructor
	Resource() : name{"Unknown"}, data{nullptr}, size{}{
		std::println("Default constructor");
	}

	// 2. Parameterized constructor
	explicit Resource(std::string_view resourceName, std::size_t dataSize = 10)
		: name{resourceName}, size{dataSize}{
		data = new int[size]{};    // Dynamic allocation
		std::println("Parameterized constructor: {}", name);
	}

	// 3. Copy constructor (Deep copy)
	Resource(const Resource& other) : name{other.name + "_copy"}, size{other.size}{
		data = new int[size];
		std::copy(other.data, other.data + size, data);
		std::println("Copy Construtor: {}", name);
	}

	// 4. Move Constructor
	Resource(Resource&& other) noexcept
		: name{std::move(other.name)}, data{std::exchange(other.data, nullptr)},
		size{std::exchange(other.size, 0)} {
		std::println("Move constructor: {}", name);
	}
};



export int beginnerclass(){
	// basicClass();
	// basicClass2();
	accessSpecifier();

	return 0;
}