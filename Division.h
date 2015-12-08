/*
 * Name: Terrance Yip, Susan Yuen, William Tran
 * MacID: yipsh, yuens2, tranwt
 * Student Number: 1415472, 1416198, 1407613
 * Description: [This is an informative excerpt about this file.]
 */

#ifndef DIVISION_H	//if not defined...
#define DIVISION_H

#include <iostream>
#include <string>
#include "ArithmeticExpression.h"
using namespace std;

//Divide two expressions
class Division: public ArithmeticExpression {
	string evaluate();
	void print();
};

#endif
