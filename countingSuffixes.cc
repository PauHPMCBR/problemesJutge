#include <bits/stdc++.h>
using namespace std;

struct Counting {
	bool hasEnding = false;
	int n = 0;
	map<char, Counting*> nodes;

	bool insert(string s) {
		if (s == "") {
			if (!hasEnding) {
				hasEnding = true;
				++n;
				return true;
			}
			return false;
		}
		else {
			char c = s[s.size()-1];
			s.pop_back();
			if (nodes.count(c)) {
				if (nodes[c]->insert(s)) {
					++n;
					return true;
				}
			}
			else {
				nodes[c] = new Counting;
				nodes[c]->insert(s);
				++n;
				return true;
			}
		}
		return false;
	}

	bool erase(string s) {
		if (s == "") {
			if (hasEnding) {
				--n;
				hasEnding = false;
				return true;
			}
		}
		else {
			char c = s[s.size()-1];
			s.pop_back();
			if (nodes.count(c)) {
				if (nodes[c]->erase(s)) {
					if (nodes[c] == nullptr or nodes[c]->n == 0) {
						delete nodes[c];
						nodes.erase(c);
					}
					--n;
					return true;
				}
			}
		}
		return false;
	}

	int count(string s) {
		if (s == "") return n;
		char c = s[s.size()-1];
		s.pop_back();
		if (nodes.count(c)) return nodes[c]->count(s);
		return 0;
	}

	void reset() {
		for (auto i : nodes) i.second->reset();
		nodes.erase(nodes.begin(), nodes.end());
		delete this;
	}
};

int main() {
	Counting* cnt = new Counting;
	char c;
	string s;
	while (cin >> c) {
		if (c == 'R') {
			cnt->reset();
			cnt = new Counting;
			cout << "---" << endl;
		}
		else if (c == 'I') {
			cin >> s;
			cnt->insert(s);
		}
		else if (c == 'E') {
			cin >> s;
			cnt->erase(s);
		}
		else {
			cin >> s;
			cout << cnt->count(s) << endl;
		}
	}
}