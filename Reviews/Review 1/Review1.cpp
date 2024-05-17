#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;

// CSC 307 C++ Review Problems 1
int main() {
	/*
	//Problem 1
	const double manufacture_price = 35.95;
	double sell_price = 1.35 * manufacture_price;
	cout << "If the manufacture's price is " << manufacture_price << " the sell price should be " << setprecision(4) << sell_price <<".";


	//Problem 2
	const int coverage = 340;	// square feet covered per gallon of paint
	int length, height;
	double gallons;

	cout << "Please enter the length and the height, in feet, of the fence you wish to paint. Separate the two integers with a space.\n";
	cin >> length >> height;

	gallons = (2.0 * length * height) / coverage;

	cout << "\nYou will need " << ceil(gallons) << " gallon(s) of paint.";


	//Problem 3
	int num_seconds, days, hours, minutes, seconds;
	cout << "Please enter a value of time in seconds: ";
	cin >> num_seconds;

	int temp_seconds = num_seconds;

	// Get number of days
	days = temp_seconds / 86400;
	cout << days << " day(s), ";
	temp_seconds = temp_seconds % 86400;

	// Get number of hours
	hours = temp_seconds / 3600;
	cout << hours << " hour(s), ";
	temp_seconds = temp_seconds % 3600;

	// Get number of minutes
	minutes = temp_seconds / 60;
	cout << minutes << " minute(s), ";
	temp_seconds = temp_seconds % 60;

	// Outpute remaining seconds
	cout << temp_seconds  << " second(s).\n";
	

	//Problem 4
	int num_names;
	vector<string> names;

	cout << "How many names will you enter? ";
	cin >> num_names;

	for (int i = 0; i < num_names; i++) {
		string name;
		cout << "Enter name " << i + 1 << ": ";
		cin >> name;

		names.push_back(name);
	}

	string smallest_name = names[0];
	string largest_name = names[0];
	

	for (int i = 1; i < num_names; i++) {
		if (names[i].compare(smallest_name) < 0) {
			smallest_name = names[i];
		}
		if (names[i].compare(largest_name) > 0) {
			largest_name = names[i];
		}
	}

	cout << "\n" << smallest_name << " should be at the front of the line, and " << largest_name << " should be at the back.\n";
	*/

	//Problem 6
	ifstream myFile;
	vector<string> commonNames;
	string newName, userName;
	bool flag = 0;

	myFile.open("names.txt");
	if (myFile.is_open()) {
		//cout << "File opened\n";
		while (getline(myFile, newName)) {
			commonNames.push_back(newName);
		}
		myFile.close();
		//cout << "File closed\n";
	}
	else {
		cout << "Unable to open file\n";
	}
	
	cout << "Enter a name to check if it is on the list: ";
	cin >> userName;

	for (int i = 0; i < size(commonNames); i++) {
		if (userName == commonNames[i]) {
			flag = 1;
		}
	}

	if (flag) {
		cout << "That name is a common name\n";
	}
	else {
		cout << "That name is not a common name\n";
	}
}