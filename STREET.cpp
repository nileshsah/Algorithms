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

ll n, k, t;
vector<ll> v;

ll dp[505][505] = {0};

ll rec( ll r, ll c ) {
	if( r >= v.size() || c >= k )
		return 0;
	if( dp[r][c] != -1 )
		return dp[r][c];
		
	ll ans = 0, mix = INT_MAX;
	
	FOR(i,r,min( int(v.size()-1) , int(r+t) ) ) {
	  mix = min( mix, v[i] );
	  ans = max( ans, mix*(i-r+1) + rec(i+1,c+1) );
	}
	
	ans = max( ans, rec(r+1,c) );
	
	dp[r][c] = ans;
	return ans;
}

int main() {
//	INPFILE;
	memset( dp, -1, sizeof dp );
	get(n); get(k); get(t);
	rep(n)
	 { ll x; get(x); v.pb(x); }
	 
	printf("%ld", rec(0,0));
}
