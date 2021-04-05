#include <bits/stdc++.h>
using namespace std;
string s;
vector<string>v;
//vector<bool>b;
int n;
int solu=2*1e9;

int dif(string a){
	int ans=0;
	for(int i=0; i<a.size(); ++i){
		if(a[i]!=s[i]) ++ans;
	}

	return ans;
}

void bt(string s2){
	if(dif(s2)>solu) return;
	if(s2.size()==s.size()){
		int prov=dif(s2);
		solu=min(solu,prov);
	}
	for(int i=0; i<v.size(); ++i){
		if(v[i].size()+s2.size()<=s.size()){
			bt(s2+v[i]);
		}
		
	}

}

int main(){
	cin>>s;
	cin>>n;
	v=vector<string>(n);
	//b=vector<bool>(n, false);
	for(int i=0; i<n; ++i){
		cin>>v[i];
	}
	bt("");
	if(solu==2*1e9) cout<<-1<<endl;
	else cout<<solu<<endl;
}