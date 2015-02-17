#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#define ll int
#define get(a) scanf("%d", &a)
#define rep(n) for( int i = 0; i < n; i++ )
#define pb push_back
using namespace std;

int main() {
   while(1) {
    ll x, y, p, min = INT_MAX;
    vector<ll> a, b;
    get(x); get(y);
    
    if( x == 0 && y == 0 )
        break;
        
    rep(x)
      { get(p); min = p < min ? p: min; }
    rep(y)
      { get(p); b.pb(p); }
    
    sort( b.begin(), b.end() );
    
    if( ( min == b[0] && min == b[1] ) || min >= b[1] )
        printf("N\n");
    else
        printf("Y\n");
    
         
   }  
}
    
