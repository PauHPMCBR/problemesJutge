#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>v;
void divisors(ll n) { 
    for (ll i = 2; i*i <= n; ++i) { 
        if (n%i == 0) { 
        	v.push_back(i);
            if (n/i != i) v.push_back(n/i);
        }
    }
} 
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    ll q, n;
    cin >> q;
    while(q--){
        cin >> n;
        vector<ll>num(n);
        for (int i = 0; i < n; ++i) {
            cin >> num[i];
        }
        sort(num.begin(), num.end());
        ll l = num[0], r = num[n-1];
        ll finalNum = l*r;
        divisors(finalNum);
        sort(v.begin(), v.end());
        if(v.size() != n) {
            cout << -1 << endl;
        }
        else{
            bool possible = true;
            for (int i = 0; i < n; ++i) {
                if(v[i] != num[i]){
                    cout << -1 << endl;
                    possible = false;
                    break;
                }
            }
            if(possible) cout << finalNum << endl;
        }
        v.clear();
    }
}