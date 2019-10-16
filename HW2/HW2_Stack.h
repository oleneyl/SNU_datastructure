#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

// Dose getSize() method is in Time complexity O(N)?

/* --- DO NOT MODIFY --- */
template <class T>
class Stack {
private:
	class Node {
	private:
		Node * next;
		T data;

	public:
		Node(T d) {
			data = d;
		}
		Node(T d, Node* n) {
			data = d;
			next = n;
		}
		void setNext(Node* n) {
			next = n;
		}
		Node* getNext() {
			return next;
		}
		T getData() {
			return data;
		}
	};

private:
	Node * top;
	
public:
	Stack();
	~Stack();
	bool isEmpty() const;
	T getTop() const;
	int getSize() const;
	void push(const T&);
	T pop();
	void print() const;

};
/* --- DO NOT MODIFY --- */

template <class T>
Stack<T>::Stack() {
	top = nullptr;
}

template <class T>
Stack<T>::~Stack() {
	Node* temp;
	while (top != nullptr) {
		temp = top;
		top = top->getNext();
		delete temp;
	}
}

template <class T>
bool Stack<T>::isEmpty() const {
	return (top == nullptr);
}

template <class T>
T Stack<T>::getTop() const {
	if (top == nullptr) {
		return T();
	}else{
		return top->getData();
	}
}

template <class T>
int Stack<T>::getSize() const {
	int size = 0;
	Node* temp = top;
	while (temp != nullptr) {
		size += 1;
		temp = top->getNext();
	}
	return size;
}

template <class T>
void Stack<T>::push(const T& newData) {
	Node* node = new Node(newData, top);
	top = node;
}

template <class T>
T Stack<T>::pop() {
	T value = top->getData();
	Node* temp = top;
	top = top->getNext();
	delete temp;
	return value;
}

template <class T>
void Stack<T>::print() const {
	cout << "[";
	Node* temp = top;
	while (temp != nullptr) {
		cout << temp->getData();
		if (temp->getNext() != nullptr) {
			cout << ", ";
		}
		temp = temp->getNext();
	}
	cout << "]" << endl;
	return;
}

#endif