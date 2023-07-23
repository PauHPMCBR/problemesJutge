#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+5;
vector<int>a(maxN);
vector<int>b(maxN);
int n;
bool check(int x){
	multiset<int>bestl;
	multiset<int>bestr;
	for(int i = 0;i<x;i++){
		bestl.insert(-a[i]);
		bestr.insert(+b[i]);
	}
	if(*bestr.begin()+*bestl.begin()+1>=x)return 1;
	for(int i = 0;i+x<n;i++){
		bestl.erase(bestl.find(-a[i]));
		bestr.erase(bestr.find(b[i]));
		bestl.insert(-a[i+x]);
		bestr.insert(b[i+x]);
		if(+*bestr.begin()+*bestl.begin()+1>=x)return 1;
	}
	return 0;
}
int main() {
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	int l = 1;
	int r = n;
	while(l<=r){
		int mid = (l+r)/2;
		if(check(mid)){
			l = mid+1;
		}
		else r = mid-1;
	}
	cout<<l-1<<endl;
}