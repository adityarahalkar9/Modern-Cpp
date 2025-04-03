import <iostream>;
export module structs;

/*
	​In C++, a struct (short for "structure") is a user-defined data type that allows grouping variables 
	of different types under a single name. This facilitates the organization and management of related 
	data. Structs are similar to classes but have some key differences, which we'll explore as we progress.​
*/

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


export int structsCall(){
    definingAndUsingStruct();

    return 0;
}