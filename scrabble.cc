#include <bits/stdc++.h>
using namespace std;

bool possible(string word, multiset<char> s, int pos) {
	if (pos == word.size()) return true;
	if (s.find(word[pos]) != s.end()) {
		s.erase(s.find(word[pos]));
		return possible(word, s, pos+1);
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<string>v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	multiset<char>s;
	char prov;
	while (cin >> prov) s.insert(prov);
	int maxLength = 0;
	for (auto word : v) {

		if (possible(word, s, 0)) {
			int mobe = word.size();
			if (mobe > 3) mobe *= 2;
			maxLength = max(maxLength, mobe);
		}
	}
	cout << maxLength << endl;
}