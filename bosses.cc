#include <bits/stdc++.h>
using namespace std;

int main(){
	int b=0,c=0;
	for (int i = 1; i < 6; ++i) {
		for (int j = 1; j < 6; ++j) {
			for (int k = 1; k < 6; ++k) {
				cout << i << ' ' << j << ' ' << k << ' ' << i*j+k << endl;
				if ((i*j+k) % 2 == 0) {
					++c;
					cout << "tafac" << endl;
				}
				++b;
			}
		}
	}
	cout << b << ' ' << c << endl;
}