#include <bits/stdc++.h>
using namespace std;

vector<string>split(string s, char c) {
	s += c;
	vector<string>vp;
	int lastPos = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == c) {
			if (i-lastPos < 1) {lastPos = i+1; continue;}
			vp.push_back(s.substr(lastPos, i-lastPos));
			lastPos = i+1;
		}
	}
	return vp;
}

int main(){
	map<string,int>m;
	string s, e;
	cin >> s >> e;
	m[s] = 0;
	m[e] = 1;
	string prov;
	int mapSize = 2;
	vector<vector<string>>vIn;
	while (cin >> prov) {
		vIn.push_back(split(prov, ':'));
		if (!m.count(vIn[vIn.size()-1][0])) {
			m[vIn[vIn.size()-1][0]] = mapSize;
			++mapSize;
		}
		if (!m.count(vIn[vIn.size()-1][2])) {
			m[vIn[vIn.size()-1][2]] = mapSize;
			++mapSize;
		}
	}
	vector<vector<pair<int,int>>>v(mapSize);
	for (auto i : vIn) {
		//ºcout << i[0] << ' ' << i[1] << ' ' << i[2] << endl;
		v[m[i[0]]].push_back({stoi(i[1]), m[i[2]]});
		v[m[i[2]]].push_back({stoi(i[1]), m[i[0]]});
	}
	priority_queue<pair<int,int>>pq;
	pq.push({0, 0});
	vector<bool>visited(mapSize, 0);
	int sol = -1;
	while (!pq.empty()) {
		int x = pq.top().second;
		int w = pq.top().first;
		pq.pop();
		if (x == 1) {
			sol = -w;
			break;
		}
		if (visited[x]) continue;
		visited[x] = true;
		for (auto i : v[x]) {
			pq.push({w-i.first, i.second});
		}
	}
	cout << sol << endl;
}