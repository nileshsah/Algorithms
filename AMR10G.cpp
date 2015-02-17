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
    
int main() {
    ll t;
    get(t);
    
    while(t--) {
      ll n, k;
      get(n); get(k);
      
      vector<ll> v;
      
      rep(n) {
         ll x;
         get(x);
         v.pb(x);
      }
      
      sort( all(v) );
      
      ll min = LONG_MAX;
      rep(n-k+1) {
         ll x = v[i+k-1] - v[i];
         if( min > x )
             min = x;
      }
      
      printf("%ld\n", min);
    }
}
