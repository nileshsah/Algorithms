#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector< pair<ll,ll> >::iterator it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
#define max(a,b) a > b ? a : b
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
       ll max, n;
       vector< pair<ll,ll> > v;
       v.pb( make_pair(0,0) );
       
       get(max); get(n);
       ll val[500] = {0};
       
       
       while(n--) {
          ll x, y;
          get(x); get(y);
          pair<ll,ll> p;
          p.first = x;
          p.second = y;
          v.pb(p);
       }
      
    
       ll dp[500+5][500+5] = {0};
       bool keep[500+5][500+5] = {0};
       ll ans = 0;
       
       for( ll i = 1; i < v.size(); i++ ) {
        for( ll j = 0; j <= max; j++ ) {
             if( v[i].first > j )
              dp[i][j] = dp[i-1][j];
             else {
               ll temp = ( v[i].second + dp[i-1][ j - v[i].first ]);
               if( dp[i-1][j] < temp )
                 keep[i][j] = 1;               
               dp[i][j] = max( dp[i-1][j], temp );
             }
            // cout << dp[i][j] << " ";
             ans = max( ans, dp[i][j] );
        }
       // cout << endl;
       }  
       
       ll min = INT_MAX;
       
       for( ll i = 1; i < v.size(); i++ )
        for( ll j = 0; j <= max; j++ )
         if( dp[i][j] == ans )
          if( min > j )
           min = j;
             
      ll item = v.size()-1;
      ll size = max;
      ll tot = 0;
      
      while( size >= 0 && item >= 0 ) {
             if( keep[item][size] )
              { size -= v[item].first; tot += v[item].first;
                cout << " ->" << v[item].first << "\n";
              }
             item--;
      }
      
      
      printf("%ld\n", ans);
      
  }
     
}
