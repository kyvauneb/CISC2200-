/*
 * Kyvaune Brammer
 *
 * Linked List Temp
 *
 * 12 / 5/ 16
 *
 * Student Class Implementation File
 *
 */

#include "student.h"

#include <iostream>
using namespace std;


Student::Student() {

        fName = "f";
        mInit = 'm';
        lName = "l";
        social = 1234;
        age = 0;

}

Student::Student(string fN, char m, string lN, int s, int a) {

        fName = fN;
        mInit = m;
        lName = lN;
        social = s;
        age = a;

}

string Student::getFName() {

        return fName;
}

void Student::setFName( string fN ) {

        fName = fN;
}

char Student::getMInit() {

        return mInit;
}


void Student::setMInit( char m ) {

        mInit = m;
}

string Student::getLName() {

        return lName;
}

void Student::setLName( string lN ) {

        lName = lN;
}

int Student::getSocial() {

        return social;
}

void Student::setSocial( int s ) {

        social = s;
}

int Student::getAge() {

        return age;
}

void Student::setAge ( int a ) {

        age = a;
}

void Student::displayStudent() {

        cout << "Student Name: " << getFName() << " " << getMInit() << " " << getLName() << endl;
        cout << "Social Security #: " << getSocial() << endl;
        cout << "Student Age: " << getAge() << endl;

}

