#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#define ll long long
#define get(a) scanf("%lld", &a)
#define put(a) printf("%lld\n", a)
#define rep(n) for( long i = 0; i < n; i++ )
#define pb push_back
using namespace std;

int main() {
    ll t, cc = 1;
    get(t);
    
    while(t--) {
       ll x,y,s, n, a, d;
       get(x); get(y); get(s);
       
       n = (2*s)/(x+y);
       d = (y - x)/(n-5);
       a = x - 2*d;
       
       put(n);
      
       rep(n)
        printf("%lld ", a + i*d);
       printf("\n");
              
    }
}
       
