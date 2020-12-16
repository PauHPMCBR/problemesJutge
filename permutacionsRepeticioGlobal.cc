#include <bits/stdc++.h>
using namespace std;

set<int> s;

void bt(vector<int>v1, vector<int>v2, vector<bool>b){
	if (v2.size() == v1.size()) {

		int x = 0;
		int exp=1;
		for(int j=0; j<v1.size(); ++j){
			x += v2[j]*exp;
			exp*=10;
		}

		if(!s.count(x)){
			s.insert(x);
		}
		
		return;
	}
	for(int i=0; i<v1.size(); ++i){
		if(b[i]==false){
			v2.push_back(v1[i]);
			b[i]=true;
			bt(v1,v2,b);
			v2.pop_back();
			b[i]=false;
		}
	}
}


int main(){
	ios::sync_with_stdio(false);
	vector<int>v1;
	int prov;
	while(cin >> prov) v1.push_back(prov);
	vector<int>v2;
	vector<bool>b(v1.size(),false);
	bt(v1,v2,b);

	int it=0;

	for(auto p:s) {
		cout<<++it<<": "<<p<<endl;
	}

}