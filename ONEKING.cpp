#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define max(a,b) ( (a > b) ? a : b )
#define min(a,b) ( (a < b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main() {
//	INPFILE;
	ll t; get(t);
	while(t--) {
		ll n; get(n);
		vector< pair<ll,ll> > v;
		
		rep(n) {
			ll x, y;
			get(x); get(y);
			v.pb( mp(x,y) );
		}
		
		sort( all(v) );
		
		ll ans = 1;
		
		FOR(i,1,v.size()-1) {
			if( v[i].F <= v[i-1].S ) {
				v[i].F = max( v[i].F, v[i-1].F );
				v[i].S = min( v[i].S, v[i-1].S );
			}
			else
				ans++;
		}
		
		printf("%ld\n", ans);
		 
	}
}
