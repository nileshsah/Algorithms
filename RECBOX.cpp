#include <bits/stdc++.h>
#define ll int
#define get(a) scanf("%d", &a);
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
//	INPFILE;
	ll t; get(t);
	while(t--) {
		ll n, m;
		get(n); get(m);
		ll val[1005];
		vector<ll> v[1005];
		set<ll> idx;
		
		FOR(i,1,n)
		 get(val[i]);
		
		FOR(i,1,m) {		
			ll x, y;
			get(x); get(y);	
			v[x].pb(y); v[y].pb(x);
		}
		
		ll ans = 0;
		bool mark[1005] = {0};
		
		ll D[1005] = {0}, O[1005] = {0};
		set< pair<ll,ll> > s;
		
		FOR(k,1,n) {
		  ll ptr = k;
		  repVector(v[ptr]) {
		   if( !mark[*it] )
		    D[ptr] += val[*it];
		  }
		  O[ptr] = D[ptr];
		  D[ptr] -= v[ptr].size()*val[ptr];
		  s.insert( mp(D[ptr],ptr) );
		}
		
		
		
	  while( s.size() != 1 ) {
		 ll ptr = s.begin()->S;
		 ans += O[ptr];
		 mark[ptr] = 1;
		 
//		cout << "REM: " << ptr << " - " << O[ptr] << endl;

		 repVector(v[ptr])
		  if( !mark[*it] ) {
		  s.erase( mp( D[*it], *it ) );
		  D[*it] += val[*it] - val[ptr];
		  O[*it] -= val[ptr];
		  s.insert( mp( D[*it], *it ) );
		 }

		 s.erase(s.begin());

	  }
			
	   printf("%d\n", ans);	
		
	}
}
