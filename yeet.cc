#include <bits/stdc++.h>
using namespace std;

int main(){
	int c = 0;
	for (int i = 1000; i < 10000; ++i) {
		int s = i%10 + (i/10)%10 + i/100;
		if (s == i%100 + 55) {
			++c;
			cout << i << endl;
		}
	}
	cout << c << endl;
}