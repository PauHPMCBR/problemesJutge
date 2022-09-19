#include <iostream>
using namespace std;

int main(){
	int n,m,o;
	cin >> n >> m >> o;
	cout << max(max(n,m),o) << endl;
}