/*
   Class: CMSC140 20082
   Instructor: Sandro Fouche
   Project 5
   Description: Build a Magic Square game
   Due Date: 12/6/2023
   I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Nardos W. Hailemariam
*/
#include<iostream>
#include <string>
#include <iomanip>

using namespace std;


const int ROWS = 3;
const int COLS = 3;
const int MIN = 1;
const int MAX = 9;
const int SUM = 15;

const string programmer_name = "Nardos W. Hailemariam", due_date = "December 6, 2023", course_details = "CMSC140 20082";
const char project_number = '5';

bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max);
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRowSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
bool checkColSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
bool checkDiagSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
void showArray(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);

int main() {
    char play_again;

    do {
        int size = COLS;
        int count = 0;

        int magicArrayRow1[COLS], magicArrayRow2[COLS], magicArrayRow3[COLS];
        cout << "***********************************************************************" << endl;
        cout << "Welcome to the a Magic Square game!" << endl << endl;
        cout << "The game revolves around a 3x3 box. You will need to fill the box with integer." << endl;
        cout << "Now, you may be thinking, 'That's so easy!' but as everything in life, it's not that simple." << endl << endl;
        cout << "There are a few rules." << endl;
        cout << ++count << ". Each number you enter should be from 1-9." << endl;
        cout << ++count << ". Each number you enter should be unique." << endl;
        cout << ++count << ". Each row should add up to " << SUM << "." << endl;
        cout << ++count << ". Each diagonal row should also add up to " << SUM << "." << endl;
        cout << endl << "Now you're ready to play. Good luck!" << endl << endl;

        fillArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);


        cout << endl;
        showArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);
        cout << endl;

        if (isMagicSquare(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS)) {
            cout << endl;
            cout << "Wow, I'm impressed! You actually won. This is a magic square!" << endl << endl;
        }
        else {
            cout << endl;
            cout << "Side eye! Did you not read the instructions?? This is not a magic square." << endl << endl;
        }

        cout << "Your game has ended. Do you want to play again(Y/N)? ";
        cin >> play_again;
        cout << endl;

    } while (play_again == 'Y' || play_again == 'y');

    cout << "Your game has ended. Please close and run the program again to have another chance." << endl;
    cout << "Thank you for participating!" << endl;
    cout << endl << endl << "Programmer name: " << programmer_name << endl << course_details << endl << "Project #" << project_number << endl << "Due date: " << due_date << endl;

    return 0;
}

void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
    cout << "Enter the values of the grid row by row, separated by an enter button:" << endl;
    for (int i = 0; i < size; ++i) {
        int a = 1;
        int b = i + 1;

        cout << "Enter the " << a << (a == 1 ? "st" : (a == 2 ? "nd" : "rd")) << " value for the " << b << (b == 1 ? "st" : (b == 2 ? "nd" : "rd")) << " row: ";
        cin >> arrayRow1[i];
        cout << "Enter the " << a + 1 << (a + 1 == 1 ? "st" : (a + 1 == 2 ? "nd" : "rd")) << " value for the " << b << (b == 1 ? "st" : (b == 2 ? "nd" : "rd")) << " row: ";
        cin >> arrayRow2[i];
        cout << "Enter the " << a + 2 << (a + 2 == 1 ? "st" : (a + 2 == 2 ? "nd" : "rd")) << " value for the " << b << (b == 1 ? "st" : (b == 2 ? "nd" : "rd")) << " row: ";
        cin >> arrayRow3[i];
    }
}

void showArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
    cout << endl << "Here is your completed Magic Square: " << endl;
    for (int i = 0; i < size; ++i)
        cout << arrayRow1[i] << " " << arrayRow2[i] << " " << arrayRow3[i] << endl;
}

bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max)
{
    for (int i = 0; i < size; ++i)
    {
        if (arrayRow1[i] < min || arrayRow1[i] > max
            || arrayRow2[i] < min || arrayRow2[i] > max
            || arrayRow3[i] < min || arrayRow3[i] > max) {
            cout << "One or more of the numbers you entered are outside the allowed range." << endl;
            return false;
        }
    }
    return true;
}

bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
    bool isMagic = true;

    cout << "Here are your errors: " << endl;

    if (!checkRange(arrayRow1, arrayRow2, arrayRow3, size, MIN, MAX)) {
        isMagic = false;
    }

    if (!checkUnique(arrayRow1, arrayRow2, arrayRow3, size)) {
        isMagic = false;
    }

    if (!checkRowSum(arrayRow1, arrayRow2, arrayRow3, size)) {
        isMagic = false;
    }

    if (!checkColSum(arrayRow1, arrayRow2, arrayRow3, size)) {
        isMagic = false;
    }

    if (!checkDiagSum(arrayRow1, arrayRow2, arrayRow3, size)) {
        isMagic = false;
    }

    if (isMagic == true) {
        cout << "You have no errors!" << endl;
    }
    return isMagic;
}

bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
    bool checked[MAX + 1] = { false };
    for (int i = 0; i < size; ++i)
    {
        if (checked[arrayRow1[i]] || checked[arrayRow2[i]] || checked[arrayRow3[i]]) {
            cout << "One or more of the numbers you entered are the same." << endl;
            return false;
        }
        checked[arrayRow1[i]] = checked[arrayRow2[i]] = checked[arrayRow3[i]] = true;
    }
    return true;
}

bool checkRowSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
    int rowSum1 = 0, rowSum2 = 0, rowSum3 = 0;

    for (int i = 0; i < size; ++i)
    {
        rowSum1 += arrayRow1[i];
        rowSum2 += arrayRow2[i];
        rowSum3 += arrayRow3[i];
    }

    bool rowSum = true;

    if (rowSum1 != SUM)
    {
        cout << "The sum of your first row is not equal to " << SUM << "." << endl;
        rowSum = false;
    }

    if (rowSum2 != SUM)
    {
        cout << "The sum of your second row is not equal to " << SUM << "." << endl;
        rowSum = false;
    }

    if (rowSum3 != SUM)
    {
        cout << "The sum of your third row is not equal to " << SUM << "." << endl;
        rowSum = false;
    }

    return rowSum;
}

bool checkColSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
    int colSum1 = arrayRow1[0] + arrayRow2[0] + arrayRow3[0];
    int colSum2 = arrayRow1[1] + arrayRow2[1] + arrayRow3[1];
    int colSum3 = arrayRow1[2] + arrayRow2[2] + arrayRow3[2];

    bool colSum = true;

    if (colSum1 != SUM)
    {
        cout << "The sum of your first column is not equal to " << SUM << "." << endl;
        colSum = false;
    }

    if (colSum2 != SUM)
    {
        cout << "The sum of your second column is not equal to " << SUM << "." << endl;
        colSum = false;
    }

    if (colSum3 != SUM)
    {
        cout << "The sum of your third column is not equal to " << SUM << "." << endl;
        colSum = false;
    }

    return colSum;
}

bool checkDiagSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{
    int diag1 = arrayrow1[0] + arrayrow2[1] + arrayrow3[2];
    int diag2 = arrayrow1[2] + arrayrow2[1] + arrayrow3[0];

    if ((diag1 == SUM) && (diag2 == SUM)) {
        return true;
    }
    else {
        cout << "The diagonal sums are not equal to " << SUM << "." << endl;
        return false;
    }
}
