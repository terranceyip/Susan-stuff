/*
 * Name: Terrance Yip, Susan Yuen, William Tran
 * MacID: yipsh, yuens2, tranwt
 * Student Number: 1415472, 1416198, 1407613
 * Description: [This is an informative excerpt about this file.]
 */

//Header => Function Declarations
//This whole file contains the function declarations for ArithmeticExpression

#ifndef ARITHMETICEXPRESSION_H	//if not defined...
#define ARITHMETICEXPRESSION_H

#include <algorithm>
#include <string>
#include <iostream>
#include <cctype>
#include "Expression.h"
using namespace std;

class ArithmeticExpression : public Expression {
	public:
		Expression *left;	//declaration of pointer variable 'left'
		Expression *right;	//declaration of pointer variable 'right'

		string evaluate(); //evaluate left expression and right expression
		void print(); //prints expression
		float convert (string s); //converts a string (as would be returned by evaluate) to a float
};

#endif
