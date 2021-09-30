#include <iostream>

using namespace std;

class Rational {
	void simplify();
public:
	int num, denom;
	Rational() {
		num = 0;
		denom = 1;
	}
	Rational(int n) {
		num = n;
		denom = 1;
	}
	Rational(int n, int d) {
		num = n;
		denom = d;
		if (d < 0) {
			num *= (-1);
			denom *= (-1);
		}
	}
	Rational& operator = (const Rational& r);
	Rational& operator += (const Rational& r);
	Rational operator + (const Rational& r) const;
};

void Rational::simplify() {
	int a = num, b = denom;
	while (a != 0 && b != 0) {
		if (a > b) {
			a %= b;
		}
		else {
			b %= a;
		}
	}
	num /= (a + b);
	denom /= (a + b);
}
Rational& Rational::operator = (const Rational& other) {
	num = other.num;
	denom = other.denom;
	return *this;
}
Rational& Rational::operator += (const Rational& other) {
	num = (num * other.denom + denom * other.num);
	denom *= other.denom;
	simplify();
	return *this;
}
Rational Rational::operator + (const Rational& r) const {
	Rational res(*this);
	return res += r;
}

int main()
{
	Rational* a = new Rational(1,2);
	Rational* b = new Rational(9,4);
	a = b;
	cout << a->num << "/" << a->denom << endl;
}