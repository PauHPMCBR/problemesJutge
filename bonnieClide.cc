#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<ll>v;
ll sum;
vector<int>sol;
vector<int>sol2;
ll minDif(ll pos, ll provSum) {
	if (pos == n-1) {
		return abs((sum-provSum)-provSum);
	}
	int a = minDif(pos+1, provSum);
	int b = minDif(pos+1, provSum + v[pos]);
	if (b == 0) sol.push_back(v[pos]);
	else if (a == 0) sol2.push_back(v[pos]);
	return min(a, b);
}
 
 
int main(){
	cin >> n;
	v = vector<ll>(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		sum += v[i];
	}

	cout << minDif(0,0) << endl;
	for (auto i : sol) cout << i << ' ';
	cout << endl;
	for (auto i : sol2) cout << i << ' ';
		cout << endl;
}