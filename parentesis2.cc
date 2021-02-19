#include <bits/stdc++.h>
using namespace std;

vector<char>v;
int toInt(char c) {return int(c-'0');}
bool isInt(char c) {return (c <= '9' && c >= '0') ? true : false;}

int res(int a, int b) {
	/*cout << "current vector: ";
	for (int i = a; i < b; ++i) cout << v[i];
		cout << endl;*/
	if (a == b-1) {
		return toInt(v[a]);
	}
	if (isInt(v[a])) {
		if (v[a+1] == '+') return toInt(v[a])+res(a+2, b);
		else if (v[a+1] == '-') return toInt(v[a])-res(a+2, b);
		else return toInt(v[a])*res(a+2, b);
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
	char prov;
	while(cin >> prov) {
		v.push_back(prov);
	}
	//cout << lastNum << ' ' << v.size() << endl;
	//cout << "lel" << endl;
	cout << res(0, v.size()) << endl;
}