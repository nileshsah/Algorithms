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
ll dp[1005][1005] = {0};

ll rec( ll r, ll ptr ) {
	if( r >= v.size() )
		return 0;
	if( dp[r][ptr] != -1 )
		return dp[r][ptr];
	
	ll ans = 0;
	
	if( v[r].F >= v[ptr].F && v[r].S >= v[ptr].S )
		ans = 1 + rec( r+1, r );
	ans = max( ans, rec( r+1, ptr ) );
	
	dp[r][ptr] = ans;
	return ans;
		
}

int main() {
//	INPFILE;
	ll t; get(t);
	while(t--) {
		ll n; get(n);
		ll a[1005], b[1005];
		v.clear();
		memset( dp, -1, sizeof dp );
		v.pb( mp(INT_MIN,INT_MIN) );
		
		FOR(i,1,n)
		 get(a[i]);
		FOR(i,1,n)
		 { get(b[i]); v.pb( mp(a[i],b[i]) ); }
		
		sort( all(v) );
		printf("%ld\n", rec(1,0) );
	}
}
