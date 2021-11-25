#include "rational.h"
#include <iostream>

void Rational::square() {
	int num = numer;
	double x = double(num) / 2;
	double prev = 0, cur = x;
	while (x != 0) {
		double res = 0.5 * (x + double(num) / x);
		res = round(res * 1000) / 1000;
		prev = cur;
		cur = res;
		if (cur == prev) {
			num = res * 1000;
			break;
		}
		x = res;
	}
	numer = num;
	num = denom;
	x = double(num) / 2;
	prev = 0, cur = x;
	while (x != 0) {
		double res = 0.5 * (x + double(num) / x);
		res = round(res * 1000) / 1000;
		prev = cur;
		cur = res;
		if (cur == prev) {
			num = res * 1000;
			break;
		}
		x = res;
	}
	denom = num;
}
void Rational::simplify() {
	if (denom < 0) {
		numer = -numer;
		denom = -denom;
	}
	for (int i = 2; i <= abs(denom) && i <= abs(numer); i++) {
		if (numer % i == 0 && denom % i == 0) {
			numer /= i;
			denom /= i;
			i--;
		}
	}
}
Rational::Rational() {
	numer = 0;
	denom = 1;
}
Rational::Rational(int n) {
	numer = n;
	denom = 1;
}
Rational::Rational(int n, int d) {
	numer = n;
	denom = d;
	simplify();
}
Rational& Rational::operator +=(const Rational& r) {
	numer = (numer * r.denom + denom * r.numer);
	denom *= r.denom;
	simplify();
	return *this;
}
Rational Rational::operator +(const Rational& r) const {
	Rational res(*this);
	return res += r;
}
Rational& Rational::operator *=(const Rational& r) {
	numer *= r.numer;
	denom *= r.denom;
	simplify();
	return *this;
}
Rational Rational::operator *(const Rational& r) const {
	Rational res(*this);
	return res *= r;
}
Rational Rational::operator *(const double val) {
	Rational res(*this);
	res.numer *= val;
	return res;
}
Rational& Rational::operator -=(const Rational& r) {
	numer = (numer * r.denom - denom * r.numer);
	denom *= r.denom;
	simplify();
	return *this;
}
Rational Rational::operator -(const Rational& r) const {
	Rational res(*this);
	return res -= r;
};
Rational& Rational::operator /=(const Rational& r) {
	numer *= r.denom;
	denom *= r.numer;
	simplify();
	return *this;
}
Rational Rational::operator /(const Rational& r) const {
	Rational res(*this);
	return res /= r;
}
Rational& Rational::operator ++() {
	numer += denom;
	return *this;
}
Rational Rational::operator ++(int) {
	Rational r(*this);
	numer += denom;
	return r;
}
bool Rational::operator ==(const Rational& r) const {
	return (numer == r.numer) && (denom == r.denom);
}
bool Rational::operator !=(const Rational& r) const {
	return !(*this == r);
}
Rational::operator int() const {
	return numer / denom;
}
Rational::operator double() const {
	return ((double)numer) / denom;
}
istream& operator >>(istream& in, Rational& r) {
	in >> r.numer >> r.denom;
	return in;
}
ostream& operator <<(ostream& out, const Rational& r) {
	if (r.denom == 1) {
		out << r.numer;
	}
	else {
		out << r.numer << "/" << r.denom;
	}
	return out;
}