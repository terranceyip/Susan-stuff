/*
 * Name: Terrance Yip, Susan Yuen, William Tran
 * MacID: yipsh, yuens2, tranwt
 * Student Number: 1415472, 1416198, 1407613
 * Description: [This is an informative excerpt about this file.]
 */

#include <iostream>
#include <string>
#include "ArithmeticExpression.h"

using namespace std;

int main() {
	/* The main function does the following:
	 *
	 * 1) Reads the integer arithmetic expression as a string from the standard input.
	 * 2) Parses that string into an Expression tree. Expression objects should be created dynamically.
	 *    If an input string is invalid (e.g., +2*3-), only print “Expression is not well formed”.
	 * 3) When the input string is successfully parsed, the program should evaluate the resulting
	 *    expression by calling Expression::evaluate() of the top Expression object. This
	 *    should recursively evaluate the entire expression. The result should be shown as a floating point
	 *    number with 2 decimal points. We are not concerned with division by zero errors.
	 * 4) Prints the original string by calling the Expression::print() of the top Expression
	 *    object, then an equal sign, followed by the final result of the evaluation. Again, printing
	 *    should be accomplished recursively. The print function does not have to print the input formula
	 *    in the same format. It should be of the form: “(“ left expression op right expression “)”
	 * 5) Deallocates all dynamically created objects appropriately. If your program exhibits
	 *    memory leaks, you will lose points.
	 * 6) Will repeat this process until the string ‘#’ is received, at which point execution will
	 *    terminate.
	 */

	return 0;
};
