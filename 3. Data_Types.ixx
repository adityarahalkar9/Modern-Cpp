export module datatypes;
import <iostream>;

/*
	Basic Data Types:
			int, float, double, char, bool, void
	Derived Data Types:
			array, pointer, reference, function
	User Defined Data Types:
			class, struct, union, typedef, using
*/

export void dataTypes() {
	// Printing the size of each data type
	std::cout << "Size of int: " << sizeof(int) << " bytes" << std::endl;
	std::cout << "Size of char: " << sizeof(char) << " byte" << std::endl;
	std::cout << "Size of float: " << sizeof(float) << " bytes" << std::endl;
	std::cout << "Size of double: " << sizeof(double) << " bytes";
}

/*
	C++ Type Modifiers
	In C++, type modifiers are the keywords used to change or give extra meaning to already
	existing data types. It is added to primitive data types as a prefix to modify their size or
	range of data they can store.

	C++ have 4 type modifiers which are as follows:
	1. signed Modifier
	2. unsigned Modifier
	3. short Modifier
	4. long Modifier
*/

/*
	Data Type				Modifiers				Size (bytes)			Range

	1. char					signed						1				-128 to 127
							unsigned (default)          1				0 to 255

	2. short int			signed               		2				-32,768 to 32,767
							unsigned					2				0 to 65,535
							                                                                                 
	3. int					signed(default)				4				-2,147,483,648 to 2,147,483,647
							unsigned					4				0 to 4,294,967,295

	4. long int				signed(default)				8				-9,223,372,036,854,775,808 to
																		9,223,372,036,854,775,807
							unsigned					8				0 to 18,446,744,073,709,551,615

	5. long long int		signed(default)				8				-9,223,372,036,854,775,808 to
																		9,223,372,036,854,775,807
							unsigned					8				0 to 18,446,744,073,709,551,615
							 
	6. double				None						8				~1.7E-308 to 1.7E+308
	7. long double			None						16				Higher precision, range varies
																		depending on implementation
*/

export void modifiers() {
	// Integer types
	short int si{32767};           // short int (usually 16-bit, range: -32,768 to 32,767)
	unsigned short int usi{65535}; // unsigned short int (range: 0 to 65,535)
	int i{2147483647};             // int (usually 32-bit, range: -2,147,483,648 to 2,147,483,647)
	unsigned int ui{4294967295};   // unsigned int (range: 0 to 4,294,967,295)
	long int li{2147483647L};      // long int (same as int on most platforms, range: -2,147,483,648 to 2,147,483,647)
	unsigned long int uli{4294967295UL}; // unsigned long int (range: 0 to 4,294,967,295)
	long long int lli{9223372036854775807LL}; // long long int (usually 64-bit, range: -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807)
	unsigned long long int ulli{18446744073709551615ULL}; // unsigned long long int (range: 0 to 18,446,744,073,709,551,615)

	// Character types
	char c{'A'};                   // char (usually 8-bit, range: -128 to 127 or 0 to 255)
	signed char sc{-128};           // signed char (range: -128 to 127)
	unsigned char uc{255};          // unsigned char (range: 0 to 255)

	// Floating-point types
	float f{3.14f};                 // float (single precision, ~6-7 decimal digits, range: ±1.5 × 10⁻⁴⁵ to ±3.4 × 10³⁸)
	double d{3.141592653589793};     // double (double precision, ~15-16 decimal digits, range: ±5.0 × 10⁻³²⁴ to ±1.8 × 10³⁰⁸)
	long double ld{3.141592653589793L}; // long double (extended precision, implementation-dependent, often greater than double)

	// Boolean type
	bool b{true}; // Boolean type (true/false, range: 0 or 1)

	// Printing values
	std::cout << "Short int: " << si << std::endl;
	std::cout << "Unsigned short int: " << usi << std::endl;
	std::cout << "Int: " << i << std::endl;
	std::cout << "Unsigned int: " << ui << std::endl;
	std::cout << "Long int: " << li << std::endl;
	std::cout << "Unsigned long int: " << uli << std::endl;
	std::cout << "Long long int: " << lli << std::endl;
	std::cout << "Unsigned long long int: " << ulli << std::endl;
	std::cout << "Char: " << c << std::endl;
	std::cout << "Signed char: " << static_cast<int>(sc) << std::endl;
	std::cout << "Unsigned char: " << static_cast<int>(uc) << std::endl;
	std::cout << "Float: " << f << std::endl;
	std::cout << "Double: " << d << std::endl;
	std::cout << "Long double: " << ld << std::endl;
	std::cout << "Boolean: " << b << std::endl;
}