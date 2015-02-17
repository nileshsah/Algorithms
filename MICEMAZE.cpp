#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector< pair<ll,ll> >::iterator it = v.begin(); it != v.end(); it++ )
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
	ll n,t,m,e;
	get(n); get(e); get(t);
	
	vector< pair<ll,ll> > v[100+5];
	
	get(m);
	while(m--) {
		ll x, y, d;
		get(x); get(y); get(d);
		v[x].pb( mp(d,y) );
	}
	
	ll ans = 0;
	
	FOR(i,1,n) {
		ll D[100+5];
		
		FOR(j,1,n)
		 D[j] = INT_MAX;
		
		set< pair<ll,ll> > s;
		D[i] = 0;
		s.insert( mp(0,i) );
		
		while( !s.empty() ) {
			ll ptr = s.begin()->S;
			s.erase( s.begin() );			
			
			repVector( v[ptr] )
				if( D[ptr] + it->F < D[it->S] ) {
					s.erase( mp( D[it->S], it->S ) );
					s.insert( mp( D[ptr] + it->F, it->S ) );
					D[it->S] = D[ptr] + it->F;
				}
		}
		
		//cout << " TMP: " << i << " " << D[e] << endl;
		if( D[e] <= t )
			ans++;	
	}
	

	printf("%ld", ans);
	
	
	
}
