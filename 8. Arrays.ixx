import <iostream>;
export module arrays;
#include <array>     // For std::array
#include <vector>    // For std::vector
#include <iterator>  // For std::begin and std::end
#include <span>      // For std::span (C++20 non-owning array view)

/*
 -> This program is organized into sections that cover:
     1. Basic C-style Arrays: Declaration, brace initialization, and iteration.
     2. STL Fixed-Size Array (std::array): Using the fixed-size container with bounds checking.
     3. Multi-Dimensional Arrays: Nested brace initialization and nested range-based loops.
     4. Dynamic Arrays: Allocation with new and cleanup with delete[].
     5. STL Dynamic Array (std::vector): Automatic memory management.
     6. std::span (C++20): A non-owning view of contiguous sequences and its use in functions.
     7. Array and Pointer Relationship: How arrays decay to pointers and pointer arithmetic.
*/


// Basic C-style Arrays
void basicCStyleArray() {
    std::cout << "=== Basic C-style Array ===\n";

    // Declare and initialize a C-style array using brace initializer syntax.
    int c_array[5]{1, 2, 3, 4, 5};

    // Range-based for loop:
    // Iterates directly over each element, making the code cleaner and less error-prone.
    std::cout << "Range-based for loop: ";
    for (int element : c_array) {
        std::cout << element << " ";
    }
    std::cout << "\n";

    // Alternatively, iterate using std::begin and std::end.
    std::cout << "Using std::begin and std::end: ";
    for (auto i = std::begin(c_array); i != std::end(c_array); ++i) {
        std::cout << *i << " ";
    }
    std::cout << "\n\n";
}



// STL Fixed-Size Array (std::array)
void fixedSizeArray() {
    std::cout << "=== std::array (Fixed-Size Array) ===\n";

    // std::array provides a fixed-size container with STL-like member functions.
    std::array<int, 5> std_array{10, 20, 30, 40, 50};

    std::cout << "Elements using range-based loop: ";
    for (const int& element : std_array) {
        std::cout << element << " ";
    }
    std::cout << "\n";

    // Use .at() for bounds-checked access.
    std::cout << "Element at index 2 (using at()): " << std_array.at(2) << "\n\n";
}



//Section 3: Multi-Dimensional C-style Arrays
void multiDimensionalArray() {
    std::cout << "=== Multi-dimensional C-style Array ===\n";

    // Declare a 2x3 array with nested brace initialization.
    int multi_array[2][3]{{1, 2, 3}, {4, 5, 6}};

    std::cout << "2D Array Elements:\n";
    // Nested range-based loops:
    // Outer loop iterates over each row, inner loop over each element in the row.
    for (const auto& row : multi_array) {
        for (int value : row) {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}



//Section 4: Dynamic Arrays
void dynamicArray() {
    std::cout << "=== Dynamically Allocated Array ===\n";

    // Dynamically allocate an array of 5 integers using brace initialization.
    int* dynamic_array = new int[5]{ 100, 200, 300, 400, 500 };

    std::cout << "Dynamic array elements: ";
    // Use a traditional for loop since dynamic_array is a pointer.
    for (int i = 0; i < 5; ++i) {
        std::cout << dynamic_array[i] << " ";
    }
    std::cout << "\n";

    // Free the allocated memory to avoid memory leaks.
    delete[] dynamic_array;
    std::cout << "\n";
}



// STL Dynamic Array (std::vector)
void dynamicVector() {
    std::cout << "=== std::vector (Dynamic Array) ===\n";

    // std::vector automatically manages its memory.
    std::vector<int> vec{1000, 2000, 3000, 4000, 5000};

    std::cout << "std::vector elements using range-based loop: ";
    for (const auto& element : vec) {
        std::cout << element << " ";
    }
    std::cout << "\n\n";
}



// Using std::span for Non-Owning Views and Function Passing
void spanExample() {
    std::cout << "=== std::span Example ===\n";

    // Create a C-style array.
    int c_array[5]{7, 8, 9, 10, 11};

    // Create a std::span to view the entire array without owning it.
    std::span<int> span_view(c_array);

    std::cout << "Elements in std::span: ";
    for (int element : span_view) {
        std::cout << element << " ";
    }
    std::cout << "\n\n";
}



// Function that prints elements from any contiguous container using std::span.
void printElements(std::span<const int> arr_span) {
    std::cout << "Elements passed to function: ";
    for (int element : arr_span) {
        std::cout << element << " ";
    }
    std::cout << "\n";
}
void passArrayToFunction() {
    std::cout << "=== Passing Array to Function Using std::span ===\n";

    // Sample C-style array.
    int sample_array[4]{42, 43, 44, 45};

    // std::span deduces the size automatically and provides a safe view.
    printElements(sample_array);
    std::cout << "\n";
}



// Array and Pointer Relationship
void arrayPointerRelationship() {
    std::cout << "=== Array and Pointer Relationship ===\n";

    // Declare a C-style array with brace initialization.
    int arr[5]{10, 20, 30, 40, 50};

    // When used in expressions, the name 'arr' decays to a pointer to its first element.
    std::cout << "Address of 'arr' (using arr): " << static_cast<const void*>(arr) << "\n";
    std::cout << "Address of 'arr' (using &arr): " << static_cast<const void*>(&arr) << "\n";
    // Note: While the printed addresses may look the same, their types differ:
    // - 'arr' decays to an int* (pointer to first element).
    // - '&arr' is of type int (*)[5] (pointer to the entire array).

    // Create a pointer to the first element of the array.
    int* ptr = arr;
    std::cout << "Address stored in pointer 'ptr': " << static_cast<const void*>(ptr) << "\n";

    // Demonstrate pointer arithmetic:
    // *(ptr + i) accesses the i-th element, equivalent to arr[i].
    std::cout << "Accessing elements via pointer arithmetic:\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << "Element " << i << ": "
            << *(ptr + i) << " (using pointer arithmetic), "
            << "arr[" << i << "]: " << arr[i] << "\n";
    }

    // sizeof operator differences:
    // - sizeof(arr) returns the total size of the array.
    // - sizeof(ptr) returns the size of the pointer.
    std::cout << "Size of entire array 'arr' in bytes: " << sizeof(arr) << "\n";
    std::cout << "Size of pointer 'ptr' in bytes: " << sizeof(ptr) << "\n";

    std::cout << "\nNote: When arrays are passed to functions, they decay to pointers, losing size information.\n\n";
}


export int arrayCall() {
    basicCStyleArray();
    fixedSizeArray();
    multiDimensionalArray();
    dynamicArray();
    dynamicVector();
    spanExample();
    passArrayToFunction();
    arrayPointerRelationship();

    return 0;
}
