#include <bits/stdc++.h>
using namespace std;
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	multiset<long long>s;
    string ask;
	long long a, n = 0, val = 0;
	while (cin >> ask) {
		if (ask == "number") {
			cin >> a;
			s.insert(a);
            ++n;
            val += a;
		}
		else {
			if (!s.empty()) {
                val -= *s.begin();
                s.erase(s.begin());
                --n;
            }
		}
        
        if (s.empty()) cout << "no elements" << endl;
        else {
            auto it = s.end();
            --it;
            cout << "minimum: " << setprecision(0) << *s.begin() << ", maximum: " << *it << ", average: " << setprecision(4) << fixed << double(val)/double(n) << endl;
        }
	}
}
