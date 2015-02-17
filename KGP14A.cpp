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
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main() {
//	INPFILE;
	ll t, c = 1; get(t);
	while(t--) {
		ll n; get(n);
		vector<ll> h, k;
		
		rep(n)
		 { ll x; get(x); h.pb(x); }
		
		rep(n)
		 { ll x; get(x); k.pb(x); }
		
		sort( all(h) );
		sort( all(k) );
		
		ll ans = 0;
		
		FOR(i,0,n)
		 ans += abs( h[i] - k[i] );
		
		printf("Case %ld: %ld\n", c++, ans);
		
		 
	}
}
