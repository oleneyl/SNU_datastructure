#include <fstream>
#include <crtdbg.h>
#include "HW1_Figure.h"

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	ofstream os;
	os.open("result.txt");
	// Constructor test
	os << "Constructor test" << endl;
	// just check if there's no compile error
	//Figure* f = new Figure();
	Figure* r = new Rectangle();
	Figure* c = new Circle();

	Figure* f1 = new Rectangle(1, 1, 2, 2);
	Figure* f2 = new Rectangle(-10, -2, 5, 4);
	Figure* f3 = new Rectangle(0, 0, 3, 4);
	Figure* f4 = new Circle(0, 0, 3);
	Figure* f5 = new Circle(1, 4, 2);

	// operator << and print function check
	os << "Operator << test" << endl;
	os << *f1 << *f2 << *f3 << *f4 << *f5 << endl;

	os << "Print test" << endl;
	//f->print(os);
	f1->print(os);
	f2->print(os);
	f3->print(os);
	f4->print(os);
	f5->print(os);
	os << endl;

	// shift check
	os << "Shift test" << endl;
	//f->shift(2, 1);
	f1->shift(-1, 1);
	f2->shift(0, 0);
	f3->shift(10, 310);
	f4->shift(1, -1);
	f5->shift(2, 3);

	os << *f1 << *f2 << *f3 << *f4 << *f5 << endl;

	// Destructor test
	//delete f;
	delete r;
	delete c;
	delete f1;
	delete f2;
	delete f3;
	delete f4;
	delete f5;

	/*
	Figure* r1 = new Rectangle(0, 0, 5, 4);
	Figure* r2 = new Rectangle(-1, -3, 2, 3);
	Figure* c1 = new Circle(0, 0, 3);
	Figure* c2 = new Circle(1, 3, 9);

	cout << *r1 << *r2 << *c1 << *c2 << endl;

	r1->shift(-1, -1);
	r2->shift(1, 3);
	c1->shift(3, 3);
	c2->shift(-1, -3);

	cout << *r1 << *r2 << *c1 << *c2 << endl;

	delete r1;
	delete r2;
	delete c1;
	delete c2;
	*/

	os.close();
	return 0;
}