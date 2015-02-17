#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main() {
	ll t; get(t);
	while(t--) {
		ll e, o;
		get(e); get(o);
		
		bool flag = 1;
		ll x = LONG_MAX;
		
		if( 3*e - 2*o >= 0 && (3*e - 2*o)%5 == 0 && ( 3*e - 2*o )/5 <= e )
			x = ( 3*e - 2*o )/5;
		
		if( 2*o - 3*e >= 0 && (2*o - 3*e)%5 == 0 && ( 2*o - 3*e )/5 <= o )
		  x = min( x, (2*o - 3*e)/5 );
		  
		if( x == LONG_MAX )
		 printf("-1\n");
		else
		 printf("%lld\n", x );
		
	}
}
