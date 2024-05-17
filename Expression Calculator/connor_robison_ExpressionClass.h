#pragma once

/*

Name: Connor Robison

NetID: w10045714

Program Description: This function will utilize a stack to convert an expression in the form of a string from infix notation to postfix notation.

*/

#include<string>
#include<iostream>

using std::string;
using std::cout;
using std::endl;

template<class T>
class Node {
public:
	T data;
	Node<T>* next;
	Node<T>* previous;
};

template<class T>
class Deque {
private:
	Node<T>* front;
	Node<T>* back;
	int count;
public:
	Deque() {
		front = back = nullptr;
		count = 0;
	}

	/*
	void PushFront(T data) {
		Node<T>* temp = new Node<T>();
		temp->data = data;

		if (count == 0) {
			front = back = temp;
			temp->next = nullptr;
			temp->previous = nullptr;
		}
		else {
			temp->next = front;
			temp->previous = nullptr;

			front->previous = temp;
			front = temp;
		}

		count++;
	}
	*/

	void PushBack(T data) {
		Node<T>* temp = new Node<T>();
		temp->data = data;

		if (count == 0) {
			front = back = temp;
			temp->next = nullptr;
			temp->previous = nullptr;
		}
		else {
			temp->next = nullptr;
			temp->previous = back;

			back->next = temp;
			back = temp;
		}

		//cout << "\tPushing " << temp->data << endl;
		count++;
	}

	/*
	bool PopFront(T& data) {
		if (count == 0)
			return false;

		data = front->data;
		Node<T>* temp = front;

		front = front->next;
		delete temp;

		if (front != nullptr) {
			front->previous = nullptr;
		}

		count--;

		return true;
	}
	*/

	bool PopBack(T& data) {
		if (count == 0)
			return false;

		data = back->data;
		Node<T>* temp = back;

		back = back->previous;
		//cout << "\tPopping " << temp->data << endl;
		delete temp;

		if (back != nullptr) {
			back->next = nullptr;
		}

		count--;

		return true;
	}

	/*
	bool PeekFront(T& data) {
		if (count == 0)
			return false;

		data = front->data;
		return true;
	}
	*/

	bool PeekBack(T& data) {
		if (count == 0)
			return false;

		data = back->data;
		return true;
	}

	bool IsEmpty() { return(count == 0 ? true : false); }

	int GetCount() { return count; }

};

class Expression {
private:
	string infix;
	string postfix;

public:
	Expression() {

	}

	Expression(string infix) {
		SetExpression(infix);
	}

	void SetExpression(string infix) {
		this->infix = infix;

		ConvertToPostfix(infix);
	}

	string GetInfix() {
		return infix;
	}

	string GetPostfix() {
		return postfix;
	}

private:
	int GetOperatorPrecedence(char o) {
		int precedence;

		if (o == '+' || o == '-')
			precedence = 1;
		if (o == '*' || o == '/')
			precedence = 2;
		if (o == '^')
			precedence = 3;
		if (o == '(' || o == ')')
			precedence = 4;

		return precedence;
	}

	bool IsOperator(char o) {
		bool result;

		if (o == '+' || o == '-' || o == '*' || o == '/' || o == '(' || o == ')' || o == '^')
			result = true;
		else
			result = false;

		return result;
	}

	void ConvertToPostfix(string infix) {
		string postfix_result;
		Deque<string> st;
		string toString;

		for (int i = 0; i < infix.size(); i++) {
			char character = infix[i];

			if (isalpha(character) || isdigit(character)) { 
				postfix_result += character;

				if (!isalnum(infix[i + 1])) {
					postfix_result += " ";
				}
			}
			else if (IsOperator(character)) {
				string current_top;
				st.PeekBack(current_top);

				if (st.IsEmpty() || current_top == "(") {
					toString += character;
					st.PushBack(toString);
					toString.clear();
				}
				else if (character == '(') {
					toString += character;
					st.PushBack(toString);
					toString.clear();
				}
				else if (character == ')') {
					while (!st.IsEmpty() && current_top[0] != '(') {

						st.PopBack(toString);
						postfix_result += toString + " ";
						toString.clear();
						st.PeekBack(current_top);
					}
					if (!st.IsEmpty() && current_top == "(") {
						st.PopBack(toString);
						toString.clear();
					}
				}
				else if (GetOperatorPrecedence(character) > GetOperatorPrecedence((current_top)[0]))
				{
					//cout << "\tcharacter > top" << endl;

					toString += character;
					st.PushBack(toString);
					toString.clear();
				}
				else if (GetOperatorPrecedence(character) == GetOperatorPrecedence((current_top)[0]))
				{
					//cout << "\tcharacter == top" << endl;

					st.PopBack(toString);
					postfix_result.append((toString + " "));
					toString.clear();
					toString += character;
					st.PushBack(toString);
					toString.clear();
				}
				else if (GetOperatorPrecedence(character) < GetOperatorPrecedence(current_top[0])) {
					do {
						//cout << "\tcharacter < top" << endl;
						st.PopBack(toString);
						toString.clear();
						postfix_result += current_top + " ";
						st.PeekBack(current_top);

					} while (GetOperatorPrecedence(character) < GetOperatorPrecedence(current_top[0]) && !(st.IsEmpty()));

					toString += character;
					st.PushBack(toString);
					toString.clear();
				}
			}
		}

		while (!st.IsEmpty()) {
			st.PopBack(toString);
			postfix_result += toString + " ";
			toString.clear();
		}

		postfix = postfix_result;
	}
};