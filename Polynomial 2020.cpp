// Polynomial 2020.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Polynomial.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

const int DEFAULT_SIZE = 100;

class Polynomial {
	int* coeff;
	int* exp;
	int terms;

	void split(string);
	int getExponentIndex(int&) const;

public:
	Polynomial();
	Polynomial(string);
	Polynomial(const Polynomial&);

	void showPolynomial();
	int getCoefficient(int&) const;
	void setCoefficient(int, int);

	Polynomial& operator+(const Polynomial&) const;
	Polynomial& operator-(const Polynomial&) const;
	Polynomial& operator*(const Polynomial&) const;
	Polynomial& operator=(const Polynomial&);

	~Polynomial();
};

Polynomial::Polynomial() {
	this->terms = 0;
	this->coeff = new int[DEFAULT_SIZE];
	this->exp = new int[DEFAULT_SIZE];

	for (int i = 0; i < DEFAULT_SIZE; i++) {
		this->coeff[i] = 0;
		this->exp[i] = 0;
	}
}

Polynomial::Polynomial(string myPoly) {
	this->terms = 0;
	this->coeff = new int[DEFAULT_SIZE];
	this->exp = new int[DEFAULT_SIZE];

	for (int i = 0; i < DEFAULT_SIZE; i++) {
		this->coeff[i] = 0;
		this->exp[i] = 0;
	}

	this->split(myPoly);
}

Polynomial::Polynomial(const Polynomial& that) {
	this->terms = that.terms;
	this->coeff = new int[this->terms];
	this->exp = new int[this->terms];
	for (int i = 0; i < this->terms; i++) {
		this->coeff[i] = *(that.coeff + i);
		this->exp[i] = *(that.exp + i);
	}
}

void Polynomial::showPolynomial() {
	for (int i = 0; i < this->terms; i++) {
		cout << this->coeff[i] << "x^" << this->exp[i];
		if (i != (terms - 1))
			cout << " + ";
	}
}

void Polynomial::split(string input) {
	string t;
	bool c = true;
	int i = 0;

	do {
		if (input[i] == '^')
			continue;

		if (c) {
			if (input[i] == 'x') {
				if (t == "+")
					this->coeff[this->terms] = 1;
				else if (t == "-")
					this->coeff[this->terms] = -1;
				else
					this->coeff[this->terms] = atoi(t.c_str());
				t = "";
				c = !c;
			}
			else {
				if (input[i] == ' ')
					continue;
				t += input[i];
			}
		}
		else {
			if (input[i] == ' ') {
				this->terms++;
				this->exp[this->terms] = atoi(t.c_str());
				t = "";
				c = !c;
			}
			else {
				t += input[i];
				if (i == (input.length() - 1)) {
					this->terms++;
					this->exp[this->terms] = atoi(t.c_str());
					t = "";
					c = !c;
				}
			}
		}
	} while (i++ < input.length());
}

int Polynomial::getCoefficient(int& exp) const {
	int e = getExponentIndex(exp);
	return *(coeff + e);
}

void Polynomial::setCoefficient(int e, int c) {
	int expIndex = getExponentIndex(e),
		newIndex;
	if (expIndex == -1) { //passed exponent is not found. creates new term
		this->terms++;
		newIndex = this->terms;
		coeff[newIndex] = c;
	}
	else { //combines like terms
		newIndex = expIndex;
		coeff[newIndex] += c;
	}
	exp[newIndex] = e;
}

int Polynomial::getExponentIndex(int& e) const {
	int index = -1,
		i = 0;
	while (i < terms) {
		if (exp[i] == e)
			return i;
		i++;
	}
	return index;
}

Polynomial& Polynomial::operator+(const Polynomial& that) const {
	auto newPoly = new Polynomial();
	for (int i = 0; i < that.terms; i++)
		newPoly->setCoefficient(that.exp[i], 0);
	for (int i = 0; i < this->terms; i++)
		newPoly->setCoefficient(this->exp[i], 0);

	for (int i = 0; i < newPoly->terms; i++) {
		int exponent = newPoly->exp[i],
			thisIndex = this->getExponentIndex(exponent),
			thatIndex = that.getExponentIndex(exponent),
			coefficient;

		if (thisIndex == -1 && thatIndex == -1)
			continue;
		else if (thisIndex == -1)
			coefficient = that.coeff[thatIndex];
		else if (thatIndex == -1)
			coefficient = this->coeff[thisIndex];
		else
			coefficient = this->coeff[thisIndex] + that.coeff[thatIndex];

		newPoly->setCoefficient(exponent, coefficient);
	}
	return *newPoly;
}

Polynomial& Polynomial::operator-(const Polynomial& that) const {
	auto newPoly = new Polynomial();

	for (int i = 0; i < this->terms; i++)
		newPoly->setCoefficient(this->exp[i], 0);
	for (int i = 0; i < that.terms; i++)
		newPoly->setCoefficient(that.exp[i], 0);

	for (int i = 0; i < newPoly->terms; i++) {
		int exponent = newPoly->exp[i],
			thisIndex = this->getExponentIndex(exponent),
			thatIndex = that.getExponentIndex(exponent),
			coefficient;

		if ((thisIndex == -1) && (thatIndex == -1))
			continue;
		else if (thisIndex == -1)
			coefficient = that.coeff[thatIndex];
		else if (thatIndex == -1)
			coefficient = this->coeff[thisIndex];
		else
			coefficient = (this->coeff[thisIndex] - that.coeff[thatIndex]);

		newPoly->setCoefficient(exponent, coefficient);
	}
	return *newPoly;
}

Polynomial& Polynomial::operator*(const Polynomial& that) const {
	auto newPoly = new Polynomial();

	if (this->terms < that.terms) {
		for (int i = 0; i < that.terms; i++) {
			for (int j = 0; j < this->terms; j++) {
				int e1 = that.exp[i],
					e2 = this->exp[j];

				if ((e1 == 0) || (e2 == 0))
					continue;

				int i1 = this->getExponentIndex(e1),
					i2 = that.getExponentIndex(e2),
					coefficient,
					exponent;

				if ((i1 == -1) && (i2 == -1))
					continue;
				else if (i1 == -1) {
					coefficient = that.coeff[i2];
					exponent = e2;
				}
				else if (i2 == -1) {
					coefficient = this->coeff[i1];
					exponent = e1;
				}
				else {
					coefficient = (this->coeff[i1] * that.coeff[i2]);
					exponent = (e1 + e2);
				}

				newPoly->setCoefficient(exponent, coefficient);
			}
		}
	}
	else {
		for (int i = 0; i < this->terms; i++) {
			for (int j = 0; j < that.terms; j++) {
				int e1 = this->exp[i],
					e2 = that.exp[j],
					c1 = that.coeff[i],
					c2 = this->coeff[j];

				if ((c1 == 0) || (c2 == 0))
					continue;

				newPoly->setCoefficient(e1 + e2, c1 * c2);
			}
		}
	}
	return *newPoly;
}

Polynomial& Polynomial::operator=(const Polynomial& that) {
	if (this->terms < that.terms) { //if this polynomial has less terms than passed polynomial
		delete[] this->coeff;
		delete[] this->exp;

		coeff = exp = nullptr;

		this->terms = that.terms;
		this->coeff = new int[this->terms];
		this->exp = new int[this->terms];

		for (int i = 0; i < this->terms; i++) {
			this->coeff[i] = that.coeff[i];
			this->exp[i] = that.exp[i];
		}
	}
	else {
		for (int i = 0; i < this->terms; i++) {
			this->coeff[i] = 0;
			this->exp[i] = 0;
		}
		for (int i = 0; i < that.terms; i++) {
			this->coeff[i] = that.coeff[i];
			this->exp[i] = that.exp[i];
		}
	}
	return *this; //return this polynomial
}

Polynomial::~Polynomial() {
	delete[] coeff;
	delete[] exp;
	coeff = exp = nullptr;
}



char input1[DEFAULT_SIZE], input2[DEFAULT_SIZE];
Polynomial* p1, * p2;
Polynomial newPoly;

void showMenu();
void add();
void sub();
void mult();
void assign();

int main() {
	cout << "Enter two polynomials in the format \"#x^# + #x^# + ... + #x^#\"" << endl;
	cout << "Polynomial 1: ";
	cin.getline(input1, sizeof(input1));
	cout << "Polynomial 2: ";
	cin.getline(input1, sizeof(input2));

	p1 = new Polynomial(input1);
	p2 = new Polynomial(input2);

	showMenu();
	return 0;
}

void showMenu() {
	int choice;
	cout << "\nChoose an operation... " << endl;
	cout << "(1) addition\n"
		<< "(2) subtraction\n"
		<< "(3) multiplication\n"
		<< "(4) change polynomials\n"
		<< "(5) exit\n";
	cin >> choice;
	cout << endl;

	switch (choice) {
	case 1:
		add();
		showMenu();
		break;
	case 2:
		sub();
		showMenu();
		break;
	case 3:
		mult();
		showMenu();
		break;
	case 4:
		assign();
		showMenu();
		break;
	case 5: // exit
		cout << "Bye...";
		return;
	default:
		cout << "Please enter a valid option (1-5) ..." << endl;
		showMenu();
	}
}

void add() {
	p1->showPolynomial();
	cout << " + ";
	p2->showPolynomial();
	cout << " = ";
	newPoly.showPolynomial();
	newPoly = *p1 + *p2;
	newPoly.showPolynomial();
}

void sub() {
	p1->showPolynomial();
	cout << " - ";
	p2->showPolynomial();
	cout << " = ";
	newPoly.showPolynomial();
	newPoly = *p1 - *p2;
	newPoly.showPolynomial();
}

void mult() {
	p1->showPolynomial();
	cout << " * ";
	p2->showPolynomial();
	cout << " = ";
	newPoly.showPolynomial();
	newPoly = *p1 * *p2;
	newPoly.showPolynomial();
}

void assign() {
	int poly;
	char replacement[DEFAULT_SIZE];
	cout << "Which polynomial would you like to change? (1 or 2): ";
	cin >> poly;
	while (poly != 1 && poly != 2) {
		cout << "Please enter 1 or 2: ";
		cin >> poly;
	}
	cout << "Enter your new polynomial: ";
	cin.getline(replacement, sizeof(replacement));
	if (poly == 1) {
		p1 = new Polynomial(replacement);
		cout << "Polynomial 1 is now: ";
		p1->showPolynomial();
	}
	else {
		p2 = new Polynomial(replacement);
		cout << "Polynomial 2 is now: ";
		p2->showPolynomial();
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
