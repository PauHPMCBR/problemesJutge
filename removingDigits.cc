//#pragma GCC optimize("-O3")
#include <stdio.h>
int max(int a, int b){return (a > b)? a: b;}
int main(){
    int n, c = 0, s = 0, p = 0, r;
    scanf("%d", &n);
    if(n >= 100){
        p = n/100;
        while(p){
            s = max(s, p%10);
            p /= 10;
        }
    }
    while(n > 0){
        if(n < 100) s = 0;
        p = max(n%10, (n/10)%10);
        r = max(s, p);
        if(n%100 < r){
            n -= r;
            int p = n/100;
            s = 0;
            while(p){
                s = max(s, p%10);
                p /= 10;
            }
        }
        else n -= r;
        ++c;
    }
    printf("%d\n", c);
}