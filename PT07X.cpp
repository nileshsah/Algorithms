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

vector<ll> v[100005];
ll parent[100005] = {0};
ll dp[100005][2] = {0};

ll rec( ll r, ll par, int mark = 0 ) {
	if( dp[r][mark] != -1 )
		return dp[r][mark];
//	cout << " REC: " << r << " " << mark << endl;
		
	ll ans = 0;
	
	repVector(v[r]) {
		if( *it == par ) 
			continue;
		
		if( mark )
		  ans += min( 1 + rec( *it, r, 1 ), rec( *it, r ) );
		else
		  ans += 1 + rec( *it, r, 1 );		
	}
	
	dp[r][mark] = ans;
	return ans;
		
}

int main() {
	memset( dp, -1, sizeof dp );

	ll n; get(n);
	rep(n-1) {
		ll x, y;
		get(x); get(y);
		v[min(x,y)].pb(maxy);

		parent[y] = x;
	}
	
	cout << min( 1+rec(1,0,1), rec(1,0,0) );
	
}
