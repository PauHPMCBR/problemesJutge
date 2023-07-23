#include <iostream>
#include <vector>
using namespace std;

int evaluate(const 	vector<int>& p, int x) {
	int power = 1;
	int ans = 0;
	for (int i = 0; i < p.size(); ++i) {
		ans += p[i]*power;
		power *= x;
	}
	return ans;
}