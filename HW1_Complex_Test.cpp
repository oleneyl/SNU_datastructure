#include "HW1_Complex.h"
#include "math.h"

template <class T>
Complex<T>::Complex(T a, T b){
	re = a;
	im = b;
}

template <class T>
Complex<T>::Complex(){
	re = (T)0;
	im = (T)0;
}

template <class T>
Complex<T> Complex<T>::operator+(const Complex& arg){
	return Complex(re + arg.re, im + arg.im);
}

template <class T>
Complex<T> Complex<T>::operator-(const Complex& arg){
	return Complex(re - arg.re, im - arg.im);
}

template <class T>
Complex<T> Complex<T>::operator*(const Complex& arg){
	return Complex(re * arg.re - im * arg.im, re * arg.im + im * arg.re);
}

template <class T>
Complex<T> Complex<T>::operator~() const {
	return Complex(re, (T)(-1 * im));
}

template <class U>
ostream& operator<< (ostream& os, const Complex<U>& cplx){
	os << '(' << cplx.re;
	if(cplx.im >= 0){
		os << " + " << cplx.im;
	}else{
		os << " - " << (U)(-1 * cplx.im);
	}
	os << "i)" << endl;
	return os;
}

void solveQuadratic(Complex<double>& x1, Complex<double>& x2, int a, int b, int c){
	int determinant = (b * b - 4 * a * c);
	double firstArg = (double)(b) * -1.0 / (double)(a) / 2.0;
	double secondArg;
	if(determinant >= 0){
		secondArg = sqrt((double)(b * b - 4 * a * c)) / (double)(a) / 2.0;
	}else{
		secondArg = sqrt((double)(b * b - 4 * a * c) * -1.0) / (double)(a) / 2.0;
	}
	if(determinant > 0){
		x1 = Complex<double>(firstArg + secondArg, 0.0);
		x2 = Complex<double>(firstArg - secondArg, 0.0);
	}else if(determinant == 0){
		x1 = Complex<double>(firstArg, 0.0);
		x2 = Complex<double>(firstArg, 0.0);
	}else{
		x1 = Complex<double>(firstArg, secondArg);
		x2 = Complex<double>(firstArg, secondArg * -1);
	}
}

int main() {
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


	return 0;
}