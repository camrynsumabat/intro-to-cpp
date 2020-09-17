// Camryn Sumabat
// Project 1
// Diamond : outputs a diamond

#include <iostream>
using namespace std;

int main()
{
	int i, j, k, m;
	bool isItOdd;
	do {
		cout << "Please enter an odd number between 1 and 15.";
		cin >> i;
		if (i % 2 == 1 && i <= 15 && i >= 1)
			isItOdd = true;
		else
			isItOdd = false;
	} while (isItOdd == false);
	
	/*do {
		cout << "Enter an odd number between 1 and 15.\n";
		cin >> i;
		if (i % 2 == 1 || i >= 15 || i <= 1)
			cout << "Please choose an odd number between 1 and 15.";
	} while (i % 2 == 1 || i >= 15 || i <= 1); */
	// Assign a variable input-1 to get correct amount of spaces on either side of the star
	m = i - 1;
	// Use for loops to create lines with the correct amount of stars and spaces
	for (k = 1; k <= i; k++)
	{
		for (j = 1; j <= m; j++)
		{
			cout << " ";
		}
		m--;
		for (j = 1; j <= ((2 * k) - 1); j++)
		{
			cout << "*";
		}
		cout << "\n";
	}
	m = 1;

	for (k = 1; k <= i - 1; k++)
	{
		for (j = 1; j <= m; j++)
		{
			cout << " ";
		}
		m++;
		for (j = 1; j <= 2 * (i - k) - 1; j++)
		{
			cout << "*";
		}
		cout << "\n";
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
