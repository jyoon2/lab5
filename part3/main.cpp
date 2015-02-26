/* Joseph Yoon, Lab 5, CSE20212
	Part 3: Sudoku driver
	reads in provided sudoku/wordoku using a puzzle constructor
	stores it in a vector of vectors (2D array) - private data member of the Puzzle class
	displays unfinished puzzles to the screen
*/

#include <iostream>
#include <vector>
#include <string>
#include "puzzle.h"

using namespace std;

int main(){
	string filename; //filenames to be inputted
	cout << "Please enter a file name: "; //ask for sudoku file
	cin >> filename; //input to filename
	Puzzle<int> sudoku(filename); //instantiate a Puzzle object of type int
	
	do{
		sudoku.print(); //print out the board
		int a, b, c; 
		cout << "Row: "; // ask for row column and number from user
		cin >> a;
		cout << "Column: ";
		cin >> b;
		cout << "Number: ";
		cin >> c;
		sudoku.play(a, b, c); //use play function to check if numbers are valid and can be put into the board
	}while(!sudoku.winner()); // continue while the board is not completed	
	if(sudoku.winner()) //if the board is full at the end then print out winning output, doesn't have to be in if statement
		cout << "Congratulations! You have won!" << endl;
	return 0;
}

