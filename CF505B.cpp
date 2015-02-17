#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

vector<ll> v[105][105];
bool explore[105][105][105] = {0};

set<ll> ans;

void dfs( ll r, ll y, ll c ) {
	if( r == y )
		{ ans.insert(c); return; }
		
	repVector(v[r][c]) 
	 if( !explore[r][*it][c] ) {
	 	explore[r][*it][c] = explore[*it][r][c] = 1;
	 	dfs( *it, y, c );
	 }
}

int main() {
//	INPFILE;
	ll n, m;
	cin >> n >> m;
	
	FOR(i,1,m) {
	  ll a, b, c;
	  cin >> a >> b >> c;
	  v[a][c].pb(b);
	  v[b][c].pb(a);
	}
	
	ll q; cin >> q;
	while(q--) {
		ll x, y;
		cin >> x >> y;
		
		ans.clear();
		memset( explore, 0, sizeof explore );
		
		
		FOR(i,1,m)
		 repVector( v[x][i] )
		   if( ans.count(i) == 0 ) {
	 	 	explore[x][*it][i] = explore[*it][x][i] = 1;
		 	dfs( *it, y, i );
		 }
		 else 	break;
		 
		cout << ans.size() << endl;
		
	}
}
