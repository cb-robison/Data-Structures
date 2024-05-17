#pragma once
/*
* Name: Connor Robison
* NetID: w10045714
* Program Description: This class will allow the user to encode and decode messages using a Ceasar Cipher with a given key.
*/

#include<string>
#include<iostream>
#include<cctype>

using std::string;
using std::cout;
using std::endl;

class Cipher {
private:
	char alpha_1[13] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M' };
	char alpha_2[13] = { 'N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };

	string plain_text;
	string cipher_text;
	int key;

	/*		Utility Functions		*/
	int FindChar(char character) {
		// A utility function that supports EncodeCharand DecodeChar. Is used to determine the position of the given letter in the alphabet vector / list.
		char temp = toupper(character);

		// If character is A-M, compare with alpha_1
		if (temp > 64 && temp < 78) {
			for (int i = 0; i < 13; i++) {
				if (temp == alpha_1[i])
					return i;
			}
		}
		// If character is N-Z, compare with alpha_2
		else if (temp > 77 && temp < 91) {
			for (int i = 13; i < 26; i++) {
				if (temp == alpha_2[i - 13])
					return i;
			}
		}
	}

	char EncodeChar(char character) {
		// A utility function that supports Encode. Is used to encode a single given character.
		
		// Test if the character is a letter
		if (isalpha(character)) {
			int position = FindChar(character);
			int new_position = position + key;

			// Find the position of the encrypted letter
			if (new_position >= 0) {
				new_position = new_position % 26;
			}
			else {
				new_position = (26 + new_position) % 26;
			}

			// Return the position of the encrypted letter
			if (new_position < 13) {
				if (islower(character))
					return tolower(alpha_1[new_position]);
				else
					return (alpha_1[new_position]);
			}
			else{
				if (islower(character))
					return tolower(alpha_2[new_position - 13]);
				else
					return (alpha_2[new_position - 13]);
			}
		}
		// Return the character if it is not a letter
		else
			return character;
	}

	void Encode() {
		// A utility function that supports SetKey and the constructor. Is called when the message needs to be transformed from plain text to cipher text using the shift key.
		cipher_text = "";
		
		for (int i = 0; i < plain_text.size(); i++) {
			char temp_2 = plain_text[i];
			cipher_text += EncodeChar(temp_2);
		}
	}

	char DecodeChar(char character) {
		// A utility function that supports Decode.Is used to decode a single given character.
		
		// Test if the character is a letter
		if (isalpha(character)) {
			int position = FindChar(character);
			int new_position = position - key;

			// Find the position of the encrypted letter
			if (new_position >= 0) {
				new_position = new_position % 26;
			}
			else {
				new_position = (26 + new_position) % 26;
			}

			// Return the position of the encrypted letter
			if (new_position < 13) {
				if (isupper(character))
					return alpha_1[new_position];
				else
					return tolower(alpha_1[new_position]);
			}
			else {
				if (isupper(character))
					return alpha_2[new_position - 13];
				else
					return tolower(alpha_2[new_position - 13]);
			}
		}
		// Return the character if it is not a letter
		else
			return character;
	}

	void Decode() {
		// A utility function that supports SetKey and the Constructor. Is called when the message needs to be transformed from cipher text to plain text using the negation of the shift key.
		plain_text = "";

		for (int i = 0; i < cipher_text.size(); i++) {
			char temp_2 = cipher_text[i];
			plain_text += DecodeChar(temp_2);
		}
	}

public:

	/*		Constructors		*/
	Cipher() {
		plain_text = cipher_text = "N/A";
		key = 0;
	}

	Cipher(string text, int shift_key, bool is_encrypted) {
		SetKey(shift_key);
		
		if(is_encrypted){
			// Decrypt
			cipher_text = text;
			Decode();
		}
		else {
			// Encrypte
			plain_text = text;
			Encode();
		}
	}

	/*		Class Attributes		*/
	string GetPlainText(){
		return plain_text;
	}

	string GetCipherText() {
		return cipher_text;
	}

	int GetKey() {
		return key;
	}

	void SetKey(int shift_key) {
		// If shift_key = 0, then reject it
		if (shift_key % 26 == 0)
			throw 1;
		else
			key = shift_key;

		// Re-encrypt the message
		Encode();
	}

	void ChangeText(string new_text, int shift_key, bool is_encrypted) {
		// Accepts and sets a new text and shift key. A Boolean is additionally passed in to determine whether the given text is already encrypted. 
		// The attributes plaintext, ciphertext, and key must be updated accordingly.
		SetKey(shift_key);

		if (is_encrypted) {
			cipher_text = new_text;
			Decode();
		}
		else {
			plain_text = new_text;
			Encode();
		}
	}
};