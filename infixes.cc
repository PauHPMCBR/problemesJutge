#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool contains(string s1, string s2) {
	if (s1.size() < s2.size()) return false;
	for (int i = 0; i < s1.size(); ++i) {
		int j = 0;
		while (j < s2.size() and i+j < s1.size() and s1[i+j] == s2[j]) ++j;
		if (j == s2.size()) return true;
	}
	return false;
}

int main() {
	int n;
	cin >> n;
	vector<string>v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	for (int i = 0; i < n; ++i) {
		cout << v[i] << ":";
		for (int j = 0; j < n; ++j) {
			if (contains(v[i], v[j])) cout << ' ' << v[j];
		}
		cout << endl;
	}
}