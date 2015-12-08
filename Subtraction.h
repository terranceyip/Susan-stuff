/*
 * Name: Terrance Yip, Susan Yuen, William Tran
 * MacID: yipsh, yuens2, tranwt
 * Student Number: 1415472, 1416198, 1407613
 * Description: [This is an informative excerpt about this file.]
 */

#ifndef SUBTRACTION_H
#define SUBTRACTION_H

#include <iostream>
#include <string>
#include "ArithmeticExpression.h"
using namespace std;

//Subtract two expressions
class Subtraction: public ArithmeticExpression {
	string evaluate();
	void print();
};
#endif
