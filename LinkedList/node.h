/*
 * Kyvaune Brammer
 *
 * CISC2200 - Linked List Lab Part 1 - Papadakis
 *
 * 10/5/2016
 *
 * Node Class header file
 *
 */

#ifndef NODE_H
#define NODE_H

#include "student.h" 

using namespace std;

class Node {

  public:

	Node();
	Node( Student *s );
	Node( string, char, string, int, int );

	void setNextPtr( Node *n );
	Node *getNextPtr();

	void setPreviousPtr(Node *p);
	Node *getPreviousPtr();

	Student *getStudentPtr();
	void setStudentPtr(Student *s);	

	void displayStudent();

	string returnFirst();
	char returnMiddle();
	string returnLast();
	int returnSocial();
	int returnAge();

  private:
	Student *sPtr;
	Node *next;
	Node *previous;
	int item;

};

#endif 
	
