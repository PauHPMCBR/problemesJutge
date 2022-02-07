#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>>v;

void floyd() {
	for (int k = 0; k < n; k++) { 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (v[i][k] + v[k][j] < v[i][j]) 
					v[i][j] = v[i][k] + v[k][j]; 
			} 
		} 
	} 
}x

int main(){
	cin >> n;
	v = vector<vector<int>>(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> v[i][j];
		}
	}
	floyd();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << v[i][j] << ' ';
		}
		cout << endl;
	}
}