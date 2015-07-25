#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define MOD 1000000007
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main() {
	ll n, m;
	cin >> n >> m;
	vector< pair<ll,ll> > v;
	
	FOR(i,1,m) {
		ll d, h;
		cin >> d >> h;
		v.pb( mp(d,h) );
	}
	
	ll ans = 0;
	
	ans = v[0].S + v[0].F - 1;
	ans = max( ans, v[0].S );
//	debug(ans);
	
	for( ll i = 1; i < v.size(); i++ ) {
		ll diff = v[i].S - v[i-1].S;
		ll id = v[i].F - v[i-1].F - 1;
				
		if( id+1 < abs(diff) )
		 { cout << "IMPOSSIBLE"; return 0; }
		
		diff++;
		 
		ll x = ( id + diff )/2;
		ll y = id - x;
		ans = max( ans, v[i-1].S + x );
		ans = max( ans, v[i].S );
//		debug(v[i].S); debug(ans);
	
	}
	
	if( v.back().F != n )
	 ans = max( ans, v.back().S + n - v.back().F );
	
	cout << ans;
	  
	 
}
