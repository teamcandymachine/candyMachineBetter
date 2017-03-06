#include <iostream>
#include <string>
#include <Windows.h>
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
* @author (TJ Ferry)
* @author (Benjamin Ansah)
* @author (Anne Marie Fernandez)
* @author (Miten Merkowsky)
* @author (Adrian Nurse)
* @author (Colin Duncan)
* @version (1.0.1)
*
*/

/*
* @param selection User's input number
* @return cost The cost of the candy matching the given selection.
*/
double getCandyCost(int selection) {
	double cost = 0.0;
	if (selection == 1 || selection == 2) {
		cost = 0.5;
	}
	else if (selection >= 3 && selection <= 5) {
		cost = 1.0;
	}
	else {
		cost = 0.0;
	}
	return cost;
}

void changeConsoleColor(string machineError){
	HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);

	// Remember how color was when program started
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);

	SetConsoleTextAttribute(hstdout, 0xEC); // set console color to red
	cout << machineError << endl; // output whatever is passed into function
	SetConsoleTextAttribute(hstdout, csbi.wAttributes); // set console color back to normal
}

void printCandy(double cost) { // header of printCandy method.

	double currentTotal = 0.0; // input: the current money that candy machine is received for user's input.
	double balance = 0.0; // input: the money users insert.
	double change = 0.0; // output: the change users can get.

	do { // header if do-while loop

		 // Prompt users to insert money.

		cout << "\nYou need to insert more money. ";

		// Read in inserted money.

		cin >> balance;

		if (balance == 0.01 || balance == 0.05 || balance == 0.10 || balance == 0.25 || balance == 1.0) {
			currentTotal += balance;
			if (fabs(currentTotal - cost) != 0){ // if remaning total is not zero; fabs pulls the absolute value of a float to not display negative number
				cout << "\nRemaining total: " << fabs(currentTotal - cost) << endl;
			}
		}
		else {
			changeConsoleColor("\nInvalid input - Insert real money. Try again!!!""\nWe only accept nickels, pennies, quarters, dimes and 1 dollar.");
		}

		// a condition for the do-while loop, as long as the cost of
		// the candy is greater than the current total money, candy machine
		// will keep asking users to insert more money.
	} while (currentTotal < cost);

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

								 // Store data into an string array.
	string myStringArray[5];

	myStringArray[0] = "Snikers";
	myStringArray[1] = "M and M's";
	myStringArray[2] = "Kitkat";
	myStringArray[3] = "Hersheys";
	myStringArray[4] = "Swedish Fish";

	switch (selection) {
	case 1: cout << myStringArray[0] << endl;
		break;
	case 2: cout << myStringArray[1] << endl;
		break;
	case 3: cout << myStringArray[2] << endl;
		break;
	case 4: cout << myStringArray[3] << endl;
		break;
	case 5: cout << myStringArray[4] << endl;
		break;


		// This is a default message telling users that the candy they chose is not in candy machine option.
		// and in this case, users will not be charged for anything.

	default:
		changeConsoleColor("\nThis machine does not carry that type of candy.");
	}

}

/**
* This is a driver for testing the operation of the candy machine.
* Display an instruction and prompt users to enter selection and insert money.
*/

int main() { // start of main function.
	char c;
	
	int selection = 0; // input: user's selection from 1 to 5.
	double candyCost = 0.0; // additional variable to store cost of the candy.

							// This is an instruction telling users what to select.
							// Users enter 1 if they want to buy Snikers
							// 2 if they want to buy M and M's
							// 3 if they want to buy Kitkat
							// 4 if they want to buy Hersheys
							// 5 if they want to buy Swedish Fish
							// 6 if they want to return.

	cout << "Make A Selection:"
		"\n1 for Snikers"
		"\n2 for M and M's"
		"\n3 for Kitkat"
		"\n4 for Hersheys"
		"\n5 for Swedish Fish"
		"\n6 to Return" << endl << endl;

	// Prompt users to make selection.

	cout << "Enter your selection here: " << endl;

	// System in selection

	cin >> selection;

	// A message prints out what the number they selected.
	cout << "\nYou selected candy number: " << selection << endl;

	// A message prints out telling users the cost of the candy they selected.

	if (selection <= 5) {
		cout << "Your candy costs $" << getCandyCost(selection) << endl;

		// Assign candy cost to variable candyCost.

		candyCost = getCandyCost(selection);

		// Call the printCandy method.

		printCandy(candyCost);

		// Call the userChoice method.

		userChoice(selection);

	}
	else if (selection == 6) {
		return 0; // end of the program.
	}
	else {
		changeConsoleColor("\nThis machine does not carry that type of candy.");
	}

	/**
	* If the program is ran in Visual Studio, this is
	* needed so once the user puts in change the window will not close
	*/

	cout << "\nEnter any character then hit the enter key to exit the program\n";
	cin >> c;

	return 0; // end of the program.

}
