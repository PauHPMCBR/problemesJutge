#include <bits/stdc++.h>
using namespace std;

int sumofdigits(int k){
    int prov=0;
    while(k>0){
        prov+=(k%10);
        k/=10;
    }

    return prov;
}

int main() {
    string n2;
    string d;
    string n="";
    getline(cin,d);
    getline(cin,n2);


    int suma=stoi(d);
    while(suma>9){
        suma=sumofdigits(suma);
    }
    int suma2=0;
    for(int i=0; i<n.size(); ++i){
        suma2+=int(n[i]);
    }
    while(suma2>9){
        suma2=sumofdigits(suma2);
    }
    int nou=10*suma+suma2;
    while(nou>9){
        nou=sumofdigits(nou);
    }

    if(nou==1) cout<<"You tend to be critical of yourself."<<endl;
    if(nou==2) cout<<"You have a great deal of unused capacity which you have not turned to your advantage."<<endl;
    if(nou==3) cout<<"While you have some personality weaknesses, you are generally able to compensate for them."<<endl;
    if(nou==4) cout<< "At times you are extroverted, affable, sociable, while at other times you are introverted, wary, reserved."<<endl;
    if(nou==5) cout<<"Disciplined and self-controlled outside, you tend to be worrisome and insecure inside."<<endl;
    if(nou==6) cout<<"At times you have serious doubts as to whether you have made the right decision or the right thing."<<endl;
    if(nou==7) cout<<"You prefer a certain amount of change and variety and become dissatisfied when hemmed in by restrictions and limitations."<<endl;
    if(nou==8) cout<<"You pride yourself as an independent thinker and do not accept others' statements without satisfactory proof."<<endl;
    if(nou==9) cout<<"You have found it unwise to be too frank in revealing yourself to others."<<endl;

}