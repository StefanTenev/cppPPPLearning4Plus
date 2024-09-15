#include "PPPheaders.h"
#include <string>

static int drill() {
	try{

		/*
		* Cout << "Success!\n";
		
			errors: identifier "Cout" is undefined 
			&& Cout was not detected in this scope

			fix by: Cout => cout
		*/
		
		/*
		* cout << "Success!\n;
		
			errors: missing closing quote 
			&& expected a ';'

			fix by: adding " at end:
			cout << "Success!\n; => cout << "Success!\n";
		*/

		/*
		* cout << "Success" << !\n"
		
			errors: stray '\' in program 
			&& missing terminatin "character 
			&& 'n' was not declared in this scope

			fix by: replacing ! with "; adding ';' at end:
			"Success" << !\n" => cout << "Success" << "!\n";
		*/

		/*
		* cout << success << ’\n’;
		
			errors: stray '\222' in program 
			&& stray '\' in program
			&& 'success'' was not declared in this scope
			&& 'n' was not declared in this scope

			fix by: adding "s to success, replacing ’s with 's: 
			cout << success << ’\n’; => cout << "success" << '\n';
		*/
		
		/*
		* string res = 7;
		* vector<int> v(10);
		* v[5] = res;
		* cout << "Success!\n";
		
			errors: conversion from ‘int’ to non - scalar type ‘PPP::Checked_string’ requested
			&& cannot convert ‘PPP::Checked_string’ to ‘int’ in assignment

			fix by: putting "s around 7, changing the vector type to string:
			string res = 7; => string res = "7";
			vector<int> v(10); => vector<string> v(10);
		*/

		/*
		* vector<int> v(10); 
		* v(5) = 7;
		* if (v(5) != 7)
		* cout << "Success!\n";

			errors: no match for call to '(PPP::Checked_vector<int>) (int)'

			fix by: using []s instead of ()s to access the vector
			&& consider != needs to be == for success to be logged:
			v[5] = 7;
			 if (v[5] == 7)
		*/

		/*
		* if (cond) cout << "Success!\n";
		* else cout << "Fail!\n";

			errors: 'cond was not declared in this scope'

			fix by: replacing cond with true:
			if (cond) cout << "Success!\n"; => if (true) cout << "Success!\n";
		*/

		/*
		* bool c = false; 
		* if (c) cout << "Success!\n";
		* else cout << "Fail!\n";
		* cout << "Success!\n";

			errors: logical error - c == false

			fix by: assigning c to true
		*/

		/*
		* string s = "ape";
		* boo c = "fool" < s;
		* if (c) cout << "Success!\n";

			errors: 'boo' was not declared in this scope, did you mean bool?
			&& logical error - comparison of fool and ape is lexicographical, meaning
			that comparison is made by comparing ASCII values ('f' == 102 && 'a' == 97), hence, c == false

			fix by: changing 'boo' to bool
			&& switching the comparison operator:
			boo c = "fool" < s; => bool c = "fool" > s;
		*/

		/*
		* string s = "ape";
		* if (s == "fool") cout << "Success!\n";

			errors: logical error - s should not equal fool

			fix by: changing == sign to !=:
			if (s == "fool") cout << "Success!\n"; => if (s != "fool") cout << "Success!\n";
		*/

		/*
		* string s = "ape";
		* if (s == "fool") cout < "Success!\n";

			errors: no operator "<"matches these opearands
			&& no match for ‘operator < ’(operand types are ‘std::ostream’{ aka ‘std::basic_ostream<char>’ } and ‘const char[10]’)

			fix by: adding < to cout:
			if (s == "fool") cout < "Success!\n"; => if (s == "fool") cout << "Success!\n";
		*/

		// 12 - with errors: string s = "ape"; if (s+"fool") cout < "Success!\n";
		std::string s = "ape"; 
		if (s == "fool") 
			cout << "Success12!\n";
		
		// 13 - with errors: vector<char> v(5); for (int i = 0; 0<v.siz e(); ++i) ; cout << "Success!\n";
		vector<char> v(5); 
		for (int i = 0; i < v.size(); ++i)
			cout << "Success13!\n";

		// 14 - with errors: vector<char> v(5); for (int i = 0; i<=v.siz e(); ++i) ; cout << "Success!\n";
		vector<char> v2(5); 
		for (int i = 0; i < v2.size(); ++i)
			cout << "Success14!\n";

		// 15 - with errors: string s = "Success!\n"; for (int i = 0; i<6; ++i) cout << s[i];
		std::string s15 = "Success15!\n"; 
		for (int i = 0; i < s15.size(); ++i) 
			cout << s15[i];
		cout << '\n';

		// 16 - with errors: if (true) then cout << "Success!\n"; else cout << "Fail!\n";
		if (true)
			cout << "Success16!\n"; 
		else cout << "Fail!\n";

		// 17 - with errors: int x = 2000; char c = x; if (c==2000) cout << "Success!\n";
		int x = 2000; 
		int c = x; 
		if (c == 2000) 
			cout << "Success17!\n";

		// 18 - with errors: string s = "Success!\n"; for (int i = 0; i<10; ++i) cout << s[i];
		std::string s18 = "Success18!\n"; 
		for (int i = 0; i < s18.size(); ++i) 
			cout << s18[i];
		cout << '\n';

		// 19 - with errors: vector v(5); for (int i = 0; i<=v.siz e(); ++i) ; cout << "Success!\n";
		vector<int> v19(5); 
		for (int i = 0; i <= v19.size(); ++i)
			cout << "Success19!\n";

		// 20 - with errors: int i = 0; int j = 9; while (i<10) ++j; if (j<i) cout << "Success!\n";
		int i = 0; 
		int j = 9; 
		while (i < 10)
			++i;
		if (j < i) cout << "Success20!\n";

		// 21 - with errors: int x = 2; double d = 5/(x−2); if (d==2∗x+0.5) cout << "Success!\n";
		// in the example above - even if x !== 0, 5/(x...) will result to a truncated int
		// the math could be change in many ways...
		double x21 = 2; 
		double d21 = 5 / (x21); 
		if (d21 == x21 + 0.5) 
			cout << "Success21!\n";

		// 22 = with errors: string<char> s = "Success!\n"; for (int i = 0; i<=10; ++i) cout << s[i];
		std::string s22 = "Success22!\n"; 
		for (int i = 0; i < s22.size(); ++i) 
			cout << s22[i];

		// 24 - with errors: int x = 4; double d = 5/(x−2); if (d=2∗x+0.5) cout << "Success!\n";
		int x24 = 4; 
		double d24 = 5 / (x24 - 3); 
		if (d24 = 2 * (x24 + 0.5)) 
			cout << "Success24!\n";

		// 25 - with errors: cin << "Success!\n";
		cout << "Success25!\n";

		return 0;
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		cerr << "Oops: unknown exception!\n";
		return 2;
	}
}