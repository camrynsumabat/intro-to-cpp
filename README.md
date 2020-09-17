# intro-to-cpp

<h1>Welcome to my Intro to C++ Repo!</h1>
Here is a compilation of the projects I completed in my University's Intro to C++ course. I only knew minimal java when I wrote these programs last year, and have included some improvements I could have made in the descriptions below. This is also the first repo I've created and I'm not sure if this is how to use Github?? But at least my code is saved here for now until I figure out how to utilize this. 

</br>_Files you can find in this repo are:_

<h3>Matrix Multiplication</h3>

*Accepts*

2 matrices, either from console or from file</br>
If the program reads the matrices from console, it will ask for the number of rows and columns for each matrix, and for each element in the matrix.

*Performs*

matrix operations on two matrices</br> 
This program can perform addition, subtraction, multiplication, or transposition on given matrices. In the event that the matrices are not compatible (ie number of rows and columns are not the same) the program will print an error message and terminate. 

*Improvements*

Some improvements that can be made to this program are input validation at the beginning of console input, and having the program loop back to creating a new matrix in the event operations can't be performed on the given matrices.

<h3>Mode Function Revised</h3>

*Accepts*

An array and array size hard-coded into the program

*Performs*

This program is a standalone function returning the mode of a pre-defined array.

*Improvements*

For what it's meant to do, this program is fine however, since the array and array size is hard-coded, I would have to change both of these elements for the program to properly run. To further improve this program, I could allow user input, and have the program read the size from the given array (rather than having the size hard-coded).

<h3>Number Converter</h3>

*Accepts*

A decimal number from console

*Performs*

Conversion to binary, octal, or hexadecimal. If a user selects an option outside of the menu, an error message prints and the user is allowed to select a valid choice.

*Improvements*

As I learned more about code and object-oriented programming, having all the methods in one file with the driver is not the best practice (And this goes for all the projects in this repo). 

<h3>Pig Latin</h3>

*Accepts*

String input from console

*Performs*

Conversion of the inputted sentence to pig latin. The program also outputs the number of words for debugging purposes.

*Improvements*

This program looks pretty good to me! Similar improvement as the number converter, methods should not all be in one file.

<h3>Pointer Rewrite</h3>

*Description*

This program was a really quick in class method to demonstrate how to use pointers in C++. Pointers are initialized as nullptr's, then the addresses of the hard-coded integer variables are assigned to the pointers. The method "doSomething" uses the pointers to add the two variables then multiply them by 10. 

<h3>Proj 1 Diamond</h3>

*Accepts*

An odd integer between 1 and 15 (inclusive)

*Performs*

Printing a diamond with the number of rows accepted from user input. If the user inputs an invalid integer (even or outside the range), then the program asks for input again.

*Improvements*

This program can have better input validation instead of regurgitating the same message when there's an invalid input. There's also probably a more efficient way to code this, since right now the time complexity is O(N^2).

<h3>Project 2 PerfectNumbers</h3>

*Accepts*

An integer n between 1 and 100,000 (inclusive)

*Performs* 

Parses through the integers from 1 to n (inclusive) and writes the perfect numbers to a file. This program was written to better understand file input/output in C++.

*Improvements*

I'm sure there's a better way to implement this algorithm, since right now it's running an O(N^2) time complexity. Commenting on this program is also good, but similar to all the other projects, a description like this at the top of the code would be handy.

<h3>Reverse Array Revised</h3>

*Accepts*

Hard-coded integer array and array size

*Performs*

As the name implies, it reverses this hard-coded array and prints the result

*Improvements*

This program could be changed to user input, and have the size not be hard-coded. 

<h3>Tic Tac Toe</h3>

*Accepts*

X's and O's as characters from 2 users (on one device, switching between X and O user) to play tic tac toe

*Performs*

Tic tac toe! This program has methods to draw the board, take input from the user, switch players on their respective turns, determine the winner, and ask to play again.

*Improvements*

DEFINITELY write these methods in different files. It was hard to go through this one and figure out everything happening. Otherwise, again, there's probably a different and better way to implement this without all the if-else statements. The rest of the code is pretty well done I must say.
