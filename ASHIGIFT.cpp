#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

vector< pair<ll,ll> > v;
map<ll,ll> ppl;


bool check( ll n ) {
	repVector(v) {
		if( it->S < 0 && n <= -it->S )
			return 0;
		if( it->S < 0 )
		  n += it->S;
		if( it->S > 0 && ppl[it->F] <= n )
		  n += it->S;
	}
	if( n >= 1 )
		return 1;
	else
		return 0;
}

ll search( ll start, ll end ) {
	ll mid = start + end;
	mid /= 2;
	
	if( start > end )
		return start;
	if( check(mid) )
	 return search( start, mid-1 );
	else
	 return search( mid+1, end );
}


int main() {
//	INPFILE;
	ll t; get(t);
	while(t--) {
		ll x; get(x);
		ll b; get(b);
		v.clear();
		
		FOR(i,1,b) {
			ll x, y;
			get(x); get(y);
			v.pb( mp(x,-y) );
		}
		
		ll c; get(c);
		
		FOR(i,1,c) {
			ll p, q, r;
			get(p); get(q); get(r);
			ppl[p] = q;
			v.pb( mp(p,r) );
		} 
		ll ans = 0;
		
		sort( all(v) );
		cout << search( 1, 10e18 ) << endl;
		
	}
}
