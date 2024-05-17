#pragma once
#include<string>

using std::string;

class RomanNumeral {
private:
	int decimal_value;
public:
	RomanNumeral(int initial_value = 1) {
		SetNumber(initial_value);
	}

	void SetNumber(int initial_value) {
		if (initial_value > 0)
			decimal_value = initial_value;
		else if (initial_value > 1000)
			decimal_value = 1000;
		else
			decimal_value = 1;
	}

	int GetNumber() {
		return decimal_value;
	}

	string GetNumeral() {
		if (decimal_value >= 1 && decimal_value <= 9) {
			// Generate Numeral for 1 - 9
			return GenerateOnesNumeral(decimal_value);
		}
		else if (decimal_value >= 10 && decimal_value <= 99) {
			// Generate Numeral for 10 - 99
			int tens_digit = decimal_value / 10;
			int ones_digit = decimal_value % 10;

			return GenerateTensNumeral(tens_digit) + GenerateOnesNumeral(ones_digit);
		}
		else if (decimal_value >= 100 && decimal_value <= 999) {
			// Generate Numeral for 100 - 999
			int hundreds_digit = decimal_value / 100;
			int tens_digit = (decimal_value % 100) / 10;
			int ones_digit = decimal_value % 10;

			return GenerateHundredsNumeral(hundreds_digit) + GenerateTensNumeral(tens_digit) + GenerateOnesNumeral(ones_digit);
		}
		else
			return "M";
	}

	// Utility/Supporting Functions Defined Here
private:
	string GenerateOnesNumeral(int digit) {
		switch (digit) {
		case 0:
			return "";
		case 1:
			return "I";
		case 2:
			return "II";
		case 3:
			return "III";
		case 4:
			return "IV";
		case 5:
			return "V";
		case 6:
			return "VI";
		case 7:
			return "VII";
		case 8:
			return "VIII";
		case 9:
			return "IX";
		}
	}

	string GenerateTensNumeral(int digit) {
		switch (digit) {
		case 0:
			return "";
		case 1:
			return "X";
		case 2:
			return "XX";
		case 3:
			return "XXX";
		case 4:
			return "XL";
		case 5:
			return "L";
		case 6:
			return "LX";
		case 7:
			return "LXX";
		case 8:
			return "LXXX";
		case 9:
			return "XC";
		}
	}

	string GenerateHundredsNumeral(int digit) {
		switch (digit) {
		case 0:
			return "";
		case 1:
			return "C";
		case 2:
			return "CC";
		case 3:
			return "CCC";
		case 4:
			return "CD";
		case 5:
			return "D";
		case 6:
			return "DC";
		case 7:
			return "DCC";
		case 8:
			return "DCCC";
		case 9:
			return "CM";
		}
	}
};