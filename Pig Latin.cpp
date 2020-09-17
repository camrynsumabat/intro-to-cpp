//Camryn Sumabat
//Project 3: Pig Latin

#include <iostream>
#include <string>
using namespace std;

string rewrite(string);
int wordCount(string&);
//const int SIZE = 51; //initialize large size for the char array

int main()
{
	string input; //initialize input array 
	string ay = "ay";
	string newString;
	int count = 0; //counter for going through the char array

	cout << "Type a sentence to be converted to Pig Latin!"<< endl;
	getline(cin, input); //takes user input as input until the size limit
	cout << "There are " << wordCount(input) << " words." << endl; //debugging purpose
	cout << rewrite(input) << endl;
	return 0;
}

int wordCount(string &s)
{
	int count = 0;
	char nextChar; //goes through each character
	for (int i = 0; i<int(s.length()); i++)
	{
		nextChar = s.at(i);
		if (isspace(s[i])) //counts spaces
			count++;
	}
	count++; //adds one for the last word
	return count;
}

string rewrite(string s)
{
	int words = wordCount(s), wordEnd = 0, wordBegin = 0;
	string firstLetter, newString, subString;

	for (int i = 0; i < words; i++) //loops for each word
	{
		firstLetter = s[wordBegin]; //gets first letter of each word
		wordEnd = s.find(' ', wordEnd+1); //finds the end of each word
		subString = s.substr(++wordBegin, wordEnd - wordBegin); //gets substring starting from the second letter of each word
		newString.append(subString + firstLetter + "ay "); //appends pig latin to new string
		wordBegin = (s.find(' ', wordEnd)) +1; //finds the next word
	}

	return newString;
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
