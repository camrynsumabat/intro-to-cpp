// Camryn Sumabat
// Class Programming Assignment for October 21, 2019
// Number 5 - Pointer Rewrite

#include <iostream>
using namespace std;

int doSomething(int* x, int* y);

int main()
{
	int num1 = 5, num2 = 3;
	int* a = nullptr; //initialized pointers
	int* b = nullptr;
	a = &num1; //assigned pointers
	b = &num2;
	cout << doSomething(a, b); // Prints ((x+y)*10)
}

int doSomething(int* x, int* y)
{
	int temp = *x;
	*x = *y * 10;
	*y = temp * 10;
	return *x + *y;
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
