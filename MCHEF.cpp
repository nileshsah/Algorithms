#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
 
 
ll dp[100005][501] = {0};
vector<ll> wt, cost;
 
ll rec( ll n, ll W ) {
	FOR(i,0,n)
	 FOR(w,0,W)
	  if( i == 0 || w == 0 )
	  	dp[i][w] = 0;
	  else if( wt[i-1] <= w )
	   dp[i][w] = max( cost[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w] );
	  else
	   dp[i][w] = dp[i-1][w];
	return dp[n][W];
}
 
int main() {
  //  INPFILE;
	ll t; get(t);
	while(t--) {
	   ll n, k, m, sum = 0;
	   get(n); get(k); get(m);
	   
	   vector<ll> v(n+1); set<ll> idx;
	   FOR(i,1,n)
	     { get(v[i]); sum += v[i]; if( v[i] < 0 ) idx.insert(i); }
	   
	   set< pair< ll, pair<ll,ll> > > s;	   
	   while(m--) {
	   	  ll l, r, c;
	   	  get(l); get(r); get(c);	   	  
	   	  s.insert( mp( c, mp(l,r) ) );
	   }
	     
	   wt.clear(); cost.clear();
	   
	   repVector(s) {
	   	  if( idx.empty() )
	   	   break;
	   	  auto itr = idx.lower_bound(it->S.F);
	   	  
	   	  while( itr != idx.end() && *itr <= it->S.S ) {
	   	  	wt.pb( it->F );
	   	  	cost.pb( abs(v[*itr]) );
	   	  	ll x = *itr; itr++;
	   	    idx.erase(x);
	   	  }
	   }
	   
	    
	   printf("%lld\n", sum + rec( wt.size(), k ));
	    
	}
} 
