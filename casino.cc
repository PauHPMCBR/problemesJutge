#include <bits/stdc++.h>
using namespace std;

int main() {
    set <string> s;
    map <string, int> p;
    string name, command;
    int money;
    while(cin >> name >> command) {
        if (command == "enters") {
            if (s.count(name)) cout << name <<  " is already in the casino" << endl;
            else {
                p[name] = 0;
                s.insert(name);
            }
        }
        else if (command == "leaves") {
            if (!s.count(name)) cout << name << " is not in the casino" << endl;
            else {
                cout << name << " has won " << p[name] << endl;
                p.erase(name);
                s.erase(name);
            }
        }
        else {
            cin >> money;
            if (!s.count(name)) cout << name << " is not in the casino" << endl;
            else p[name] += money;
        }
    }
    cout << "----------" << endl;
    for (auto x : p) cout << x.first << " is winning " << x.second << endl;
}
