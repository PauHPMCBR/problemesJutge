#include <bits/stdc++.h> 
using namespace std;

bool ask(int x) {
	cout << "? " << x << endl;
	char res; cin >> res;
	return (res == '>');
}

int main() {
	int n,m;
	cin >> n >> m;
	vector<int>cab;
	bool prev = ask(0);
	if (prev) cab.push_back(0);
	for (int i = 1; i < n-1; ++i) {
		bool prev2 = ask(i);
		if (!prev && prev2) cab.push_back(i);
		prev = prev2;
	}
	if (!ask(n-1)) cab.push_back(n-1);
	cout << '!';
	for (auto i : cab) cout << ' ' << i;
	cout << endl;
}