#include <iostream>
#include <vector>
using namespace std;

int main() {
	string s;
	while (cin >> s) {
		bool correct = true;
		int p = 0, k = 0;
		vector<char>v(s.size());
		int ind = 0;
		for (int i = 0; i < s.size() and correct; ++i) {
			if (s[i] == '(') {
				++p;
				++ind;
				v[ind] = '(';
			}
			else if (s[i] == ')') {
				--p;
				if (v[ind] != '(') correct = false;
				--ind;
			}
			else if (s[i] == '[') {
				++k;
				++ind;
				v[ind] = '[';
			}
			else {
				--k;
				if (v[ind] != '[') correct = false;
				--ind;
			}
			if (p < 0 or k < 0) correct = false;
		}
		if (p != 0 or k != 0) correct = false;
		cout << (correct ? "yes" : "no") << endl;
	}
}