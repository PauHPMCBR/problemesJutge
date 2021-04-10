#include <bits/stdc++.h>
using namespace std;

int n;
unordered_map<string,vector<string>>m;
unordered_set<string>visited;
unordered_map<string,int>dist;

void bfs(string x) {
    queue<string>q;
    q.push(x);
    dist[x] = 0;
    while (!q.empty()) {
        string a = q.front();
        q.pop();
        for (auto i : m[a]) {
            //if (i == "erdos") return c;
            if (!visited.count(i)) {
                visited.insert(i);
                if (dist.count(i)) dist[i] = min(dist[i], dist[a]+1);
                else dist[i] = dist[a]+1;
                q.push(i);
            }
        }
    }
    //return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        m = unordered_map<string,vector<string>>();
        set<string>autors;
        cin >> n;
        while (n--) {
            int b;
            cin >> b;
            vector<string>prov(b);
            for (int i = 0; i < b; ++i) {
                cin >> prov[i];
                autors.insert(prov[i]);
            }
            for (int i = 0; i < b; ++i) {
                for (int j = 0; j < b; ++j) {
                    m[prov[i]].push_back(prov[j]);
                }
            }
        }
        dist["erdos"] = 0;
        bfs("erdos");
        for (auto i : autors) {
            if (!dist.count(i)) cout << i << " -1" << endl;
            else cout << i << ' ' << dist[i] << endl;
        }
    }
}