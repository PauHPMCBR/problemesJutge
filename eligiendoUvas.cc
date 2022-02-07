#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
	ll a, b, bestA = -1, bestB = 1e18+1, bpa = -1, bpb = 1e18+1;
	while (cin >> a >> b) {
		if (a == 0 && b == 0) {
			if (bestA == bpa && bestB == bpb) cout << bestA << ' ' << bestB << endl;
			else cout << "NO HAY MEJOR" << endl;
			bestA = -1, bestB = 1e18+1, bpa = -1, bpb = 1e18+1;
		}
		else {
			if (a >= bestA && b <= bestB) {bpa = a; bpb = b;}
			bestA = max(bestA, a);
			bestB = min(bestB, b);
		}
	}
}