#include <bits/stdc++.h>
using namespace std;
#define int long long

int mod = 1e9+7;

int power(int x, int y) {
    int res = 1;
    x = x % mod;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1) res = (res*x) % mod;
 
        y = y>>1;
        x = (x*x) % mod;
    }
    return res;
}

vector<int>fact;
vector<int>invfact;
void factorials(int x) {
	fact = vector<int>(x+1);
	fact[1] = 1;
	for (int i = 2; i <= x; ++i) {
		fact[i] = fact[i-1] * i;
		fact[i] %= mod;
	}
}

int inverse(int x) {
	return power(x, mod-2);
}


int inv(int a){
    return power(a,mod-2);
}
int C(int n, int k){
    if(k>n || k<0)return 0;
    return fact[n]*invfact[k]%mod*invfact[n-k]%mod;
}
int perms(int n, int k){
    if(k==0)return 1;
    return n*perms(n-1,k-1)%mod;
}
int f(int m, int k){
    int ans = 0;
    for(int cnt = 0;cnt<=m;cnt++){
        if((m-cnt)%2!=0 || cnt>k)continue;
        ans+=C(m,cnt)*perms(k,cnt)%mod*C(k-cnt, (m-cnt)/2)%mod*fact[m-cnt]*inv(power(2,(m-cnt)/2))%mod;
        ans%=mod;
    }
    return ans;
}

int n, m, k;
vector<int>v(m/2+4);
int patternsTotal = 0;

void b(int pos) {
	for (int i = 0; i <= (m+1)/2; ++i) {
		int mogus = f(m - 2*i, k-i);
		patternsTotal += mogus;
		v[i] = mogus;
	}
}

/*vector<bool>current;
vector<int>current2;
void b(int pos) {
	if (pos == m) {
		patternsTotal += fact[k] * inverse(fact[k - current.size() + 1]) % mod;
		int x = m-2;
		int inc = current2[m-1];
		while (inc != 0) {
			if (current2[x] != inc) return;
			--inc;
			--x;
		}
		v[current2[m-1]] += fact[k] * inverse(fact[k - current.size() + 1]) % mod; //?????
		return;
	}

	for (int i = 1; i < current.size(); ++i) {
		if (!current[i]) {
			current[i] = true;
			current2[pos] = i;
			b(pos+1);
			current[i] = false;
		}
	}
	current.push_back(false);
	current2[pos] = current.size()-1;
	b(pos+1);
	current.pop_back();
} */


signed main() {
	cin >> n >> m >> k;

invfact = vector<int>(k+1);
fact = vector<int>(k+1);
	fact[0] = 0;
    invfact[0] = 0;
    for(int i = 0;i<k+2;i++){
        fact[i] = fact[i-1]*i%mod;
        invfact[i]= inv(fact[i]);
    }

	factorials(k);
	cout << 1 << endl;
	b(0);
	cout << 2 << endl;

	int sol = power(k, n-m);
	sol *= (n-m+1);
	sol %= mod;
	sol *= patternsTotal;
	sol %= mod;

	for (int a = 1; a <= (m+1)/2; ++a) {

		int x = v[a];

		int sum = 0;
		int mida = 2*m - a;
		int neg = -1;

		while (mida <= n) {
			int term = power(k, n-mida);
			term *= (n - mida + 1);
			term %= mod;
			term *= x;
			term %= mod;
			term *= neg; //?

			sum += term;

			neg = -neg;
			mida = mida + m - a;
		}

		sol += sum; //?
		sol %= mod;

	}

	cout << sol << endl;
}