#include <iostream>
using namespace std;

void f(int a) {
	cout << a << endl;
	f(a-1);
	cout << a << '-' << endl;
}

int main(){
	int a;
	cin >> a;
	f(a);
	cout << "finished" << endl;
}


