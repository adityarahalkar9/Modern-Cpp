import <iostream>;
import <vector>;
export module references;

/*
	At its core, a reference in C++ is an alias for an already existing object. Think of it as another 
	name for a variable that's already been declared. Once a reference is initialized to refer to an 
	object, it cannot be "reseated" or made to refer to a different object. Any operation performed on 
	the reference acts directly on the object it refers to.
	
	Key Characteristics:
	-> Must be Initialized: A reference must be initialized when it's declared. You cannot have an 
							uninitialized reference.
	-> Cannot be Rebound: Once initialized, a reference will always refer to the same object it was 
						  initially bound to.
	-> Not an Object Itself: References don't typically occupy separate storage (though the compiler might 
							 implement them using pointers under the hood).They are primarily compile-time 
							 constructs.
	-> Cannot be Null: Unlike pointers, you cannot have a reference that refers to "nothing" in a 
					   standard way, though you can get into trouble with dangling references
*/


// Demonstrates creating and using references
void references() {
	int x{10};    
	int &ref_x = x;  

	std::cout << "references:\n";
	std::cout << "x: " << x << std::endl;           // Outputs: x: 10
	std::cout << "ref_x: " << ref_x << std::endl;   // Outputs: ref_x: 10
	std::cout << "&x: " << &x << std::endl;
	std::cout << "&ref_x: " << &ref_x << std::endl;

	ref_x = 20;   // Changes the value of x to 20
	std::cout << "After modifying ref_x:\n";
	std::cout << "x: " << x << std::endl;           // Outputs: x: 20
	std::cout << "ref_x: " << ref_x << std::endl;   // Outputs: ref_x: 20
	std::cout << std::endl;
}


//Function that increments a number by reference
void increment(int &num) {
	num++;
}
//Demonstrates passing variables by reference to functions
void referenceParameters() {
	int value{5};      
	increment(value);    //value is passed by reference and incremented

	std::cout << "referenceParameters:\n";
	std::cout << "value: " << value << std::endl;   // Outputs: value: 6
	std::cout << std::endl;
}


// Function that returns a reference to an integer
int &getReference(int &num) {
	return num;
}
// Demonstrates returning references from functions
void referenceReturn() {
	int a{10};            
	getReference(a) = 20;    // Sets a to 20

	std::cout << "referenceReturn:\n";
	std::cout << "a: " << a << std::endl;    // Outputs: a: 20
	std::cout << std::endl;
}


// Function that prints a value using a const reference
void printValue(const int &num) {
	std::cout << "Value: " << num << std::endl;
}
// Demonstrates using const references
void constReferences() {
	int x{30};       
	printValue(x);    // Outputs: Value: 30

	std::cout << "constReferences:\n";
	std::cout << std::endl;
}


// Demonstrates the differences between references and pointers
void referencesVsPointers() {
	int x{10};       
	int y{20};      

	int &ref = x;    
	int *ptr{&x};    

	ref = y;         // Assigns the value of y to x (not changing the reference)
	ptr = &y;        // Changes ptr to point to y

	std::cout << "referencesVsPointers:\n";
	std::cout << "x: " << x << std::endl;       // Outputs: x: 20
	std::cout << "ref: " << ref << std::endl;   // Outputs: ref: 20
	std::cout << "*ptr: " << *ptr << std::endl; // Outputs: *ptr: 20
	std::cout << std::endl;
}


// Class demonstrating move semantics with rvalue references
class MoveExample {
public:
	std::vector<int> data;

	// Constructor that moves data into the object
	MoveExample(std::vector<int> &&d) : data{std::move(d)} {}
};
// Demonstrates rvalue references and move semantics
void rvalueReferences() {
	std::vector<int> vec{1, 2, 3, 4, 5}; 
	MoveExample example{std::move(vec)};   // Moves vec into example

	std::cout << "rvalueReferences:\n";
	std::cout << "example.data size: " << example.data.size() << std::endl;   // Outputs: example.data size: 5
	std::cout << std::endl;
}



export int referenceCall(){
	references();
	referenceParameters();
	referenceReturn();
	constReferences();
	referencesVsPointers();
	rvalueReferences();

	return 0;
}