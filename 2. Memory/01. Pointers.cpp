import std;
#include "memory_header.h"

// A pointer is a variable that stores the address of another variable
int pointer(){
	int num{45};
	int* n_ptr = &num;

	std::cout << "num is: " << num << std::endl;		 // num is : 45
	std::cout << "&num is: " << &num << std::endl;		 // & num is : 0000009C32CFFAE4
	std::cout << "n_ptr is: " << n_ptr << std::endl;	 // n_ptr is : 0000009C32CFFAE4
	std::cout << "&n_ptr is: " << &n_ptr << std::endl;	 // & n_ptr is : 0000009C32CFFB08

	// Dereferencing the pointer n_ptr
	std::cout << "*n_ptr is: " << *n_ptr << std::endl;   // *n_ptr is : 45

	// &num = n_ptr as n_ptr pointer stores memory address of variable num
	// *n_ptr = num = 45 as the dereferenced pointer *n_ptr holds value of num.

	return 0;
}


int pointerManipulation(){
	int a{90};
	int* a_ptr = &a;

	*a_ptr += 4;
	std::cout << "a is: " << a << std::endl;			// Value of a changes to 94 from 90

	*a_ptr = 150;
	std::cout << "a is: " << a << std::endl;			// Value of a changes to 150

	return 0;
}


// Null pointers
void nullPointer(){
	int* n_ptr{nullptr};
	if (n_ptr == nullptr){
		std::cout << "no target" << std::endl;
	}
}


// Pointer declaration syntax & const-correctness
void constPointer(){
	int x{13};
	const int y{15};

	int* p1{&x};			  // can change *p1 and p1
	const int* p2{&y};		  // cannot change *p2 (If you change p2, undefined behavior because you are accessing a memory location that you have not explicitly allocated or initialized)
	int* const p3{&x};        // cannot change p3 (address), but can change *p3
	const int* const p4{&y};  // neither p4 nor *p4 can change

	// p2+=1 will create undefined behaviour
}


// Pointer arithmetic
void pointerArithmetic(){
	int arr[]{10,20,30,40};
	int* p{arr};	// Points to arr[20]
	std::cout << *(p + 1) << std::endl;    // prints 20
	++p;			// Now points to arr[1]
	std::cout << *p << std::endl;	// Prints arr[1] which is 20

	// Beware: going outside bounds -> undefined behaviour
}


// Pointer decay
void pointerDecay(){
	int arr[]{11,12,13,14};
	int* p{arr};	// Points to first element of arr
	std::cout << *p << std::endl;
	std::cout << sizeof(arr) << std::endl;
	std::cout << sizeof(p) << std::endl;
}


// Function and Pointers
void increment(int* p){
	if (p){
		++*p;
	}
}
void pointerArgument(){
	int a{5};
	increment(&a);
	std::cout << a << std::endl;
}


// Pointer to Pointer
void pointerToPointer(){
	int a{20};
	int* a_ptr{&a};
	int** b_ptr{&a_ptr};

	std::cout << "a is: " << a << std::endl;
	std::cout << "a_ptr is: " << a_ptr << std::endl;
	std::cout << "b_ptr is: " << b_ptr << std::endl;
}


// Pointer to Whole Array
void pointerToWholeArray(){
	int arr[]{10, 20, 30};
	int (*pArr)[3] = &arr;    // pointer to array of 3 ints
	std::cout << (*pArr)[1] << std::endl;	// prints 20
}


// Function pointers
int addition(int a, int b){
	return a + b;
}
void functionPointers(){
	// pointer to function taking (int, int) -> int
	int (*op)(int, int) = &addition;
	std::cout << op(2, 3) << "\n";      // prints 5
	std::cout << (*op)(4, 5) << "\n";   // prints 9
}


struct Foo{
	int value{0};
	void show(int x){
		std::cout << "Value: " << value << " arg: " << x << std::endl;
	}
};
int pointerToMember(){
	// pointer to member data
	int Foo::* dataPtr = &Foo::value;
	Foo f{7};
	std::cout << f.*dataPtr << "\n";  // prints 7

	// pointer to member function
	void (Foo:: * fnPtr)(int) = &Foo::show;
	(f.*fnPtr)(10);                   // call on object
	Foo* pf{&f};
	(pf->*fnPtr)(20);                 // call through pointer

	return 0;
}


int pointers(){
	// nullPointer();
	// constPointer();
	// pointerArithmetic();
	// pointerDecay();
	// pointerArgument();
	// pointerToPointer();
	// pointerToWholeArray();
	// functionPointers();
	pointerToMember();

	return 0;
}