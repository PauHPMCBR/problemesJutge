#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
  string p;
  while (cin >> p) {
    cout << p << ": ";
    p.resize(p.size()-2);
    int s = p.size() - 1;
    int esp = 0;
    if (p[s] == 'c' && p[s-1] == ',') esp = 1;
    else if (p[s] == 'g') esp = 2;
    else if (p[s] == 'j') esp = 3;
    else if (p[s] == 'c') esp = 4;
    else if (p[s] == 'u' && (p[s-1] == 'q' || p[s-1] == 'g')) esp = 5;

    string e = p;
    if (esp == 1) e.resize(s-1);
    else e.resize(s);

    cout << p+"o ";

    if (esp == 0) cout << p+"es ";
    else if (esp == 1) cout << e+"ces ";
    else if (esp == 2) cout << p+"ues ";
    else if (esp == 3) cout << e+"ges ";
    else if (esp == 4) cout << e+"ques ";
    else if (esp == 5) cout << e+"\"ues ";

    cout << p+"a ";

    if (esp == 0) cout << p+"em ";
    else if (esp == 1) cout << e+"cem ";
    else if (esp == 2) cout << p+"uem ";
    else if (esp == 3) cout << e+"gem ";
    else if (esp == 4) cout << e+"quem ";
    else if (esp == 5) cout << e+"\"uem ";

    if (esp == 0) cout << p+"eu ";
    else if (esp == 1) cout << e+"ceu ";
    else if (esp == 2) cout << p+"ueu ";
    else if (esp == 3) cout << e+"geu ";
    else if (esp == 4) cout << e+"queu ";
    else if (esp == 5) cout << e+"\"ueu ";

    if (esp == 0) cout << p+"en";
    else if (esp == 1) cout << e+"cen";
    else if (esp == 2) cout << p+"uen";
    else if (esp == 3) cout << e+"gen";
    else if (esp == 4) cout << e+"quen";
    else if (esp == 5) cout << e+"\"uen";

    cout << endl;
  }
}

