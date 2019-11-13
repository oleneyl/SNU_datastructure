#include <iostream>
#include "HW3_AVL.h"
using namespace std;

void test_0() {
	AVL* dict = new AVL();
	dict->insert(30, 3.3);
	dict->insert(40, 4.4);
	dict->insert(50, 5.5);
	cout << dict->getHeight() << endl;
	dict->insert(80, 8.8);
	dict->insert(60, 6.6);
	dict->preorder(); cout << endl;
	dict->postorder(); cout << endl;
	dict->levelorder(); cout << endl;
	dict->insert(90, 9.9);
	dict->levelorder(); cout << endl;
	dict->insert(40, 4.444);
	cout << dict->getHeight() << endl;
	dict->levelorder(); cout << endl;
	dict->insert(42, 4.2);
	dict->insert(41, 4.1);
	cout << dict->getHeight() << endl;
	dict->levelorder(); cout << endl;
	dict->remove(40);
	cout << dict->getHeight() << endl;
	dict->levelorder(); cout << endl;
	dict->insert(20, 2.2);
	dict->insert(32, 3.2);
	dict->insert(31, 3.1);
	dict->insert(70, 7.7);
	dict->insert(68, 6.8);
	cout << dict->getHeight() << endl;
	dict->levelorder(); cout << endl;
	dict->remove(20);
	cout << dict->getHeight() << endl;
	dict->levelorder(); cout << endl;
}

void test_2() {
	AVL* dict = new AVL();
	int i, j;
	for (i = 0; i < 1000; i++) {
		dict->insert(i, 0.0001 * i);
	}

	for (i = 0; i < 990; i++) {
		dict->remove(i);
	}
	cout << dict->getHeight() << endl;
	dict->levelorder(); cout << endl;
}

int main() {
	test_0();
}