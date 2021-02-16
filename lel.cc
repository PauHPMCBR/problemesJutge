#include <bits/stdc++.h>
using namespace std;

int main(){
	int pos = 0;
	for (int i = 0; i < 200; i+=2) {
		for (int j = 0; j < i; ++j) {
			++pos;
			if (pos == 2016) cout << i << endl;
		}
	}
}