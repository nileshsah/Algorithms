#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cout << "[DEBUG]" << #x << " " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main() {
	ll t; cin >> t;
	while(t--) {
		ll l, n, k;
		cin >> l >> n >> k;
		
		vector<ll> v;
		FOR(i,1,n) {
		  ll x; cin >> x; v.pb(x);
		}
		
		sort( all(v) );
		ll ans = 0;
		
		FOR(i,0,v.size()-1)
		 FOR(j,i+1,v.size()-1) {
		  
		  if( v[i] > k )
		   { ans++; continue; }
		  if( v[j] - v[i] > k )
		    { ans++; continue; }
		  if( l - v[j] > k )
		    { ans++; continue; }
		 
		 }
		 
		 cout << ans << endl;
	}
}
