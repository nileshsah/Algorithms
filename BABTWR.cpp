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

struct node {
	ll x;
	ll y;
	ll z;
	ll h;
	
	friend bool operator<( node a, node b ) {
		if( a.x != b.x )
			return a.x < b.x;
		else
			return a.y < b.y;
	}
};

int main() {
	while(1) {
		ll n; get(n);
		if( n == 0 ) return 0;
		
		vector<node> v;
			
		rep(n) {
			ll x, y, z;
			get(x); get(y); get(z);
			vector<ll> p; p.pb(x); p.pb(y); p.pb(z);
			sort( all(p) );
			node n;
			do {
				n.x = max(p[0],p[1]); n.y = min(p[0],p[1]); n.z = p[2];
				v.pb(n);				
			}while( next_permutation( all(p) ) );
		
		}
		
		sort( all(v) );
		ll ans = 0, xx, yy;
		
		
		FOR(i,0,v.size()) {
			v[i].h = v[i].z;
			xx = v[i].x; yy = v[i].y;
			FOR(j,0,i)		
		      if( v[j].x < v[i].x && v[j].y < v[i].y )
			    { v[i].h = max(v[i].h, v[j].h + v[i].z ); }
			ans = max(ans,v[i].h);
		}
		
		printf("%ld\n", ans);
		
	}
}
