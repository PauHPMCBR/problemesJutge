#include <bits/stdc++.h>

using namespace std;

int main(){
     map<string,int>pepo;
     map<int,string>pope;
     string persons;
     getline(cin, persons);
     stringstream iss(persons);
     string q;
     int i = 0;
     while(iss>>q){
        pepo[q]=i;
         pope[i]=q;
         ++i;
     }
     string s1, aux, s2;
     while(cin >> s1 >> aux >> s2){
         int pos1=pepo[s1];
         int pos2=pepo[s2];     
         pope[pos1]=s2;
         pope[pos2]=s1;
         pepo[s1]=pos2;
         pepo[s2]=pos1;
     }
     for(auto x:pope){
         cout<<x.second<<endl;
     }
}