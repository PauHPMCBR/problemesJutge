#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while (cin >> n) {
		vector<int>a(n);
		vector<int>b(n);
		map<int,int>m;
		int p;
		for (int i = 0; i < n; ++i) {
			cin >> a[i] >> p;
			m.insert(make_pair(a[i], p));
		}
		sort(a.begin(), a.end());
		for (int i = 0; i < n; ++i) {
			b[i] = m[a[i]];
		}



		int max = 0;
		int t = 0, ct = 0, st = 0;
		int count = 0;
		int i = 0, j = 0;
		while (i < n || j < n) {
			if (i == n) {
				ct = b[j];
				if (st != 0) {
					int prov = st-ct;
					if (prov < t) t = prov;
					st = 0;
				}
				else if (count == max) {
					t -= ct;
				}
				j = n;
			}
			else if (a[i] < b[j] || j == n) {
				ct = a[i];
				++count;
				if (max < count) {max = count; t = ct;}
				else if (max == count) st = ct;
				++i;
			}
			else {
				ct = b[j];
				if (st != 0) {
					int prov = st-ct;
					if (prov < t) t = prov;
					st = 0;
				}
				else if (count == max) {t -= ct;}

				--count;
				++j;
			}

		}
		cout << max << ' ' << t*-1 << endl;

	}
}