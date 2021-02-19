#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(cin >> n) {
		vector<int>v(n);
		int m1=0, m2=0, s1=0, s2=0;
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
			s1 += v[i];
			if (s1 > m1) m1 = s1;
		}
		for (int i = n-1; i >= 0; --i) {
			s2 += v[i];
			if (s2 > m2) m2 = s2;
		}
		cout << m1 << ' ' << m2 << endl;
	}
}