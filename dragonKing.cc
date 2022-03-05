#include <bits/stdc++.h>
using namespace std;

map<string,int>m = {{"DragonValley",0},{"BearHills",1},{"BlueFields",2},{"DeepLagoon",3},
{"GreenFields",4},{"RedFields",5},{"SlimeRock",6},{"DragonEye",7}};
map<int, string>m2 = {{0,"DragonValley"},{1,"BearHills"},{2,"BlueFields"},{3,"DeepLagoon"},
{4,"GreenFields"},{5,"RedFields"},{6,"SlimeRock"},{7,"DragonEye"}};
vector<vector<pair<int,int>>>v;
vector<bool>visited;
vector<int>denecswan;

int stops;
int dfs(int pos, int time) {
	if (pos == 7) {stops = 1; return time;}
	if (visited[pos]) return 1e9;
	visited[pos] = true;
	int minT = 1e9, minstops = 1e9;
	bool secondTime = (time/30)%2;
	for (int i = 0; i < 8; ++i) {
		if (v[pos][i].first == -1) continue;
		if (secondTime) {
			int v1 = dfs(i, time+v[pos][i].second), s1 = stops;
			int v2 = dfs(i, (time/30+1)*30+v[pos][i].first), s2 = stops;
			if (v1 < minT || (v1 == minT && s1 < minstops)) {denecswan[pos] = i; minT = v1; minstops = s1;}
			if (v2 < minT || (v2 == minT && s2 < minstops)) {denecswan[pos] = i; minT = v2; minstops = s2;}
		}
		else {
			int v1 = dfs(i, time+v[pos][i].first), s1 = stops;
			int v2 = dfs(i, (time/30+1)*30+v[pos][i].second), s2 = stops;
			if (v1 < minT || (v1 == minT && s1 < minstops)) {denecswan[pos] = i; minT = v1; minstops = s1;}
			if (v2 < minT || (v2 == minT && s2 < minstops)) {denecswan[pos] = i; minT = v2; minstops = s2;}
		}
	}
	visited[pos] = false;
	stops = minstops+1;
	return minT;
}

int main(){
	int n;
	cin >> n;
	v = vector<vector<pair<int,int>>>(8, vector<pair<int,int>>(8, {-1,-1}));
	denecswan = vector<int>(8, -1);
	visited = vector<bool>(8, false);
	for (int i = 0; i < n; ++i) {
		string s1, s2;
		int t1, t2;
		cin >> s1 >> s2 >> t1 >> t2;
		v[m[s1]][m[s2]] = {t1, t2};
	}
	cout << "Minimum time: " << dfs(0,0) << endl;
	cout << "Minimum path:";
	int x = 0;
	while (x != 7) {
		cout << ' ' << m2[x];
		x = denecswan[x];
	}
	cout << ' ' << m2[7] << endl;
}