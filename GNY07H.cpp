#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define max(a,b) ( (a > b) ? a : b )
#define min(a,b) ( (a < b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll dp[5][1005] = {0};
ll N = 4, M = 1000;

ll rec( ll x, ll y ) {
//		printf(" REC: %ld %ld = %ld\n", x,y,dp[x][y]);

	if( x > N || y > M )
		return 0;

	
	if( dp[x][y] != -1 )
		return dp[x][y];
	
	ll m2x1 = 0, m1x2 = 0;
	// 2x1
	if( N - x >= 1 && M - y >= 2 )
		m2x1 = 1 + max( rec( N, y+2 ) + rec( x+1, 2 ) , rec( 1, y+2 ) + rec( x+1, y ) );
	// 1x2
	if( N - x >= 2 && M - y >= 1 )
		m1x2 = 1 + max( rec( x+2, 1 ) + rec( N, y+1 ), rec( 2, y+1 ) + rec( x+2, y ) );

	dp[x][y] = max( m2x1, m1x2 );

	printf(" REC: %ld %ld = %ld\n", x,y,dp[x][y]);
	return dp[x][y];
}

int main() {
	
	memset( dp, -1, sizeof dp );
	rec(0,0);
	
	ll t; get(t);
	while(t--) {
		ll n; get(n);
		printf("%ld %ld\n", rec(0,0) - rec(0,n+1));
	}
}
