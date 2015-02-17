#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define foo(a,b,c) mp( mp(a,b), c )
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main() {
//	INPFILE;
	ll t; get(t);
	while(t--) {
		ll n; get(n);
		vector< pair< pair<ll,ll>, ll> > v;
		
		FOR(i,1,n) {
		  ll x, y, z; 
		  get(x); get(y); get(z); 
		  v.pb( foo(x,x+y,z) ); 
		}
		
		sort( all(v) );
		
		ll dp[10005] = {0};
		
		for( ll i = n-1; i >= 0; i-- ) {
			ll end = v[i].F.S;
			dp[i] = v[i].S;
		   FOR(j,i+1,n-1) {
		 	dp[i] = max( dp[i], dp[j] );
		   if( v[j].F.F >= end )
		  	dp[i] = max( dp[i], v[i].S + dp[j] );
		   } 
	    }
	    
	    printf("%lld\n", dp[0]);
		
	}
}
