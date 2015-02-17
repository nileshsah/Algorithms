#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( long i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
using namespace std;

vector<ll> v[100000+5];
bool a[100000+5] = {0};
ll mm = 0;

ll dfs( ll n, ll val ) {
   // cout << " CALL: " << n << " VAL: " << val << endl;
   ll max = val;
   a[n] = 1;
   vector<ll> adj;
   
   for(vector<ll>::iterator it = v[n].begin(); it != v[n].end(); it++ )
      if( a[*it] == false ){
          ll ret = dfs(*it, val+1);
          // cout << " RET: " << *it << " VAL: " << ret << endl;
          adj.pb(ret-val);
          max = max > ret ? max: ret;       
      }
   

     
   
    ll ans = 0;
    if( adj.size() >= 2 )
      {  sort( all(adj), greater<ll>() ); ans = adj[0]+adj[1]; }
    else if( !adj.empty() )
      ans = adj[0];
    else
      ans = 0;
    
   //cout << "Vector #" << n;
  /* repVector(adj) {
     cout << " " << *it;
   }*/
  // cout << ":ans: " << ans << endl;
   
    mm = mm > ans ? mm : ans;
   return max; 
}

int main() {
    ll n;
    get(n);
    
    rep(n) {
      ll x, y;
      get(x); get(y);
      v[x].pb(y); v[y].pb(x);
    }
    
    a[1] = 1;
    dfs(1,1);
    ll ans = 0;

    
    printf("%ld", mm);
    //cin >> n;
      
}
    
