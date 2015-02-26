/*Joseph Yoon, Lab 5, CSE20212
	Part 2
	puzzle class header file
	templated to easily create Puzzle<int> or Puzzle<char>
*/

#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

//Puzzle class definition
template <typename T>
class Puzzle {
	public:
	Puzzle(); //default constructor
	Puzzle(string); //non-default constructor
	void print(); //prints out the board
	int winner(); //checks to see if board is complete
	void play(int, int, int); //ask if user wants to play, if yes, input row col num
	int checkRow(int, int); //check to see if works in row
	int checkColumn(int, int); //check to see if works in column
	int checkGrid(int, int, int); //check to see if works in grid
	private:
		vector<vector <T> > board; //private data member 2D vector 
}; //end of class Puzzle

//beginning of implementation
template <typename T>
int Puzzle<T>::winner(){
	for(int x = 0; x < board.size()-1; x++)
		for(int y = 0; y < board.size()-1; y++)
			if(board[x][y] == 0)
				return 0;
	return 1;
}

template <typename T>
void Puzzle<T>::play(int r, int c, int n){
	int check = 0;
	if(!(r > 9 || r < 1 || c > 9 || c < 1 || n > 9 || n < 1)){
		if(checkRow(r, n)){
			check++;
			cout << "Duplicate number in row." << endl;
		}
		if(checkColumn(c, n)){
			check++;
			cout << "Duplicate number in column." << endl;
		}
		if(checkGrid(r, c, n)){
			check++;
			cout << "Duplicate number in grid." << endl;
		}
		if(board[r-1][c-1] != 0){
			check++;
			cout << "This space is not empty." << endl;
		}
		if(check == 0)
			board[r-1][c-1] = n;
	}
	else
		cout << "Please enter valid numbers." << endl << "Numbers must be between 1-9 (inclusive)." << endl;

}

template <typename T>
int Puzzle<T>::checkRow(int row, int num){
	for(int c = 0; c < board.size()-1; c++)
		if(board[row-1][c] == num)
			return 1;	
	return 0;
}

template <typename T>
int Puzzle<T>::checkColumn(int col, int num){
	for(int r = 0; r < board.size()-1; r++)
		if(board[r][col-1] == num)
			return 1;
	return 0;
}

template <typename T>
int Puzzle<T>::checkGrid(int row, int col, int num){
	int rowStart = (row-1) - (row-1)%3;
	int colStart = (col-1) - (col-1)%3;
	for(int r = rowStart; r < (rowStart+3); r++){
		for(int c = colStart; c < (colStart+3); c++){
			if(board[r][c] == num)
				return 1;
		}
	}
	return 0;
} 


template <typename T>
Puzzle<T>::Puzzle(string fileN){
	T value; //value could be int or char
	ifstream infile; 
	infile.open(fileN.c_str()); //change to a c string for opening
	vector<T> tempVec; //temporary vector to push back on 2D vector
	while(!infile.eof()){ //While the file is not at the end  
        	for(int i = 0 ; i < 9 ; i++){    //Read in a line into a temporary vector
                	infile >> value; //Put just read value into temporary vector
			tempVec.push_back(value); 
          	}
        	board.push_back(tempVec);   //Push back the line just read)
          	tempVec.clear(); //Clear/recycle temporary vector
	}
} //end of Puzzle default constructor

template <typename T>
void Puzzle<T>::print(){ //prints out the 2D vector board
	for(int d = 0; d < 2; d++){ //print column numbers to make it easier to see
		if(d == 0)
			cout << "    ";
		if(d == 1)
			cout << "   ";
		for(int e = 0; e < board.size()-1; e++){
			if(d == 0)
				cout << e+1 << " ";
			if(d == 1)
				cout << "--";
		}
		cout << endl;
	}		 
	for(int x = 0; x < board.size()-1; x++){ //uses vectors size() member function
		cout << x+1 << " | "; // prints row numbers
		for(int y = 0; y < board.size()-1; y++){
			cout << board[x][y] << " "; //make sure to put a space between
		}
		cout << endl; //separate each row
	} 
}

#endif
