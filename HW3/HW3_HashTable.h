#ifndef HW3_HASH_H
#define HW3_HASH_H

#include <iostream>
using namespace std;

template <class V>

class HashTable {
private:
	template <class V>
	class HashNode {
	public:
		int key;
		V value;
		HashNode(int key_, V value_) {
			key = key_;
			value = value_;
		}
	};
	HashNode<V> **table;
	int capacity;
	int number;
	HashNode<V> *dummy;

public:
	HashTable(int cap);
	~HashTable();
	void tableDoubling();
	int hashFunction(int key) {
		return key % capacity;
	}
	void insertNode(int key, V value);
	V deleteNode(int key);
	V search(int key);
	void display();
};

template <class V>
HashTable<V>::HashTable(int cap) {
	capacity = cap;
	number = 0;
	dummy = new HashNode<V>(-1, NULL);
	table = new HashNode<V>*[cap];
	for (int i = 0; i < cap; i++) {
		table[i] = nullptr;
	}
	// TODO
}


template <class V>
HashTable<V>::~HashTable() {
	// TODO
	for (int i = 0; i < capacity; i++) {
		if (table[i] != nullptr && table[i] != dummy) {
			delete table[i];
		}
	}
	delete[] table;
	delete dummy;
}

template <class V>
void HashTable<V>::tableDoubling() {
	// TODO
	int i;
	int hashKey;
	capacity = capacity * 2;
	HashNode<V>** newTable = new HashNode<V> * [capacity];
	for (int i = 0; i < capacity; i++) {
		newTable[i] = nullptr;
	}
	for (i = 0; i < capacity / 2; i++) {
		if (table[i] == nullptr || table[i] == dummy) {
			continue;
		}
		hashKey = hashFunction(table[i]->key);
		while (newTable[hashKey] != nullptr) {
			hashKey = (hashKey + 1) % capacity;
		}
		newTable[hashKey] = table[i];
	}
	delete[] table;
	table = newTable;
}


template <class V>
void HashTable<V>::insertNode(int key, V value) {
	// TODO
	int hashKey = hashFunction(key);
	while (table[hashKey] != nullptr && table[hashKey] != dummy) {
		if (table[hashKey]->key == key) {
			// Replace. No resizing.
			table[hashKey]->value = value;
			return;
		}else{
			// Linear Probing
			hashKey = (hashKey + 1) % capacity;
		}
	}
	table[hashKey] = new HashNode<V>(key, value);
	number += 1;
	if (capacity / 2 < number) {
		tableDoubling();
	}
}

template <class V>
V HashTable<V>::deleteNode(int key) {
	// TODO
	int hashKey = hashFunction(key);
	int iterHashKey;
	V output;
	for (int i = 0; i < capacity; i++) {
		iterHashKey = (hashKey + i) % capacity;
		if (table[iterHashKey] == nullptr || table[iterHashKey] == dummy) {
			continue;
		}
		if (table[iterHashKey]->key == key) {
			// Detected
			output = table[iterHashKey]->value;
			delete table[iterHashKey];
			table[iterHashKey] = dummy;
			number -= 1;
			return output;
		}
	}
	cout << "Key <" << key << "> does not exist." << endl;
	return NULL;
}

template <class V>
V HashTable<V>::search(int key) {
	int hashKey = hashFunction(key);
	int iterHashKey;
	for (int i = 0; i < capacity; i++) {
		iterHashKey = (hashKey + i) % capacity;
		if (table[iterHashKey]->key == key) {
			// Detected
			return table[iterHashKey]->value;
		}
	}
	return NULL;
}


template <class V>
void HashTable<V>::display() {
	// TODO
	cout << "Capacity : " << capacity << ", The number of nodes : " << number << endl;
	for (int i = 0; i < capacity; i++) {
		if (table[i] != nullptr && table[i] != dummy) {
			cout << "address " << i << ", key = " << table[i]->key << ", value = " << table[i]->value << endl;
		}
	}
	cout << endl;
}

#endif
