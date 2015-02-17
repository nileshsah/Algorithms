#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector< pair<ll,ll> >::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set< pair< ll, pair<ll,ll> > >::iterator it = s.begin(); it != s.end(); it++ )
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

int rec( ll start, ll sum ) {

}

int main() {
	ll t;
	get(t);
	
	while(t--) {
		ll a[50] = {0}, n, k;
		get(n); get(k);
		rep(k)
		 { ll x; get(x); a[x] = 1; }
		
		ll dp[40][40] = {0};
	
		dp[1][1] = 1;
		
		FOR(i,2,2*n+1)
		 FOR(j,0,i+1) {
		  if( a[i] == 1 ) {
		  	if( j == 0 ) 
			  dp[i][j] = 0;
		  	else
		  	  dp[i][j] = dp[i-1][j-1];
		  }
		  else {
		  	if( j == 0 )
		  	  dp[i][j] = dp[i-1][1];
		  	else
		  	  dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
		  }
		}

		printf("%ld\n", dp[2*n][0] );
	}
}
