#include "rational.h"
#include <iostream>
#include <cmath>

using namespace std;

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
