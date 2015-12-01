/*
 * Name: Terrance Yip, Susan Yuen, William Tran
 * MacID: yipsh, yuens2, tranwt
 * Student Number: 1415472, 1416198, 1407613
 * Description: [This is an informative excerpt about this file.]
 */

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>
#include <string>
using namespace std;

class Expression {
	//Function Declarations
	virtual string evaluate(); //evaluate expression and return string representation of the result
	virtual void print(); // prints expression

	//Destructors
	virtual string ~evaluate();
	virtual void ~print();
};

#endif
