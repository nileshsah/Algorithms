#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) cin >> a
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

ll c1, c2, x, y;


ll solve( ll start, ll end ) {
	if( start > end )
		return start;
	
	ll i = ( start+end )/2;
	
	ll v1 = i - i/x;
	ll v2 = i - i/y;
	ll v3 = i - i/(x*y);

	if( v1 < c1 || v3 < c1+c2 || v2 < c2 )
		solve( i+1, end );
	else
		solve( start, i-1 );
}

int main() {
	cin >> c1 >> c2 >> x >>  y;
	
	cout << solve(1,10e12);
	
}
