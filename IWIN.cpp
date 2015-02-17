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
//	INPFILE;

	ll t; get(t);
	while(t--) {
		ll val = 0;
		FOR(i,1,15)
		 { ll x; get(x); val ^= x; }
		ll m; get(m);
		
		ll c = 0;
	
		while( val != 0 ) {
		  if( (val&1) )
		  	c++;
		  val = val>>1;
		}	
		
//		cout << c << endl;
		
		if( c > m )
		  printf("YES\n");
		else
		  printf("NO\n");	
	}
}
