#include <bits/stdc++.h>
#include <cstdio>
#define ll int
#define llu long long unsigned
#define get(a) scanf("%d", &a);
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


ll search( vector<ll> v, ll start, ll end, ll val ) {
	ll mid = ( start + end )/2;
	
	if( start > end )
		return start;
	if( val < v[mid] )
		return search( v, start, mid-1, val );
	else 
		return search( v, mid+1, end, val );
	
	
}

int main() {
	ll t; get(t);
	while(t--) {
		ll n; get(n);
		vector<ll> v(n+1,0);
		get(v[0]);
		ll ans = 0;
	
		rep(n-1) {
		   ll x; get(x);
		   ll val = search( v, 0, i, x );
		   v.insert( v.begin() + val, x );
		   ans += i+1 - val;
		}
		
		printf("%d\n", ans);
	}
	
}
