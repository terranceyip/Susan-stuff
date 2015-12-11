/*
 * Name: Terrance Yip, Susan Yuen, William Tran
 * MacID: yipsh, yuens2, tranwt
 * Student Number: 1415472, 1416198, 1407613
 * Description: Implements a calculator that is capable of evaluating basic arithmetic (+, -, *, /) expressions.
 */

#include <iostream>
#include <string>
#include <ctype.h>
#include "ArithmeticExpression.h"
#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"

using namespace std;

bool checkError(string in) {	//function to check for errors in the expression

	//checks if first or last character is an operator
	char c = in.at(in.length()-1);	//sets c to last character in expression
	if (c == '+' || c == '-' || c == '*' || c == '/')	//if last character is an operator,
		return true;									//return true for error checking.
	c = (in.at(0));										//sets c to first character in expression
	if (c == '+'|| c == '*' || c == '/')				//if first character is an operator,
		return true;									//return true for error checking.

	//checks if two operators are next to each other
	for (unsigned int i=0; i<in.length(); i++) {
		char b = '0';
		c = in.at(i);			//sets c to the character at index i
		if (i > 0)
			b = in.at(i-1);	//sets b as the character before c index(i-1)
		if ((c == '+' || c == '-' || c == '*' || c == '/') && (b == '+' || b == '-' || b == '*' || b == '/'))
			return true;	//if two operators are next to each other, return true for error checking
	}

	//checks for white space between two numbers
	bool numflag = false;	//determines whether or not we have passed a number in the expression
	bool whiteflag = false;	//determines whether or not there is currently white space
	for (unsigned int i=0; i<in.length(); i++) {
		c = in.at(i);
		if (numflag && whiteflag && (c >= '0' && c <= '9')) //if there was a number, there is white space after it, and c is currently at another number,
			return true;									//return true for error checking.
		if (c == '+' || c == '-' || c == '*' || c == '/') {	//if c is an operator,
			numflag = false;								//set all flags to false.
			whiteflag = false;
		}
		if (c >= '0' && c <= '9') {							//if c is a number,
			numflag = true;									//set numflag to true.
		}
		if (isblank(c) && numflag) {						//if white space is found after a number,
			whiteflag = true;								//set whiteflag to true.
		}
	}

	//checks for equal number of brackets and if all characters are valid
	int openBrackets = 0;		//stores how many open brackets '(' there are in the expression
	int closedBrackets = 0;		//stores how many closed brackets ')' there are in the expression
	for (unsigned int i = 0; i<in.length(); i++) {
		c = in.at(i);
		if (!((c >= '0' && c <= '9') || c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || isspace(c))) {
			return true;	//if c is not a number, operator, or a white space, return true for error checking.
		}
		if (c == '(')			//if c is an open bracket,
			openBrackets++;		//add one to openBrackets.
		else if (c == ')')		//if c is a closed bracket,
			closedBrackets++;	//add one to closedBrackets.
	}
	if (openBrackets != closedBrackets) {	//if openBrackets is not equal to closedBrackets,
		return true;						//return true for error checking.
	}

	//checks if brackets and operators are valid when next to each other
	for (unsigned int i=0; i<in.length(); i++) {
		char b = '0';
		c = in.at(i);			//sets c to the character at index i
		if (i>0)
			b = in.at(i-1);	//sets b as the character before c index(i-1)
		if ((c == '+' || c == '*' || c == '/') && (b == '('))	//if the situation where (+ (* or (/ is found,
			return true;										//return true for error checking.
		if ((b == '+' || b == '*' || b == '/' || b == '-') && (c == ')'))	//if the situation where +) *) /) -) is found,
			return true;													//return true for error checking.
	}

	//if expression passes all error checks, return false for error checking.
	return false;
}

bool checkExp(string in) {							//function that checks if the input is an expression
	for (unsigned int i=0; i<in.length(); i++) {	//for each character in the expression,
		char b = '0';
		char c = in.at(i);
		if (i>0)
			b = in.at(i-1);
		if (c == '+' || (c == '-' && i != 0 && b != '(') || c == '*' || c == '/')	//check if character is an operator,
			return true;			//if it is, return true
	}
	return false;					//if no operator is found, return false
}

string evaluate(ArithmeticExpression exp) {		//function that evaluates the expression
	string op = exp.evaluate();					//op holds the operator

	//evaluates the expression recursively
	if (op != "0") {					//if op is not nothing,
		string left = exp.getLeft();	//sets left to left,
		string right = exp.getRight();	//sets right to right.

		bool isLeftExp, isRightExp;		//used to determine whether left or right is an expression

		isLeftExp = checkExp(left);		//checks if left is an expression then stores it in isLeftExp
		isRightExp = checkExp(right);	//checks if right is an expression then stores it in isRightExp

		if (isLeftExp) {				//if left is still an expression, evaluate it (recursively)
			cout << "(";				//prints '('
			ArithmeticExpression l (left);
			left = evaluate(l);			//evaluates the left expression
			cout << op;					//print the operator
		}
		else {							//if left is not an expression,
			cout << "(" << left << op;	//print '(', then left, then the operator.
		}
		if (isRightExp) {				//if right is still an expression, evaluate it (recursively)
			ArithmeticExpression r (right);
			right = evaluate(r);		//evaluates right expression
		}
		else {							//if right is not an expression,
			cout << right << ")";		//print the right expression followed by ')'
		}

		//performs final operation then returns the final answer
		if (op == "+") {					//if op is +
			Addition result(left, right);
			return result.evaluate();		//evaluate it as addition and return the final answer
		}
		else if (op == "-") {				//if op is -
			Subtraction result(left, right);
			return result.evaluate();		//evaluate it as subtraction and return the final answer
		}
		else if (op == "*") {				//if op is *
			Multiplication result(left, right);
			return result.evaluate();		//evaluate it as muliplication and return the final answer
		}
		else if (op == "/") {				//if op is /
			Division result(left, right);
			return result.evaluate();		//evaluate it as division and return the final answer
		}
	}
	return "0";		//if evaluate failed, return "0"
}

int main() {

	string input;	//declares input which will hold the user input

	while (true) {	//ensures the program will loop
		cout << "Please enter an expression: ";		//prints "Please enter an expression: "
		getline(cin, input);						//takes user input as input

		if (input == "#")	//if user inputs '#',
			return 0;		//exit the function.

		ArithmeticExpression exp (input);	//creates an ArithmeticExpression from the inputed expression

		if (checkError(input))								//if error checking finds an error,
			cout << "Expression not well formed." << endl;	//print "Expression not well formed."
		else if(!checkExp(exp.input)) {						//if input is just a number,
			cout << exp.input << " = " << exp.input << endl;//returns final answer as the number inputed.
		}
		else if (checkError(exp.input)) {					//if error checking finds an error (with brackets and white spaced removed),
			cout << "Expression not well formed." << endl;	//print "Expression not well formed."
		}
		else {												//if there are no errors,
			cout << " = " << evaluate(exp) << endl;			//print the final answer.
		}
	}
	return 0;
};
