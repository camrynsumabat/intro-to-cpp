//Camryn Sumabat
//Project 3: Number Converter
//Converts decimal numbers to either binary, octal, or hexadecimal numbers

#include <iostream>
using namespace std;

int showMenu(); //shows menu and returns user input
void chooseMenu(int, int);
void convert(int, int); //converts decimal user input to specified base
void decToHex(int); //converts decimal user input to hex
int bits(int, int); //finds bits necessary for the array storing converted decimal. used in convert method

int main()
{
	int menuChoice, userInput;

	cout << "What decimal number would you like to convert?\n";
	cin >> userInput; 

	menuChoice = showMenu();

	while (menuChoice < 0 || menuChoice > 5) //input validation
	{
		cout << "Please select a valid choice\n";
		menuChoice = showMenu();
	}

	chooseMenu(menuChoice, userInput);
	return 0;
}

int showMenu()
{
	int input;
	cout << "Select one to convert to:\n1. Binary\n2. Octal\n3. Hexadecimal\n\nOr select:\n4. Input a different decimal number\n5. Exit program\n";
	cin >> input;
	return input;
}

void chooseMenu(int choice, int userInput)
{
	if (choice == 1) //decimal to binary conversion
	{
		convert(userInput, 2);
	}
	if (choice == 2) //decimal to octal conversion
	{
		convert(userInput, 8);
	}
	if (choice == 3) //decimal to hexadecimal conversion
	{
		decToHex(userInput);
	}
	if (choice == 4) //returns input
	{
		int another;
		cout << "What would you like your new decimal number to be?\n";
		cin >> userInput;
		another = showMenu();
		chooseMenu(another, userInput);
	}
	if (choice == 5) //exits program
	{
		cout << "Exiting program...";
		exit(0);
	}
}

void convert(int userInput, int base) //for decimal to binary and decimal to octal
{
	int bit = bits(userInput, base), i;
	int* a = new int[bit];
	
	for (i = 0; userInput > 0; i++)
	{
		*(a + i) = userInput % base;
		userInput = userInput / base;
	}

	//prints the array back (pops)
	for (int j = i-1; j>=0; j--)
	{
		cout << *(a + j);
	}
	cout << endl;
}

void decToHex(int userInput) //for decimal to hexadecimal
{
	char *a = new char[100];
	int i = 0;

	while (userInput != 0)
	{
		int temp = 0;
		temp = userInput % 16;

		//ascii values
		if (temp < 10)
		{
			*(a + i) = temp + 48;
			i++;
		}
		else
		{
			*(a + i) = temp + 55;
			i++;
		}
		userInput = userInput / 16;
	}

	//prints the array back (pops)
	for (int j = i - 1; j >= 0; j--)
	{
		cout << *(a + j);
	}
	cout << endl;
}

int bits(int userInput, int base)
{
	int b = base;
	while (b <= userInput)
		b *= base;
	return b;
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
