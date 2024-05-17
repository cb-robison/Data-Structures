#include<iostream>
#include<random>

using namespace std;

int* GenerateRandomNumbers(int amount);

int main() {
	srand(time(NULL));

	int num_numbers = 100;
	
	cout << "How many numbers? ";
	cin >> num_numbers;

	int* list = GenerateRandomNumbers(num_numbers);
	
	for (int i = 1; i <= num_numbers; i++) {
		cout << list[i - 1] << "\t";
		
		if (i % 12 == 0)
			cout << "\n";
	}
	cout << endl;

	delete[] list;
 }

int* GenerateRandomNumbers(int amount) {
	int* list = new int[amount];

	for (int i = 0; i < amount; i++) {
		list[i] = rand() % 1001;
	}

	return list;
}