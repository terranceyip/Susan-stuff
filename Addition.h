/*
 * Name: Terrance Yip, Susan Yuen, William Tran
 * MacID: yipsh, yuens2, tranwt
 * Student Number: 1415472, 1416198, 1407613
 * Description: [This is an informative excerpt about this file.]
 */

#ifndef ADDITION_H
#define ADDITION_H

#include <iostream>
#include <string>
#include "ArithmeticExpression.h"
using namespace std;

//Add two expressions
class Addition: public ArithmeticExpression {
	string evaluate();
	void print();
};

#endif
