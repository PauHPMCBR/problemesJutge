#include <bits/stdc++.h>
using namespace std;

int main(){
	int b=0, c=0;
	for (int i = 1; i < 7; ++i) {
		for (int j = 1; j < 7; ++j) {
			for (int k = 1; k < 7; ++k) {
				for (int l = 1; l < 7; ++l) {
					if (i*j*k*l == 48) ++c;
					++b;
				}
			}
		}
	}
	cout << double(c)/double(b) << ' ' << c << ' ' << b << endl;
}