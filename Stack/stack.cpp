/*
 * Kyvaune Brammer
 *
 * CISC2200 - Papadakis
 *
 * Stack implementation file
 *
 */

template<class T>
Node<T>::Node() {

	next = NULL;
	data;
}

template<class T> 
Node<T> *Node<T>::getNextPtr() {

	return next;
}

template<class T>
void Node<T>::setNextPtr(Node<T> *n) {

	next = n;
}

template<class T>
Stack<T>::Stack() {

	top = NULL;
}

template<class T>
Stack<T>::~Stack() {

	while (!isEmpty() ){
		pop();
	}
}

template<class T>
bool Stack<T>::isEmpty() const {

	if ( top == NULL )
		return true;
	else
		return false;
}

template<class T>
void Stack<T>::push( const T &newNodeData ) {

	Node<T> *newNode = new Node<T>;

	newNode -> data = newNodeData;

	newNode -> setNextPtr(top);

	top = newNode;

}

template<class T>
void Stack<T>::pop() {

	if (isEmpty() ) {
		cout << "The stack is empty!" << endl;
	} 
	else {
		Node<T> *tempPtr = top;
		top = top -> getNextPtr();
		tempPtr -> setNextPtr(NULL);
		delete tempPtr;
	}
}

template<class T>
void Stack<T>::pop(T &stackTop) {

	if (isEmpty()) {
		cout << "The stack is empty!" << endl;
	}
	else {
		stackTop = top -> data;
		Node<T> *tempPtr = top;
		top = top -> getNextPtr();
		tempPtr -> setNextPtr(NULL);
		delete tempPtr;
	}
}

template<class T>
void Stack<T>::peekAndStore(T &stackTop) const {

	if (isEmpty()) {
		cout << "The stack is empty!" << endl;
	}
	else {
		stackTop = top -> data;
	}
}

template<class T>
void Stack<T>::displayStack() {

	T output;

	cout << "Displaying contents of the stack .." << endl << endl;

	while (!isEmpty() ) {
		pop(output);
		cout << output;
	}

	cout << endl;
	cout << "The stack is now empty" << endl;
}
