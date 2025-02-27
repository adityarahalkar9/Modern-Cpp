export module variable;
import <iostream>;

// Variables are containers for storing data values.

export void variables() {
	// int - stores integers (whole numbers), without decimals, such as 123 or -123
	int appleCount{10};

	// double - stores floating point numbers, with decimals, such as 19.99 or -19.99
	double salary{2500.900};

	// char - stores single characters, such as 'a' or 'B'. Char values are surrounded by single quotes
	char myLetter{'d'};

	// string - stores text, such as "Hello World". String values are surrounded by double quotes
	std::string name{"Aditya"};

	// bool - stores values with two states: true or false
	bool isTrue = true;

	std::cout << appleCount << std::endl;
	std::cout << salary << std::endl;
	std::cout << myLetter << std::endl;
	std::cout << name << std::endl;
	std::cout << isTrue << std::endl;
}

export void userInput() {
	int x{}, y{};
	std::cout << "Enter x: " << std::endl;
	std::cin >> x;
	std::cout << "Enter y: " << std::endl;
	std::cin >> y;

	std::cout << "x is: " << x << std::endl;
	std::cout << "y is: " << y << std::endl;
}