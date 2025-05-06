//Abygale Cochrane, assignment 5 , April 3rd
//this code is designed for a 5x5 TicTacToe game
//in which either X or O could win by having
//5 of their characters consecutive in a 
//row, column or diagonal



#include <iostream>
#include <string>
using namespace std;

char run; //used to ask if user wants to reloop the game or stop
char board[5][5]; //the 5 by 5 Tic Tac Toe board
string playerMove; //the users input containing the row and column that they want to place X/O
int i; //row on board
int j; //column on board
char player; //is it X's or O's turn
int NumbOfMoves; // checks if board is all full


//function that prints out the whole board including any changed X/O characters
void printBoard()

{
	cout << "-------------------------------------\n"
		<< "|   | 0 | 1 | 2 | 3 | 4 | \n"
		<< "--------------------------------------\n";
	for (int i = 0; i < 5; i++) {//goes through every row and column in for loop
		cout << "| " << i << " | ";
		for (int j = 0; j < 5; j++) {
			cout << board[i][j] << " | ";
		}
		cout << "\n";
	}
}

//takes user input of row and column to place respective X/O
//used player variable so it can apply to either user depending on input
void turn(char board[5][5], char player) {
	while (true) {
		cout << player << "'s turn. Please enter your move (row,col) *be sure to put comma between*:";
		cin >> playerMove;
		i = stoi(playerMove.substr(0, 1));
		j = stoi(playerMove.substr(2, 1));

		//if theres already a character in that spot, it will ask for a new value
		if (board[i][j] != ' ') {
			cout << "This spot is taken! Please try again.\n";
		}

		//if its out of bounds, it will ask for a new value
		else if (i < 0 || i > 4
			|| j < 0 || j > 4)
			{
				cout << "Out of bounds. Please try again.\n";
			}
		//there's nothing wrong with the input, proceed
		else {
			break; 
		}
	}

	board[i][j] = player;//places character in respective row and column position
	printBoard(); 
}



//function that checks all of the rows, columns, and diagonals for a straight character set
//AKA a winner
bool checkWinner(char board[5][5], char player)
{
	
	for (int i = 0; i < 5; i++) {
		//checks each row
		if (board[i][0] == player && board[i][1] == player
			&& board[i][2] == player && board[i][3] == player && board[i][4] == player)
			return true;
		//checks each column
		if (board[0][i] == player && board[1][i] == player
			&& board[2][i] == player && board[3][i] == player && board[4][i] == player)
			return true;
	}

	//checks left to right diagonal
	if (board[0][0] == player && board[1][1] == player
		&& board[2][2] == player && board[3][3] == player && board[4][4] == player)
		return true;
	//checks right to left diagonal
	if (board[0][4] == player && board[1][3] == player
		&& board[2][2] == player && board[3][1] == player && board[4][0] == player)
		return true;
	return false;//if none of the statements are true then there is no winner yet
}




int main(){
	run = 'y';//starts on y for run so that while loop is on
	while (run == 'y')
	{
		NumbOfMoves = 0;//each time game is reset, # of moves goes back to zero

		//initialize board with blanks
		cout << "Welcome to TicTacToe: 5x5 Grid \n"; 
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				board[i][j] = ' ';
			}
		}
		//shows blank board
		printBoard(); 

		//the while loop will play out X and O turns back and forth until
		//checkWinner function comes back true and loop breaks
		while (true) {

			//start of X's turn
			player = 'X';//reassigns player value
			turn(board, player); //gets user input for character assignment
			if (checkWinner(board, player)) {//checks if it was the winning move
				cout << "X IS THE WINNER!\n";
				break; 
			}
			//if there isn't a winner by the time the boards full
			//call it a draw and reset
			NumbOfMoves = NumbOfMoves++;
			if (NumbOfMoves == 25)
			{
				cout << "It's a draw!\n";
				break;
			}

			//start of O's turn
			player = 'O';//reassigns player value
			turn(board,player);//gets user input for character assignment
			if (checkWinner(board, player)) { //checks if it was the winning move
				cout << "O IS THE WINNER!\n";
				break;
			}

			//if there isn't a winner by the time the boards full
			//call it a draw and reset
			NumbOfMoves = NumbOfMoves++;
			if (NumbOfMoves == 25) 
			{
				cout << "It's a draw!"; 
				break; 
			}
		}

		cout << "play again? (y/n):"; 
		cin >> run; 
	}


}