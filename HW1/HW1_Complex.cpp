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
	if(im == (T)0){	//Prevent eps value inversion
		return Complex(re, im);
	}else{
		return Complex(re, (T)((T)-1 * im));
	}
}

template <class U>
ostream& operator<< (ostream& os, const Complex<U>& cplx){
	os << '(' << cplx.re;
	if(cplx.im >= (U)(0)){
		os << " + " << cplx.im;
	}else{
		os << " - " << (U)(-1) * cplx.im;
	}
	os << "i)" << endl;
	return os;
}

void solveQuadratic(Complex<double>& x1, Complex<double>& x2, int a, int b, int c){
	int determinant = (b * b - 4 * a * c);
	double firstArg = (double)(b) * -1.0 / (double)(a) / 2.0;
	double secondArg;
	if(determinant >= 0){
		secondArg = sqrt((double)(b) * (double)(b)- 4.0 * (double)(a) * (double)(c)) / (double)(a) / 2.0;
	}else{
		secondArg = sqrt(((double)(b) * (double)(b)- 4.0 * (double)(a) * (double)(c)) * (double)(-1.0)) / (double)(a) / 2.0;
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