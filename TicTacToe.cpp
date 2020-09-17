//Camryn Sumabat
//Tic Tac Toe (REVISED with classes)

#include <iostream>
#include <iomanip>

using namespace std;

class Tictactoe {
	int ROW, COL;
	char board[3][3];
	char player;
public:
	Tictactoe();
	Tictactoe(const Tictactoe&);
	void Reset();
	void Draw();
	void Input();
	void SwitchPlayer();
	char Win();
	bool PlayAgain();
	~Tictactoe();
};

Tictactoe::Tictactoe() {
	ROW = 3;
	COL = 3;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			board[i][j] = ' ';
		}
	}
	player = 'X';
}

Tictactoe::Tictactoe(const Tictactoe& obj) {
	ROW = obj.ROW;
	COL = obj.COL;
	**board = **obj.board;
	player = obj.player;
}

void Tictactoe::Reset() {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			board[i][j] = ' ';
		}
	}
}

void Tictactoe::Draw() {
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			cout << *(*(board + i) + j);
			if (j != (COL - 1))
				cout << " | ";
		}
		cout << endl;
		if(i != (ROW-1))
			cout << "------------" << endl;
	}
}

void Tictactoe::Input() {
	bool openSpace;
	cout << "Player " << player << ", your turn.\n";

	int inputRow, inputColumn;
	do
	{
		//initializes boolean val
		openSpace = true;

		//choose row
		cout << "Row(1-3): ";
		cin >> inputRow;
		while (inputRow < 1 || inputRow > 3)
		{
			cout << "Invalid input. Choose Row(1-3):\n";
			cin >> inputRow;
		}

		//choose column
		cout << "Column(1-3): ";
		cin >> inputColumn;
		while (inputColumn < 1 || inputColumn > 3)
		{
			cout << "Invalid input. Choose Row(1-3):\n";
			cin >> inputColumn;
		}

		//checks if the space is taken already
		if (board[inputRow - 1][inputColumn - 1] != ' ')
		{
			cout << "That space is taken. Try again\n";
			openSpace = false;
		}

	} while (openSpace == false);

	//make mark on board
	board[inputRow - 1][inputColumn - 1] = player;
}
void Tictactoe::SwitchPlayer() {
	if (player == 'X')
	{
		player = 'O';
	}
	else
	{
		player = 'X';
	}
}
char Tictactoe::Win() {
	char winner;

	if (board[0][0] == board[0][1] && board[0][1] == board[0][2])  //first row across
	{
		winner = board[0][0];
	}
	else if (board[1][0] == board[1][1] && board[1][1] == board[1][2]) //second row across
	{
		winner = board[1][0];
	}
	else if (board[2][0] == board[2][1] && board[2][1] == board[2][2]) //third row across
	{
		winner = board[2][0];
	}
	else if (board[0][0] == board[1][0] && board[1][0] == board[2][0]) //first column down
	{
		winner = board[0][0];
	}
	else if (board[0][1] == board[1][1] && board[1][1] == board[2][1]) //second column down
	{
		winner = board[0][1];
	}
	else if (board[0][2] == board[1][2] && board[1][2] == board[2][2]) //third row across
	{
		winner = board[0][2];
	}
	else if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) //diagonal upper left to lower right
	{
		winner = board[0][0];
	}
	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) //diagonal lower left to upper right 
	{
		winner = board[0][2];
	}
	else
	{
		winner = 't'; //for tie
	}

	return winner;
}

bool Tictactoe::PlayAgain() {
	char input;
	bool again;
	cout << "Play Again? (Y/N)";
	cin >> input;
	while (input != 'Y' && input != 'y' && input != 'N' && input != 'n') {
		cout << "Please enter 'Y' or 'N'";
		cin >> input;
	}

	if (input == 'Y' || input == 'y')
		again = true;
	else
		again = false;

	return again;
}

Tictactoe::~Tictactoe() {
	for (int i = 0; i < ROW; i++) {
		delete[] board[i];
	}
	delete[] board;
}


int main()
{
	cout << "Welcome to Tic Tac Toe.\n";

	Tictactoe game;
	int i;

	for (i = 0; i < 9; i++)
	{
		game.Draw();
		game.Input();
		game.SwitchPlayer();
		char w = game.Win();
		if (w == 'X' || w == 'O') {
			cout << "Player " << w << " wins!" << endl;
			if (!game.PlayAgain()) {
				cout << "Thanks for playing!";
				return 1;
			}
			else {
				game.Reset();
				i = 0;
			}
		}
		else if (i == 9 && w != 'X' && w != 'O') {
			cout << "It's a tie!" << endl;
			if (!game.PlayAgain()) {
				cout << "Thanks for playing!";
				return 1;
			}
			else {
				game.Reset();
				i = 0;
			}
		}	
	}
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
