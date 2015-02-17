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

vector< pair<ll,ll> > v;
ll n;

ll dp[5005][5005] = {0};

ll rec( ll r = 0, ll c = 0, ll a = 0 ) {
	
	if( r >= n )
		return 0;
	if( dp[c][a] != 0 )
		return dp[c][a];
	
	ll ans = LONG_MAX;
	
	if( c < n/2 && a > c )
	  ans = min( ans, v[r].F + rec( r+1, c+1, a ) );
	if( a < n/2 )
	  ans = min( ans, v[r].S + rec( r+1, c, a+1 ) );
	
	dp[c][a] = ans;
	return ans;
}

int main() {
//	INPFILE;
	get(n);
	FOR(i,1,n) {
		ll x, y;
		get(x); get(y);
		v.pb( mp(x,y) );
	}
	
	printf("%ld", rec());
	
}
