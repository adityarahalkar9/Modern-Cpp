import <iostream>;
export module structs;

/*
	​In C++, a struct (short for "structure") is a user-defined data type that allows grouping variables 
	of different types under a single name. This facilitates the organization and management of related 
	data. Structs are similar to classes but have some key differences, which we'll explore as we progress.​
*/

// Defining and Using a Struct
void definingAndUsingStruct() {
    // Define a struct named 'Person'
    struct Person {
        std::string firstName{};
        std::string lastName{};
        int age{};
        double salary{};
    };

    // Initialize a Person instance using brace initialization
    Person person1{"John", "Doe", 30, 50000.0};

    // Access and modify struct members using the dot operator
    std::cout << "Defining and Using a Struct:\n";
    std::cout << "First Name: " << person1.firstName << "\n";
    std::cout << "Last Name: " << person1.lastName << "\n";
    std::cout << "Age: " << person1.age << "\n";
    std::cout << "Salary: " << person1.salary << "\n";

    // Modify a member
    person1.age = 31;
    std::cout << "Updated Age: " << person1.age << "\n\n";
}


// Initialising Structs
void initialisingStructs() {
    struct Person {
        std::string firstName{};
        std::string lastName{};
        int age{};
        double salary{};
    };

    // Aggregate Initialization
    Person person1{"Alice", "Smith", 28, 60000.0};

    // Designated Initializers (C++20)
    Person person2{.firstName = "Bob", .lastName = "Brown", .age = 35, .salary = 70000.0};

    // Default Initialization
    struct PersonWithDefaults {
        std::string firstName{"John"};
        std::string lastName{"Doe"};
        int age{30};
        double salary{50000.0};
    };
    PersonWithDefaults person3; // Uses default values

    std::cout << "Initializing Structs:\n";
    std::cout << "Person1: " << person1.firstName << " " << person1.lastName << ", Age: " << person1.age << ", Salary: " << person1.salary << "\n";
    std::cout << "Person2: " << person2.firstName << " " << person2.lastName << ", Age: " << person2.age << ", Salary: " << person2.salary << "\n";
    std::cout << "Person3: " << person3.firstName << " " << person3.lastName << ", Age: " << person3.age << ", Salary: " << person3.salary << "\n\n";
}


// Structs with Member Functions
void structsWithMemberFunctions() {
    struct Person {
        std::string firstName;
        std::string lastName;
        int age;
        double salary;

        // Member function to display information
        void displayInfo() const {
            std::cout << "Name: " << firstName << " " << lastName << "\n";
            std::cout << "Age: " << age << "\n";
            std::cout << "Salary: $" << salary << "\n";
        }
    };

    Person person{"Charlie", "Davis", 40, 80000.0};
    std::cout << "Structs with Member Functions:\n";
    person.displayInfo();
    std::cout << "\n";
}


// Arrays of Structs
void arraysOfStructs() {
    struct Person {
        std::string firstName;
        std::string lastName;
        int age;
        double salary;
    };

    // Array of Person structs
    Person people[]{
        {"David", "Edwards", 25, 55000.0},
        {"Eva", "Foster", 32, 62000.0},
        {"Frank", "Green", 29, 58000.0}
    };

    std::cout << "Arrays of Structs:\n";
    for (const auto &person : people) {
        std::cout << "Name: " << person.firstName << " " << person.lastName << "\n";
        std::cout << "Age: " << person.age << "\n";
        std::cout << "Salary: $" << person.salary << "\n";
        std::cout << "------------------------\n";
    }
    std::cout << "\n";
}

export int structsCall() {
    definingAndUsingStruct();
    initialisingStructs();
    structsWithMemberFunctions();
    arraysOfStructs();

    return 0;
}