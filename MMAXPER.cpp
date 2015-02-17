#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define llu long long unsigned
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
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

vector< pair<ll,ll> > v;

map< pair<ll,pair<ll,ll> >, ll > dp;

ll rec( pair<ll,ll> adj = mp(0,0), ll n = 0 ) {
	if( n == v.size() )
		return 0;
    if( dp[ mp( n, adj ) ] != 0 )
		return dp[ mp( n, adj ) ];
	
	
	ll ans1 =  v[n].F, ans2 = v[n].S;
	if( adj.F != 0 && adj.S != 0 ) {
		ans1 += abs( v[n].S - adj.S );
		ans2 += abs( v[n].F - adj.S );
	}
	
	pair<ll,ll> adj1 = v[n], adj2 =  mp( v[n].S, v[n].F );
	
	ll val = max( ans1 + rec( adj1, n+1 ), ans2 + rec( adj2, n+1 ) );
	dp[ mp( n, adj ) ]= val;
//	cout << " REC: " << n << " " << dp[adj.F][adj.S] << endl;
	return val;
}

int main() {
	ll n; get(n);
	rep(n) {
		ll x, y;
		get(x); get(y);
		v.pb( mp(x,y) );
	}
	
	vector< pair<ll,ll> > adj;
	rec( );
	
	cout << dp[ mp( 0, mp(0,0) ) ];
	
}
