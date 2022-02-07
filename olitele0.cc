#include <bits/stdc++.h>
using namespace std;

int main(){
	int sols = 0;
	for (int i = -10000; i <= 10000; ++i) {
		if (abs(2021 - abs(i)) <= 2022) ++sols;
	}
	cout << sols << endl;
}