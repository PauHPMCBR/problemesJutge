#include <iostream>
using namespace std;

int main() {
    string s, t;
    while (cin >> s >> t) {
        //j es l'iterador de t (paraula "curta")
        //i es l'iterador de s (paraula "llarga")
        int j = 0;
        for (int i = 0; i < s.size(); ++i) {
            //quan la lletra s[i] coincideix amb t[j], suposem que hem eliminat
            //les lletres des de l'ultima que coincidia fins a l'actual
            if (t[j] == s[i]) {
                //indiquem que ja hem trobat la lletra t[j]
                ++j;
                //si hem recorregut la paraula t sencera ja hem acabat
                if (j == t.size()) break;
            }
        }
        //hem aconseguit transformar s en t si i nomes si hem aconseguit trobar totes les lletres
        //de t en ordre dintre s (i per tant l'iterador j ha arribat al final de la paraula)
        if (j == t.size()) cout << "SI" << endl;
        else cout << "NO" << endl;
    }
}