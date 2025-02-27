export module loops;
import <iostream>;

/*
	A for loop is a repetition control structure that allows us to write a loop that is
	executed a specific number of times. It is an entry-controlled loop that enables us to
	perform n number of steps together in one line. for loop is an entry-controlled loop that is
	used to execute a block of code repeatedly for the given number of times. It is generally
	preferred over while and do-while loops in case the number of iterations is known beforehand.
*/
export void forLoop() {
	for (int i = 0; i <= 10; ++i) {
		std::cout << i << std::endl;
	}
}

/*
	the while loop is an entry-controlled loop that repeatedly executes a block of code as
	long as the given condition remains true. Unlike the for loop, while loop is used in
	situations where we do not know the exact number of iterations of the loop beforehand as
	the loop execution is terminated on the basis of the test condition.
*/
export void whileLoop() {
	int count{10};
	while (count > 0) {
		std::cout << count << std::endl;
		count--;
	}
}

/*
	the do-while loop is an exit-controlled loop that repeatedly executes a block of code at least
	once and continues executing as long as a given condition remains true. Unlike the while loop,
	the do-while loop guarantees that the loop body will execute at least once, regardless of whether
	the condition is true or false.
*/
export void doWhileLoop() {
	int i{0};
	do {
		std::cout << "Hi" << std::endl;
		i++;
	} while (i < 5);
}