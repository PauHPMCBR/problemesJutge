#include <iostream>
using namespace std;

int main() {
    string words;
    bool trobat = false;
    while (cin >> words and !trobat) 
    {
        if (words.size() == 4 or words.size() == 5) 
        {
            if (words[0] == 'n' or words[0] == 'N') 
            {
                if (words[1] == 'o' or words[1] == 'O' or words[1] == '0') 
                {
                    if (words[2] == 'o' or words[2] == 'O' or words[2] == '0') 
                    {
                        if (words[3] == 'b' or words[3] == 'B') 
                        {
                            trobat=true;
                        }
                    }
                }
            }
        } 
    }
    if (trobat)
    {
        cout << "User is banned." << endl;
    }
    else
    {
        cout << "User is exhibiting a friendly behaviour." << endl;
    }
}
