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
using namespace std;

int main() {
	ll n, k;
	cin >> n >> k;
	vector<ll> v;
	FOR(i,1,n) {
		ll x; cin >> x; 
		v.pb(x);
	}
	sort( all(v) );
	
	ll maxx = 1; ll x = v[0];
	ll end = 0, left = k;
	
	FOR(i,1,n-1) {
	 while( (i-end)*( v[i] - v[i-1] ) > left )
	 	{ left += v[i-1] - v[end]; end++; }
	  left -= (i-end)*( v[i] - v[i-1] );
	  if( i-end+1 > maxx )
	   { maxx = i-end+1; x = v[i]; }
	}
	 
	 cout << maxx << " " << x;
	
}
