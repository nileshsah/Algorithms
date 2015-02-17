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
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;
 
inline ll dist( pair<ll,ll> p, pair<ll,ll> q ) {
   return ( (p.F-q.F)*(p.F-q.F) + (p.S-q.S)*(p.S-q.S) );
}
 
int main() {
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
		bool bit[500] = {0};
		vector< pair<ll,ll> >  idx[n+1];
		ll mat[500] = {0};
		ll mm = INT_MAX, ii = 0;
	 
	 FOR(k,0,n) {
	 	ll ptr = k;
		FOR(z,1,n) {
		 ll i = ptr;
		 ll mix = INT_MAX;
		 bit[i] = 1;
		 FOR(j,0,v.size())
		 	if( j == i || bit[j] )
		 		continue;
		 	else if( dist( v[i], v[j] ) < mix )
		 	 { ptr = j; mix = dist( v[i], v[j] ); }
 		 
		   mat[k] += mix;
		   idx[k].pb( mp(i+1,ptr+1) );
		}
		
		if( mm < mat[k] )
		  { ii = k; mm = mat[k]; }
	 }
	 
	 repVector(idx[ii])
	 	printf("%ld %ld\n", it->F, it->S);
	 
	}
} 
