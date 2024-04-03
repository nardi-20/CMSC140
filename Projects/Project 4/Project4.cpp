#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int ITEM_NUM = 10;
const double SALES_TAX = 0.6;

void displayMenu();
double calculateTotal(int choice, const double itemPrices[]);
void giveChange(double change);

int main() {
    string itemNames[ITEM_NUM] = {
        "Twix",
        "Snickers",
        "M&M's",
        "Peanut M&M's",
        "Lay's Potato Chips",
        "Lay's BBQ Potato Chips",
        "Fritos",
        "Doritos",
        "Pepsi",
        "Coca-Cola"
    };

    double itemPrices[ITEM_NUM] = {
        1.75,
        1.79,
        1.95,
        1.99,
        2.00,
        2.10,
        2.25,
        2.50,
        2.99,
        3.00
    };

    int choice;
    double amount = 0.0;

    displayMenu();

    cout << "Enter your choice: ";
    cin >> choice;

    cout << endl;

    amount = calculateTotal(choice, itemPrices);

    if (amount > 0.0) {
        cout << "Your purchase amount is: $" << amount << endl;
        cout << "Sales tax is: $" << amount * SALES_TAX << endl;
        cout << "Your total purchase price is: $" << amount * (1 + SALES_TAX) << endl;

        cout << "Enter in amount tendered: $";
        double tendered;
        cin >> tendered;

        double change = tendered - amount * (1 + SALES_TAX);
        if (change >= 0) {
            cout << "Thank you for your purchase!" << endl;
            giveChange(tendered, amount);
        }
        else {
            cerr << "Insufficient funds." << endl;
        }
    }
    else {
        cerr << "You selected an invalid choice. Please select items 1-" << ITEM_NUM << "." << endl;
    }

    return 0;
}

void displayMenu() {
    cout << setw(35) << "Welcome to the MC vending machine!" << endl;
    cout << setw(35) << "==================================" << endl << endl;

    for (int i = 0; i < ITEM_NUM; ++i) {
        cout << i + 1 << ". " << left << setw(25) << itemNames[i] << "$" << itemPrices[i] << endl;
    }
}

double calculateTotal(int choice, const double itemPrices[]) {
    if (choice >= 1 && choice <= ITEM_NUM) {
        return itemPrices[choice - 1];
    }
    else {
        cout << "Invalid choice. Please select items 1-" << ITEM_NUM << "." << endl;
        return 0.0;
    }
}

void giveChange(double tendered, double amount) {
    double change = tendered - amount;

    if (change < 0) {
        cerr << "You tried to short-change me! I quit!" << endl;
        return;
    }

    int dollars = static_cast<int>(change);
    change -= dollars;

    int cents = static_cast<int>(round(change * 100)); 

    int quarters = cents / 25;
    cents %= 25;

    int dimes = cents / 10;
    cents %= 10;

    int nickels = cents / 5;
    cents %= 5;

    int pennies = cents;

    cout << "Change breakdown:" << endl;
    cout << "Dollars: " << dollars << endl;
    cout << "Quarters: " << quarters << endl;
    cout << "Dimes: " << dimes << endl;
    cout << "Nickels: " << nickels << endl;
    cout << "Pennies: " << pennies << endl;
}
