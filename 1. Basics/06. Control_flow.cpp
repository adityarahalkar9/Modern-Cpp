import std;
#include "basics_header.h"

/*
	continue keyword
	=> Instantly stops the current iteration and jumps to the start of the next one.
	=> Works inside for, while, and do-while.
	=> Useful when you want to skip processing certain elements.
*/
void continueStatement(){
	for (int i = 0; i < 5; ++i){
		if (i == 3){
			continue;  // Skips the element when i = 3
		}
		std::cout << i << std::endl;
	}
}

/*
	break keyword
	=> Immediately exits the innermost loop or switch block.
	=> Control goes to the statement right after the loop.
*/
void breakStatement(){
	for (int i = 0; i < 5; ++i){
		if (i == 3){
			break;  // Exits the loop entirely
		}
		std::cout << i << std::endl;
	}
}

