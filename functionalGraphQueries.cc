#include <bits/stdc++.h>
using namespace std;
<<<<<<< HEAD
int n,m;
unordered_map<int,int>graph;

int main(){
	cin >> n >> m;
	while (m--) {
		int a,b;
		cin >> a >> b;
		graph[a] = b;
	}
	int q;
	cin >> q;
	while (q--) {
		unordered_map<int,int>steps;
		int stepsRemaining, pos;
		cin >> pos >> stepsRemaining;
		while (stepsRemaining--) {
			if (steps.count(pos)) {
				stepsRemaining = stepsRemaining % (steps[pos] - stepsRemaining);
			}
			steps[pos] = stepsRemaining;
			if (graph.count(pos)) pos = graph[pos];
			else stepsRemaining = 0;
		}
		cout << pos << endl;
	}
=======

int main(){
	
>>>>>>> d5dc4b0e9abf2c7c69f326aeee2e037c6de0735c
}