/*
 * Name: Terrance Yip, Susan Yuen, William Tran
 * MacID: yipsh, yuens2, tranwt
 * Student Number: 1415472, 1416198, 1407613
 * Description: Holds the function declarations for Division. Performs operations for division.
 */

#ifndef DIVISION_H	//include guard
#define DIVISION_H

#include <iostream>
#include <string>
#include <sstream>
#include "ArithmeticExpression.h"
using namespace std;

//Divide two expressions
class Division: public ArithmeticExpression {
	public:
		string evaluate();				//returns left/right
		void print();					//prints "(left/right)"

		Division(string l, string r);	//constructor
		~Division();					//destructor
};

#endif
