#include <bits/stdc++.h>
using namespace std;

int main(){
	chrono::steady_clock::time_point cBegin = chrono::steady_clock::now();
	for (int i = 0; i < 1000000; ++i) {
		cout << 1 << '\n';
	}
	chrono::steady_clock::time_point cEnd = chrono::steady_clock::now();
	int diff = chrono::duration_cast<chrono::milliseconds>(cEnd-cBegin).count();
	cout << diff << '\n';
}

//2700 vs 42