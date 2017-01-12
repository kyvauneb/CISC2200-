/*
 * Kyvaune Brammer
 * CISC2200 - Papadakis
 * Algebraic Equation Implementation File
 * Evaluating Infix Algebraic Expressions Lab
 */

#include "equation.h"

AEquation::AEquation() {

	Stack<char> operatorStack;
	Stack<int> operandStack;
	char inFix[LENGTH] = {'0'};
	string postFix = "NULL";
}

void AEquation::operatorStackInput() {
	
	bool startfinish = false;

	while (startfinish == false) {

		cout << "Enter an infix expression or 'E' to exit: ";
		cin >> inFix;

		if (inFix[0] != 'E') {

			for (int i = 0; inFix[i] != '\0'; i++) {

				char input = inFix[i];

				switch(input) {
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
						postFix += input;
						break;
					case '(': 
						operatorStack.push(input);
						break;
					case ')': 
						closedParOperator(input);
						break;
					case '+':
					case '-':
						plusMinusOperator(input);
						break;
					case '*':
					case '/':
						multDivideOperator(input);
						break;
				}
			}
			while (!operatorStack.isEmpty()) {
		
				char stackTop;
				operatorStack.pop(stackTop);
				postFix += stackTop;
			}
		}
		else {
			startfinish = true;;
		}
	cout << postFix << endl;	
	}
}

void AEquation::closedParOperator(char inp ) {
	
	char stackTop;
	operatorStack.peekAndStore(stackTop);
	while (stackTop != '(') {

		operatorStack.pop(stackTop);
		postFix += stackTop;
		operatorStack.peekAndStore(stackTop);
	}
	operatorStack.pop();
}

void AEquation::plusMinusOperator(char inp) {

	if (!operatorStack.isEmpty()) {
		char stackTop;
		operatorStack.peekAndStore(stackTop);

		while (!operatorStack.isEmpty() && stackTop != '(') {
			operatorStack.pop(stackTop);
			postFix += stackTop;
			operatorStack.peekAndStore(stackTop);
		}
	}
	operatorStack.push(inp);
}

void AEquation::multDivideOperator(char inp) {

	if (!operatorStack.isEmpty()) {
		char stackTop;
		operatorStack.peekAndStore(stackTop);

		while (!operatorStack.isEmpty() && stackTop != '(' && stackTop != '+' && stackTop != '-') {
			operatorStack.pop(stackTop);
			postFix += stackTop;
			operatorStack.peekAndStore(stackTop);
		}
	}
	operatorStack.push(inp);
}

void AEquation::operandStackCalc() {

	const char *postFixCalc = postFix.c_str();

	for (int i = 0; postFixCalc[i] != '\0'; i++) {

		char input = postFixCalc[i];

		switch(input) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': {
				int intInput = input - '0';
				operandStack.push(intInput);
				break;
			}
			case '+': 
			{ 
				additionPostFix(input);
				break;
			}
			case '-':
			{ 
				minusPostFix(input);
				break;
			}
			case '*':
			{ 
				multPostFix(input);
				break;
			}
			case '/': 
			{ 
				dividePostFix(input);
				break;
			}
		}
	}		
	int finalResult;
	operandStack.pop(finalResult);
	cout << finalResult << endl;
}

void AEquation::additionPostFix(char inp) {

	int op1, op2, result;
	operandStack.pop(op2);
	operandStack.pop(op1);
	result = op1 + op2;
	operandStack.push(result);
}

void AEquation::minusPostFix(char inp) {

	int op1, op2, result;
	operandStack.pop(op2);
	operandStack.pop(op1);
	result = op1 - op2;	
	operandStack.push(result);
	
}

void AEquation::multPostFix(char inp) {

	int op1, op2, result;
	operandStack.pop(op2);
	operandStack.pop(op1);
	result = op1 * op2;
	operandStack.push(result);
	
}

void AEquation::dividePostFix(char inp) {

	int op1, op2, result;
	operandStack.pop(op2);
	operandStack.pop(op1);
	result = op1 / op2;
	operandStack.push(result);

}

