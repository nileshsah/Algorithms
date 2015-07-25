#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( auto it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
#define MOD 1000000009
using namespace std;

ll n, l, r, ql, qr;

ll dp[100005][2] = {0};
vector<ll> v;

ll rec( ll x, bool last ) {
	if( x >= v.size() )
	 return 0;
	if( dp[x][last] != -1 )
	 return dp[x][last];
	return dp[x][last] = min( v[x]*l + last*ql + rec( x+1, 1 ),
	            v[x]*r + (!last)*qr + rec( x+1, 0 ) );
	          
}

int main() {
	cin >> n >> l >> r >> ql >> qr;
	FOR(i,1,n)
	 { ll x; cin >> x; v.pb(x); }
	memset( dp, -1, sizeof dp );
	cout << min( v[0]*l + rec( 1,1 ), v[0]*r + rec( 1,0 ) );
}
	
