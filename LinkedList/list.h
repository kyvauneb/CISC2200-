/*
 * Kyvaune Brammer
 *
 * Linked List Lab - Part 2
 *
 * List Header file
 *
 */

#ifndef LIST_H
#define LIST_H

#include "node.h"

using namespace std;

class List {

  public:
	
	List();
	List( const List &copyList );
	~List();

	bool isEmpty();
	int getNumNodes();

	Node *getHeadPtr();
	Node *getTailPtr();	
	
	void append(Node *nPtr);
	void deleteNode(int d);
	void insertNode(Node *nPtr);

	void input();	
	void displayAscending();
	void fileInput();
	void fileOutput();

  private:
	
	Node *head;
	Node *tail;
	int numNodes;

};

#endif
