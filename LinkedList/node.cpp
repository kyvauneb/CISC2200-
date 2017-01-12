/*
 * Kyvaune Brammer
 *
 * Linked List Lab Part 1 - Papadakis
 *  
 * 10/5/2016
 *
 * Node Implementation File
 *
 */

#include "student.h"
#include "node.h"

#include <iostream>

using namespace std;

Node::Node() {

	next = NULL;
	sPtr = NULL;

}

Node::Node ( Student *s ) {

	next = NULL;
	sPtr = s;
}

Node *Node::getNextPtr() {

	return next;
}

void Node::setNextPtr ( Node *n ) {

	next = n;
}

Node *Node::getPreviousPtr() {

	return previous;
}

void Node::setPreviousPtr(Node *p) {

	previous = p;
}

Student *Node::getStudentPtr() {	

	return sPtr;
}

void Node::setStudentPtr(Student *s) {

	sPtr = s;
}

void Node::displayStudent() {

	sPtr->displayStudent();
}

string Node::returnFirst() {
	
	return sPtr -> getFName();
}

char Node::returnMiddle() {

	return sPtr -> getMInit();
}

string Node::returnLast() {

	return sPtr -> getLName();
}

int Node::returnSocial() {

	return sPtr -> getSocial();
}

int Node::returnAge() {
	
	return sPtr -> getAge();
}


