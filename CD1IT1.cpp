#include <bits/stdc++.h>
#define ll long 
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define foo(a,b,c) mp( mp(a,b), c )
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main() {
	ll n; get(n);
	vector<ll> v;
	
	FOR(i,1,n)
	 { ll x; get(x); v.pb(x); }
	sort( all(v) );
	
	if( n%2 == 0 )
	  printf("%ld", v[n/2-1]);
	else
	  printf("%ld", v[(n-1)/2]);
	
}
