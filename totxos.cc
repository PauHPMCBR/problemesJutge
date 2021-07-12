#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll n;
	cin >> n;
	ll count = 1;
	ll sum = 0;
	while (sum <= n) {
		sum += count;
		++count;
	}
	cout << count-2 << endl;
}