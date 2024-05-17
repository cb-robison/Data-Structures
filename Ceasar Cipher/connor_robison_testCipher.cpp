#include"connor_robison_Cipher.h"
#include<iostream>

/*
* Name: Connor Robison
* NetID : w10045714
* Program Description : This program will be used to test the Cipher header file.
*/

using namespace std;

int main() {
	Cipher c1("", 1, false);
	cout << "Encode Test: Shift Key = "<< c1.GetKey() << endl;
	for (int i = 65; i < 123; i++) {
		string s1(1, char(i));
		c1.ChangeText(s1,1, false);

		cout << "\t" << c1.GetPlainText() << " -> " << c1.GetCipherText() << endl;
	}

	cout << "\n\nDecode Test: Shift Key = " << c1.GetKey() << endl;
	for (int i = 65; i < 123; i++) {
		string s1(1, char(i));
		c1.ChangeText(s1, 1, true);

		cout << "\t" << c1.GetCipherText() << " -> " << c1.GetPlainText() << endl;
	}

	c1.ChangeText("The army will strike at 18:59. All troops prepare immediately!", 11, false);
	cout << "\n\nEncode Test: Shift Key = " << c1.GetKey() << endl;
	cout << c1.GetPlainText() << " -> " << c1.GetCipherText() << endl;

	c1.ChangeText(c1.GetCipherText(), 11, true);
	cout << "\n\nDecode Test: Shift Key = " << c1.GetKey() << endl;
	cout << c1.GetCipherText() << " -> " << c1.GetPlainText() << endl;

	c1.ChangeText("The quick brown fox jumped over the lazy dog's back.", 9, false);
	cout << "\n\nMiscellaneous Testing:\nShift Key = " << c1.GetKey() << endl;
	cout << c1.GetPlainText() << " -> " << c1.GetCipherText() << endl;

	c1.ChangeText(c1.GetCipherText(), -9, false);
	cout << "\nShift Key = " << c1.GetKey() << endl;
	cout << c1.GetPlainText() << " -> " << c1.GetCipherText() << endl;

	c1.ChangeText("The five boxing wizards jump quickly.", -20, false);
	cout << "\nShift Key = " << c1.GetKey() << endl;
	cout << c1.GetPlainText() << " -> " << c1.GetCipherText() << endl;

	c1.ChangeText("Aruvu qfdszvj rtkvu hlrzekcp slk bvgk uizmzex kyvzi fove wfinriu.", 17, true);
	cout << "\nShift Key = " << c1.GetKey() << endl;
	cout << c1.GetCipherText() << " -> " << c1.GetPlainText() << endl;
}