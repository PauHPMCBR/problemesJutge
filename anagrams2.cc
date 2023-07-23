#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		vector<int>v(26);
		char c;
		cin >> c;
		while (c != '.') {
			if (c <= 'Z' and c >= 'A') ++v[c-'A'];
			cin >> c;
		}

		cin >> c;
		while (c != '.') {
			if (c <= 'Z' and c >= 'A') --v[c-'A'];
			cin >> c;
		}

		bool anagram = true;
		for (int j = 0; j < 26; ++j) if (v[j] != 0) anagram = false;
		cout << (anagram ? "YES" : "NO") << endl;
	}
}