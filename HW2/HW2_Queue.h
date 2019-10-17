#ifndef HW2_QUEUE_H
#define HW2_QUEUE_H

#include <iostream>

using namespace std;

/* --- DO NOT MODIFY --- */
template <class T>
class Queue
{
private:
	int front;
	int rear;
	T* array;
	int capacity;
public:
	Queue(int c);
	~Queue();
	bool isEmpty() const;
	T getFront() const;
	T getRear() const;
	int getSize() const;
	int getCapacity() const;
	void push(const T& x);
	T pop();
	void print() const;
	void shift(int amount);
};
/* --- DO NOT MODIFY --- */

// Custom function headers
template <class T>
void swap(T*, int, int);

template <class T>
void terminal_swap(T*, int, int, int);




template <class T>
Queue<T>::Queue(int c) {
	array = new T[c];
	front = 0;
	rear = 0;
	capacity = c;
}

template <class T>
Queue<T>::~Queue() {
	delete array;
}

template <class T>
bool Queue<T>::isEmpty() const {
	return (rear == front);
}

template <class T>
T Queue<T>::getFront() const {
	if (isEmpty()) {
		return T();
	} else {
		return array[front];
	}
}

template <class T>
T Queue<T>::getRear() const {
	if (isEmpty()) {
		return T();
	} else {
		return array[rear - 1];
	}
}

template <class T>
int Queue<T>::getSize() const {
	return (rear - front + capacity) % capacity;
}

template <class T>
int Queue<T>::getCapacity() const {
	return capacity;
}

template <class T>
void Queue<T>::push(const T& x) {
	if (getSize() == (capacity - 1)) {
		T* another = new T[capacity * 2];
		for (int i = 0; i < (capacity - 1); i++) {
			another[i] = array[(front + i) % capacity];
		}
		delete array;
		array = another;
		front = 0;
		rear = capacity - 1;
		capacity = capacity * 2;
		//Resize. This operation must be seperable;
	}
	array[rear] = x;
	rear += 1;
	rear = rear % capacity;
	//cout << "LOG " <<  front << ' ' << rear << ' ' << capacity << endl;
}

template <class T>
T Queue<T>::pop() {
	if (isEmpty()) {
		return T();
	}
	else {
		T temp = array[front];
		front += 1;
		front = front % capacity;
		return temp;
	}
}

template <class T>
void Queue<T>::print() const {
	int index = front;
	cout << "[";
	while (index != rear) {
		cout << array[index];
		if ((index + 1 - rear + capacity) % capacity != 0) {
			cout << ", ";
		}
		index += 1;
		index %= capacity;
	}
	cout << "]" << endl;
}

// Function for swap
template <class T>
void swap(T* arr, int i, int j) {
	T temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

template <class T>
void terminal_swap(T* arr, int start, int end, int size) {
	for (int i = 0; i < size; i++) {
		swap(arr, start + i , end - size + i);
	}
}

template <class T>
void Queue<T>::shift(int amount) {
	int i;
	int real_amount = amount;
	if (real_amount < 0) {
		real_amount = real_amount * -1;
		for (i = 0; i < real_amount; i++) {
			array[rear] = array[front];
			front += 1;
			rear += 1;
			front %= capacity;
			rear %= capacity;
		}
	}
	else if (real_amount > 0) {
		for (i = 0; i < real_amount; i++) {
			array[(front - 1 + capacity) % capacity] = array[(rear-1+capacity)%capacity];
			front += capacity - 1;
			rear += capacity - 1;
			front %= capacity;
			rear %= capacity;
		}
	}
}
#endif