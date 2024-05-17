#include "RomanNumeral.h"
#include<iostream>

using namespace std;

int main() {

	RomanNumeral rn(50);
	RomanNumeral rn2;

	cout << rn.GetNumber() << endl;
	rn2.SetNumber(51);
	cout << rn2.GetNumber() << endl;
	rn.SetNumber(52);
	cout << rn.GetNumber() << endl;

	rn.SetNumber(879);
	cout << rn.GetNumeral() << endl;

}