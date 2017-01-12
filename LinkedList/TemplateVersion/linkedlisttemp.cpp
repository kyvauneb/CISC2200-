/*
 * Kyvaune Brammer
 *
 * Linked List Template Implementation File
 *
 */


#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

#include "student.cpp"

template <class T>
Node<T>::Node() {

	next = NULL;
	previous = NULL;
	data;
}

template <class T>
Node<T> *Node<T>::getNextPtr() {

	return next;
}

template <class T>
void Node<T>::setNextPtr(Node<T> *n) {

	next = n;
}

template <class T>
Node<T> *Node<T>::getPreviousPtr() {

	return previous;
}

template <class T>
void Node<T>::setPreviousPtr(Node<T> *p) {

	previous = p;
}
 
template <class T>
List<T>::List() {

	head = NULL;
	tail = NULL;
	numNodes = 0;

	cout << "Default constructor has successfully run." << endl;
}

template <class T>
bool List<T>::isEmpty() {
       
	if (head == NULL) {

		return true;
	}
	else {
		return false;
	}

	cout << "List is empty!" << endl;
}

template <class T>
List<T>::List(const List<T> &original) {

	Node<T> *currentPtr;
	Node<T> *tempPtr;
	Node<T> *prev;

	head = NULL;

	if (original.head != NULL) {

		currentPtr = original.head;
				

		while (currentPtr != NULL) {

			tempPtr = new Node<T>();
			tempPtr -> data = currentPtr -> data;
			tempPtr -> setNextPtr(NULL);

			if (head == NULL) 
				head = tempPtr;
			else
				prev -> setNextPtr(tempPtr);
			currentPtr = currentPtr -> getNextPtr();
			prev = tempPtr;	
		}
	}
	cout << "Copy constructor ran successfully!" << endl;
}
 
template<class T>
void List<T>::input() {

	bool onoff = true;
	string onoffswitch;
	T value;

	while (onoff == true) {

		cout << "Hello! Would you like to enter information?(Y/N):";
		cin >> onoffswitch;

		if (onoffswitch == "Y") {

			cout << "Enter type of information: " << endl << endl;
			cin >> value;	
			insert(value);
		}
		else 
			onoff = false;
	}
	cout << "Input function has ran successfully!" << endl;
}
	
template <class T>
List<T>::~List() {

	if ( !isEmpty() ) {

		Node<T> *currentPtr = head;
		Node<T> *tempPtr;

		while (currentPtr != NULL) {

			tempPtr = currentPtr;
			currentPtr = currentPtr -> getNextPtr();
			delete tempPtr;
		}
	}
	cout << "Destructor ran successfully!" << endl;
}

template<class T>
int List<T>::getNumNodes() {

	return numNodes;
}

template<class T>
void List<T>::fileInput() {

	char fileName[50];
	T entry;
	Node<T> *currentPtr = head;
	Node<T> *newNodePtr = new Node<T>();

	ifstream inputFile;

	cout << "Enter the name of the file to load from: ";
	cin >> fileName;

	inputFile.open(fileName);

	cout << "Sample.txt correctly opened" << endl << endl;

	if (!inputFile.is_open()) {
		exit(EXIT_FAILURE);
	}

	do {

		inputFile >> entry;
	
		if (inputFile.eof()) {
			break;
		}
		inputFile.close();
		cout << "Data correctly read from inputFile" << endl << endl;

//		cout << entry;

		newNodePtr -> data = entry;

		if (newNodePtr != NULL) {

			currentPtr = newNodePtr;
			insert(currentPtr->data);
			cout << "Insertion successful" << endl;
		}
	} while (!inputFile.eof());
}
		
template <class T>
void List<T>::append(T value) {

	Node<T> *newNode = new Node<T>();

	if (head == NULL) {
	
		newNode -> data = value;
		head = newNode;		
		tail = head;
	}
	else {

		newNode -> data = value;
		tail -> setNextPtr(newNode);
		tail = tail->getNextPtr();		
	}
	numNodes++;
	cout << "Append function ran successfully" << endl << endl;
}

template<class T>
void List<T>::fileOutput() {

	Node<T> *currentPtr = head;
	char fileName[50];

	ofstream outputFile;

	cout << "Enter the name of the file to output to: ";
	cin >> fileName;

	outputFile.open(fileName);

	cout << "Output file successfully opened" << endl << endl;

	do {

		if (outputFile.eof()){
			break;
		}

		while (currentPtr != NULL) {

			outputFile << currentPtr -> data;
			currentPtr = currentPtr -> getNextPtr();
		}
	outputFile.close();
	break;
	} while (!outputFile.eof());
	
} 

template<class T>
void List<T>::insert(T value) {

	Node<T> *newPtr = new Node<T>();

	if (!head) {
 				
		newPtr -> data = value;
		head = newPtr;
		tail = newPtr;
		}
	else {
	
		Node<T> *currentPtr = head;
		Node<T> *previousPtr = NULL;

		newPtr -> data = value;
		
		while (currentPtr) {	
			if (currentPtr -> data >= newPtr -> data) 
				break;
			previousPtr = currentPtr;
			currentPtr = currentPtr->getNextPtr();
		}

		newPtr->setNextPtr(currentPtr);
		
		if(previousPtr) 	
			previousPtr->setNextPtr(newPtr);
		else
			head = newPtr;		
	}
	cout << "Insert function complete" << endl;

	numNodes++;
}	
template<class T>
void List<T>::deleteNode() {

	int nodeCount, position = 0;
	Node<T> *currentPtr = head;
	Node<T> *tempPtr = head;

	cout << "Which node would you like to delete: ";
	cin >> position;
	
	if (head == 0) 
		cout << "List is empty." << endl;
	
	else {
		int i = 1;
	
		while (i < position && currentPtr != NULL) {
			tempPtr = currentPtr;
			currentPtr = currentPtr -> getNextPtr();
			i++;
		}
		if (currentPtr == NULL || i < position)
			cout << "Item doesn't exist." << endl; 
		
		else if (currentPtr == head) {
			head = head -> getNextPtr();
			delete currentPtr;
			cout << "Head was deleted." << endl;	
		}
		else {
			tempPtr -> setNextPtr(currentPtr->getNextPtr());
			delete currentPtr;
			cout << "Selected item was deleted." << endl;
		}
	}
	cout << "Delete function ran successfully!" << endl;

}		

template <class T>
void List<T>::sort() {

	if ( head != NULL ) {

		Node<T> *current = head;
		Node<T> *prev = NULL;
		Node<T> *tempNode = NULL;

		int flag = 0;

		for (int i = 0; i < numNodes; i++) {
			while (current->getNextPtr() != NULL) {
	
				tempNode = current -> getNextPtr();
	
				if (current -> data > tempNode -> data) {

					flag = 1;
					current->setNextPtr(tempNode->getNextPtr());
					tempNode->setNextPtr(current);

					if (prev != NULL)
						prev->setNextPtr(tempNode);	
					prev = tempNode;
					if (head == current)
						head = tempNode;
					if (current->getNextPtr() == NULL)
						tail = current;
				}
				else {
					
					prev = current;
					current = current->getNextPtr();
				}
			}
			if (flag == 0)
				break;
			else {
				prev = NULL;
				current = head;
				flag = 0;
			}
		}
	}
	cout << "Sort function ran successfully!" << endl;
} 


template <class T>
void List<T>::display() {
	
	Node <T> *currentPtr = head;
	int i = 0;

	if (head == NULL)
		cout<< "There is nothing to display!" << endl;
	
	else {

		while (currentPtr != NULL) {

			cout << i+1 << ". Item: " << currentPtr -> data << endl;
			currentPtr = currentPtr -> getNextPtr();
			i++;
		}
	}

}

 
