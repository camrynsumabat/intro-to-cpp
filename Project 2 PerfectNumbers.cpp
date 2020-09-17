//Camryn Sumabat
//Project 2 
//PerfectNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int input, sum;
	static string equation = "";
	vector<int> factorsVector;

	ofstream o("output.txt");

	cout << "Input a number between 1 and 100,000 (inclusive):\n";
	cin >> input;

	//input validation
	while (input < 1 || input > 100000)
	{
		cout << "Invalid input. Please input a number between 1 and 100,000\n";
		cin >> input;
	}

	//finds perfect numbers
	for (int possiblePerfect = input; possiblePerfect > 0; possiblePerfect--) //iterates each possible perfect number
	{
		sum = 0;
		factorsVector.clear();

		for (int factor = 1; factor <= (possiblePerfect/2); factor++) //iterates each possible factor for possible perfect number
		{
			//while (findPerfect < possiblePerfect) //checks that the added factors have not exceeded the possible perfect number being checked
			//{
			if ((possiblePerfect % factor) == 0) //finds factors
			{
				factorsVector.insert(factorsVector.end(), factor);//write the factors to a string
				sum += factor; //adds the factor to the running total of possible perfect numbers
			}
		}
		if (sum == possiblePerfect) //if the running total is equal to the possible perfect number, then it is perfect
		{
			int size = factorsVector.size();

			o << sum << " = ";

			for (int i = 0; i < size; i++)
			{
				o << to_string(factorsVector.at(i));

				if (i != (size-1))
				{
					o << " + ";
				}
				else
				{
					o << endl;
				}
			}
		}
	}
	
	//close output file
	o.close();


	string line;
	//read perfect numbers from the file
	ifstream i ("output.txt");

	//change this to string
	if (i)
	{
		while (getline (i, line))
		{
			cout << line << endl;
		}
	}
	else
	{
		cout << "Error opening file... :(";
	}

	//close input file
	i.close();

	return 0;
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
