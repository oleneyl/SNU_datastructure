#include <crtdbg.h>
#include <fstream>
#include "HW1_Complex.h"
#include "HW1_Complex.cpp"

int main() {
	ofstream os;
	os.open("result.txt");
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	// Constructor test
	Complex<int> c1;
	Complex<float> c2;
	Complex<double> c3;
	Complex<int> c4(1, -3);
	Complex<int> c5(0, 0);
	Complex<float> c6(3.2, -1.5);
	Complex<double> c7(1.4, 6.2);

	os << "Constructor test" << endl;
	os << c1 << c2 << c3 << c4 << c5 << c6 << c7 << endl;

	// Operator+ test
	Complex<int> a(0, 0);
	Complex<int> b(1, 3);
	Complex<int> c(3, 5);

	os << "Operator+ int test" << endl;
	os << a + b << b + a << b + c << a + c << a + b + c << b + c + a << endl;

	Complex<double> d(1.4, 2.6);
	Complex<double> e(2.4, 5.4);
	Complex<double> f(1.2, 1.5);

	os << "Operator+ double test" << endl;
	os << d + e << e + d << e + f << f + d << d + e + f << e + f + d << endl;

	// Operator- test

	os << "Operator- int test" << endl;
	os << a - b << b - a << b - c << c - b << c - a << a - c << a - b - c << c - b - a << b - a - c << endl;
	os << "Operator- double test" << endl;
	os << d - e << e - d << e - f << f - e << f - d << d - f << d - e - f << f - e - d << e - d - f << endl;

	// Operator* test

	os << "Operator* int test" << endl;
	os << a * b << b * a << b * c << c * a << a * b * c << c * a * b << endl;
	os << "Operator* double test" << endl;
	os << d * e << e * d << e * f << f * d << d * e * f << f * d * e << endl;

	// Operator~ test
	os << "Operator~ test" << endl;
	os << ~a << ~b << ~c << ~d << ~e << ~f << endl;

	// Operator mix test
	os << "Operator mix int test" << endl;
	os << ~(a + b) << ~(b * c) << a + b * c << ~(c - b * a) << endl;
	os << "Operator mix double test" << endl;
	os << d + ~(e * f) << d - e + ~f << ~(e * f - d) << endl;

	// solveQuadratic test
	Complex<double> x1, x2;
	int a1 = 3, a2 = 2, a3 = 1;
	solveQuadratic(x1, x2, a1, a2, a3);
	os << "The solution of " << a1 << "x^2 + " << a2 << "x + " << a3 << " = 0 : " << endl;
	os << x1 << x2;

	a1 = 2, a2 = 1, a3 = 0;
	solveQuadratic(x1, x2, a1, a2, a3);
	os << "The solution of " << a1 << "x^2 + " << a2 << "x + " << a3 << " = 0 : " << endl;
	os << x1 << x2;

	a1 = -1, a2 = 3, a3 = 2;
	solveQuadratic(x1, x2, a1, a2, a3);
	os << "The solution of " << a1 << "x^2 + " << a2 << "x + " << a3 << " = 0 : " << endl;
	os << x1 << x2;

	a1 = 1, a2 = 6, a3 = 9;
	solveQuadratic(x1, x2, a1, a2, a3);
	os << "The solution of " << a1 << "x^2 + " << a2 << "x + " << a3 << " = 0 : " << endl;
	os << x1 << x2;

	a1 = 4, a2 = -12, a3 = 9;
	solveQuadratic(x1, x2, a1, a2, a3);
	os << "The solution of " << a1 << "x^2 + " << a2 << "x + " << a3 << " = 0 : " << endl;
	os << x1 << x2;

	a1 = 1, a2 = 1, a3 = -2;
	solveQuadratic(x1, x2, a1, a2, a3);
	os << "The solution of " << a1 << "x^2 + " << a2 << "x + " << a3 << " = 0 : " << endl;
	os << x1 << x2;

	os.close();



	/*
	Complex<int> a;
	Complex<int> b(5, 3);
	Complex<double> c(2.1542, 7);
	Complex<double> d(-3.2121, -4.6089);

	cout << "a : " << a;
	cout << "b : " << b;
	cout << "c : " << c;
	cout << "d : " << d;

	cout << "a + b : " << a + b;
	cout << "c - d : " << c - d;
	cout << "a * b : " << a * b;
	cout << "d * c : " << d * c;

	cout << endl;

	Complex<double> x1, x2;
	int a1 = 1, a2 = 4, a3 = 3;
	solveQuadratic(x1, x2, a1, a2, a3);
	cout << "The solution of " << a1 << "x^2 + " << a2 << "x + " << a3 << " = 0 : " << endl;
	cout << x1 << x2;

	a3 = 4;
	solveQuadratic(x1, x2, a1, a2, a3);
	cout << "The solution of " << a1 << "x^2 + " << a2 << "x + " << a3 << " = 0 : " << endl;
	cout << x1 << x2;

	a3 = 5;
	solveQuadratic(x1, x2, a1, a2, a3);
	cout << "The solution of " << a1 << "x^2 + " << a2 << "x + " << a3 << " = 0 : " << endl;
	cout << x1 << x2;
	*/

	return 0;
}