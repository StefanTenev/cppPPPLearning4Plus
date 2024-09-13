#include <iostream>
#include <string>
// including random for the random number generator
#include <random>

static void follow_along() {
	/* 
		the multiplication of the 2 positive ints bellow, will create an int overflow
		i.e. the 64 bit system cannot contain the product, hence overflowing and creating
		a negative result, this is something to consider if we are working with 
		positive ints and requiring a positive result (as the negative product of the 2 below can break such expectations)
	*/ 
	std::cout << 3037000500 * 3037000500 << '\n';

	// defining the random engine
	/*
		By default, the engine will generate any random number,
		this may not be useful on its own, hence, we can create a distribution
	*/
	std::default_random_engine engine;

	// creating a distribution of numbers 1 - 10 (inclusive)
	// the distribution transforms the random number and maps it to one of the numbers within the range
	std::uniform_int_distribution<int> dist(1, 10);

	// using the engine with the distribution, to generate a number within the distribution 
	for (int i = 0; i < 5; i++) {
		std::cout << dist(engine) << '\n';
	}

	// this syntax allows us to create a string with 10 characters (1st argument), initiated to x (2nd argument)
	std::string s(10, 'x');

	std::cout << "initiated string: " << s << '\n';

	// creating a random distribution with chars a - z
	std::uniform_int_distribution<int> letterDist('a', 'z');

	// randomising our string
	for (char& ch : s) {
		// note, it is good to have a narrow function ensuring that the result si safely cast to char
		// in this case, we are based as we don't yet know how a function would look
		ch = letterDist(engine);
	}

	std::cout << "random string: " << s << '\n';
}