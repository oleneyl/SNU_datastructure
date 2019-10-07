#ifndef NARYBIGNUM_H
#define NARYBIGNUM_H

#include <iostream>
#include <string>

using namespace std;

class NaryBigNum {
private:
	char *number;
	int size;
	int base;
public:
	NaryBigNum();
	NaryBigNum(int, string);
	NaryBigNum(const NaryBigNum&);
	~NaryBigNum();
	NaryBigNum operator+(const NaryBigNum&);
	NaryBigNum& operator=(const NaryBigNum&);
	NaryBigNum operator*(const NaryBigNum&);
	friend ostream& operator<< (ostream&, const NaryBigNum&);
	int getSize() const;
	char safeAccessCharacterAt(int) const;
	NaryBigNum shiftAs(int) const;
	NaryBigNum multiplyChar(char) const;
};

int charToBase(char, int);
char baseToChar(int, int);
#endif NARYBIGNUM_H