#include <bits/stdc++.h>
#include <cstdio>
#define ll int
#define get(a) scanf("%d", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector< pair< ll, pair<ll,ll> > >::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set< pair< ll, pair<ll,ll> > >::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

int main()  {
	while(1) {
		ll n; get(n);
		if( n == 0 ) break;
		vector<ll> v;
		v.pb(0);
		
		ll val = 0;
		bool ptr = 1;
		
		rep(n) {
			ll x; get(x);
			v.pb(x);
		}
		
		sort( all(v) );
		
		FOR(i,1,v.size()) {
			val = v[i] - v[i-1];
			if( val > 200 )
				{ ptr = 0; break; }
		}	
		
		
		ll b = 1422 - v.back();
		
		if( 2*b > 200 ) ptr = 0;
		
		if( ptr )
		 printf("POSSIBLE\n");
		else
		 printf("IMPOSSIBLE\n");			
		
	}
}
