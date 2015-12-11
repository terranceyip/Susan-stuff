/*
 * Name: Terrance Yip, Susan Yuen, William Tran
 * MacID: yipsh, yuens2, tranwt
 * Student Number: 1415472, 1416198, 1407613
 * Description: Contains the function declarations for ArithmeticExpression. Performs functions on the expression.
 */

#include "ArithmeticExpression.h"

ArithmeticExpression::ArithmeticExpression() {		//constructor for no parameters
	splitIndex = NULL;								//sets all values to NULL
	left = NULL;
	right = NULL;
}

ArithmeticExpression::ArithmeticExpression(string in) {	//constructor with 1 parameter (string in)
	int openBrackets = 0;		//openBrackets counts how many '(' are in the expression
	int closedBrackets = 0;		//closedBrackets counts how many ')' are in the expression
	splitIndex = 0;				//index of the operator
	input = in;					//sets input as string parameter (the expression)
	input = removeWhiteSpace(input);	//removes white space in the expression
	input = removeBrackets(input);		//removes outer excess brackets in the expression

	//checks addition and subtraction
	for (unsigned int i=0; i<input.length(); i++) {	//for each character in the expression
		char b = '0';		//placeholder for b when i = 0
		if (i > 0)
			b = input.at(i-1);	//b is the character before c
		char c = input.at(i);	//c is the current character being looked at in the expression
		if (c == '(' )			//if c is an open bracket,
			openBrackets++;		//add one to openBrackets.
		else if (c == ')' )		//if c is a closed bracket,
			closedBrackets++;	//add one to closedBrackets.
		else if ((c == '+' || (c == '-' && b != '(')) && openBrackets == closedBrackets) {	//if c is operator + or - and number of '(' == number of ')',
			splitIndex = i;		//sets splitIndex to the index of the operator.
		}
	}

	//checks multiplication and division
	if (splitIndex == 0) {		//if there are no more + or - operators, looks for * or /
		for (unsigned int i=0; i<input.length(); i++) {
			char c = input.at(i);
			if (c == '(' )
				openBrackets++;
			else if (c == ')' )
				closedBrackets++;
			else if ((c == '*' || c == '/') && openBrackets == closedBrackets)	//if c is operator * or / and number of brackets are equal,
				splitIndex = i;		//sets splitIndex to the index of the operator
		}
	}
}

string ArithmeticExpression::evaluate() {		//function to evaluate the expression
	left = new ArithmeticExpression(input.substr(0,splitIndex));	//sets left to the left expression
	right = new ArithmeticExpression(input.substr(splitIndex+1));	//sets right to the right expression
	string op = input.substr(splitIndex,1);							//sets op to the operator
	return op;														//returns the operator
}

string ArithmeticExpression::getLeft() {	//returns the left expression as a string
	return left->input;
}

string ArithmeticExpression::getRight() {	//returns the right expression as a string
	return right->input;
}

void ArithmeticExpression::print() {		//prints the expression
	cout << input;
}

float ArithmeticExpression::convert (string s) {	//converts string s to a float
	return (float) atof(s.c_str());
}

string ArithmeticExpression::removeBrackets(string in) {	//function that removes excess outer brackets

	while (true) {		//repeats the process until there are no more outer brackets

		if (in.at(0) != '(' || in.at(in.length() - 1) != ')')	//if there are no outer brackets,
			return in;											//return the expression.

		int openBrackets = 0;
		int closedBrackets = 0;
		//if openBrackets == closedBrackets only at the last character, then there are excess outer brackets.
		for (unsigned int i = 0; i<in.length()-1; i++) {
			char c = in.at(i);
			if (c == '(')
				openBrackets++;
			else if (c == ')')
				closedBrackets++;
			if (openBrackets == closedBrackets && i != in.length()-1) { //if openBrackets == closedBrackets NOT at the last character,
				return in;												//return the expression.
			}
		}
		in = in.substr(1, in.length()-2);	//removes the outer brackets (first and last character in the expression)
	}
}

string ArithmeticExpression::removeWhiteSpace(string in) {		//removes all white space in the expression
	for (unsigned int i=0; i<in.length(); i++) {
		char c = in.at(i);
		if (c == ' ') {				//if c is a white space,
			in.erase(i,1);			//erase it from the expression.
		}
	}
	return in;						//returns the expression as a string.
}

ArithmeticExpression::~ArithmeticExpression() {		//destructor
}
