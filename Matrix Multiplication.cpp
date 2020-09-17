//Camryn Sumabat
//Matrix Multiplication
/*Requests two matrices from the user, either through file or console. 
  Displays menu with options to add, subtract, multiply, or transpose the matrices.
*/


//libraries
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//function prototypes
void functionMenu(); 
void consoleOrFile();
void matrixFile();
void matrixConsole();
void printMatrix(int**, int, int);
void addMatrix();
void subMatrix();
void multMatrix();
void transMatrix();

//variable initialization
int** matrix1 = nullptr, **matrix2 = nullptr, **matrix3 = nullptr;
int row1, col1, row2, col2;

int main()
{
	consoleOrFile();
	functionMenu();
	return 0;
}

//FUNCTION DEFINITIONS
void functionMenu() 
{
	int choice;

	cout << "Choose a function to perform on your matrices:\n";
	cout << "1. addition\n2. subtraction\n3. multiplication\n4. transpose\n5. exit\n";
	cin >> choice;
	while (choice < 1 || choice >5)
	{
		cout << "Please choose a valid option: \n";
		functionMenu();
	}

	switch (choice)
	{
		case 1:
			cout << "Adding your matrices...\n";
			addMatrix();
			functionMenu();
			break;
		case 2:
			cout << "Subtracting your matrices...\n";
			subMatrix();
			functionMenu();
			break;
		case 3:
			cout << "Multiplying your matrices...\n";
			multMatrix();
			functionMenu();
			break;
		case 4:
			cout << "Transposing your matrices...\n";
			transMatrix();
			functionMenu();
			break;
		case 5:
			cout << "Thanks! Bye...";
			return;
	}
}

void consoleOrFile()
{
	char input;

	cout << "Would you like to input your matrices through console or file?\n'c' for console or 'f' for file\n";
	cin >> input;

	while (toupper(input) != 'C' && toupper(input) != 'F')
	{
		cout << "Please choose a valid option.\n'c' for console or 'f' for file\n";
		cin >> input;
	}

	if (toupper(input) == 'C')
		matrixConsole();
	else
		matrixFile();
}

void matrixFile()
{
	string filename;

	cout << "Enter file name: ";
	cin >> filename;

	ifstream infile(filename);

	while (!infile)
	{
		cout << "File open failure\nPlease enter a valid file name";
		cin >> filename;
		infile.open(filename);
	}

	infile >> row1;
	infile >> col1;

	matrix1 = new int* [row1];
	for (int i = 0; i < row1; i++)
		* (matrix1 + i) = new int[col1];

	for (int i = 0; i < row1; i++)
		for (int j = 0; j < col1; j++)
			infile >> *(*(matrix1 + i) + j);

	infile >> row2;
	infile >> col2;

	matrix2 = new int* [row2];
	for (int i = 0; i < row2; i++)
		* (matrix2 + i) = new int[col2];

	for (int i = 0; i < row2; i++)
		for (int j = 0; j < col2; j++)
			infile >> *(*(matrix2 + i) + j);

	infile.close();

	cout << "First Matrix:\n";
	printMatrix(matrix1, row1, col1);

	cout << "Second Matrix:\n";
	printMatrix(matrix2, row2, col2);
}

void matrixConsole() 
{
	cout << "For your first matrix... \nRows: ";
	cin >> row1;
	cout << "Columns: ";
	cin >> col1;

	matrix1 = new int* [row1];
	for (int i = 0; i < row1; i++)
	{
		*(matrix1 + i) = new int[col1];
	}

	for (int i = 0; i < row1; i++)
	{
		for (int j = 0; j < col1; j++)
		{
			cout << "Row " << i + 1 << ", Column " << j + 1 << ": ";
			cin >> *(*(matrix1 + i) + j);
		}
	}
	
	cout << "For your second matrix... \nRows: ";
	cin >> row2;
	cout << "Columns: ";
	cin >> col2;

	matrix2 = new int* [row2];
	for (int i = 0; i < row2; i++)
	{
		*(matrix2 + i) = new int[col2];
	}

	for (int i = 0; i < row2; i++)
	{
		for (int j = 0; j < col2; j++)
		{
			cout << "Row " << i + 1 << ", Column " << j + 1 << ": ";
			cin >> *(*(matrix2 + i) + j);
		}
	}

	cout << "\nMatrix 1:\n";
	printMatrix(matrix1, row1, col1);

	cout << "Matrix 2:\n";
	printMatrix(matrix2, row2, col2);
}

void printMatrix(int** m, int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << *(*(m + i) + j) << "\t";
		}
		cout << endl;
	}
}

void addMatrix()
{
	if (row1 != row2 || col1 != col2)
	{
		cout << "To add two matrices, the rows and columns must be the same. Exiting program...\n";
		exit(1);
	}

	matrix3 = new int* [row1];
	for (int i = 0; i < row1; i++)
	{
		*(matrix3 + i) = new int[col1];
	}

	for (int i = 0; i < row1; i++)
	{
		for (int j = 0; j < col1; j++)
		{
			*(*(matrix3 + i) + j) = *(*(matrix1 + i) + j) + *(*(matrix2 + i) + j);
		}
	}
	
	cout << "Matrix 1 + Matrix 2:\n";
	printMatrix(matrix3, row1, col1);
}

void subMatrix()
{
	if (row1 != row2 || col1 != col2)
	{
		cout << "To subtract two matrices, the rows and columns must be the same. Exiting program...\n";
		exit(1);
	}

	matrix3 = new int* [row1];
	for (int i = 0; i < row1; i++)
	{
		*(matrix3 + i) = new int[col1];
	}

	for (int i = 0; i < row1; i++)
	{
		for (int j = 0; j < col1; j++)
		{
			*(*(matrix3 + i) + j) = *(*(matrix2 + i) + j) - *(*(matrix1 + i) + j);
		}
	}

	cout << "Matrix 2 - Matrix 1: \n";
	printMatrix(matrix3, row1, col1);
}

void multMatrix()
{
	if (row1 != row2 || col1 != col2)
	{
		cout << "To multiply two matrices, the rows and columns must be the same. Exiting program...\n";
		exit(1);
	}

	matrix3 = new int* [row1];
	for (int i = 0; i < row1; i++)
	{
		*(matrix3 + i) = new int[col1];
	}

	int sum;
	for (int i = 0; i < row1; i++)
	{
		for (int j = 0; j < col1; j++)
		{
			sum = 0;
			for (int k = 0; k < col1; k++)
			{
				sum += (*(*(matrix1 + i) + k)) * (*(*(matrix2 + k) + j));
			}
			*(*(matrix3 + i) + j) = sum;
		}
	}

	cout << "Matrix 1 x Matrix 2: \n";
	printMatrix(matrix3, row1, col1);
}

void transMatrix()
{
	int** new1 = nullptr, ** new2 = nullptr;

	new1 = new int* [col1]; 
	for (int i = 0; i < col1; i++)
	{
		*(new1 + i) = new int[row1];
	}

	for (int i = 0; i < row1; i++)
	{
		for (int j = 0; j < col1; j++)
		{
			*(*(new1 + j) + i) = *(*(matrix1 + i) + j);
		}
	}

	new2 = new int* [col2];
	for (int i = 0; i < col2; i++)
	{
		*(new2 + i) = new int[row2];
	}

	for (int i = 0; i < row2; i++)
	{
		for (int j = 0; j < col2; j++)
		{
			*(*(new2 + j) + i) = *(*(matrix2 + i) + j);
		}
	}

	cout << "Matrix 2 transposed:\n";
	printMatrix(new1, col1, row1);

	cout << "Matrix 1 transposed:\n";
	printMatrix(new2, col2, row2);
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
