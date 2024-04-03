/*
Class: CMSC140 22082
Instructor: Sandro Fouche
Project 3
Description: Build Mastermind game using do while, while, and for loops.
Due Date:10/28/2023
I pledge that I have completed the programming assignment independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
Print your name here: Nardos W. Hailemariam
*/
#include <iostream>
#include <string>

using namespace std;

char getRandomColor() { 
	string colors = "RGBYOP"; 
	return colors[rand() % 6]; 
}

int main() {
	const string programmer_name = "Nardos W. Hailemariam", due_date = "October 28, 2023", course_details = "CMSC140 20082";
	const char project_number = '3';

	bool WIN = true;
	int maximum_guess = 10, actual_guess = 1;
	int total_possible_score = 100, best_score = 0, last_score = 0;
	int score= total_possible_score / maximum_guess;
	string guess;
	string white = "[W]", black = "[B]";
	char play_again;
	
	cout << "Welcome to the Code Breaker!" << endl;
	cout << "Your goal is to guess the secret code." << endl;
	cout << "For each guess, you will receive feedback in the form of colored pegs." << endl;
	cout << "[B] for each color that is correct and in the correct position." << endl;
	cout << "[W] for each color that is correct but in the wrong position." << endl << endl;

	cout << "Possible colors are:" << endl;
	cout << "R- Red" << endl;
	cout << "O- Orange" << endl;
	cout << "Y- Yellow" << endl;
	cout << "G- Green" << endl;
	cout << "B- Blue" << endl;
	cout << "P- Purple" << endl << endl;

	cout << "Let's start!" << endl;

	do {
		srand(time(0));
		char color1 = getRandomColor();
		char color2 = getRandomColor();
		char color3 = getRandomColor();
		char color4 = getRandomColor();

		string secret;
		secret += color1;
		secret += color2;
		secret += color3;
		secret += color4;

		cout << "The secret code: " << secret << endl << endl;

		for (actual_guess=1; actual_guess <= maximum_guess; actual_guess++) {
			cout << endl <<  "Enter your guess #" << actual_guess << " (eg - RGBY): " << endl;
			cin >> guess;

			cout << "Feedback: ";

			int black_count = 0, white_count = 0;

			for (int i = 0; i < 4; i++) {
				if (guess[i] == secret[i]) {
					cout << black;
				}
				else {
					for (int j = 0; j < 4; j++) {
						if (guess[i] == secret[j]) {
							cout << white;
							break;
						}
					}
				}
			}

			if (guess == secret) {
				WIN = true;
				break;
			}
			else {
				WIN = false;
			}
		}
		if (WIN) {
			if (actual_guess == 1) {
				last_score = maximum_guess * 10;
			}
			else {
				last_score = (maximum_guess - actual_guess) * 10;
			}
		}
		else {
			last_score = 0;
		}

		if (last_score > best_score) {
			best_score = last_score;
		}

		if (WIN) {
		cout << endl << "You won! I admit defeat! You guessed my secret (that I spent so long working on) in " << actual_guess << " try/tries." << endl << endl;
		}
		else {
			cout << endl << "You lost!! I triumph! You're going to have to try harder than that." << endl << endl;
		}
		cout << "The secret code was " << secret << "!" << endl << endl;

		cout << "Your current score: " << last_score << endl;
		cout << "Your highest score: " << best_score << endl;
		
		cout << "Do you want to play again? (Y/N)" << endl;
		cin >> play_again;

		if (play_again == 'N' || play_again == 'n') {
		cout << endl << "Thanks for playing, hope to see you back again soon!" << endl << endl;
		cout << "Programmer name: " << programmer_name << endl << course_details << endl << "Project #" << project_number << endl << "Due date: " << due_date << endl;
		break;
		}
		else {
			cout << endl << "Great! Your code has changed, let's play again!" << endl;
			WIN = false;
		}

	} while (play_again=='Y' || play_again == 'y');

	return 0;
}
