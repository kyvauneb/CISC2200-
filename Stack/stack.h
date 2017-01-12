/*
 * Kyvaune Brammer
 *
 * CISC2200 - Papadakis
 *
 * Stack implementation file
 *
 */

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

template<class T>
class Node {

  public:

	Node();

	void setNextPtr(Node<T> *n);
	Node<T> *getNextPtr();

	T data;
  private:
	
	Node<T> *next;
};

template<class T>
class Stack {
  
  public:
	  Stack();
	  ~Stack();
	  bool isEmpty() const;
	  void push( const T &newItem );
	  void pop();
	  void pop(T &stackTop);
	  void peekAndStore(T &stackTop) const;
	  void displayStack();

  private:

	  Node<T> *top;

};


#include "stack.cpp"
#endif 
