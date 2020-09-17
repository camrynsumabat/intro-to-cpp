// Camryn Sumabat
// Class Programming Assignemnt for Monday October 21
// Mode Function revised

#include <iostream>
using namespace std;

void findMode(int*, int);

const int SIZE = 5;

int main()
{
	int array[SIZE] = { 1,2,2,4,5 };
	findMode(array, SIZE);
}

void findMode(int* a, int num)
{
	int mode = -1, count;
	for (int i = 0; i < num; i++)
	{
		count = 0;
		for (int j = 1; j < num; j++)
		{
			if (a[i] == a[j])
			{
				mode = a[i];
				count++;
			}
		}
	}
	cout << mode;
	// for loop for each element in the array to be checked
	// for loop to check each element in the array with the first for loop num
	// if statement to change int mode if the count is greater than the last
	//return mode
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
