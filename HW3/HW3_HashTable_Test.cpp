#include "HW3_HashTable.h"

void insertWithLog(HashTable<int>* map, int key, int value) {
	cout << "Insert Node (Key : " << key << ", Value : " << value << ")" << endl;
	map->insertNode(key, value);
}

void deleteWithLog(HashTable<int>* map, int key) {
	cout << "Delete Node (Key : " << key << ")" << endl;
	map->deleteNode(key);
}

void searchWithLog(HashTable<int>* map, int key) {
	cout << "Search node that key is " << key << endl;
	cout << "Value : " << map->search(key) << endl;
}

void current(HashTable<int>* map) {
	cout << "<Current HashTable>" << endl;
	map->display();
}

void test_0() {
	HashTable<int>* map = new HashTable<int>(7);
	insertWithLog(map, 1, 10);
	insertWithLog(map, 11, 11);
	insertWithLog(map, 8, 12);

	cout << "Induce collision";
	insertWithLog(map, 8, 12);
	current(map);


	cout << "need capacity doubling" << endl;
	insertWithLog(map, 21, 13);
	map->insertNode(21, 13);
	current(map);

	deleteWithLog(map, 11);
	current(map);

	map->insertNode(11, 13);
	current(map);

	deleteWithLog(map, 27);
	current(map);

	searchWithLog(map, 21);
	delete map;
}

void test_1() {
	HashTable<int>* map = new HashTable<int>(7);
	int i, j;
	for (i = 0; i < 100; i++) {
		map->insertNode(i, i * i);
	}

	for (i = 0; i < 15; i++) {
		searchWithLog(map, 10 * i);
	}

	for (i = 0; i < 33; i++) {
		deleteWithLog(map, i*3);
	}

	for (i = 0; i < 10; i++) {
		searchWithLog(map, 10 * i);
	}

	for (i = 0; i < 33; i++) {
		map->insertNode(i * 3, i * 300);
	}

	for (i = 0; i < 10; i++) {
		searchWithLog(map, 10 * i);
	}

	for (i = 0; i < 100; i++) {
		map->insertNode(i + 100, i * i);
	}

	for (i = 0; i < 21; i++) {
		searchWithLog(map, 10 * i);
	}
}


int main() {
	test_1();
	return 0;
}