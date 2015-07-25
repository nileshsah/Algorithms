#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
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
#define foo pair< pair<ll,ll>, ll >
using namespace std;

int main() {
	ll t; get(t);
	while(t--) {
		ll n; get(n);
		vector<foo> v;
		FOR(i,1,n) {
		  ll m; get(m);
		  pair<ll,ll> p = mp( LONG_MIN, LONG_MIN );
		  FOR(j,1,m) {
		  	ll x, y;
		  	get(x); get(y);
		  	p = max( p, mp(x,y) );
		  }
		  v.pb( mp(p,i-1) );
		}
		
		sort( all(v) );
		ll ans[100005] = {0};
		
		FOR(i,0,n-1)
		 ans[ v[i].S ] = i;
		FOR(i,0,n-1) 
		 printf("%lld ", ans[i]);
		printf("\n");
						
	}
}
