#include "HW2_Calculator.h"
#include <iostream>
using namespace std;

int main() {

	Calculator a("(2+5)*3^(2+1)");
	cout << "Calculate (2+5)*3^(2+1)" << endl;
	cout << "Postfix : " << a.getPostfixExp() << endl; // "25+321+^*"
	cout << "Result : " << a.calculate() << endl << endl; // 189

	a.setWeight('+', 3);
	a.setWeight('-', 3);
	a.setWeight('*', 2);
	a.setWeight('/', 2);
	a.setWeight('^', 1);
	cout << "Calculate (2+5)*3^(2+1)" << endl;
	cout << "Postfix : " << a.getPostfixExp() << endl; // "25+3*21+^"
	cout << "Result : " << a.calculate() << endl << endl; // 9261

	Calculator c("3/2*6");
	cout << "Calculate 3/2*6" << endl;
	cout << "Postfix : " << c.getPostfixExp() << endl; // "32/6*"
	cout << "Result : " << c.calculate() << endl << endl; // 6
	
	c.setInfixExp("3*6/2");
	cout << "Calculate 3*6/2" << endl;
	cout << "Postfix : " << c.getPostfixExp() << endl; // "36*2/"
	cout << "Result : " << c.calculate() << endl << endl; // 9

	c.setInfixExp("(3*(6/2))");
	cout << "Calculate (3*(6/2))" << endl;
	cout << "Postfix : " << c.getPostfixExp() << endl; // "362/*"
	cout << "Result : " << c.calculate() << endl << endl; // 9

	c.setInfixExp("7^3/8+4*5*6-3/2+(4+7)*5/(3-2)");
	cout << "Calculate 7^3/8+4*5*6-3/2+(4+7)*5/(3-2)" << endl;
	cout << "Postfix : " << c.getPostfixExp() << endl; // "362/*"
	cout << "Result : " << c.calculate() << endl << endl; // 216

	c.setInfixExp("2");
	cout << "Calculate 2" << endl;
	cout << "Postfix : " << c.getPostfixExp() << endl; // "362/*"
	cout << "Result : " << c.calculate() << endl << endl; // 9

	c.setInfixExp("2+5^1-3*3");
	cout << "Calculate 2+5^0-3*3" << endl;
	cout << "Postfix : " << c.getPostfixExp() << endl; // "362/*"
	cout << "Result : " << c.calculate() << endl << endl; // 9


	return 0;
}