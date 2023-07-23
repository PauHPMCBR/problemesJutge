#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int sol = 0;
		set<pair<int,int>>s;
		set<int>s2;
		for (int i = 0; i < n; ++i) {
			int prov;
			cin >> prov;
			pair<int,int> mobe = {prov,prov};
			if (s.size() == 0) {s.insert(mobe); sol = prov-1; s2.insert(prov); cout << sol << ' '; continue;}
			cout << "sus" << endl;
			auto x = lower_bound(s.begin(), s.end(), mobe);
			if ((x != s.end()) && (*x).first <= prov and (*x).second >= prov) {cout << "sus1" << endl;
				if ((*x).first == 1) continue;
				else {cout << "susa" << endl;
					s2.insert((*x).first-1);
					sol -= distance(s2.find((*x).first-1) , s2.end()) -1; //?
					pair<int,int> np = {(*x).first-1, (*x).second};cout << "susb" << endl;
					if (x == s.begin()) {cout << "susamogus" << endl;s.erase(x); cout << "sussus" << endl;}
					else {cout << "suss" << endl;
						auto y = x;
						--x; cout << "sus22" << endl;
						s.erase(y); cout << "sus33" << endl;
						if ((*x).second == np.first -1) {cout << "sus44" << endl;
							np = {(*x).first, np.second};
							s.erase(x);
						}
						else sol += np.first-1 - (*x).second; cout << "sus55" << endl;
					}cout << "sus" << endl;
					s.insert(np);
				}

			}
			else if (x == s.begin()) {cout << "sus2" << endl;
				sol -= s2.size(); //?
				s2.insert(prov);
				if ((*x).first == prov+1) {
					pair<int,int>np = (*x);
					s.erase(x);
					np.first = prov;
					s.insert(np);
				}
				else s.insert({prov,prov});
			}
			else {cout << "sus3" << endl;
				s2.insert(prov);
				if ((*x).first == prov+1) {
					sol -= distance(s2.find(prov) , s2.end()) -1; //?
					pair<int,int>np = (*x);
					s.erase(x);
					np.first = prov;
					s.insert(np);
				}
				else if ((*(--x)).second == prov-1) {
					sol -= distance(s2.find(prov) , s2.end()) -1; //?
					pair<int,int>np = (*x); //should be --x already
					s.erase(x);
					np.second = prov;
					s.insert(np);
				}
				else {
					sol -= distance(s2.find(prov) , s2.end()) -1; //?
					sol += prov - (*x).second; //?
					s.insert({prov,prov});

				}
			}cout << "sus" << endl;
			cout << sol << ' ';
		}
		cout << endl;
		
	}
}