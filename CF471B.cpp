#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) cin >> a
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

vector<ll> sum;

int srch( ll start, ll end, ll val ) {
	ll mid = ( start  + end )/2;
	
	if( start > end || end < start )
		return max( start, end );
	
	if( sum[mid] == val )
		return mid;
	if( val > sum[mid] )
		return srch( mid+1, end, val );
	else
		return srch( start, mid-1, val );
		
}

int main() {
	ll n,m;
	get(n);
	
	vector<ll> v(n);
	sum.pb(0);
	
	rep(n)
	 { get(v[i]); sum.pb( sum[i] + v[i] ); }
	
	get(m);
	
	while(m--) {
	  ll x; get(x);
	  cout << srch( 1, sum.size(), x ) << endl;
	}
	
}
