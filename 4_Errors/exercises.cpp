//#include "PPPheaders.h"
#include <iostream>
#include <string>

inline void customError(std::string err) {
	std::cout << "Error: " << err << '\n';
	exit(1);
}

// exercises 2-5
// correcting a piece of code on page 112
// program is meant to take a temperature in celsius and covert it into kelvin
static double exercise2_ctok(std::string convert_choice, double c) {
	// expects a double, c to be more than -273.15;
	// convert_choice - expects to be 1 or 2
	if (convert_choice != "1" && convert_choice != "2") {
		customError("This is not a viable choice, the program will not exit.\n");
	}
	if ((convert_choice == "1" && c < -273.15)
		|| convert_choice == "2" && c < 0) {
		customError("The temperature you have entered is below absolute zero, the program will now exist\n");
	}


	double temp = convert_choice == "1" ? c + 273.25 : c - 273.25;

	
}

static void exercises() {
	// exercises 2 - 5
	double temp = 0;
	std::string convert_choice;
	std::cout << "This programme converts temperatures of C/K to C/K.\n"
		<< "Please press 1 for Celsius to Kelvin, or 2 for Kelvin to Celsius, press enter when you have given your choice.\n";
	std::cin >> convert_choice;
	if (convert_choice == "1") {
		std::cout << "Enter a value of temp in Celsius, to convert into Kelvin:\n";
		std::cin >> temp;
	}
	else if (convert_choice == "2"){
		std::cout << "Enter a value of temp in Kelvin, to convert into Celsius:\n";
		std::cin >> temp;
	}
	double k = exercise2_ctok(convert_choice, temp);
	std::cout << k << '\n';
}