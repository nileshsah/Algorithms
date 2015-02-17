#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector< pair<ll,ll> >::iterator it = v.begin(); it != v.end(); it++ )
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

int main() {
	ll t;
	get(t);
	
	while(t--) {
		ll n; get(n);
		vector< pair<ll,ll> > v[n+1];
		map<string,ll> str;		
		
		rep(n) {
			char s[1000];
			scanf("%s", &s);
			str[string(s)] = i+1;
			ll m; get(m);
			while(m--) {
			   ll r,c; get(r); get(c);
			   v[i+1].pb( mp(r,c) );
			}
		}
		
		ll q; get(q);
		
		while(q--) {
			char x[1000], y[1000];
			scanf("%s %s", &x, &y);
			vector<ll> D(n+1,LONG_MAX);
			ll src = str[string(x)], dest = str[string(y)];
			
			set< pair<ll,ll> > s;
			s.insert( mp(0,src) );
			D[src] = 0;
			
			while(!s.empty()) {
				ll d = s.begin()->F;
				ll i = s.begin()->S;
				s.erase(s.begin());
				
				repVector(v[i])
				  if( D[it->F] > D[i] + it->S ) {
				  	if( D[it->F] != LONG_MAX )
				  		s.erase( mp(D[it->F],it->F) );
				  	D[it->F] = D[i] + it->S;
				  	s.insert( mp(D[it->F],it->F) );
				  }
				  		
			}
			
			printf("%ld\n", D[dest]);
		
		}
	}
}
