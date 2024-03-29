#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<map<char,int>> trie(1), t_hor(1);
const int max_m = 4;
int it [max_m];
int n, m, a, b;
void tr (int u, int i, int cur, int j) {
	if (j == n) return;
	while(u < trie.size()) {
		for (auto x: trie[u]) {
			if (t_hor[cur].find(x.first) == t_hor[cur].end())
				return;
			else {
				it[i] = t_hor[cur][x.first];
				if (i < m) tr(x.second, i+1, it[i+1], j);
				else tr(0, 0, it[0], j+1);
				it[i] = cur;
			}
		}
	}
}

void add_hor(int u, string& s) {
	int i = 0;
	while (i < s.size()) {
		if (t_hor[u].find(s[i]) == t_hor[u].end()) {
			t_hor[u][s[i]] = t_hor.size();
			map<char,int> mp;
			t_hor.push_back(mp);
		}
		u = t_hor[u][s[i]];
		++i;
	}
}
void add_ver(int u, string& s) {
	int i = 0;
	while (i < s.size()) {
		if (trie[u].find(s[i]) == trie[u].end()) {
			trie[u][s[i]] = trie.size();
			map<char,int> mp;
			trie.push_back(mp);
		}
		u = trie[u][s[i]];
		++i;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >>n >> m >> a >> b;
	for (int i = 0; i < a; ++i) {
		string s;
		cin >> s;
		add_ver (0, s);
	}
	for (int i = 0; i < b; ++i) {
		string s;
		cin >> s;
		add_hor(0, s);
	}

	tr (0, 0, 0, 0);
}