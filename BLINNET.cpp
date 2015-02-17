#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for(vector< pair<ll,ll> >::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

ll parent[10000+5];

ll rec( ll r ) {
	if( r != parent[r] )
		r = rec(parent[r]);
	return r;
}

int main() {
	ll t; get(t);
	while(t--) {
		ll n; get(n);
		string s[n+1];
		set< pair< ll, pair<ll,ll> > > v;
		
		rep(n) {
			char str[15];
			scanf("%s", str);
			parent[i] = i;
			ll m; get(m);
			while(m--) {
				ll x, d;
				get(x); get(d);
				v.insert( mp( d, mp( min(i,x), max(i,x) ) ) );
			}
		}
		
		ll ans = 0;
		
		repSet(v) {
			ll x = rec(it->S.F);
			ll y = rec(it->S.S);
			
			if( x != y )
			 { ans += it->F; parent[x] = y; }
			
		}
		
		printf("%ld\n", ans);
		
		
		
	}
}
