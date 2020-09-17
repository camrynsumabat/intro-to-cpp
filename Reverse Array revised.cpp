// Camryn Sumabat
// Class Programming Assignment for Monday October 21
// Reverse Array (fixed)

#include <iostream>
using namespace std;

void reverse(int* a, int size); 
const int SIZE = 5; //QUESTION: is there a better way to code this? see line 19

int main()
{
	int arr[SIZE] = { 1, 2, 3, 4, 5 }; //array declaration
	reverse(arr, SIZE); //function call
}

void reverse(int* a, int size) //function definition
{
	int n[SIZE]; // without having to grab the global constant? How do I use size instead of SIZE?
	int temp, count = 0;
	for (int i = size; i > 0; i--)
	{
		temp = *(a+i-1); //prints elements in the array backwards
		n[count] = temp;
		count++;
	}
	for (int j = 0; j < size; j++)
	{
		cout << n[j];
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
