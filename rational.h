#ifndef RATIONAL_H_
#define RATIONAL_H_

#include <ostream>

using namespace std;

class Rational{
private:
	int numer;
	int denom;
	void simplify();
public:
	Rational();
	Rational(int n);
	Rational(int n, int d);
	Rational& operator +=(const Rational& r);
	Rational operator +(const Rational& r) const;
	Rational& operator *=(const Rational& r);
	Rational operator *(const Rational& r) const;
	Rational operator *(const double val);
    Rational operator -(const Rational& r) const;
	Rational& operator -=(const Rational& r);
	Rational& operator /=(const Rational& r);
	Rational operator /(const Rational& r) const;
	Rational& operator ++();
	Rational operator ++(int);
	bool operator ==(const Rational& r) const;
	bool operator !=(const Rational& r) const;
	operator int() const;
	operator double() const;
	friend istream& operator >>(istream& in, Rational& r);
	friend ostream& operator <<(ostream& out, const Rational& r);
	void square();
};



#endif /* RATIONAL_H_ */
