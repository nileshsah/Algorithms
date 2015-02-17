#include <bits/stdc++.h>
#define ll long 
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define foo(a,b,c) mp( mp(a,b), c )
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll dp[3][100005] = {0};
ll n;

ll mark[100005] = {0};

ll rec( ll x = 1 ) {
	
	if( x > n )
		return 0;
	
	if( mark[x] != -1 )
		return mark[x];
		
	ll val = 0;
	
	if( x < n ) {
	  val  = max( dp[1][x], dp[1][x+1] ) - min( dp[1][x], dp[1][x+1] );
	  val += max( dp[2][x], dp[2][x+1] ) - min( dp[2][x], dp[2][x+1] );
	  val += rec( x+2 );
	}
	
	ll idx = max( dp[1][x], dp[2][x] ) - min( dp[1][x], dp[2][x] );
	idx += rec( x+1 );
	
	mark[x] = max(idx,val);
	return mark[x];
}

int main() {
	get(n);
	memset( mark, -1, sizeof mark );
	
	FOR(i,1,n)
	 get(dp[1][i]);
	FOR(i,1,n)
	 get(dp[2][i]);
	
	printf("%ld", rec());
}
