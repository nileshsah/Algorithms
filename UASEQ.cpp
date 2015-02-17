#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <algorithm>
#include <limits.h>
#include <cstring>
#define ll long long
#define get(a) scanf("%lld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define max(a,b) a > b ? a : b
#define pb push_back
#define MOD 1000000007
using namespace std;

struct node {
  ll n;
  ll an;
  ll d;
};

int main() {
    ll n, k;
    ll a[100000+5] = {0};
    set<ll> rem;
    map< ll, ll > v;
    map< ll, ll > m;
    
    get(n); get(k);
    
    for( ll i = 1; i <= n; i++ ){ 
         get(a[i]); 
         ll val =  a[i] - a[i-1];
         if( i > 1 && rem.count(val) == 0 ) {
           rem.insert(val);
           ll a1 = a[i] - (i-1)*val;
           v[val] = a1;
           m[val] = 0;
         }
         
         if( i > 1 )
          m[val]++;
    }
    
    ll besta = LONG_MAX;
    ll bestd = LONG_MAX;
    
    for(set<ll>::iterator it = rem.begin(); it != rem.end(); it++) {
         
        if( n - 1 - m[*it] <= k ) {
            if( v[*it] < besta )
            { besta = v[*it]; bestd = *it; }
            else if( v[*it] == besta && *it < bestd )
             { bestd = *it; }
        }
    }
    
    if( besta == LONG_MAX )
    { besta = a[1]; bestd = a[2] - a[1]; }
    
    
    for( ll i = 1; i <= n; i++ ) {
     ll val = besta + (i-1)*bestd;
     printf("%lld ", val );
    }
  
  //cin >> n;
}
