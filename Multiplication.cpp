/*
 * Name: Terrance Yip, Susan Yuen, William Tran
 * MacID: yipsh, yuens2, tranwt
 * Student Number: 1415472, 1416198, 1407613
 * Description: Holds the function definitions for Multiplication. Performs operations for multiplication.
 */

#include "Multiplication.h"

Multiplication::Multiplication(string l, string r) {	//constructor
	left = new ArithmeticExpression(l);					//sets left expression
	right = new ArithmeticExpression(r);				//sets right expression
}

string Multiplication::evaluate() {						//returns left*right
	std::ostringstream buff;
	buff<<convert(left->input)*convert(right->input);	//performs left*right
	return buff.str();
}

void Multiplication::print() {							//prints "(left*right)"
	cout << "(" + left->input + "*" + right->input + ")";
}

Multiplication::~Multiplication() {						//destructor
	delete left;										//deletes Expression left
	delete right;										//deletes Expression right
}
