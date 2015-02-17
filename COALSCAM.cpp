#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define repSTL(i, c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
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
#define foo(c,a,b) mp( c, mp(a,b) )
#define INPFILE freopen("input.in", "r", stdin)
using namespace std;

ll parent[5005] = {0};

ll find( ll x ) {
	if( parent[x] == x )
	  return x;
	else 
	  return parent[x] = find( parent[x] );
}

void join( ll x, ll y ) {
	ll p = find(x);
	ll q = find(y);
	parent[p] = q;
}

int main() {
//	INPFILE;
	ll t; get(t);
	while(t--) {
		ll n, m1, m2;
		get(n); get(m1); get(m2);
		vector< pair<ll, pair<ll,ll> > > v;
		
		FOR(i,1,m1) {
			ll x, y, c;
			get(x); get(y); get(c);
			v.pb( foo(c,x,y) );
		}
		FOR(i,1,m2) {
			ll x, y, c;
			get(x); get(y); get(c);
			v.pb( foo(-c,x,y) );
		}
		
		FOR(i,0,n-1)
		 parent[i] = i;
		 		
		sort( all(v) );
		ll profit = 0, cost = 0;
		set<ll> s;
		
		repVector(v) {
			ll c = abs(it->F);
			ll x = it->S.F;
			ll y = it->S.S;
			
			if( find(x) == find(y) )
				continue;
			join( x, y );
			s.insert(x); s.insert(y);
			
			if( it->F < 0 )
			  profit += c;
			cost += c;
			
			if( s.size() == n )
				break;		
		}
		
		if( s.size() == n )
		 printf("%lld %lld\n", profit, cost );
		else
		 printf("Impossible\n");
		
	}
}
