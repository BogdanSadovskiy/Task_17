// calculator
using namespace std;
#include <iostream>
int factorial(int a) {
	if (a > 1) {
		return a * factorial(a - 1);
	}
	else{
		return 1;
	}
}
int multiplication(int a, int b) {
	cout << "ldasd" << endl;
	return a * b;
}
double division(double a, double b) {
	return a / b;
}
int addition(int a, int b) {
	return a + b;
}
int subtraction(int a, int b) {
	return a - b;
}
int exponentiation(int a, int b) {
	if (b > 0) {
		return a * exponentiation(a, b - 1);
	}
	else {
		return 1;
	}
}
int main()
{
	cout << "This calculator have addition, subtraction,";
	cout << " division, multiplication, exponentiation and factorial options \n";
	cout << "-----------------------------------------------------------------\n";
	int a; int c;
	char b;
	start:
	cout << "Input your act (Example \"1 * 4\" or \"4 ^ 2\")\n";
	cin >> a;
	cin >> b;
	if (b == '!') {
		cout << a << b << " = " << factorial(a);
	}
	else {
		cin >> c;
		if (b == '*') {
			cout << a << " " << b << " " << c << " = " << multiplication(a, c);
		}
		else if (b == '/') {
			cout << a << " " << b << " " << c << " = " << division(a, c);
		}
		else if (b == '+') {
			cout << a << " " << b << " " << c << " = " << addition(a, c);
		}
		else if (b == '-') {
			cout << a << " " << b << " " << c << " = " << subtraction(a, c);
		}
		else {
			cout << a << " " << b << " " << c << " = " << exponentiation(a, c);
		}

	}
	cout << endl <<  "Try again - 1\n";
	cout << "Exit - 0\n";
	cin >> a;
	if (a == 1) {
		goto start;
	}
	else {
		cout << "Bye\n";
		return 0;
	}
}

