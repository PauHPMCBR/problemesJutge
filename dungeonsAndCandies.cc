#include <bits/stdc++.h>
using namespace std;
int n,m,k,w;
vector<vector<vector<char>>>lel;
vector<pair<int,pair<int,int>>>v;

int getDiff(int x, int y) {
	int diff = 0;
	for (int i = 0; i < n, ++i) {
		for (int j = 0; j < m; ++j) {
			if (lel[x][i][j] != lel[y][i][j]) ++diff;
		}
	}
	return diff*w;
}

int main(){
	cin >> n >> m >> k >> w;
	lel = vector<vector<vector<char>>>(k, vector<vector<char>>(n, vector<char>(m, '.')));
	for (int h = 0; h < k; ++h) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> lel[h][i][j];
			}
		}
		for (int i = 0; i < h; ++i) {
			v.push_back({getDiff(i,h), {i,h}});
		}
	}
	
}