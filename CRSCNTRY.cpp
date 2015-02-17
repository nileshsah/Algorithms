#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

ll dp[2001][2001] = {0};

ll LCS( vector<ll> a, vector<ll> b ) {
	
	memset( dp, 0, sizeof dp );
	
	FOR(i,1,a.size()+1)
	 FOR(j,1,b.size()+1) {
	 	
	 	if( a[i-1] == b[j-1] )
	 		dp[i][j] = dp[i-1][j-1] + 1;
	 	else
	 		dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
	 }
	 
	 return dp[a.size()][b.size()];
}

int main() {
	ll t; get(t);
	while(t--) {
		matrix adj;
		while(1) {
			vector<ll> v;
			ll a, b; get(a);
			if( a == 0 ) break;
			get(b); v.pb(a);
		
			while( b != 0 )
			 { v.pb(b); get(b); }
			adj.pb(v);
		}
		
		ll ans = 0;
		FOR(i,1,adj.size())
			ans = max( ans, LCS( adj[0], adj[i] ) );
		printf("%ld\n", ans);
	}
}
