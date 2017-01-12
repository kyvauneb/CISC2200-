/*
 * Kyvaune Brammer
 *
 * Linked List Lab Part 1 - Papadakis
 *
 * 10/7/2016
 *
 * Driver implementation file
 *
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

#include "student.h" 
#include "node.h"
#include "list.h"

const int FILESIZE = 20;

//COMMENTED OUT CODE BEGINS HERE

/*
void append(Node *n);
void input();
void display();


void append (Node *n) {

	Node* curr = head;

	if (curr == NULL) {
		
		head = n;
	}
	else {
		while (curr -> getNextPtr() != NULL) { 
			
		curr = curr -> getNextPtr();
		
		}
		curr -> setNextPtr(n);
	}
}

void input() {

	string fN; 
   	char m;
	string lN;
   	int social;
   	int age;

	cout << "First name: ";
    	cin >> fN;
	
	cout << "Middle Initial: ";
	cin >> m;

	cout << "Last name: ";
	cin >> lN;

	cout << "Social security number: ";
   	cin >> social;
	
  	cout << "Age: ";
    	cin >> age;

 	Student * sPtr = new Student(fN, m, lN, social, age);
	sPtr->displayStudent();

  	Node * nPtr = new Node(sPtr);

  	append(nPtr);
}

void display() {

	Node *curr = head;

	while(curr) {
        	
		curr->getStudentPtr()->displayStudent();
       
	 	curr = curr->getNextPtr(); 
    	}	
}
*/

//COMMENTED OUT CODE ENDS HERE

Node *head = NULL;
Node *currentPtr = NULL;
/*
void fileInput() {

	char fileName[50];
	string fName, lName;
	char mInit;
	int social, age;

	ifstream inputFile;

	cout << "Input stream correct" << endl << endl;
	
	cout << "Enter name of file to input: ";
	cin >> fileName;

	inputFile.open(fileName);

	cout << "sample.txt correctly opened" << endl << endl;

	if (!inputFile.is_open()) {

		exit(EXIT_FAILURE);
	}

	while ( inputFile.eof() != true ) {

		inputFile >> fName >> mInit >> lName >> social >> age;

		cout << "Members correctly read from inputFile" << endl << endl;
	
		cout << fName << mInit << lName << social << age;
	
		Student *studentPtr = new Student (fName, mInit, lName, social, age);

		if (studentPtr != NULL) {	

			currentPtr = new Node (studentPtr);
		
			studentList.insertNode (currentPtr);

			cout << "Insertion successful" << endl;
			
			inputFile.close();
		}
	}
}
*/
void fileOutput() {

	string fileName;

	cout << "Enter name of file to output: ";
	cin >> fileName;

	ofstream outputFile (fileName, ios::out);

	while ( currentPtr != NULL ) {

		outputFile << currentPtr -> returnFirst() << " " 
		<< currentPtr -> returnMiddle() << " " 
		<< currentPtr -> returnLast() << " " 
		<< currentPtr -> returnSocial() << " " 
		<< currentPtr -> returnAge() << endl;

		currentPtr = currentPtr -> getNextPtr();
	}
	outputFile.close();
}
		
int main() {

	char menu;
	List studentList;
	char inputMethod;
	bool onoff = false;
	int deleteNode;
	char deleteOrNah;
	char outputOrNah;

	
	do {
		cout << "Please enter A to add a student record, D to display all records, or Q" 
			<< " to quit: ";

		cin >> menu;
	
		switch (menu) {
		
			case 'A':

				cout << "Enter either 'M' to enter student information manually or " 
					<< "'F' to input student information from a file: ";
				cin >> inputMethod;

				if (inputMethod == 'M') {
					studentList.input();
				}
				else if (inputMethod == 'F') {
					cout << "Commencing file input." << endl << endl;
					studentList.fileInput();
				}
				else {
					cout << "That wasn't a valid input." << endl;
				}
				break;
			case 'D':
				studentList.displayAscending();
				break;
		}
	} while (menu != 'Q');

	cout << "There are " << studentList.getNumNodes() << " nodes within this list, would you like to delete one?(Y/N): ";
	cin >> deleteOrNah;

	if (deleteOrNah == 'Y') {

		cout << "Enter the number of the node you would like to delete(1 being the most recent): ";
		cin >> deleteNode;
		
		studentList.deleteNode(deleteNode);
		studentList.displayAscending();
		cout << endl;
	}

	cout << "Would you like to save the final list to a file?(Y/N): ";
	cin >> outputOrNah;

	if (outputOrNah == 'Y') {

		studentList.fileOutput();
		cout << endl;
	}
}
