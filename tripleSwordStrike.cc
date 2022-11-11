#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin >>n;
	vector<vector<ll>>v(n);
	map<ll,vector<ll>>mx;
	map<ll,vector<ll>>my;

	vector<pair<ll, ll>>compX(1e6+12, {0,0});
	vector<pair<ll, ll>>compY(1e6+12, {0,0});

	for (ll i = 0; i < n; ++i) {
		ll x,y,val;
		cin >> x >> y >> val;
		v[i] = {x,y,val};
		mx[x].push_back(i);
		my[y].push_back(i);
		compX[x].first-=val;
		compY[y].first-=val;
		compX[x].second = x;
		compY[y].second = y;
	}

	auto lel5 = compX;
	auto lel6 = compY;
	sort(compX.begin(), compX.end());
	sort(compY.begin(), compY.end());

	ll ans1 = -(compX[0].first + compX[1].first + compX[2].first);
	ll ans2 = -(compY[0].first + compY[1].first + compY[2].first);

	ll ans3 = -(compX[0].first + compX[1].first);
	auto lel = lel6;
	for (auto i : mx[compX[0].second]) {
		lel[v[i][1]].first += v[i][2];
	}
	for (auto i : mx[compX[1].second]) {
		lel[v[i][1]].first += v[i][2];
	}
	sort(lel.begin(), lel.end());
	ans3 += -lel[0].first;


	ll ans4 = -(compX[0].first);
	auto lel3 = lel6;
	for (auto i : mx[compX[0].second]) {
		lel3[v[i][1]].first += v[i][2];
	}
	sort(lel3.begin(), lel3.end());
	ans4 += -(lel3[0].first + lel3[1].first);


	ll ans5 = -(compY[0].first + compY[1].first);
	auto lel2 = lel5;
	for (auto i : my[compY[0].second]) {
		lel2[v[i][0]].first += v[i][2];
	}
	for (auto i : my[compY[1].second]) {
		lel2[v[i][0]].first += v[i][2];
	}
	sort(lel2.begin(), lel2.end());
	ans5 += -lel2[0].first;


	ll ans6 = -(compY[0].first);
	auto lel4 = lel5;
	for (auto i : my[compY[0].second]) {
		lel4[v[i][0]].first += v[i][2];
	}
	sort(lel4.begin(), lel4.end());
	ans6 += -(lel4[0].first + lel4[1].first);

	//cout << ans1 <<' '<<ans2<<' '<<ans3<<' '<<ans4<<' '<<ans5<<' '<<ans6 << endl;
	cout << max(ans1, max(ans2, max(ans3, max(ans4, max(ans5, ans6))))) << endl;
}