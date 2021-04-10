#include <bits/stdc++.h>
using namespace std;

bool matches(string s, string s2) {
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
	for (int i = 0; i < s.size(); ++i) if (s[i] != s2[i]) return false;
	return true;
}

int main(){
	string initialString;
    
    string aux;
    multiset<string>s;
    int maxim = 0;
    string toComplete;
    string completed;
    vector<string>v;

    getline(cin,initialString);
    stringstream iss(initialString);
    while(iss>>aux){
    	v.push_back(aux);
    }
    cin >> toComplete;
    for (auto aux : v) {
    	s.insert(aux);
    	if (matches(toComplete, aux)) {
    		if (s.count(aux) > maxim) {
    			maxim = s.count(aux);
    			completed = aux;
    		}
    	}
    }
    if (maxim == 0) cout << toComplete << endl;
    else cout << completed << endl;
}