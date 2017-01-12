/*
 * Kyvaune Brammer
 *
 * Linked List Lab Part 1 - Papadakis
 *
 * 10/5/2016
 *
 * Student Class header file
 *
 */

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

class Student {

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

  private:
	string fName;
	char mInit;
	string lName;
	int social;
	int age;

};

#endif
