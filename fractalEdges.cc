#include <iostream>
#include <math.h>
using namespace std;
#define MOD 32749

/*double lelMod(double n) {
	while (n >= MOD) n-=MOD;
	return n;
}

double modpow(double a, int b) {
  double x=1, y=a; 
    while (b > 0) {
        if (b%2 == 1) {
            x = x*y; // multiplying with base
        }
        y = lelMod(y*y); // squaring the base
        if (b > 1) x = lelMod(x);
        b /= 2;
    }
    return x;
}*/

int main(){
	int n;
	cin >> n;
	if (n == 0) {
		cout << "1 0" << endl;
		return 0;
	}/*
	double LEMAO = (sqrt(double(3)/2) * (modpow(3+sqrt(6), n)))/2;
	--n;
	double LEMAO2 = (sqrt(double(3)/2) * (modpow(3+sqrt(6), n)))/2;
	cout << int(lelMod(LEMAO-LEMAO2+MOD))+1 << ' ' << int(lelMod(LEMAO)) << endl;*/
	int a,b=0,c=3;
	--n;
	while (n--) {
		a = b;
		b = c;
		c = (6*b-3*a)%MOD;
	}
	cout << (c-b+MOD)%MOD << ' ' << c << endl;
}