/*
Name: Connor Robison
NetID: w10045714

Program Description: Write a program that reads in a passage of English text from a text file. 
The program should count the number of English words present in the file.
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>


using namespace std;

// function prototypes
int count_words(vector<string> document);
vector<string> load_file_data(string name);

int main() {
	bool run = true;
	string file_name, answer;
	ifstream file;
	int word_count;

	while (run) {

		while (!(file.is_open())) {
			cout << "Enter your file name: ";
			cin >> file_name;

			file.open(file_name); //if (file.is_open()) { cout << "   File opened" << endl; }
			
			if(!(file.is_open()))
				cout << "Error: Could not open the file entered. Please try again." << endl;

		}

		file.close(); //cout << "   File closed" << endl;

		word_count = count_words(load_file_data(file_name));
		cout << "Your file has " << word_count << " word(s) in it." << endl;

		answer = "X"; // invalid answer to start while loop

		while (!((answer == "Y") || (answer == "N"))) {
			cout << "Read another file? (Y/N): ";
			cin >> answer;

			for (int i = 0; i < answer.size(); i++)
				answer[i] = toupper(answer[i]);

			if (!((answer == "Y") || (answer == "N")))
				cout << "Error: Invalid input. Enter Y or N for the following prompt." << endl;

		}

		if (answer == "N") // this condition will end the main function
			run = false;
	}

	return 0;
	
} // end main

int count_words(vector<string> document) {
	int count = 0;

	for  (int i = 0; i < document.size(); i++) {
		int k = 0; 
		//cout << "Checking line " << i + 1 << endl;

		while ( k < document[i].size()) {
			//cout << "   " << document[i][k] << endl;

			if((isalpha(document[i][k]) || ispunct(document[i][k])) && isspace(document[i][k + 1])) {
				count++;
				k++;
				//cout << "   **Found a word" << endl;
			}
			else
				k++;
		}

		// if the line ends with a word, then increment the count.
		if (isalpha(document[i][k - 1]) || ispunct(document[i][k - 1])) {
			count++;
			//cout << "   **Found a word" << endl;
		} 

	}

	return count;

} // end count_words

vector<string> load_file_data(string name) {
	ifstream file (name);
	vector<string> words;
	string new_line;
		
	while (getline(file, new_line)) {
		words.push_back(new_line);
		//cout << new_word << endl;
	}

	return words;

} // end load_file_data