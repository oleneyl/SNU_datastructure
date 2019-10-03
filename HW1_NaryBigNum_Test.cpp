#include "HW1_NaryBigNum.h"

NaryBigNum::NaryBigNum(){
	number=NULL;
	size=0;
	base=0;
}

NaryBigNum::NaryBigNum(int n, string num){
	char tempChar;
	int i;
	int convertedNumber = 0;
	
	int nonZeroPosition = 0;
	while(nonZeroPosition < num.size() - 1 && num.at(nonZeroPosition) == '0'){
		nonZeroPosition += 1;
	}
	string shortenNum = num.substr(nonZeroPosition, num.size());
	// Initialization
	number = new char[shortenNum.size()];
	size = shortenNum.size();
	// Base handling
	base = n;
	if(base < 2 || base > 36){
		base = 10;
	}

	/* TODO : 앞에오는 0 처리하기*/

	for(i = 0; i < shortenNum.size(); i++){
		tempChar = shortenNum.at(i);
		if(tempChar>=97 && tempChar<123){
			tempChar = tempChar - 32;
		}	// To uppercase
		// If non-convertable
		if(!((48<=tempChar && tempChar<=57) || (65<=tempChar && tempChar<=90)) ){
			tempChar = '0';
		}else{
			if(48<=tempChar && tempChar<=57){
				convertedNumber = tempChar - 48;
			}else{
				convertedNumber = tempChar - 65 + 10;
			}
			if(convertedNumber >= base){
				tempChar = '0';
			}else{
				// Validation chekcing OK so we can use general API
				tempChar = baseToChar(convertedNumber, base);
			}
		}
		number[i] = tempChar;
	}
}

NaryBigNum::NaryBigNum(const NaryBigNum& prev){
	number = new char[prev.size];
	size = prev.size;
	base = prev.base;
	for(int i=0;i<size;i++){
		number[i]=prev.number[i];
	}	
}

NaryBigNum::~NaryBigNum(){
	delete number;
	size=0;
	base=10;
}

int NaryBigNum::getSize() const{
	return size;
}

char NaryBigNum::safeAccessCharacterAt(int index) const{
	if(index >= size || index < 0){
		return '0';
	}else{
		return number[size - index - 1];
	}
}

NaryBigNum NaryBigNum::shiftAs(int shift) const{
	string s;
	for(int i=0; i<size; i++){
		s.append(1, number[i]);
	}
	s.append(shift, '0');
	return NaryBigNum(base, s);
}

NaryBigNum NaryBigNum::multiplyChar(char mux) const{
	string outputBuffer;
	string reversedBuffer;
	int currentPointer = 0;
	int currentOverFlow = 0;
	int currentSum = 0;
	char from_mine;
	while(true){
		if(getSize() <= currentPointer && currentOverFlow == 0){
			break;
		}
		from_mine = safeAccessCharacterAt(currentPointer);
		currentSum = charToBase(from_mine, base) * charToBase(mux, base) + currentOverFlow;
		currentOverFlow = currentSum / base;
		currentPointer += 1;
		outputBuffer.append(1, baseToChar(currentSum % base, base));
	}
	for(int i=0; i<outputBuffer.size(); i++){
		reversedBuffer.append(1, outputBuffer.at(outputBuffer.size() - i-1));
	}
	return NaryBigNum(base, reversedBuffer);
}

NaryBigNum NaryBigNum::operator+(const NaryBigNum& arg){
	string outputBuffer;
	string reversedBuffer;
	int currentPointer = 0;
	int currentOverFlow = 0;
	int currentSum = 0;
	char from_arg, from_mine;
	while(true){
		if(currentPointer >= arg.getSize() && currentPointer >= getSize() && currentOverFlow == 0){
			break;
		}
		from_arg = arg.safeAccessCharacterAt(currentPointer);
		from_mine = safeAccessCharacterAt(currentPointer);
		//cout << from_arg << ' ' << from_mine << ' ' << getSize() << ' ' << arg.getSize() << endl;
		currentSum = charToBase(from_arg, base) + charToBase(from_mine, base) + currentOverFlow;
		currentOverFlow = currentSum / base;
		outputBuffer.append(1, baseToChar(currentSum % base, base));
		currentPointer += 1;
	}
	for(int i=0; i<outputBuffer.size(); i++){
		reversedBuffer.append(1, outputBuffer.at(outputBuffer.size() - i-1));
	}
	return NaryBigNum(base, reversedBuffer);
}

NaryBigNum& NaryBigNum::operator=(const NaryBigNum& arg){
	delete number;
	size = arg.size;
	base = arg.base;
	number = new char[size];
	for(int i=0; i<size; i++){
		number[i] = arg.number[i];
	}
}

NaryBigNum NaryBigNum::operator*(const NaryBigNum& arg){
	NaryBigNum output = NaryBigNum(base, "0");
	for(int i=0; i < size; i++){
		output = output + arg.shiftAs(i).multiplyChar(safeAccessCharacterAt(i));
	}
	return output;
}

ostream& operator<<(ostream& os, const NaryBigNum& arg){
	for(int i=0; i<arg.getSize(); i++){
		os << arg.number[i];
	}
	os << "(" << arg.base << ")";
	return os;
}

// For convenient calculation
int charToBase(char a, int base){
	if(48<=a && a<=57){
		return (int)(a-48);
	}else{
		return (int)(a-65 + 10);
	}
}

char baseToChar(int a, int base){
	if(a < 10){
		return (char)(a+48);
	}else{
		return (char)(a+65 - 10);
	}
}



int main() {
	NaryBigNum a(16, "3G@36");
	NaryBigNum b(16, "c6C77");
	NaryBigNum c(8, "1941");
	NaryBigNum d(8, "1554A12");

	cout << "a : " << a << endl;
	cout << "b : " << b << endl;
	cout << "c : " << c << endl;
	cout << "d : " << d << endl;

	NaryBigNum e = a + b;
	cout << "a + b : " << e << endl;

	NaryBigNum f(a * b);
	cout << "a * b : " << f << endl;

	NaryBigNum g;
	g = c + d;
	cout << "c + d : " << g << endl;

	cout << "c * d : " << c * d << endl;

	return 0;
}