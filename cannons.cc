#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int>lel(n);
	for (int i = 0; i < n; ++i) cin >> lel[i];
	priority_queue<pair<int,int>>pq;
    pq.push({0,0});
    vector<int>dist(n, -1);
    vector<bool>v(n, false);
    dist[0]=0;
    while(!pq.empty()){
        int actual=pq.top().second;
        if (actual == n-1) break;
        pq.pop();
        if(v[actual]) continue;
        v[actual]=true;
        for(int i = 1; i < n; ++i) {
        	if (v[i]) continue;
        	int pes = abs(actual-i);
        	if (lel[actual] == i) pes = 0;
        	if (dist[actual]+pes < dist[i] || dist[i] == -1) {
        	    dist[i] = dist[actual]+pes;
        	    pq.push({-dist[i], i});
        	}
        }
    }
    cout << dist[n-1] << endl;
}