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

ll n, d;
ll ans;
vector<ll> v;
ll dp[105][1005][1005] = {0};

ll rec( ll r, ll maxx, ll minx ) {
//	cout << " REC: " << r << " " << c << endl;
	if( r >= v.size() )
		return 0;	
	if( dp[r][maxx][minx] != -1 )
		return dp[r][maxx][minx];
		
	maxx = max( maxx, v[r] );
	minx = min( minx, v[r] );

	if( maxx - minx >= d  )
		return 1;
	ll val = 0;
		
	if( r+1 < v.size() )	
	 val = rec( r+1, maxx, minx );
	if( r+2 < v.size() )
	 val = min( val, rec( r+2, maxx, minx ) );
	val++;
	
	 dp[r][maxx][minx] = val;
	 return val;
}

int main() {
	ll t; get(t);
	while(t--) {
		get(n); get(d);
		v.clear();
		memset( dp, -1, sizeof dp );
		ans = n;
		
		FOR(i,1,n)
		 { ll x; get(x); v.pb(x); }
		
	/*	ll maxval[105] = {0}, minval[105] = {0};
		maxval[0] = minval[0] = v[0];
		
		FOR(i,1,n-1) {
			if( i > 1 ) {
				maxval[i] = min( maxval[i-2], v[i] );
				minval[i] = max( minval[i-2], v[i] );
			}
			maxval[i] = min( maxval[i-2], min( maxval[i], v[i] ) );
			minval[i] = max( minval[i-2], max( minval[i], v[i] ) );
		 	
		 	if( maxval
		}
		*/
		
		cout << rec( 0, v[0], v[0] ) << endl;

	}
}
