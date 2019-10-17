#include "HW2_Calculator.h"
#include "HW2_Stack.h"

Calculator::Calculator(string str) {
	exp_infix = str;
	w_add = 1;
	w_sub = 1;
	w_mult = 2;
	w_div = 2;
	w_pow = 4;
}

void Calculator::setInfixExp(string str) {
	exp_infix = str;
}

void Calculator::setWeight(char op, int w) {
	switch (op) {
		case '+':
			w_add = w;
			break;
		case '-':
			w_sub = w;
			break;
		case '*':
			w_mult = w;
			break;
		case '/' : 
			w_div = w;
			break;
		case '^':
			w_pow = w;
			break;
		default:
			break;
	}
}

bool isOperand(char ch) {
	return (('0' <= ch) && ('9' >= ch));
}

int Calculator::comparePriority(char op1, char op2) const {
	if (op1 == '(' || op2 == ')') {
		return 1;
	}
	else if (op1 == ')' || op2 == '(') {
		return -1;
	}else{
		if (getPriority(op1) > getPriority(op2)) {
			return -1;
		}else if (getPriority(op1) < getPriority(op2)) {
			return 1;
		}
		else {
			return 0;
		}
	}
}

int Calculator::getPriority(char op) const {
	switch (op) {
	case '+':
		return w_add;
	case '-':
		return w_sub;
	case '*':
		return w_mult;
	case '/':
		return w_div;
	case '^':
		return w_pow;
	default:
		return 0;
	}
}

string Calculator::getPostfixExp() const {
	Stack<char> operators;
	string output_string;
	char ch;
	int size = exp_infix.size();
	for (int i = 0; i < size; i++) {
		ch = exp_infix.at(i);
		//cout << ch << ", " << output_string << endl;
		//operators.print();
		if (isOperand(ch)) {
			output_string.push_back(ch);
		} else { // operators
			if (operators.isEmpty() || ch == '(') {
				operators.push(ch);
			}
			else if (ch == ')') { // () processing
				while (operators.getTop() != '(') {
					output_string.push_back(operators.pop());
				}
				operators.pop(); // Remove '('
			}else{
				while (!operators.isEmpty() && comparePriority(operators.getTop(), ch) <= 0) {
					output_string.push_back(operators.pop());
				}
				operators.push(ch);
			}
		}
	}
	while (!operators.isEmpty()) {
		output_string.push_back(operators.pop());
	}
	return output_string;
}

int Calculator::calcTwoOperands(int operand1, int operand2, char op) const {
	int output = 1;
	int i = 1;
	switch (op) {
	case '+':
		return operand1 + operand2;
	case '-':
		return operand1 - operand2;
	case '*':
		return operand1 * operand2;
	case '/':
		return operand1 / operand2;
	case '^':
		for (i = 0; i < operand2; i++) {
			output *= operand1;
		}
		return output;
	default:
		return 111111111;
	}
}

int Calculator::calculate() {
	string postfix = getPostfixExp();
	Stack<int> operands;
	int size = postfix.size();
	char ch;
	int operand1, operand2;
	for (int i = 0; i < size; i++) {
		ch = postfix.at(i);
		if (isOperand(ch)) {
			operands.push((int)(ch - '0'));
		}
		else {
			operand2 = operands.pop();
			operand1 = operands.pop();
			operands.push(calcTwoOperands(operand1, operand2, ch));
		}
	}
	return operands.pop();
}