#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( long i = 0; i < n; i++ )
#define pb push_back
using namespace std;

int main() {
    ll t, cc = 1;
    get(t);
    
    while(t--) {
       ll n, stamp, p;
       vector<ll> v;
       get(stamp); get(n);
       
       rep(n)
        { get(p); v.pb(p); }
       
       sort( v.begin(), v.end(), greater<ll>() );
       
       ll sum = 0; ll i = 0;
       while( sum < stamp && i < n )
        { sum += v[i++]; }
       
       if( sum >= stamp )
           printf("Scenario #%ld:\n%ld\n\n", cc++, i);
       else
           printf("Scenario #%ld:\nimpossible\n\n", cc++);
    }
}
       
