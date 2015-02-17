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
#include <cmath>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define max(a,b) a > b ? a : b
#define pb push_back
using namespace std;

vector<ll> v;
ll n, k;

bool func( ll mid ) {
     ll first = v[0];
     ll count = 1;
     
     rep( v.size() ) {
       if( v[i] - first >= mid )
          { count++; first = v[i]; }
       if( count >= k )
           return 1;
     }
     
     return 0;
}

ll binsearch( ll top, ll rear ) {
     int mid = top + rear;
     mid /= 2;
     
     //cout << "( " << top << " , " << rear << " )";
     if( top >= rear ) {
         return top-1;
     }
         
     ll r = func(mid);
     if( r == 1 )
        return binsearch( mid+1, rear );
     else if( r == 0 )
        return  binsearch( top, mid );
     
     
}

int main() {
    ll t;
    get(t);
    
    while(t--) {
      get(n); get(k);
      v.clear();
      ll max = 0;
      
      rep(n) {
         ll x;
         get(x);
         v.pb(x);
         max = max > x ? max : x;
      }
      
      sort( all(v) );
      
      
      printf("%ld\n", binsearch(0, max-1) );
    }
}
