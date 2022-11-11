#include <iostream>
using namespace std;

void infoSequence(int& max, int& lpos) {
	max = 0;
	lpos = 0;
	int x;
	int pos = 1;
	cin >> x;
	while (x != 0) {
		if (x >= max) {
			max = x;
			lpos = pos;
		}
		++pos;
		cin >> x;
	}
}

int main() {
	int max, lpos;
	infoSequence(max, lpos);
	int x;
	cin >> x;
	int pos = 1;
	int fpos = -1;
	while (x != 0 and fpos == -1) {
		if (x == max) fpos = pos;
		++pos;
		cin >> x;
	}
	cout << max << ' ' << lpos << ' ';
	if (fpos == -1) cout << '-' << endl;
	else cout << fpos << endl;
}