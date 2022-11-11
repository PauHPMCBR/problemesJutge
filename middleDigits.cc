#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	char win = '=';
	cin >> n;
	char prevDig = -1;
	for (int i = 0; i < 2*n and win == '='; ++i) {
		int prov;
		cin >> prov;
		if (int(log10(prov))%2 == 1) win = (i%2==0 ? 'B' : 'A');
		else {
			int l = int(log10(prov)+1)/2;
			for (int j = 0; j < l; ++j) prov /= 10;
			if (prevDig == -1) prevDig = prov%10;
			else if (prevDig != prov%10) win = (i%2==0 ? 'B' : 'A');
		}
	}
	cout << win << endl;
}