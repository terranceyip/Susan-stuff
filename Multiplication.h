/*
 * Name: Terrance Yip, Susan Yuen, William Tran
 * MacID: yipsh, yuens2, tranwt
 * Student Number: 1415472, 1416198, 1407613
 * Description: Holds the function declarations for Multiplication. Performs operations for multiplication.
 */

#ifndef MULTIPLICATION_H		//include guard
#define MULTIPLICATION_H

#include <iostream>
#include <string>
#include <sstream>
#include "ArithmeticExpression.h"
using namespace std;

//Multiply two expressions
class Multiplication: public ArithmeticExpression {
	public:
		string evaluate();						//returns left*right
		void print();							//prints "(left*right)"

		Multiplication(string l, string r);		//constructor
		~Multiplication();						//destructor
};
#endif
