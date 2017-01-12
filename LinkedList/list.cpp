/*
 * Kyvaune Brammer 
 *
 * List Class Implementation File
 *
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

#include "list.h"
#include "node.h"
#include "student.h"

using namespace std;

List::List() {

	head = NULL;
	numNodes = 0;

	cout << "Default constructor run succesfully "<< endl;
}

List::List( const List &copy ) {

	head = NULL;
	numNodes = 0;

	Node *currentPtrCopy = copy.head;

	while ( currentPtrCopy != NULL ) {

		string fName = currentPtrCopy -> returnFirst();
		char mInit = currentPtrCopy -> returnMiddle();
		string lName = currentPtrCopy -> returnLast();
		int social = currentPtrCopy -> returnSocial();
		int age = currentPtrCopy -> returnAge();

		Student *studentPtr = new Student ( fName, mInit, lName, social, age);

		Node *newCopy = new Node (studentPtr);

		append( newCopy );

		currentPtrCopy = currentPtrCopy -> getNextPtr();
	}
	cout << "Copy constructor ran successfully " << endl;
}

List::~List() {

	// can't delete an empty list, so

	if ( !isEmpty() ) {

		Node *currentPtr = head;
		Node *tempPtr;

		while ( currentPtr != NULL ) {
	
			// setting the currentPtr to a temporaryPtr which is then deleted
		
			tempPtr = currentPtr;
			currentPtr = currentPtr -> getNextPtr();
			delete tempPtr;
		}
	}
	cout << "Destructor ran succesfully " << endl;
}

bool List::isEmpty() {

	if (head == NULL) {

		return true;
	}
	else {
		return false;
	}
}

int List::getNumNodes() {

	return numNodes;
}

Node *List::getHeadPtr() {

	return head;
}

Node *List::getTailPtr() {

	return tail;
}

void List::append( Node *nPtr) {

	if ( head != NULL ) {

		nPtr ->	setPreviousPtr(tail);
		tail -> setNextPtr(nPtr);
		tail = nPtr;
	}
	else {

		head = nPtr;
		tail = nPtr;
	}
	numNodes++;
	
	cout << "Append function ran successfully" << endl;
}

void List::deleteNode( int d) {

	Node *currentPtr = head;

	int nodeCount = 0;

	// detects node that will be deleted as per user input

	while (nodeCount < d) {

		currentPtr = currentPtr -> getNextPtr();
		nodeCount++;
	}

	// points to the node previous to and after the node that is to be deleted

	Node *previousPtr = currentPtr -> getPreviousPtr();
	Node *nextPtr = currentPtr -> getNextPtr();

	// deletes node

	if (previousPtr != NULL) {

		previousPtr -> setNextPtr(nextPtr);
	}
	if (nextPtr != NULL) {

		nextPtr -> setPreviousPtr(previousPtr);
	}

	currentPtr -> setNextPtr(NULL);
	currentPtr -> setPreviousPtr(NULL);

	cout << "Delete function ran succesfully!" << endl;
}

void List::displayAscending() {

	Node *currentPtr = head;

	cout << "Ascending List" << endl;
	cout << "--------------" << endl << endl;

	while (currentPtr != NULL) {

		currentPtr -> displayStudent();
		currentPtr = currentPtr -> getNextPtr();
	}

	cout << endl;
}

void List::insertNode(Node *nPtr) {

	Node *currentPtr = head;
	Node *previousPtr = tail;

	int newPtr = nPtr -> returnAge();

	if (isEmpty() == true) {

		head = nPtr;
	}

	else {

		while (currentPtr -> returnAge() < newPtr ) {

			currentPtr = currentPtr -> getNextPtr();
		}

		previousPtr = currentPtr -> getPreviousPtr();
		
		nPtr -> setNextPtr(currentPtr);
		nPtr -> setPreviousPtr(previousPtr);
		currentPtr -> setPreviousPtr(nPtr);
		previousPtr -> setNextPtr(nPtr);
		
	}

	numNodes++;
}	

void List::input() {

	string fName, lName;
	char mInit;
	int social, age;
	string onoffswitch;
	bool onoff = true;

	Node *currentPtr = NULL;

	while (onoff == true) {

	cout << "Would you like to enter student data?(Y/N): ";
	cin >> onoffswitch;

	if  ( onoffswitch == "Y" ) {

		cout << "Enter first name: ";
		cin >> fName;

		cout << "Enter middle initial: ";
		cin >> mInit;

		cout << "Enter last name: ";
		cin >> lName;

		cout << "Enter social security number: ";
		cin >> social;

		cout << "Enter student's age: ";
		cin >> age;
	
		Student *studentPtr = new Student (fName, mInit, lName, social, age);

		currentPtr = new Node (studentPtr);

		append(currentPtr);
	}
	else
		onoff = false;
	}
	cout << "Input function ran successfully!" << endl;
}

void List::fileInput() {

        char fileName[50];
        string fName, lName;
        char mInit;
        int social, age;
	Node *currentPtr = NULL;
	Student *studentPtr = NULL;

        ifstream inputFile;

        cout << "Input stream correct" << endl << endl;

        cout << "Enter name of file to input: ";
        cin >> fileName;

        inputFile.open(fileName);

        cout << "sample.txt correctly opened" << endl << endl;

        if (!inputFile.is_open()) {

                exit(EXIT_FAILURE);
        }

        do {

                inputFile >> fName >> mInit >> lName >> social >> age;
		
		if (inputFile.eof()) {
			break;
		}

		inputFile.close();
                cout << "Members correctly read from inputFile" << endl << endl;

                cout << fName << mInit << lName << social << age;
		
                Student *studentPtr = new Student (fName, mInit, lName, social, age);

                if (studentPtr != NULL) {

                        currentPtr = new Node (studentPtr);

                        insertNode (currentPtr);

                        cout << "Insertion successful" << endl; 
	       }
	
	} while (!inputFile.eof());
}

void List::fileOutput() {

	Node *currentPtr = head;
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

		while ( currentPtr != NULL ) {

			outputFile << currentPtr -> returnFirst() << " "
				<< currentPtr -> returnMiddle() << " "
				<< currentPtr -> returnLast() << " "
				<< currentPtr -> returnSocial() << " " 
				<< currentPtr -> returnAge() << endl;

			currentPtr = currentPtr -> getNextPtr();

		}
	outputFile.close();
	}while (!outputFile.eof());
}
