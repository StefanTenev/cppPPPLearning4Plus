//#include "PPPheaders.h"
#include <iostream>
#include <string>
#include <limits>
#include <vector>

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

	return temp;
}

static void exercise_8_to_10() {
	std::cout << "This program let's you enter enter numbers into a list and then get the sum of a specified amount of numbers from that list\n."
		<< "Lastly, it also calculates the numberical difference between adjacent numbers in your list.\n"
		<< "Please begin entering your input by giving a number and then pressing enter for each input.\n"
		<< "Enter '|' when you have given all your entries.\n";
	std::vector<double> numbers;

	
	double double_min = std::numeric_limits<double>::min();
	double double_max = std::numeric_limits<double>::max();

	for (std::string input; std::cin >> input;) {
		if (input == "|") {
			break;
		}
		double coerced_num = std::stod(input);
		if (coerced_num < double_min || coerced_num > double_max) {
			customError("The input you have entered cannot be represented as a double");
		}
		numbers.push_back(coerced_num);
	}
	std::cout << "Your numbers:\n";
	for (double num : numbers) {
		std::cout << num << " ";
	}

	std::cout << "How many of the numbers of the list would you like to sum up (in the order which you have given)?\n";
	int sum_amount;
	std::cin >> sum_amount;

	while (sum_amount > numbers.size() || sum_amount < 0) {
		std::cout << "You have entered an invalid sum amount (below 0 or more than the amount of numbers in the list)."
			<< "Please try again: ";
		std::cin >> sum_amount;
	}

	double sum = 0;

	for (int i = 0; i < sum_amount; i++) {
		std::cout << sum << "+" << numbers[i] << " = " << sum + numbers[i] << '\n';
		sum += numbers[i];
	}

	std::cout << "Total = " << sum << '\n';

	if (numbers.size() > 1) {
		std::vector<double> differences;

		for (int i = 1; i < numbers.size(); i++) {
			double difference = numbers[i] - numbers[i - 1];
			differences.push_back(difference);

		}

		std::cout << '\n' << "Difference between adjacent numbers:\n";
		for (double difference : differences) {
			std::cout << difference << "; ";
		}
	}
	else {
		std::cout << "Your list has one or less numbers, hence, there are no adjacent numbers to take differences from!";
	}
}


static void exercises() {
	// exercises 2 - 5
	
	//double temp = 0;
	//std::string convert_choice;
	//std::cout << "This programme converts temperatures of C/K to C/K.\n"
	//	<< "Please press 1 for Celsius to Kelvin, or 2 for Kelvin to Celsius, press enter when you have given your choice.\n";
	//std::cin >> convert_choice;
	//if (convert_choice == "1") {
	//	std::cout << "Enter a value of temp in Celsius, to convert into Kelvin:\n";
	//	std::cin >> temp;
	//}
	//else if (convert_choice == "2"){
	//	std::cout << "Enter a value of temp in Kelvin, to convert into Celsius:\n";
	//	std::cin >> temp;
	//}
	//double k = exercise2_ctok(convert_choice, temp);
	//std::cout << k << '\n';

	// Exercises 8 - 10

	exercise_8_to_10();
}