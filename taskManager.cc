#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
    getline(cin,s);
    stringstream iss(s);
    string aux;
    int i = 0;
    vector<pair<double,pair<int,string>>>v;
    vector<pair<int,string>>prov;
    while(iss>>aux){
        prov.push_back({i,aux});
        ++i;
    }
    for (int i = 0; i < prov.size(); ++i) {
    	double mobe;
    	cin >> mobe;
    	v.push_back({mobe, prov[i]});
    }
    sort(v.begin(), v.end());
    double waitTime = 0;
    double mobeWait = 0;
    for (auto i : v) {
    	waitTime += i.first;
    	mobeWait += waitTime;
    	cout << i.second.second << " wait time: " << waitTime << endl;
    }
    cout << "Total time waited: " << mobeWait << endl;
}