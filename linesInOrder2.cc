#include <iostream>
using namespace std;

int main() {
	int lastLine = -1;
	int n;
	int line = 0;
	while (cin >> n) {
		++line;
		string s, prev;
		if (n < 2) {
			lastLine = line;
			if (n == 1) cin >> s;
		}
		else {
			cin >> s;
			bool correct = true;
			for (int i = 1; i < n; ++i) {
				prev = s;
				cin >> s;
				if (s < prev) correct = false;
			}
			if (correct) lastLine = line;
		}
	}
	if (lastLine == -1) cout << "There is no line in increasing order." << endl;
	else cout << "The last line in increasing order is " << lastLine << "." << endl;
}