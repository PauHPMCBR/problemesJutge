#include <bits/stdc++.h>
using namespace std;

vector<char>v;

int res(int a, int b) {
	if (a == b-1) {
		return int(v[a]-'0');
	}
	if (v[a] <= '9' && v[a] >= '0') {
		if (v[a+1] == '+') return int(v[a]-'0')+res(a+2, b);
		else if (v[a+1] == '-') return int(v[a]-'0')-res(a+2, b);
		else return int(v[a]-'0')*res(a+2, b);
	}
	int parentesis = 1;
	for (int i = a+1; i < b; ++i) {
		if (v[i] == '(') ++parentesis;
		else if (v[i] == ')') -- parentesis;
		if (parentesis == 0) {
			if (i+1 == b) return res(a+1, i);
			if (v[i+1] == '+') return res(a+1, i) + res(i+2, b);
			else if (v[i+1] == '-') return res(a+1, i) - res(i+2, b);
			return res(a+1, i) * res(i+2, b);
		}
	}
	return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	char prov;
	while(cin >> prov) {
		v.push_back(prov);
	}
	cout << res(0, v.size()) << endl;
}
