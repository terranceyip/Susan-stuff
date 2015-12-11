/*
 * Name: Terrance Yip, Susan Yuen, William Tran
 * MacID: yipsh, yuens2, tranwt
 * Student Number: 1415472, 1416198, 1407613
 * Description: Holds the virtual function declarations for Expression.
 */

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>
#include <string>
using namespace std;

class Expression {
	public:
		string input;

		virtual string evaluate(); 	//evaluate expression and return string representation of the result
		virtual void print(); 		//prints expression

		virtual ~Expression();		//virtual destructor
};

#endif
