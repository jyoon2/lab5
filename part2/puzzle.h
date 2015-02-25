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
	private:
		vector<vector <T> > board; //private data member 2D vector 
}; //end of class Puzzle

//beginning of implementation
template<typename T>
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
	print();
} //end of Puzzle default constructor

template<typename T>
void Puzzle<T>::print(){ //prints out the 2D vector board
	for(int x = 0; x < board.size()-1; x++){ //uses vectors size() member function
		for(int y = 0; y < board.size()-1; y++){
			cout << board[x][y] << " "; //make sure to put a space between
		}
		cout << endl; //separate each row
	} 
}

#endif
