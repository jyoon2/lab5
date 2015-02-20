/*Joseph Yoon, Lab 5, CSE20212
	Part 2
	puzzle class header file
	templated to easily create Puzzle<int> or Puzzle<char>
*/

#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>
using namespace std;

//Puzzle class definition
template <typename T>
class Puzzle {
	public:
	Puzzle(); //default constructor
	Puzzle( const Puzzle<T> & ); //copy constructor
	~Puzzle(); //deconstructor

	private:
}; //end of class Puzzle

template<typename T>
Puzzle<T>::Puzzle(){
} //end of Puzzle default constructor

template<typename T>
Puzzle<T>::Puzzle( const Puzzle<T> &puzzleToCopy ) : size(puzzleToCopy.size) {
	
} //end copy constructor

template<typename T>
Puzzle<T>::~Puzzle() {
} //end deconstructor

#endif
