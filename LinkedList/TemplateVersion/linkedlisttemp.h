#ifndef LINKEDLISTTEMP_H
#define LINKEDLISTTEMP_H

#include <iostream>
using namespace std;

template <class T>
class Node {
 
  public: 
	
	Node();
	
	void setNextPtr (Node<T> *n);
	Node<T> *getNextPtr();

	void setPreviousPtr (Node<T> *p);
	Node<T> *getPreviousPtr();

	T data;
  private:

	Node<T> *next;
	Node<T> *previous;
};

template <class T>
class List {

  public:

	List();
	List(const List<T> &original); 
	~List();

	int getNumNodes();
	
	Node<T> *getHeadPtr;
	Node<T> *getTailPtr;

	void input();
	void insert(T data);
	void append(T data);
	void display();
	void fileInput();
	void fileOutput();
	void deleteNode();
	void sort();

	bool isEmpty();

  private:
	
	Node<T> *head;
	Node<T> *tail;
	Node<T> *current;
	int numNodes;
};	
		
#include "linkedlisttemp.cpp"
#endif	
