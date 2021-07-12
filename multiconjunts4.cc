#include <bits/stdc++.h>
using namespace std;

vector<int>w;
int n, t, x, y;

void escriu() {
	cout << '{';
	bool firstDone = false;
	for (int i = 0; i < n; ++i) {
        for (int j = 0; j < w[i]; ++j) {
            if (!firstDone) firstDone = true;
            else cout << ',';
            cout << i+1;
        }
	}
	cout << '}' << endl;
}

void backtrack(int pos, int s) {
    if (s + x*(n-pos) > t) return;
    if (s + y*(n-pos) < t) return;
	if (pos == n) {
        if (s != t) return;
        return escriu();
    }
	for (int i = x; i <= y; ++i) {
        w[pos] = i;
        backtrack(pos+1, s+i);
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin >> n >> x >> y >> t;
    w = vector<int>(n);
	backtrack(0,0);
}
