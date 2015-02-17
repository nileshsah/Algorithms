#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    long long int n, m;
    scanf("%lld %lld", &n, &m);
    
    while(m--) {
       long long int q, a;
       scanf("%lld", &q);
       a = q;
       
       if( a <= 2*n ) {
           a = q - n;
           a--;
       }
       else if( a > 2*n ) {
        a = q - 2*n - 1;
        a = n - a;    
       }
       
       if( a <= 0 )
           printf("0\n");
       else
           printf("%lld\n", a);
    }
}
       
       
