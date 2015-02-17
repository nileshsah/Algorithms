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
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define max(a,b) a > b ? a : b
#define pb push_back
#define MOD 1000000007
using namespace std;

 map < pair<ll,ll>, long long > dp;
  vector<ll> v;
  
long long rec( ll x, ll y ) {
   if( x > y )
     return -LLONG_MAX;
   if( dp[make_pair(x,y)] != 0 )
       return dp[make_pair(x,y)];
       
 cout << x << "  " << y << endl;
 
 long long sum = v[y] - v[x-1];
 long long val =  max( rec( x + 1, y ), rec( x, y-1 ) );
 val = max( sum, val );
 dp[make_pair(x,y)] = val;
 return val;
}

int main() {
    ll n, m;
    get(n);
    v.pb(0);
    
    rep(n) {
       ll x;
       get(x);
       v.pb( x + v[v.size()-1] );
    }
    
    get(m);
    
    rep(m) {
       ll x, y;
       get(x); get(y);
       printf("%lld\n", rec(x,y));
    }
    
}
