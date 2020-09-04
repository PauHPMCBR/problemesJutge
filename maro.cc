#include <iostream>
#include <vector>
using namespace std;

int w, l;
vector < vector <int> > v;
int x, y, pos;

void checkRow(int row) {
if (row == 0) return;
else if (row == w-1) {
    for (int i = 0; i < l; ++i) {
        if (v[row][i] == -1) v[row][i] = 0;
        else if (v[row][i] == -3) v[row][i] = 3;
    }
}
for (int i = 0; i < l; ++i) {
    if (v[row][i] < 0) continue;
    int value = v[row][i];
    
    if (i > 0) {
        pos = v[row-1][i-1];
        if (pos == -1) v[row-1][i-1] = value+1;
        else if (pos == -3) v[row-1][i-1] = value+4;
        else if (pos > value) v[row-1][i-1] = value;
    }
    
    pos = v[row-1][i];
    if (pos == -1) v[row-1][i] = value;
    else if (pos == -3) v[row-1][i] = value+3;
    else if (pos > value) v[row-1][i] = value;
    
    if (i < l-1) {
        pos = v[row-1][i+1];
        if (pos == -1) v[row-1][i+1] = value+1;
        else if (pos == -3) v[row-1][i+1] = value+4;
        else if (pos > value) v[row-1][i+1] = value;
    }
    
}
checkRow(row-1);
}

int main() {
cin >> l >> w;
char prov;

v = vector < vector <int> > (w);
for (int i = 0; i < w; ++i) {
    v[i] = vector <int> (l);
    for (int j = 0; j < l; ++j) {
        cin >> prov;
        if (prov == '.') v[i][j] = -1;
        else if (prov == 'T') v[i][j] = -3;
        else if (prov == '*') v[i][j] = -7;
        else {v[i][j] = -1; x = i; y = j;}
    }
}
checkRow(w-1);
/*for (int i = 0; i < w; ++i) {
    for (int j = 0; j < l; ++j) cout << v[i][j];
    cout << endl;
}*/
if (v[x][y] == -1) cout << "IMPOSSIBLE" << endl;
else cout << v[x][y] << endl;
}
