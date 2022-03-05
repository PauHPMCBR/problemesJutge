#include <bits/stdc++.h>
using namespace std;
int n, m;

bool isValid(int x, int y){
	return (x >= 0 && x < n && y >= 0 && y < m);
}

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
	cin >> n >> m;
	int k;
	cin >> k;
	vector<set<int>>v(n*m+m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (isValid(i-1,j)) v[i*m+j].insert((i-1)*m+j);
			if (isValid(i+1,j)) v[i*m+j].insert((i+1)*m+j);
			if (isValid(i,j-1)) v[i*m+j].insert((i)*m+j-1);
			if (isValid(i,j+1)) v[i*m+j].insert((i)*m+j+1);
		}
	}
	for (int i = 0; i < k; ++i) {
		string s;
		cin >> s;
		vector<string>prov = split(s, ',');
		int x1 = stoi(prov[0]);
		int y1 = stoi(prov[1]);
		int x2 = stoi(prov[2]);
		int y2 = stoi(prov[3]);
		if (x2 < x1) swap(x1, x2);
		if (y2 < y1) swap(y1, y2);
		if (x1 == x2) {
			for (int j = y1; j < y2; ++j) {
				v[x1*m+j].erase((x1-1)*m+j);
				v[(x1-1)*m+j].erase(x1*m+j);
			}
		}
		else {
			for (int j = x1; j < x2; ++j) {
				v[j*m+y1].erase(j*m+y1-1);
				v[j*m+y1-1].erase(j*m+y1);
			}
		}
	}
	queue<pair<int,int>>q;
	q.push({0,0});
	int res = -1;
	vector<bool>visited(n*m+m, 0);
	while (!q.empty()){
		int d = q.front().first;
		int x = q.front().second;
		q.pop();
		if (x == (n-1)*m+m-1) {res = d; break;}
		for (auto i : v[x]) {
			if (visited[i]) continue;
			visited[i] = true;
			q.push({d+1,i});
		}
	}
	cout << res << endl;
}