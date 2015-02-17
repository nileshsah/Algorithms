#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a)
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
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

ll gcd( ll a, ll b ) { return ( ( b == 0 ) ? a : gcd( b, a%b ) ); }

int main() {
	ll n; get(n);
	vector<ll> v;
	ll g;
	
	rep(n) {
		ll x; get(x);
		v.pb(x);
		
		if( i > 1 )
			g = gcd( g, x - v[v.size()-2] );
		else if( i == 1 )
			g = x - v[v.size()-2];
		
	}
	
	double h = double ( v[v.size()-1] - v[0] );	
	 h /= g;
	 h++;
	ll m = ceil(h);
	
	printf("%ld\n", m - n );	
}
