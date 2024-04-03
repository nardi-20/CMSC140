#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {

	double favorite_number;
	double number_1, number_2;

	cout << setprecision(2) << fixed;

	cout << "************* Welcome to the Programming Event! *************" << endl;

	cout << "Hello! What is your name?" << endl;
	getline(cin, name);

	cout << "Glad you're here " << name << "!" << endl;

	cout << "Think of your favorite number. It could be your birthdate, lucky number or one that reminds you of someone you care about. Please give me that number now. " << endl << endl;
	cin >> favorite_number;

	cout << "Here are some facts about " << favorite_number << "." << endl << endl;

	if (favorite_number > 0)
		cout << "Your number is positive!" << endl;
	else if (favorite_number < 0)
		cout << "Your number is negative!" << endl;
	else cout << "Your number is zero! This is a rare integer that is neither postive or negative."<<endl;

	cout << "The double of " << favorite_number << " is: " << favorite_number * 2 << "." << endl;

	cout << "The half of " << favorite_number << " is: " << favorite_number * 0.5 << "." << endl;

	cout << "The square of " << favorite_number << " is: " << favorite_number * favorite_number << "." << endl;
	
	if (favorite_number > 0)
		cout << "The square root of " << favorite_number << " is: " << sqrt(favorite_number) << "." << endl;
	else if (favorite_number == 0)
		cout << "The square root of " << favorite_number << " is: " << favorite_number << endl;
	else cout << "Since your number is negative, it does not have a square root."<<endl;

	cout << "That was so fun! Let's try something else now." << endl << endl<< "Please give me two other whole numbers. They can be random or special to you. Please enter the first number: " << endl;

	cin >> number_1;

	cout << endl << "Thanks! Now enter the second number: " << endl;

	cin >> number_2;

	cout << endl << "Great! Now that we have both numbers, we can do some fun things with them too. Let's see." << endl;

	cout << "The sum of those numbers is " << number_1 + number_2 << "." << endl;

	cout << "The difference of those numbers is " << number_1 - number_2 << "." << endl;

	cout << "The product of those numbers is " << number_1 * number_2 << "." << endl;

	cout << "The quotient of those numbers is " << int(number_1 / number_2) << "." << endl;

	cout << "The float division of those numbers is " << float(number_1/number_2) << "." << endl;

	cout << "The increment of the first number is " << ++number_1 << "." << endl;

	cout << "The increment of the second number is " << ++number_2 << "." << endl;

	double a = (number_1) - 2;
	cout << "The decrement of the first number is " << a << "." << endl;

	double b = (number_2) - 2;
	cout << "The decrement of the second number is " << b << "." << endl;

	cout << "Thank you so much for participating! It's been a pleasure to have you. Stay curious!" << endl << endl;

	return 0;
}
