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

int main() {
	ll t; get(t);
	while(t--) {
		ll n; get(n);
		vector<ll> v;
		ll minv[1005] = {0}, maxv[1005] = {0};
		
		FOR(i,1,n)
		 { ll x; get(x); v.pb(x); }
		
		minv[0] = maxv[0] = v[0];
		
		FOR(i,1,n-1) {
			minv[i] = min( v[i], minv[i-1] );
			maxv[i] = max( v[i], maxv[i-1] );
		}
		
		ll fluc = LONG_MIN;
		
		FOR(i,1,n-1)
		 fluc = max( fluc, v[i]-minv[i-1] );
		
		printf("%lld\n", fluc); 
	}
}
