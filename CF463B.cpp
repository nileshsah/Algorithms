#include <bits/stdc++.h>
#define ll int
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define DEBUG(x) cout << "[DEBUG]" << #x << " " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main() {
	ll n; cin >> n;
	
	vector<ll> v;
	v.pb(0);
	FOR(i,1,n)
	 { ll x; cin >> x; v.pb(x); }
	
	ll ans = 0;
	ll health = 0;
	
	FOR(i,1,v.size()-1) {
		ll val = v[i-1] - v[i];
		health += val;
		
		if( health < 0 )
		  { ans += abs(health); health = 0; }
	}
	
	cout << ans;
}
