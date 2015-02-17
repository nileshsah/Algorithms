#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define llu long long unsigned
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
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

int main() {
	ll t; get(t);
	while(t--) {
		ll n; get(n);
		vector< pair<ll,ll> > v;
		
		rep(n) {
			ll x, y;
			get(x); get(y);
			v.pb( mp(y,x) );
		}
		
		sort( all(v) );
		ll ans = 0, i = 0;
		
		while( i < v.size() ) {
			ll end = v[i].F;
			ans++; i++;
			while( i < v.size() && v[i].S <= end )
				i++;
		}
		
		printf("%lld\n", ans);
		
	}
}
