/*
 * Name: Terrance Yip, Susan Yuen, William Tran
 * MacID: yipsh, yuens2, tranwt
 * Student Number: 1415472, 1416198, 1407613
 * Description: Holds the function definitions for Addition. Performs operations for addition.
 */

#include "Addition.h"

//Function Definitions

//Constructor

Addition::Addition(string l, string r) {	//constructor
	left = new ArithmeticExpression(l);		//sets left expression
	right = new ArithmeticExpression(r);	//sets right expression
}

string Addition::evaluate() {				//returns left + right
	std::ostringstream buff;
	buff<<convert(left->input)+convert(right->input);	//adds left + right
	return buff.str();
}

void Addition::print() {
	cout << "(" + left->input + "+" + right->input + ")";	//prints "(left + right)"
}

Addition::~Addition() {		//destructor
	delete left;			//deletes Expression left
	delete right;			//deletes Expression right
}
