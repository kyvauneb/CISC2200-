/*
 * Kyvaune Brammer
 *
 * Linked List Template Class w/ doubly linked lists
 *
 * 12/ 8/ 16
 *
 * CISC2200 - Papadakis
 *
 */


#include "linkedlisttemp.h"

#include <iostream>

using namespace std;

int main () {

	List<Student> studentList;
	char menu;
	char inputMethod;
	bool onoff = false;
	char deleteOrNah;
	char outputOrNah;

	do {

		cout << "Please enter A to add a record, D to display all records, or Q" 
			<< " to quit: ";
		cin >> menu;

		switch (menu) {

			case 'A':

				cout << "Enter 'M' to enter information manually or " 
					<< "'F' to input information from a file: ";
				cin >> inputMethod;

				if (inputMethod == 'M') {
					studentList.input();
				} else if (inputMethod == 'F') {
					cout << "Commencing file input." << endl << endl;
					studentList.fileInput();
				}
				else {
					cout << "That wasn't a valid input option." << endl;
				}
				break;
			case 'D':
				studentList.display();
				break;
		}
	}while (menu != 'Q');

	cout << "There are " << studentList.getNumNodes() << " nodes in this list, would you like to delete one(Y/N): ";
	cin >> deleteOrNah;
	
	if (deleteOrNah == 'Y') {

	studentList.deleteNode();
	studentList.display(); 
	cout << endl << endl;
	}

	cout << "Would you lke to save the final list to a file?(Y/N): ";
	cin >> outputOrNah;

	if (outputOrNah == 'Y') {

		studentList.fileOutput();
		cout << endl;
	}

	cout << "Now creating a new list from the last list created." << endl << endl;

	List<Student> studentList2(studentList);

	cout << "Displaying new list.." << endl << endl;

	studentList2.display();
	
	cout << "Sorting new list.." << endl << endl;

	studentList2.sort();

	cout << "Displaying new sorted list: " << endl << endl;

	studentList2.display();




	cout << "Now let's make a list of integers! " << endl;

	List<int> intList;
	menu = ' ';
	inputMethod = ' ';
	onoff = false;
	deleteOrNah = ' ';
	outputOrNah = ' ';

	do {

		cout << "Please enter A to add a record, D to display all records, or Q" << " to quit :";
		cin >> menu;

		switch(menu) {

			case 'A':
				
				cout << "Enter 'M' to enter information manually or " << "'F' to input "
					<< "information from a file: ";
				cin >> inputMethod;

				if (inputMethod == 'M') {
					intList.input();
				} else if (inputMethod == 'F') {
					cout << "Commencing file input." << endl << endl;
				}
				else {
					cout << "That wasn't a valid input option." << endl;
				}
				break;
			case 'D':
				intList.display();
				break;
		}
	}while (menu != 'Q');

	cout << "There are " << intList.getNumNodes() << " nodes in this list, would you like to delete one(Y/N): ";
	cin >> deleteOrNah;

	if (deleteOrNah == 'Y') {

		intList.deleteNode();
		intList.display();
		cout << endl << endl;
	}

	cout << "Would you like to save the final list to a file?(Y/N): ";
	cin >> outputOrNah;
	
	if (outputOrNah == 'Y') {

		intList.fileOutput();
		cout << endl;
	}

	cout << "Now creating a new list from the last list created." << endl << endl;

	List<int> intList2(intList);

	cout << "Displaying new list.." << endl << endl;

	intList2.display();

	cout << "Sorting new list.." << endl << endl;

	intList2.sort();

	cout << "Displaying new sorted list: " << endl << endl;

	intList2.display();

}
