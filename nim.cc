#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string name1, name2;
    for (int i = 0; i < n; ++i) {
    	cin >> name1 >> name2;
    	vector <int> v(6);
    	for (int j = 0; j < 6; ++j) cin >> v[j];
    	cout << "Joc #" << i+1 << ": ";
    	sort(v.begin(), v.end());
    	bool done = false;
    	while(v[5] > 0) {
    		bool thisPair = true;
    		for (int j = 0; j < 6; ++j) {
    			if (v[j]%2 == 1) thisPair = !thisPair;
    			v[j] /= 2;
    		}
    		if (!thisPair) {
    			done = true;
    			cout << name1 << endl;
    			break;
    		}
    	}
    	if (!done) {
    		cout << name2 << endl;
    	}
    }
}
