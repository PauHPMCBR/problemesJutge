#include <bits/stdc++.h>
using namespace std;

int main(){
	double x;
	cin >> x;
	int n = ceil(x/5);
	cout << "- " << n << " natural yogurt." << endl;
	cout << "- " << n*3 << " eggs." << endl;
	cout << "- " << n*250 << "gr flour." << endl;
	cout << "- " << 125*n << "gr cocoa powder." << endl;
	cout << "- " << 250*n << "gr sugar." << endl;
	cout << "- " << 125*n << "gr olive oil." << endl;
	cout << "- " << n << " packet of yeast." << endl;
}