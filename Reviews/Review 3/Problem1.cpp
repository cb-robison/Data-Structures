#include<iostream>
#include<cctype>
#include<string>

using namespace std;

string FilterPhrase(string original);
bool IsPalindrome(string phrase);
bool IsPalindrome(string phrase, int i, int j);

int main() {
	cout << (IsPalindrome("Able was I, ere I saw Elba") ? "Yes" : "No") << endl;
	cout << (IsPalindrome("A man, a plan, a canal, Panama") ? "Yes" : "No") << endl;
	cout << (IsPalindrome("Desserts, I stressed") ? "Yes" : "No") << endl;
	cout << (IsPalindrome("Kayak") ? "Yes" : "No") << endl;
	cout << (IsPalindrome("Word") ? "Yes" : "No") << endl;

	// Expected Output: Yes, Yes, Yes, Yes, No
}

string FilterPhrase(string original) {
	string filtered = "";

	for (int i = 0; i < original.size(); i++) {
		if (isalpha(original[i])) {
			char c = tolower(original[i]);
			filtered += c;
		}
	}

	return filtered;
}

bool IsPalindrome(string phrase, int i, int j) {
	if (i >= j) {
		return true;
	}
	else {
		if (phrase[i] != phrase[j])
			return false;
		else
			return IsPalindrome(phrase, i + 1, j - 1);
	}
}

bool IsPalindrome(string phrase) {
	string filter = FilterPhrase(phrase);

	return IsPalindrome(filter, 0, filter.size() - 1);
}
