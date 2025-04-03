export module auto_keyword;
import <iostream>;    // For standard input and output
import <vector>;      // For using std::vector container
import <map>;         // For using std::map container
import <type_traits>; // For type trait utilities like std::is_integral_v
import <typeinfo>;    // For runtime type information

// Function to print the type of a variable at runtime
// Useful for understanding what 'auto' deduces in each case
template <typename T>
void printType(const T&) {
    std::cout << "Type: " << typeid(T).name() << std::endl;
}

// ------------------------------------------------------------
// 1. Basic Usage of auto (Starting with simplest use case)
// ------------------------------------------------------------
void basicAutoUsage() {
    auto x{42};         // x is deduced as int
    auto y{3.14};       // y is deduced as double
    auto z{"Hello"};    // z is deduced as const char*

    std::cout << "x: " << x << " (auto deduced as int)" << std::endl;
    std::cout << "y: " << y << " (auto deduced as double)" << std::endl;
    std::cout << "z: " << z << " (auto deduced as const char*)" << std::endl;
}

// ------------------------------------------------------------
// 2. Auto with References (Understanding how references work with auto)
// ------------------------------------------------------------
void autoWithReferences() {
    int a{10};
    auto& refA{a};  // refA is a reference to a (int&)
    refA = 20;       // Modifies 'a' as well

    std::cout << "a: " << a << " (modified via refA, auto deduced as int&)" << std::endl;
}

// ------------------------------------------------------------
// 3. Auto with Pointers (Using auto for pointer type deduction)
// ------------------------------------------------------------
void autoWithPointers() {
    int b{100};
    auto ptr{&b}; // ptr is deduced as int*
    *ptr = 200;    // Changing value of b through ptr

    std::cout << "b: " << b << " (modified via ptr, auto deduced as int*)" << std::endl;
}

// ------------------------------------------------------------
// 4. Auto with Containers and Iterators (Simplifying iteration)
// ------------------------------------------------------------
void autoWithContainers() {
    std::vector<int> numbers{1, 2, 3, 4, 5};

    // Using auto to declare an iterator
    auto it{numbers.begin()}; // it is deduced as std::vector<int>::iterator
    std::cout << "First element: " << *it << std::endl;

    // Using auto in a range-based for loop
    std::cout << "Vector elements: ";
    for (auto num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// ------------------------------------------------------------
// 5. Auto in Function Return Types (Letting compiler infer return type)
// ------------------------------------------------------------
auto multiply(int a, int b) {
    return a * b; // Compiler deduces return type as int
}

// ------------------------------------------------------------
// 6. Auto with Lambda Functions (Using auto for generic lambdas)
// ------------------------------------------------------------
void autoWithLambdas() {
    auto square{[](auto x) { return x * x; }}; // Generic lambda

    std::cout << "Square of 5: " << square(5) << std::endl;       // Deduce int
    std::cout << "Square of 3.5: " << square(3.5) << std::endl;   // Deduce double
}

// ------------------------------------------------------------
// 7. Auto with Structured Bindings (C++17+ feature for decomposition)
// ------------------------------------------------------------
void autoWithStructuredBindings() {
    std::pair<int, double> p{10, 3.14};

    // Structured bindings using auto
    auto [first, second] {p}; // first is int, second is double

    std::cout << "Pair values: " << first << ", " << second << std::endl;
}

// ------------------------------------------------------------
// 8. Auto in Range-based for loops (Iterating over key-value pairs)
// ------------------------------------------------------------
void autoWithRangeLoops() {
    std::map<std::string, int> ageMap{{"Alice", 25}, {"Bob", 30}};

    // Using auto to deduce iterator type
    for (auto& [name, age] : ageMap) {
        std::cout << name << " is " << age << " years old." << std::endl;
    }
}

// ------------------------------------------------------------
// 9. Auto and Type Traits (Checking type at compile-time)
// ------------------------------------------------------------
void autoWithTypeTraits() {
    auto value{42};

    // Checking the type of value at compile-time
    if constexpr (std::is_integral_v<decltype(value)>) {
        std::cout << "Value is an integer" << std::endl;
    }
}

// ------------------------------------------------------------
// Main function to execute all examples step by step
// ------------------------------------------------------------
export int autoCall() {
    std::cout << "--- Basic auto Usage ---" << std::endl;
    basicAutoUsage();

    std::cout << "\n--- Auto with References ---" << std::endl;
    autoWithReferences();

    std::cout << "\n--- Auto with Pointers ---" << std::endl;
    autoWithPointers();

    std::cout << "\n--- Auto with Containers ---" << std::endl;
    autoWithContainers();

    std::cout << "\n--- Auto in Function Return Types ---" << std::endl;
    std::cout << "Multiplication result: " << multiply(4, 5) << std::endl;

    std::cout << "\n--- Auto with Lambdas ---" << std::endl;
    autoWithLambdas();

    std::cout << "\n--- Auto with Structured Bindings ---" << std::endl;
    autoWithStructuredBindings();

    std::cout << "\n--- Auto in Range-based Loops ---" << std::endl;
    autoWithRangeLoops();

    std::cout << "\n--- Auto and Type Traits ---" << std::endl;
    autoWithTypeTraits();

    return 0;
}
