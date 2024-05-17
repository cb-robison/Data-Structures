#include<iostream>
#include"Counter.h"

using namespace std;

int main() {

	// Exercises 1 and 2
	Counter my_count(50);

	cout << my_count.GetCount() << endl;
	my_count.SetCount(34);
	cout << my_count.GetCount() << endl;
	my_count.Reset();
	cout << my_count.GetCount() << endl << endl;

	for (Counter i(0); i.GetCount() < 100; i.Increment())
		cout << i.GetCount() << "\n";

	for (Counter i = 0; i < 100; i++)
		cout << i.GetCount() << "\n";

	for (Counter i = 100; i > 0; i--)
		cout << i.GetCount() << "\n";

	Counter c1 = 5;
	Counter c2 = 10;

	cout << "c1 = " << c1.GetCount() << "\nc2 = " << c2.GetCount() << endl;

	if (c1 <= 6)
		cout << "c1 <= 6" << endl;
	if (c2 >= 6)
		cout << "c2 >= 6" << endl;
	if (c2 == 10)
		cout << "c2 == 10" << endl;
	if (!(c1 == c2))
		cout << "c1 != c2" << endl;
	if (c1 < c2)
		cout << "c1 < c2" << endl;
	if (c2 > c1)
		cout << "c2 > c1" << endl;
	if (c1 <= c2)
		cout << "c1 <= c2" << endl;
	if (c2 >= c1)
		cout << "c2 >= c1" << endl;

	return 0;

}