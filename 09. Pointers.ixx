import <iostream>;
export module pointers;

// Basic Pointer Concepts
void basicPointers() {
    std::cout << "=== Basic Pointers ===\n";
    int x{10};                    // A simple integer
    int* p{&x};                   // p holds the address of x
    std::cout << "x = " << x << "\n";
    std::cout << "Address of x: " << p << "\n";
    std::cout << "Value pointed by p: " << *p << "\n";

    // Modify x via pointer dereference:
    *p = 20;
    std::cout << "After *p = 20, x = " << x << "\n";

    // Demonstrate nullptr (modern alternative to NULL)
    int* pNull{nullptr};
    if (pNull == nullptr) {
        std::cout << "pNull is nullptr.\n";
    }
    std::cout << "\n";
}



// Pointer Arithmetic
void pointerArithmetic() {
    std::cout << "=== Pointer Arithmetic ===\n";
    int arr[]{1, 2, 3, 4, 5};
    int* ptr{arr};  // Arrays decay to pointer to first element.

    std::cout << "Array elements using pointer arithmetic:\n";
    for (std::size_t i{0}; i < 5; ++i) {
        // *(ptr + i) accesses arr[i]
        std::cout << "Element " << i << ": " << *(ptr + i) << "\n";
    }
    // Pointer subtraction: distance (in elements) between pointers.
    std::cout << "Distance between ptr and &arr[3]: "
        << (&arr[3] - ptr) << "\n\n";
}



// Pointer to Pointer (Double Pointers)
void pointerToPointer() {
    std::cout << "=== Pointer to Pointer ===\n";
    int a{100};
    int* p{&a};
    int** pp{&p};  // Pointer to the pointer p

    std::cout << "a = " << a << "\n";
    std::cout << "p (address of a) = " << p << "\n";
    std::cout << "pp (address of p) = " << pp << "\n";
    std::cout << "Value via p: " << *p << "\n";
    std::cout << "Value via pp (i.e. **pp): " << **pp << "\n\n";
}



// Const Pointers and Pointers to Const
void constPointers() {
    std::cout << "=== Const Pointers and Pointers to Const ===\n";
    int var{50};
    int anotherVar{75};

    // Pointer to const int: cannot change the pointed-to value through this pointer.
    const int* ptrToConst{&var};  // or int const* ptrToConst
    std::cout << "Value via ptrToConst: " << *ptrToConst << "\n";
    // *ptrToConst = 60; // ERROR: cannot modify value through ptrToConst.
    ptrToConst = &anotherVar;  // Allowed: pointer itself is not constant.

    // Const pointer: the pointer’s address is fixed; cannot reassign it.
    int* const constPtr{&var};
    std::cout << "Value via constPtr: " << *constPtr << "\n";
    *constPtr = 60;            // Allowed: modifies the value pointed to.
    // constPtr = &anotherVar;  // ERROR: cannot change the address stored.

    // Const pointer to const int: neither pointer nor value can be changed.
    const int* const constPtrToConst{&var};
    std::cout << "Value via constPtrToConst: " << *constPtrToConst << "\n\n";
}



// Function Pointers
// A simple add() function that returns the sum of two integers.
// It is used here to demonstrate function pointers.
int add(int a, int b) {
    return a + b;
}

// A function that takes a function pointer as a parameter.
void applyFunction(int (*func)(int, int), int x, int y) {
    std::cout << "Result of applying function: " << func(x, y) << "\n";
}

void functionPointers() {
    std::cout << "=== Function Pointers ===\n";
    // Declare a function pointer and initialize it to point to add.
    int (*funcPtr)(int, int){ &add }; // The address-of operator is optional.
    std::cout << "Using function pointer to add 5 and 3: " << funcPtr(5, 3) << "\n";
    applyFunction(funcPtr, 10, 20);
    std::cout << "\n";
}



// Void Pointers
void voidPointerExample() {
    std::cout << "=== Void Pointers ===\n";
    int num{42};
    void* voidPtr{&num};  // void pointer can point to any data type.
    // To access the pointed value, cast it back to the proper pointer type.
    std::cout << "Value through void pointer: " << *(static_cast<int*>(voidPtr)) << "\n\n";
}



// Dynamic Memory Allocation (new and delete)
void dynamicMemoryAllocation() {
    std::cout << "=== Dynamic Memory Allocation ===\n";
    // Dynamically allocate an int using brace initialization.
    int* pInt{new int{99}};
    std::cout << "Dynamically allocated int: " << *pInt << "\n";
    *pInt = 101;
    std::cout << "Modified dynamically allocated int: " << *pInt << "\n";
    delete pInt;  // Free the memory.
    pInt = nullptr; // Avoid dangling pointer.

    // Dynamically allocate an array of 5 ints using brace initializer.
    int* pArray{new int[5]{1, 2, 3, 4, 5}};
    std::cout << "Dynamically allocated array elements:\n";
    for (int i{0}; i < 5; ++i) {
        std::cout << "Element " << i << ": " << pArray[i] << "\n";
    }
    delete[] pArray;
    pArray = nullptr;
    std::cout << "\n";
}



// Pointer Casting Examples
void pointerCasting() {
    std::cout << "=== Pointer Casting ===\n";
    double d{3.14159};
    // reinterpret_cast: treats the address of d as an int pointer.
    // (Note: This is for demonstration only—dereferencing the result is undefined behavior.)
    int* intPtr{reinterpret_cast<int*>(&d)};
    std::cout << "Value of double via reinterpret_cast to int pointer (undefined behavior): "
        << *intPtr << "\n";

    // static_cast: used for safe conversions (here, converting int to double).
    int i{42};
    double d2{static_cast<double>(i)};
    std::cout << "static_cast from int to double: " << d2 << "\n\n";
}



// Member Pointers (Pointers to Data Members and Member Functions)
class MyClass {
public:
    int value{0};
    void show() const {
        std::cout << "MyClass::value = " << value << "\n";
    }
};

void memberPointersExample() {
    std::cout << "=== Member Pointers ===\n";
    MyClass obj;
    obj.value = 10;

    // Pointer to data member:
    int MyClass::* ptrToMember{&MyClass::value};
    std::cout << "Accessing member via pointer-to-member: " << obj.*ptrToMember << "\n";

    // Pointer to member function:
    void (MyClass:: * ptrToMemberFunc)() const { &MyClass::show };
    (obj.*ptrToMemberFunc)();
    std::cout << "\n";
}



// Array of Pointers
void arrayOfPointers() {
    std::cout << "=== Array of Pointers ===\n";
    constexpr int SIZE{3};
    int a{10}, b{20}, c{30};
    // An array of pointers, each initialized using brace syntax.
    int* arrPointers[SIZE]{&a, &b, &c};
    for (int i{0}; i < SIZE; ++i) {
        std::cout << "Pointer " << i << " points to value: "
            << *(arrPointers[i]) << "\n";
    }
    std::cout << "\n";
}



// Pointer to Array Example
void pointerToArrayExample() {
    std::cout << "=== Pointer to Array Example ===\n";
    int arr[5]{10, 20, 30, 40, 50};
    // Pointer to an entire array of 5 ints:
    int (*pArray)[5] = &arr;
    std::cout << "Accessing third element via pointer-to-array: "
        << (*pArray)[2] << "\n\n";
}



// Volatile Pointer Example
void volatilePointerExample() {
    std::cout << "=== Volatile Pointer Example ===\n";
    volatile int x{100};  // 'volatile' tells the compiler not to optimize accesses
    volatile int* pVolatile{&x};
    std::cout << "Volatile int value: " << *pVolatile << "\n\n";
}



export int pointerCall(){
    basicPointers();
    pointerArithmetic();
    pointerToPointer();
    constPointers();
    functionPointers();
    voidPointerExample();
    dynamicMemoryAllocation();
    pointerCasting();
    memberPointersExample();
    arrayOfPointers();
    pointerToArrayExample();
    volatilePointerExample();

    return 0;
}
