#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s;
    while (getline(cin,s)) {
    stringstream iss(s);
    string aux;
    while(iss>>aux){
        if (aux == "#") return 0;
        int h = stoi(aux.substr(0,2));
        int m = stoi(aux.substr(3,2));
        h %= 12;
        if (m == 60) {
            m = 0;
            ++h;
            h %= 12;
        } 
        double ha = 0.5*(h*60+m); 
        double ma = 6*m; 
        double angle = abs(ha-ma); 
        cout << fixed << setprecision(1) << min(360-angle,angle) << endl;
    }
    }
}
 