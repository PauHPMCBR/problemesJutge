#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxN = 2*1e6+10;

signed main() {
	int n, m, q;
	cin >> n >> m >> q;
	string ap, bp;
	cin >> ap >> bp;

	set<pair<int,int>>wPos; //val, position

	string sn = string(2*n, '0');
	string sm = string(2*m, '0');
	int pos = 0;
	for (int i = 0; i < n; ++i) {
		if (ap[i] == 'v') sn[pos] = '0';
		else {
			sn[pos] = '1';
			++pos;
			sn[pos] = '1';
		}
		++pos;
	}
	sn.resize(pos);

	pos = 0;
	for (int i = 0; i < m; ++i) {
		if (bp[i] == 'v') sm[pos] = '0';
		else {
			wPos.insert({i+1, wPos.size()});
			sm[pos] = '1';
			++pos;
			sm[pos] = '1';
		}
		++pos;
	}
	sm.resize(pos);

	int mida = sn.size();
	int mida2 = sm.size();

	//cout << mida << endl << sn << endl;
	//cout << mida2 << endl << sm << endl;

	//for (auto i : wPos) cout << i.first << ' ' << i.second << endl;
	//	cout << endl;

	//cout << sn << endl;
	//cout << sm << endl;


	reverse(sn.begin(), sn.end());
	reverse(sm.begin(), sm.end());
	bitset<maxN>bn(sn);
	bitset<maxN>bm(sm);
	bitset<maxN>subset;
	bitset<maxN>result;
	bitset<maxN>compar;

	//for (int i = sn.size(); i >= 0; --i) cout << bn[i]; cout << endl;
	//for (int i = sm.size(); i >= 0; --i) cout << bm[i]; cout << endl;

	while (q--) {
		int a, b;
		cin >> a >> b;
		auto ita = wPos.lower_bound({a,-1});
		auto itb = wPos.lower_bound({b,1e9}); //should not matter?
		if (ita != wPos.end()) a += (*ita).second;
		else a += wPos.size(); //!!
		if (itb != wPos.end()) b += (*itb).second;
		else b += wPos.size();
		

		//cout << a << ' ' << b << ": " << b-a+1 << endl;

		if (b-a+1 != mida) {
			cout << "No" << endl;
			continue;
		}

		subset = bm>>(a-1);
		//for (int i = mida+2; i >= 0; --i) cout << subset[i]; cout << "(orig)" << endl;
		compar = bitset<maxN>(string((b-a+1), '1'));
		subset &= compar; //?

		result = subset & bn;
		//result = result ^ subset;


		//for (int i = mida+2; i >= 0; --i) cout << subset[i]; cout << endl;
		//for (int i = mida+2; i >= 0; --i) cout << compar[i]; cout << endl;
		//for (int i = mida+2; i >= 0; --i) cout << result[i]; cout << endl;
		//for (int i = mida+2; i >= 0; --i) cout << bn[i]; cout << endl;


		//cout << bn << ' ' << subset << endl;

		if (result != subset) {
			cout << "No" << endl;
			continue;
		}

		cout << "Yes" << endl;
	}
}