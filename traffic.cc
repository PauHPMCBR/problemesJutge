#include <bits/stdc++.h>
using namespace std;

int main(){
	int c = 0, d = 0;
	char e;
	int a, b;
	while (cin >> e){
		if (e == '#') {
			cout << c << " fines to Whynot" << endl;
			cout << d << " fines to Zzyzx" << endl;
			if (c > d) cout << "Zzyzx inhabitants are safer at driving than Whynot ones" << endl;
			else if (c == d) cout << "Whynot and Zzyzx inhabitants are equally safe at driving" <<endl;
			else cout << "Whynot inhabitants are safer at driving than Zzyzx ones" << endl;
			return 0;
		}
		cin >> a >> b;
		if (a>b) {
			if (e == 'W') ++c;
			else ++d;
		}
	}
}