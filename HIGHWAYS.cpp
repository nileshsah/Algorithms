#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSTL(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
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

vector< pair<ll,ll> > v[100005];
	

int main() {
	ll t; get(t);
	while(t--) {
		ll n, m, src, dest;
		get(n); get(m); get(src); get(dest);
		
		rep(m) {
			ll x, y, d;
			get(x); get(y); get(d);
			v[x].pb( mp(y,d) );
			v[y].pb( mp(x,d) );
		}
		
		set< pair<ll,ll> > s;
		vector<ll> D(n+1,INT_MAX);
		D[src] = 0;
		s.insert( mp(0,src) );
		
		while( !s.empty() ) {
			ll ptr = s.begin()->S;
			s.erase(s.begin());
			
			repVector(v[ptr]) 
			   if( D[ptr] + it->S < D[it->F] ) {
			 	s.erase( mp( D[it->F], it->F ) );
			   	D[it->F] = D[ptr] + it->S;
			   	s.insert( mp( D[it->F], it->F ) );
			 }
			
		}
		
		if( D[dest] == INT_MAX )
			printf("NONE\n");
		else
			printf("%ld\n", D[dest] );
	}
}
