#include <iostream>
#include <unordered_map>
#include <vector>
typedef long long ll;
using namespace std;
int MOD = 10000019;
int n,h;
vector<unordered_map<int,int>>v;

int b(int pos, int val) {
	if (pos == n) return (val == h);
	if (v[pos].find(val) != v[pos].end()) return v[pos][val];
	ll sum = 0;
	for (int i = 1; i != 10; ++i) {
		sum += b(pos+1, (val*i)%MOD);
	}
	return v[pos][val] = sum%MOD;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> h;
	v = vector<unordered_map<int,int>>(n);
	ll sol = 0;
	for (int i = 1; i != 10; ++i) {
		sol += b(1, i);
	}
	cout << sol%MOD << endl;
}