#include <iostream>
using namespace std;

int main() {
	int firstLine = -1;
	int n;
	int line = 0;
	while (cin >> n and firstLine == -1) {
		++line;
		string s, prev;
		if (n < 2) firstLine = line;
		else {
			cin >> s;
			bool correct = true;
			for (int i = 1; i < n; ++i) {
				prev = s;
				cin >> s;
				if (s < prev) correct = false;
			}
			if (correct) firstLine = line;
		}
	}
	if (firstLine == -1) cout << "There is no line in increasing order." << endl;
	else cout << "The first line in increasing order is " << firstLine << "." << endl;
}