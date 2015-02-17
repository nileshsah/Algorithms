#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSTL(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

ll dp[2][200][200] = {0};

ll rec( ll bit, ll n, ll k ) {
	if( n == 0 || k < 0 || k >= n )
		return 0;
		
	if( dp[bit][n][k] != -1 )
		return dp[bit][n][k];
	
	ll ans = 0;
	
	if( bit == 0 )
	 ans += rec( 0, n-1, k ) + rec( 1, n-1, k );
	else if( bit == 1 )
	 ans += rec( 1, n-1, k-1 ) + rec( 0, n-1, k );
	
//	printf("[%d][%ld][%ld] = %ld\n", bit, n, k, ans );
	dp[bit][n][k] = ans; 
	return ans;
}

int main() {
	ll t; get(t);
	memset( dp, -1, sizeof dp );
	dp[1][2][1] = 1;
	dp[0][2][0] = 2;
	dp[1][2][0] = 1;
	
	while(t--) {
		ll c, n, k;
		get(c); get(n); get(k);
		rec(1,n,k); rec(0,n,k);
		printf("%lld %lld\n", c, dp[0][n][k] + dp[1][n][k] );
	}
}
