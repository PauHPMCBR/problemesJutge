#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(number) cout << "test " << number << endl;
#define FOR(n) for (int (i) = 0; (i) < (n); ++(i))
#define pb push_back

int x2, y2, jump, fall;

map<pair<int,int>,int>m;
bool possible(int x, int y, int h) {
	if (m.find({x,y}) == m.end()) return false;
	if (h-m[{x,y}] < 0) {
		if (m[{x,y}]-h > jump) return false;
	}
	else {
		if (h-m[{x,y}] > fall) return false;
	}
	return true;
}

bool dfs(int x, int y) {
	int h = m[{x,y}];
	m[{x,y}] = -1e7;
	if (x == x2 && y == y2) return true;
	if (possible(x+1,y,h)) if (dfs(x+1,y)) return true;
	if (possible(x+1,y-1,h)) if (dfs(x+1,y-1)) return true;
	if (possible(x,y-1,h)) if (dfs(x,y-1)) return true;
	if (possible(x,y+1,h)) if (dfs(x,y+1)) return true;
	if (possible(x-1,y+1,h)) if (dfs(x-1,y+1)) return true;
	if (possible(x-1,y,h)) if (dfs(x-1,y)) return true;
	return false;
}

int main(){
	char prov;
	int x,y,h;
	string s;
	bool stop = false;
	map<pair<int,int>,int>MOBE;
	while (!stop && getline(cin, s)) {
    	stringstream iss(s);
    	string aux;
    	int counter = 0;
    	while(iss>>aux){
    		if (aux == "#") stop = true;
    		else {
    			if (counter == 0) x = stoi(aux);
    			if (counter == 1) y = stoi(aux);
    			if (counter == 2) h = stoi(aux);
    		}
    		++counter;
    	}
    	if (!stop) {
    		MOBE[{x,y}] = h;
    	}
	}
	while (cin >> jump >> fall >> x >> y >> x2 >> y2) {
		m = MOBE;
		if (dfs(x,y)) cout << "The fox says: what a delicious fish!" << endl;
		else cout << "The fish says: not today, little fox!" << endl;
	}
}