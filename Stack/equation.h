/*
 * Kyvaune Brammer
 * CISC2200 - Papadakis
 * Algebraic Equation Header File
 * Evauating Algebraic Expressions Lab 
 *
 */

#include "stack.h"

#ifndef EQUATION_H
#define EQUATION_H

static const int LENGTH = 16;

class AEquation {

  public:
	 
	AEquation();

	void operatorStackInput();
	void operandStackCalc();
	
	void closedParOperator(char);
	void plusMinusOperator(char);
	void multDivideOperator(char);

	void additionPostFix(char);
	void minusPostFix(char);
	void multPostFix(char);
	void dividePostFix(char);

	Stack <char> operatorStack;
	Stack <int> operandStack;

	

  private:

	char inFix[LENGTH];
	string postFix;
};

#endif
