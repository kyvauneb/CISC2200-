/*
 * Kyvaune Brammer
 *
 * Linked List Temp Lab - Papadakis
 *
 * 12/5/16
 *
 * Student Class Header File
 */

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

class Student {

	friend istream &operator>> (istream &input, Student &S) {

		cout << "Please enter the following student information.." << endl;
		cout << "Student first name: ";
		input >> S.fName;
		cout << "Student middle initial: ";
		input >> S.mInit;
		cout << "Student last name: ";
		input >> S.lName;
		cout << "Student SSN: ";
		input >> S.social;
		cout << "Student age: ";
		input >> S.age;
		
		return input;
	}

	friend ostream &operator<< (ostream &output, const Student &S) {

		output << "Student Information" << endl;
		output << "-------------------" << endl << endl;

		output << "Student Name: " << S.fName << " " << S.mInit << " " << S.lName << endl;
		output << "Student SSN: " << S.social << endl;
		output << "Student age: " << S.age << endl;

		return output;
	}

  public:
	
	Student();
        Student( string fN, char m, string lN, int s, int age);

        void setFName( string fN);
        string getFName();

        void setMInit( char m);
        char getMInit();

        void setLName ( string lN);
        string getLName();

        void setSocial( int s);
        int getSocial();

        void setAge( int a);
        int getAge();

        void displayStudent();

	friend bool operator>(const Student &ls, const Student &rs) {

		return (ls.age > rs.age);
	}

	friend bool operator<(const Student &ls, const Student &rs) {
	
		return (ls.age < rs.age);
	}
	
	friend bool operator>= (const Student &ls, const Student &rs) {

		if (ls.age > rs.age) {	
			return true;
		}
		if (ls.age == rs.age) {
			return true;
		}
		return false;
	}

  private:
	string fName;
	char mInit;
	string lName;
	int social;
	int age;

};

#endif
	
	
