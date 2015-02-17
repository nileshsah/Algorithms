#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

vector<ll> v;

ll dp[205][205][205] = {0};

ll rec( ll r, ll b, ll w, ll bc, ll wc ) {
	if( r >= v.size() )
		return 0;
	
	if( dp[r][b][w] != -1 )
		return dp[r][b][w];
	
	ll ans = 0;
	
	if( v[r] < v[b] )
	  ans = max( ans, 1 + rec( r+1, r, w, bc+1, wc ) );
	if( v[r] > v[w] )
	  ans = max( ans, 1 + rec( r+1, b, r, bc, wc+1 ) );
	ans = max( ans, rec( r+1, b, w, bc, wc ) );
	
	dp[r][b][w] = ans;
	return ans;
}

int main() {
//	INPFILE;
	while(1) {
		ll n; get(n);
		v.clear();
		v.pb(-1); v.pb(LONG_MAX);
		memset( dp, -1, sizeof dp );
		
		if( n == -1 ) return 0;
		
		FOR(i,1,n)
		 { ll x; get(x); v.pb(x); }
		
		printf("%ld\n", n-rec(2,1,0,0,0) );
	}
}
