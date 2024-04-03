#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	int count = 1, movie_selection, age, adult_tickets, child_tickets;
	const int list_width = 30, g=0, pg=7, pg13=13, r=17, nc17=18;
	const double adult_price = 12.00, child_price = 8.00;
	double amount, tendered, sales_tax = 0.06, total;

	cout << setprecision(2) << fixed;

	cout << "*********************************** MOVIE TICKET BOOKING **********************************\n\n";
	//error codes
			//-1 is wrong movie selection
			//-2 is negative number in age
			//-3 is age doesn't match movie rating
			//-4 is adult tickets is negative
			//-5 is child tried to purchase adult tickets
			//-6 is child tickets is negative
			//-7 is tendered amount less than zero
			//-8 is total cost greater than tendered amount

	cout << "Welcome! Please select a movie you'd like to watch from the list below.\n";

	cout << setw(2) << count++ << ". " << left << "The Suicide Squad (Rated R)\n";
	cout << right << setw(2) << count++ << ". " << left << "Cruella (Rated PG)\n";
	cout << right << setw(2) << count++ << ". " << left << "Shang-Chi and the Legend of the Ten Rings (Rated PG-13)\n";
	cout << right << setw(2) << count++ << ". " << left << "Luca (Rated G)\n";
	cout << right << setw(2) << count++ << ". " << left << "Blue Is the Warmest Color (Rated NC-17)\n\n";

	cout << "Please make a single selection for the movie you would like to watch (1-5): ";
	cin >> movie_selection;

	if (movie_selection < 1 || movie_selection > 5) {
		cout << "Invalid menu choice, please choose again." << endl;
		return -1;
	}
	

	cout << "Please enter your age: ";
	cin >> age;

	if (age < 0) {
		cout << "Age cannot be a negative number, please enter your age again." << endl;
		return -2;
	}
	
	switch (movie_selection) {
	case 1:
		if (age >= r) {
			cout << "The Suicide Squad is Rated R. You can watch this movie!" << endl;
		}
		else {
			cout << "The Suicide Squad is Rated R. You are too young to watch this movie. Please choose another movie." << endl;
			return -3;
		}
		break;
	case 2:
		if (age >= pg) {
			cout << "Cruella is rated PG. You can watch this movie!" << endl;
		}
		else {
			cout << "Cruella is rated PG. You are too young to watch this movie. Please choose another movie." << endl;
			return -3;
		}
		break;
	case 3:
		if (age >= pg13) {
			cout << "Shang-Chi and the Legend of the Ten Rings is rated PG-13. You can watch this movie!" << endl;
		}
		else {
			cout << "Shang-Chi and the Legend of the Ten Rings is rated PG-13. You are too young to watch this movie. Please choose another movie." << endl;
			return -3;
		}
		break;
	case 4:
		if (age >= g) {
			cout << "Luca is rated G. You can watch this movie!" << endl;
		}
		else {
			cout << "Luca is rated G. You are too young to watch this movie. Please choose another movie." << endl;
			return -3;
		}
		break;
	case 5:
		if (age >= nc17) {
			cout << "Blue Is the Warmest Color is rated NC-17. You can watch this movie!" << endl;
		}
		else {
			cout << "Blue Is the Warmest Color is rated NC-17. You are too young to watch this movie. Please choose another movie." << endl;
			return -3; 
		}
		break;
	}

	cout << "How many adult tickets would you like to purchase?" << endl;
	cin >> adult_tickets;

	if (adult_tickets < 0) {
		cout << "You can't purchase a negative amount of tickets. Please try again to purchase a ticket." << endl;
		return -4;
	}
		
	if (age < 18) {
		cout << "You are too young to buy an adult ticket. Please start again to purchase a child ticket." << endl;
		return -5;
	}

	cout << "How many child tickets would you like to purchase?" << endl;
	cin >> child_tickets;

	if (child_tickets < 0) {
		cout << "You can't purchase a negative amount of tickets. Please try again to purchase a ticket." << endl;
		return -6;
	}

	amount = (adult_tickets * adult_price) + (child_tickets * child_price);

	cout << "Your purchase amount is: $" << amount << endl;
	cout << "Sales tax is: $" << amount * sales_tax << endl;

	total = amount * (1 + sales_tax);
	cout << "Your total purchase price is: $" << total << endl;

	cout << "Enter in amount tendered: $";
	cin >> tendered;

	if (tendered < 0) {
		cout << "You have to enter a positive/greater than zero amount of money. Please try again." << endl;
		return -7;
	}

	if (total > tendered) {
		cout << "You entered less money than you owe. Please try again." << endl;
		return -8;
	}

	double change = tendered - total;

	if (change >= 1) {
		int dollars = change;
		cout << "You have $" << dollars << " in change." << endl;
		change -= dollars;

		int quarters = change / 0.25;
		cout << "You have " << quarters << " quarters in change." << endl;
		change -= quarters * 0.25;

		int dimes = change / 0.10;
		cout << "You have " << dimes << " dimes in change." << endl;
		change -= dimes * 0.10;

		int nickels = change / 0.05;
		cout << "You have " << nickels << " nickels in change." << endl;
		change -= nickels * 0.05;

		int pennies = change / 0.01;
		cout << "You have " << pennies << " pennies in change." << endl;
		change -= pennies * 0.01;

		int cents = change * 100;
		cout << "You have " << cents << " cents in change." << endl << endl;
		change -= cents * 0.01;
	}

	cout << "Thank you so much for participating! It's been a pleasure to have you. Stay curious!" << endl << endl;

	return 0;
}
