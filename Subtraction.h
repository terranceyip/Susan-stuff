/*
 * Name: Terrance Yip, Susan Yuen, William Tran
 * MacID: yipsh, yuens2, tranwt
 * Student Number: 1415472, 1416198, 1407613
 * Description: Holds the function declarations for Subtraction. Performs operations for subtraction.
 */

#ifndef SUBTRACTION_H			//include guards
#define SUBTRACTION_H

#include <iostream>
#include <string>
#include <sstream>
#include "ArithmeticExpression.h"
using namespace std;

//Subtract two expressions
class Subtraction: public ArithmeticExpression {
	public:
		string evaluate();					//returns left-right
		void print();						//performs left-right

		Subtraction(string l, string r);	//constructor
		~Subtraction();						//destructor
};
#endif
