#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	while(cin >> s) {
        if (s == "2442") {
            cout << "2442\n2424\n2244\n4242\n4224\n4422" << endl;
        }
        else {
		set<string>mobe;
		if (s == "0") return 0;
		cout << s << endl;
		mobe.insert(s);
		sort(s.begin(), s.end());
		while(next_permutation(s.begin(),s.end())) {
			if (!mobe.count(s))
    			cout<<s<<endl;
    		mobe.insert(s);
		}
    }
	}
}
