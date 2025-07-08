import std;
#include "basics_header.h"

void dataTypes(){

	/*
		 => Data Types
			1. Primitive Data Types:
				-> Integer (int)
				-> Character (char)
				-> Boolean (bool)
				-> Floating Point (float)
				-> Double Floating Point (double)
				-> Void (void)

			2. Derived Data Types:
				-> Function
				-> Array
				-> Pointer
				-> Reference

			3. Abstract or User-Defined Data Types:
				-> Class
				-> Structure
				-> Union
				-> Enumeration
				-> Typedef defined Datatype

		=> Size of Data Types
		   __________________________________________________________________
		   |    TYPE    |  TYPICAL BIT WIDTH  |        TYPICAL RANGE        |
		   |____________|_____________________|_____________________________|
		   |            |                     |                             |
		   | -> char    |  1 byte             |         -127 to 127         |
		   | -> int     |  4 bytes            |  -2147483648 to 2147483647  |
		   | -> float   |  4 bytes            |   -3.4×10^38 to 3.4×10^38   |
		   | -> double  |  8 bytes            |  -1.7×10^308 to 1.7×10^308  |
		   |____________|_____________________|_____________________________|

		=> 1 byte = 8 bits
		   - int type has 32 bits out of which 1 bit is reserved for sign of integer, so
			 the int data type can store upto the value of 2^31
		   - For using all 32 bits declare variable as unsigned int.

		=> Data type modifiers

		   __________________________________________________________________________________________________
		   | DATA TYPE                 |    SIZE IN BYTES    |          RANGE                               |
		   |___________________________|_____________________|______________________________________________|
		   |                           |                     |                                              |
		   | -> short int              |      2 byte         |        -32,768 to 32,767                     |
		   | -> unsigned short int     |      2 bytes        |              0 to 65535                      |
		   | -> unsigned int           |      4 bytes        |              0 to 4,294,967,295              |
		   | -> int                    |      4 bytes        | -2,147,483,648 to 2,147,483,647              |
		   | -> long int               |      4 bytes        | -2,147,483,648 to 2,147,483,647              |
		   | -> unsigned long int      |      4 bytes        |              0 to 4,294,967,295              |
		   | -> long long int          |      8 bytes        |        -(2^63) to (2^63)-1                   |
		   | -> unsigned long long int |      8 bytes        |              0 to 18,446,744,073,709,551,615 |
		   | -> signed char            |      1 bytes        |           -128 to 127                        |
		   | -> float                  |      4 bytes        |     -3.4×10^38 to 3.4×10^38                  |
		   | -> double                 |      8 bytes        |    -1.7×10^308 to 1.7×10^308                 |
		   | -> long double            |     12 bytes        |   -1.1×10^4932 to 1.1×10^4932                |
		   | -> wchar_t                |   2 or 4 bytes      |           1 wide character                   |
		   |___________________________|_____________________|______________________________________________|

	*/
	bool value{true};
	std::cout << value << std::endl;
}