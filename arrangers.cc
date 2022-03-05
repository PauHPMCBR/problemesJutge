#include <bits/stdc++.h>
using namespace std;

vector<int>getInts(string ss) {
	stringstream parse(ss);
	vector<int>vProv;
	int i;
	while (parse >> i) {
		vProv.push_back(i);
	}
	return vProv;
}

int main(){
	deque<int>q;
	string s;
	getline(cin, s);
	vector<int>v = getInts(s);
	for (auto i : v) q.push_back(i);
	int pos;
	cin >> pos;
	--pos;
	int t = 0;
	while (++t) {
		int x = q.front() -1;
		q.pop_front();
		if (x != 0) {
			q.push_back(x);
		}
		if (pos == 0) {
			pos = q.size()-1;
			if (x == 0) break;
		}
		else --pos;
	}
	cout << t << endl;
}