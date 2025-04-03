export module controlstatement;
import <iostream>;

export void ifElseStatement() {
	int number{};
	std::cout << "Enter a number: ";
	std::cin >> number;

	if (number > 0) {
		std::cout << "Positive number" << std::endl;
	}
	else if (number < 0) {
		std::cout << "Negative number" << std::endl;
	}
	else {
		std::cout << "Zero" << std::endl;
	}
}

export void nestedIfElse() {
	std::cout << "To find greatest among three numbers" << std::endl;
	int num1{}, num2{}, num3{};

	std::cout << "Enter number 1: ";
	std::cin >> num1;
	std::cout << "Enter number 2: ";
	std::cin >> num2;
	std::cout << "Enter number 3: ";
	std::cin >> num3;

	if (num1 < num2) {
		if (num3 < num2) {
			std::cout << "Number 2 is the greatest which is: " << num2 << std::endl;
		}
		else {
			std::cout << "Number 3 is the greatest which is: " << num3 << std::endl;
		}
	}
	else {
		if (num3 < num1) {
			std::cout << "Number 1 is the greatest which is: " << num1 << std::endl;
		}
		else {
			std::cout << "Number 3 is the greatest which is: " << num3 << std::endl;
		}
	}
}

export void switchStatement() {
	int day{};
	std::cout << "Enter day number" << std::endl;
	std::cin >> day;

	switch (day) {
	case 1:
		std::cout << "Monday";
		break;
	case 2:
		std::cout << "Tuesday";
		break;
	case 3:
		std::cout << "Wednesday";
		break;
	case 4:
		std::cout << "Thursday";
		break;
	case 5:
		std::cout << "Friday";
		break;
	case 6:
		std::cout << "Saturday";
		break;
	case 7:
		std::cout << "Sunday";
		break;
	default:
		std::cout << "Invalid day number";
		break;
	}
}