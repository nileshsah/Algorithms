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
#define F first
#define S second
#define mp make_pair
#define foo(a,b,c) mp( mp(a,b), c )
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

vector<ll> v;
ll ans = LLONG_MAX;
ll n, c;


void rec( ll x, ll sum ) {
	
	if( c-sum >= 0 )
	 ans = min( ans, c-sum );

	if( sum > c || x >= v.size() )
		return;
			
	FOR(i,x,v.size()-1)
	 if( sum+v[i] <= c )
	  rec( i+1, sum+v[i] );
}

int main() {
	ll t; get(t);
	while(t--) {
		get(n); get(c);
		v.clear();
		ans = LLONG_MAX;
		
		FOR(i,1,n)
		 { ll x; get(x); v.pb(x); }
		
		sort( all(v) );
		
		rec(0,0);
		
		printf("%lld\n", ans);
	}
}
