/* Joseph Yoon, Lab 5, CSE20212
	Part 2: Sudoku driver
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
	string sudokuFile, wordokuFile; //filenames to be inputted
	cout << "Please enter a file name(int): "; //ask for sudoku file
	cin >> sudokuFile; //input to sudokoFile
	Puzzle<int> sudoku(sudokuFile); //instantiate a Puzzle object of type int
	cout << "Please enter a file name(char): "; //ask for wordoku file
	cin >> wordokuFile; //input to wordokuFile
	Puzzle<char> wordoku(wordokuFile); //instantiate a Puzzle object of type char
	return 0;
}

