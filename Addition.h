/*
 * Name: Terrance Yip, Susan Yuen, William Tran
 * MacID: yipsh, yuens2, tranwt
 * Student Number: 1415472, 1416198, 1407613
 * Description: Holds the function declarations for Addition. Performs operations for addition.
 */

#ifndef ADDITION_H						//include guard
#define ADDITION_H

#include <iostream>
#include <string>
#include <sstream>
#include "ArithmeticExpression.h"
using namespace std;

//Add two expressions
class Addition: public ArithmeticExpression {
	public:
		string evaluate();				//returns left + right
		void print();					//prints "(left + right)"

		Addition(string l, string r);	//constructor
		~Addition();					//destructor
};

#endif
