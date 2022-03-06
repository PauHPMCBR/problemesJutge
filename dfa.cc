#include <bits/stdc++.h>
using namespace std;

vector<string>split(string s, char c) {
    s += c;
    vector<string>vp;
    int lastPos = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == c) {
            if (i-lastPos < 1) {lastPos = i+1; continue;}
            vp.push_back(s.substr(lastPos, i-lastPos));
            lastPos = i+1;
        }
    }
    return vp;
}

int main(){
	string prov;


	getline(cin, prov);
	vector<string>states = split(prov, ' ');
	set<string>statesSet;
	for (auto i : states) statesSet.insert(i);
	int numStates = states.size();

	getline(cin, prov);
	vector<string>alphabet = split(prov, ' ');
	set<string>alphabetSet;
	for (auto i : alphabet) alphabetSet.insert(i);
	int numAlphabet = alphabet.size();

	string startState;
	getline(cin, startState);

	getline(cin, prov);
	vector<string>acceptedStates = split(prov, ' ');
	set<string>acceptedStatesSet;
	for (auto i : acceptedStates) acceptedStatesSet.insert(i);

	map<string,map<string,string>>transition; //transition[state][letterOfAlphabet]
	bool valid = true;
	for (auto state : states) {
		map<string,string>prov2;
		set<string>alphProv;
		set<string>stateProv;
		getline(cin, prov);
		vector<string> gamingProv = split(prov, ' ');
		if (gamingProv.size() != numAlphabet*2) valid = false;
		else {
		for (int j = 0; j < numAlphabet; ++j) {
			string s1, s2;
			s1 = gamingProv[2*j];
			s2 = gamingProv[2*j+1];
			if (alphProv.count(s1)) valid = false;
			//if (stateProv.count(s2)) valid = false;
			if (!alphabetSet.count(s1)) valid = false;
			if (!statesSet.count(s2)) valid = false;
			alphProv.insert(s1);
			stateProv.insert(s2);
			prov2[s1] = s2;
		}
	}
		transition[state] = prov2;
	}

	string input;
	getline(cin, input);

	bool invalidInput = false;
	for (auto i : input) {
		//cout << i << endl;
		if (!alphabetSet.count(string(1,i))) invalidInput = true;
	}


	if (invalidInput) cout << "Invalid input string!" << endl;
	else if (!valid) cout << "This is not a deterministic finite automaton!" << endl;
	else {
		for (auto i : input) {
			startState = transition[startState][string(1, i)];
		}
		if (acceptedStatesSet.count(startState)) cout << "Input string accepted" << endl;
		else cout << "Input string rejected" << endl;
	}
}