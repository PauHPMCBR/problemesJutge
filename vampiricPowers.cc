#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Trie {
	Trie* z;
	Trie* o;

	void add(int n, int depth) {
		cout << depth << endl;
		if (depth == -1) return;
		if ((n>>depth & 1) == 1) {
			if (o == nullptr) o = new Trie;
			o->add(n, depth-1);
		}
		else {
			if (z == nullptr) z = new Trie;
			z->add(n, depth-1);
		}
	}

	int get(int n, int depth) {
		if (depth == -1) return 0;
		if ((n>>depth & 1) == 1) {
			if (z != nullptr) return z->get(n, depth-1);
			return o->get(n, depth-1) | (1<<depth);
		}
		else {
			if (o != nullptr) return o->get(n, depth-1) | (1<<depth);
			return z->get(n, depth-1);
		}
	}
};

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		int ans = 0, curr = 0;
		Trie t;
		t.add(0, 9);

		vector<int>v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
			curr ^= v[i];
			ans = max(ans, t.get(curr, 9) ^ curr);
			t.add(curr, 9);
		}

		cout << ans << endl;

	}
}