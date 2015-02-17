#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) scanf("%lld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector< pair<ll,double> >::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set< pair< ll, pair<ll,ll> > >::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 10000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

int main() {
	while(1) {
		ll n, m;
		get(n); if( n == 0 ) return 0;
		get(m);
		
		vector< pair<ll,double> > v[n+1];
		
		rep(m) {
			ll x, y; double p;
			get(x); get(y); scanf("%lf", &p);
			v[x].pb( mp(y,p/100) );
			v[y].pb( mp(x,p/100) );
		}
		
		vector<double> D(n+1,LONG_MAX);
		set< pair<double,ll> > s;
		s.insert( mp(-1,1) );
		D[1] = -1;
		
		while(!s.empty()) {
		 ll ptr = s.begin()->S;
		 double d = s.begin()->F;
		 s.erase(s.begin());
		 
		 if( d <= D[ptr] )
		  repVector(v[ptr]) {
		  	if( D[it->F] > -absol( D[ptr]*(it->S) ) ) {
		  	   if( D[it->F] != LONG_MAX )
		  	   	s.erase( s.find( mp(D[it->F],it->F) ) );
		  	   D[it->F] = -absol( D[ptr]*(it->S) );
		  	   s.insert( mp(D[it->F],it->F) );
			}
		  }
	
		}
		 
		printf("%0.6lf percent\n", absol(D[n]*100) );
	}
}
