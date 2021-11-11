#include "rational.h"
#include <iostream>
#include <cmath>

using namespace std;

void Rational::square(){
	int num = numer;
	double x = double(num) / 2;
	double prev = 0, cur = x;
	while (x != 0){
		double res = 0.5*(x+double(num)/x);
		res = round(res*1000)/1000;
		prev = cur;
		cur = res;
		if (cur == prev){
			num = res*1000;
			break;
		}
		x = res;
	}
	numer = num;
	num = denom;
	x = double(num) / 2;
	prev = 0, cur = x;
	while (x != 0){
		double res = 0.5*(x+double(num)/x);
		res = round(res*1000)/1000;
		prev = cur;
		cur = res;
		if (cur == prev){
			num = res*1000;
			break;
		}
		x = res;
	}
	denom = num;
}
void Rational::simplify(){
	if (denom < 0){
		numer = -numer;
		denom = -denom;
	}
	for (int i = 2; i <= abs(denom) && i <= abs(numer); i++){
		if (numer % i == 0 && denom % i == 0) {
			numer /= i;
			denom /= i;
			i--;
		}
	}
}
Rational::Rational(){
	numer = 0;
	denom = 1;
}
Rational::Rational(int n){
	numer = n;
	denom = 1;
}
Rational::Rational(int n, int d){
	numer = n;
	denom = d;
	simplify();
}
Rational& Rational::operator +=(const Rational& r){
	numer = (numer * r.denom + denom * r.numer);
	denom *= r.denom;
	simplify();
	return *this;
}
Rational Rational::operator +(const Rational& r) const {
	Rational res(*this);
	return res += r;
}
Rational& Rational::operator *=(const Rational& r){
	numer *= r.numer;
	denom *= r.denom;
	simplify();
	return *this;
}
Rational Rational::operator *(const Rational &r) const{
	Rational res(*this);
	return res *= r;
}
Rational Rational::operator *(const double val){
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
	Rational res (*this);
	return res -= r;
};
Rational& Rational::operator /=(const Rational& r) {
	numer *= r.denom;
	denom *= r.numer;
	simplify();
	return *this;
}
Rational Rational::operator /(const Rational& r) const{
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
	return (numer==r.numer) && (denom==r.denom);
}
bool Rational::operator !=(const Rational& r) const {
	return !(*this==r);
}
Rational::operator int() const {
	return numer / denom;
}
Rational::operator double() const {
	return ((double)numer)/denom;
}
istream& operator >>(istream& in, Rational& r) {
	in >> r.numer >> r.denom;
	return in;
}
ostream& operator <<(ostream& out, const Rational& r){
	if (r.denom == 1) {
		out << r.numer;
	}
	else{
		out << r.numer << "/" << r.denom;
	}
	return out;
}



int main() {
	Rational a, b, c;
	Rational x1, x2;
	cout<<"Enter a"<<endl;
	cin>>a;
	cout<<"Enter b"<<endl;
	cin>>b;
	cout<<"Enter c"<<endl;
	cin>>c;
	Rational D = a*c;
	D *= (-4);
	D += b*b;
	D.square();
	x1 = (D - b)/a;
	b *= (-1);
	x2 = (b - D)/a;
	cout<<x1*0.5<<endl;
	cout<<x2*0.5<<endl;
}
