export module operators;
import <iostream>;
#include <bitset> // Used to display binary representation of numbers

void testPrecedenceAndAssociativity() {
    int a{10}, b{5}, c{2};
    std::cout << "Operator Precedence and Associativity in C++" << std::endl;

    // Multiplication (*) has higher precedence than addition (+)
    std::cout << "10 + 5 * 2 = " << (a + b * c) << " (Multiplication first)" << std::endl;

    // Parentheses override precedence
    std::cout << "(10 + 5) * 2 = " << ((a + b) * c) << " (Parentheses first)" << std::endl;

    // Division and multiplication have same precedence and left-to-right associativity
    std::cout << "10 / 5 * 2 = " << (a / b * c) << " (Left-to-right associativity)" << std::endl;

    // Modulus has same precedence as multiplication and division
    std::cout << "10 % 5 + 2 = " << (a % b + c) << " (Modulo first, then addition)" << std::endl;

    // Logical AND has lower precedence than comparison
    std::cout << "(10 > 5) && (5 > 2) = " << ((a > b) && (b > c)) << " (Comparison first)" << std::endl;

    // Logical OR (||) has lower precedence than logical AND (&&)
    std::cout << "(10 > 5) || (5 < 2) && (10 == 10) = "
        << ((a > b) || (b < c) && (a == a))
        << " (AND before OR)" << std::endl;

    // Bitwise operators: AND (&), OR (|), XOR (^)
    std::cout << "10 & 5 | 2 = " << (a & b | c) << " (Bitwise AND first, then OR)" << std::endl;

    // Assignment has right-to-left associativity
    int x{}, y{}, z{};
    x = y = z = 5;
    std::cout << "x = y = z = 5 results in x: " << x << ", y: " << y << ", z: " << z << std::endl;

    // Ternary operator has right-to-left associativity
    int result = (a > b) ? (b > c ? 100 : 200) : 300;
    std::cout << "Ternary operator result: " << result << std::endl;

    // Comma operator evaluates left to right
    int m = (std::cout << "Comma operator: ", 10 + 5);
    std::cout << m << std::endl;
}



// Operators in C++
void arithmeticOperators() {
    std::cout << "Arithmetic Operators" << std::endl;
    int a{10}, b{3};
    std::cout << "a + b = " << (a + b) << std::endl;
    std::cout << "a - b = " << (a - b) << std::endl;
    std::cout << "a * b = " << (a * b) << std::endl;
    std::cout << "a / b = " << (a / b) << " (Integer division)" << std::endl;
    std::cout << "a % b = " << (a % b) << " (Modulo)" << std::endl;
    std::cout << std::endl;
}
void relationalOperators() {
    std::cout << "Relational Operators" << std::endl;
    int a{10}, b{5};
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << std::endl;
}
void logicalOperators() {
    std::cout << "Logical Operators" << std::endl;
    bool x{true}, y{false};
    std::cout << "x && y: " << (x && y) << std::endl;
    std::cout << "x || y: " << (x || y) << std::endl;
    std::cout << "!x: " << (!x) << std::endl;
    std::cout << std::endl;
}
void bitwiseOperators() {
    std::cout << "Bitwise Operators" << std::endl;
    int a{5}, b{3};
    std::cout << "a & b: " << (a & b) << " (Bitwise AND)" << std::endl;
    std::cout << "a | b: " << (a | b) << " (Bitwise OR)" << std::endl;
    std::cout << "a ^ b: " << (a ^ b) << " (Bitwise XOR)" << std::endl;
    std::cout << "~a: " << (~a) << " (Bitwise NOT)" << std::endl;
    std::cout << "a << 1: " << (a << 1) << " (Left shift)" << std::endl;
    std::cout << "a >> 1: " << (a >> 1) << " (Right shift)" << std::endl;
    std::cout << std::endl;
}
void assignmentOperators() {
    std::cout << "Assignment Operators" << std::endl;
    int a{10};
    std::cout << "a += 5: " << (a += 5) << std::endl;
    std::cout << "a -= 3: " << (a -= 3) << std::endl;
    std::cout << "a *= 2: " << (a *= 2) << std::endl;
    std::cout << "a /= 4: " << (a /= 4) << std::endl;
    std::cout << "a %= 3: " << (a %= 3) << std::endl;
    std::cout << std::endl;
}
void ternaryOperator() {
    std::cout << "Ternary Operator" << std::endl;
    int a{10}, b{5};
    int min{(a < b) ? a : b};
    std::cout << "Minimum of a and b: " << min << std::endl;
    std::cout << std::endl;
}


// Function to demonstrate PREFIX increment and decrement
void Prefix() {
    int a{5}, b{5};  // Brace initialization

    std::cout << "Before Prefix Increment: a = " << a << '\n';
    int prefixIncrement{++a}; // a is incremented first, then assigned
    std::cout << "After Prefix Increment: a = " << a << ", prefixIncrement = " << prefixIncrement << '\n';

    std::cout << "\nBefore Prefix Decrement: b = " << b << '\n';
    int prefixDecrement{--b}; // b is decremented first, then assigned
    std::cout << "After Prefix Decrement: b = " << b << ", prefixDecrement = " << prefixDecrement << '\n';
}


// Function to demonstrate POSTFIX increment and decrement
void Postfix() {
    int x{5}, y{5};  // Brace initialization

    std::cout << "Before Postfix Increment: x = " << x << '\n';
    int postfixIncrement{x++}; // x is assigned first, then incremented
    std::cout << "After Postfix Increment: x = " << x << ", postfixIncrement = " << postfixIncrement << '\n';

    std::cout << "\nBefore Postfix Decrement: y = " << y << '\n';
    int postfixDecrement{y--}; // y is assigned first, then decremented
    std::cout << "After Postfix Decrement: y = " << y << ", postfixDecrement = " << postfixDecrement << '\n';
}



export int operatorCpp() {
    arithmeticOperators();
    relationalOperators();
    logicalOperators();
    bitwiseOperators();
    assignmentOperators();
    ternaryOperator();
    testPrecedenceAndAssociativity();
    Prefix();
    Postfix();
    return 0;
}

