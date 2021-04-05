#include <bits/stdc++.h>
using namespace std;

int main(){
	stack<char>p;
	map<char,char>m = {{'(',')'},{'{','}'},{'[',']'}};
	string s;
	getline(cin, s);
	string mod = s;
	int fixes = 0;
	for (int i = 0; i < s.size(); ++i) {
		char c = s[i];
		if (c == '(' || c == '{' || c == '[') p.push(c);
		else if (c == ')' || c == '}' || c == ']') {
			char current = p.top();
			p.pop();
			if (m[current] != c) {
				++fixes;
				mod[i] = m[current];
			}
		}
	}
	cout << mod << endl;
	cout << fixes << " fixes made to the formula." << endl;
}