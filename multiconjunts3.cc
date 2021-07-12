#include <bits/stdc++.h>
using namespace std;

vector<int>v;
int n, m;

void escriu() {
	cout << '{';
	bool firstDone = false;
	for (int i = n-1; i >= 0; --i) {
		if (!firstDone) firstDone = true;
        else cout << ',';
		cout << v[i];
	}
	cout << '}' << endl;
}

void backtrack(int pos, int last) {
	if (pos == n) return escriu();
	for (int i = 1; i <= last; ++i) {
        v[pos] = i;
        backtrack(pos+1, i);
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin >> m >> n;
	v = vector<int>(n);
	backtrack(0, m);
}
