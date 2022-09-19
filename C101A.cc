#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a, b, c;
	a = n%10;
	b = (n%100)/10;
	c = (n%1000)/100;
	cout << a+b+c << endl;
}