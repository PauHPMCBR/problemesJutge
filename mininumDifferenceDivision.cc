#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<ll>v;
ll sum;

ll minDif(ll pos, ll provSum) {
	if (pos == n-1) return abs((sum-provSum)-provSum);
	return min(minDif(pos+1, provSum), minDif(pos+1, provSum + v[pos]));
}


int main(){
	cin >> n;
	v = vector<ll>(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		sum += v[i];
	}
	cout << minDif(0,0) << endl;
}