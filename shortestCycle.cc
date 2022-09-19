#include <bits/stdc++.h>
using namespace std;

void bellmanford() {
	d[0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (auto a : g[j]) {
				ll e = a.first;
				ll p = a.second;
				if (d[j]+p < d[e]) {
					d[e] = d[j]+p;
				}
			}
		}
	}
}

int main() {

}