#include <bits/stdc++.h>

using namespace std;

int posicio(double x, const vector<double>&v, int esq, int dre){
    int mid=(esq+dre)/2;
    if(esq>dre) return -1;
    if(v[mid]>x) return posicio(x,v,esq,mid-1);
    if(v[mid]<x) return posicio(x,v,mid+1,dre);
    if(v[mid]==x) return mid;
}

int first_occurrence(double x, const vector<double>&v){
    
    int pos=-1;
    int esq=0;
    int dre=v.size()-1;
    int prov=-1;
    do{
        pos=posicio(x,v,esq,dre);
        if(pos==-1 and prov!=-1) return prov;
        dre=pos-1;
        prov=pos;
        
    }while(pos!=-1);
    
    return pos;

}

int main(){
    
    vector<double>v={1.1,1.1,5.5,5.5,6.0,99.99,99.99,99.99,99.99};
    double n;
    cin>>n;
    cout<<first_occurrence(n,v);
}
