#include <iostream>
using namespace std;


/**
 * This is an better program for the candy machine project that still sells 5 kinds of
 * candy.
 *
 * However, this program will use Arrays as a tool to store data.
 *
 * Users can only insert a fixed amount of money include nickels, pennies, quarters, dimes
 * and 1 dollar.
 *
 * This is a class project in CS04103 - COMPUTER SCI & PROGM (Section 9).
 * @professor Dr. Doug Riecken.
 * @author (Xuan Do)
 * @version (1.0.1)
 *
 */

/*
 * @param selection User's input number
 * @return cost The cost of the candy matching the given selection.
 */
double getCandyCost(int selection) {
	double cost = 0.0;
	if(selection == 1 || selection == 2) {

		cost = 0.5;

	} else if(selection >= 3 && selection <= 5) {

		cost = 1.0;

	} else {

		cost = 0.0;
	}
	return cost;
}


void printCandy(double cost) { // header of printCandy method.
	double currentTotal = 0.0; // input: the current money that candy machine is received for user's input.
	double balance = 0.0; // input: the money users insert.
	double change = 0.0; // output: the change users can get.

	do { // header if do-while loop

		// Prompt users to insert money.

		cout << "You need to insert more money ";

		// Read in inserted money.

		cin >> balance;

		if(balance == 0.1 || balance == 0.5 || balance == 0.10 || balance == 0.25 || balance == 1.0) {
			currentTotal += balance;
		} else {
			cout << "Invalid input - Insert real money. Try again!!!"
					"\nWe only accept nickels, pennies, quarters, dimes and 1 dollar." << endl;
		}

		// a condition for the do-while loop, as long as the cost of
		// the candy is greater than the current total money, candy machine
		// will keep asking users to insert more money.
	} while(currentTotal < cost);

	cout << endl;
	change = currentTotal - cost;

	// Print out a message telling users that the change they will get.

	cout << "Here is your change " << change << endl;

	// Print out a message telling users that their candy is out.

	cout << "Here is your candy ";

}

/*
 * Print name of candy matching the given selection
 * @param selection The number from 1 to 5.
 *
 */

void userChoice(int selection) { // header of userChoice

	if(selection == 1) {

		cout << "Snikers" << endl;
	}

	else if(selection == 2) {

		cout << "M and M's" << endl;
	}

	else if(selection == 3) {

		cout << "Kitkat" << endl;
	}

	else if(selection == 4) {

		cout << "Hersheys" << endl;
	}

	else if(selection == 5) {

		cout << "Sweedish fish" << endl;
	}
	else {

		// This is a default message telling users that the candy they chose is not in candy machine option.
		// and in this case, users will not be charged for anything.

		cout << "There is no candy like that";
	}
}

/**
 * This is a driver for testing the operation of the candy machine.
 * Display an instruction and prompt users to enter selection and insert money.
 */

int main() { // start of main function.
	int selection = 0; // input: user's selection from 1 to 5.
	double candyCost = 0.0; // additional variable to store cost of the candy.

	// This is an instruction telling users what to select.
	// Users enter 1 if they want to buy Snikers
	// 2 if they want to buy M and M's
	// 3 if they want to buy Kitkat
	// 4 if they want to buy Hersheys
	// 5 if they want to buy Sweedish fish.

	cout << "Enter 1 for Snikers"
					"\n2 for M and M's"
					"\n3 for Kitkat"
					"\n4 for Hersheys"
					"\n5 for Sweedish fish" << endl << endl;

	// Prompt users to make selection.

	cout << "Enter selection here: " << endl;

	// System in selection

	cin >> selection;

	// A message prints out what the number they selected.

	cout << "\nYou selected candy number " << selection << endl;

	// A message prints out telling users the cost of the candy they selected.

	cout << "Your candy costs " << getCandyCost(selection) << " dollar(s)" << endl;

	// Assign candy cost to variable candyCost.

	candyCost = getCandyCost(selection);

	cout << endl; // print a new line

	// Call the printCandy method.

	printCandy(candyCost);

	// Call the userChoice method.

	userChoice(selection);

	return 0; // end of the program.

}





















