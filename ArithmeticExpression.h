/*
 * Name: Terrance Yip, Susan Yuen, William Tran
 * MacID: yipsh, yuens2, tranwt
 * Student Number: 1415472, 1416198, 1407613
 * Description: Contains the function declarations for ArithmeticExpression, which will perform functions on the expression.
 */

//Header => Function Declarations
//This whole file contains the function declarations for ArithmeticExpression

#ifndef ARITHMETICEXPRESSION_H
#define ARITHMETICEXPRESSION_H

#include <algorithm>
#include <string>
#include <iostream>
#include <cctype>
#include "Expression.h"
using namespace std;

class ArithmeticExpression : public Expression {
	public:
		Expression *left;					//holds the left expression
		Expression *right;					//holds the right expression
		int splitIndex;						//holds the index of the operator being looked at

		ArithmeticExpression();				//constructor (with no parameters)
		ArithmeticExpression(string in); 	//constructor (with 1 parameter)
		virtual ~ArithmeticExpression();	//virtual destructor
		string evaluate(); 					//evaluates left expression and right expression
		void print(); 						//prints expression
		float convert (string s); 			//converts a string to a float
		string removeBrackets(string in);	//removes excess brackets from the expression
		string removeWhiteSpace(string in);	//removes all white space from the expression
		string getLeft();					//returns the left expression as a string
		string getRight();					//returns the right expression as a string
};

#endif
