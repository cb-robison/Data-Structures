/*

Name: Connor Robison

NetID: w10045714

Program Description: This program will test the Expression Class with multiple examples.

*/

#include"connor_robison_ExpressionClass.h"
#include<iostream>

using namespace std;

int main() {
	Expression e1("A*B+C");

	cout << "\n\n\n\tInfix: " << e1.GetInfix() << endl;
	cout << "\tPostfix: " << e1.GetPostfix() << endl << endl;

	e1.SetExpression("56*B+2");

	cout << "\tInfix: " << e1.GetInfix() << endl;
	cout << "\tPostfix: " << e1.GetPostfix() << endl << endl;

	e1.SetExpression("2+8*C");

	cout << "\tInfix: " << e1.GetInfix() << endl;
	cout << "\tPostfix: " << e1.GetPostfix() << endl << endl;

	e1.SetExpression("5*(3+4)");

	cout << "\tInfix: " << e1.GetInfix() << endl;
	cout << "\tPostfix: " << e1.GetPostfix() << endl << endl;

	e1.SetExpression("55-2+1");

	cout << "\tInfix: " << e1.GetInfix() << endl;
	cout << "\tPostfix: " << e1.GetPostfix() << endl << endl;

	e1.SetExpression("A*2^C+6");

	cout << "\tInfix: " << e1.GetInfix() << endl;
	cout << "\tPostfix: " << e1.GetPostfix() << endl << endl;

	e1.SetExpression("A*(45+5*D)+8");

	cout << "\tInfix: " << e1.GetInfix() << endl;
	cout << "\tPostfix: " << e1.GetPostfix() << endl << endl << endl;
}