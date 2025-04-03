export module functions;
import <iostream>;
import <functional>;
import <memory>;

// Function without parameters and without return value
void greet(){
    std::cout << "Hello, World!" << std::endl;
}

// Function with parameters and a return value
int add(int a, int b){
    return a + b;
}

// Function with default arguments
int multiply(int a, int b = 2){
    return a * b;
}

// Function with pass by reference
void increment(int& num){
    num += 1;
}

// Function with pass by pointer
void square(int* num){
    if (num) {
        *num *= *num;
    }
}

// Function returning a pointer (Dynamic memory allocation)
int* createInt(int value){
    return new int{value};
}

// Function returning a reference
int& returnReference(int& ref){
    return ref;
}

// Function pointer
void (*functionPointer)() = greet;

// Function reference
auto& functionReference = greet;

// Lambda function
auto lambda = [](int x, int y){ return x + y; };

// Nested function (using lambda inside a function)
void outerFunction() {
    auto innerFunction = [](){ std::cout << "Inside nested function" << std::endl; };
    innerFunction();
}

// Function with std::function (Polymorphic function wrapper)
std::function<int(int, int)> funcWrapper = add;

// Function with unique_ptr as return type
std::unique_ptr<int> makeUniqueInt(int value) {
    return std::make_unique<int>(value);
}

// Function with shared_ptr as return type
std::shared_ptr<int> makeSharedInt(int value) {
    return std::make_shared<int>(value);
}

// Function template
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

// Variadic template function
template <typename... Args>
void printValues(Args... args) {
    ((std::cout << args << " "), ...) << std::endl;
}

// Recursive function
int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

export int functionsCall() {
    greet();
    std::cout << "Add: " << add(3, 5) << std::endl;
    std::cout << "Multiply: " << multiply(4) << std::endl;

    int num{10};
    increment(num);
    std::cout << "Incremented: " << num << std::endl;

    square(&num);
    std::cout << "Squared: " << num << std::endl;

    int* ptr = createInt(42);
    std::cout << "Created Int: " << *ptr << std::endl;
    delete ptr;

    int refValue{7};
    returnReference(refValue) += 5;
    std::cout << "Reference Modified: " << refValue << std::endl;

    functionPointer();
    functionReference();

    std::cout << "Lambda Result: " << lambda(2, 3) << std::endl;

    outerFunction();

    std::cout << "Function Wrapper Result: " << funcWrapper(4, 6) << std::endl;

    auto uniqueInt = makeUniqueInt(99);
    std::cout << "Unique Int: " << *uniqueInt << std::endl;

    auto sharedInt = makeSharedInt(88);
    std::cout << "Shared Int: " << *sharedInt << std::endl;

    std::cout << "Max of 3 and 7: " << max(3, 7) << std::endl;

    std::cout << "Factorial of 5: " << factorial(5) << std::endl;

    printValues("Hello", 42, 3.14, 'X');

    return 0;
}