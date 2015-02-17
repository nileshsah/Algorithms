#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
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
	ll x, y, d;
};

vector<node> v;
	
bool compare( const node a, const node b ) {
	return a.y <= b.y;
}

ll dp[1000000+5] = {0};

ll rec( ll end, ll n ) {
	if( n == v.size() )
		return 0;
	
	if( dp[n] != -1 )
		return dp[n];
		
	ll x, y;
	x = y = 0;
	
	if( v[n].x >= end )
	  x = v[n].d + rec( v[n].y, n+1 );
	y = rec( end, n+1 );
	
	dp[n] = max(x,y);
	return max(x,y);
	 
}


int main() {
	ll t; get(t);
	while(t--) {
		ll n; get(n);
		v.clear();
		memset( dp, -1, sizeof dp );
				
		rep(n) {
			node p;
			get(p.x); get(p.y); get(p.d);
			v.pb(p);
		}
		
		sort( all(v), compare );
		rec(0,0);
		
		printf("%ld\n", dp[0]);
		
		
	}
}
