#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
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
	  ll s, c, k;
	  get(s); get(c); get(k);
	  unsigned long long val = 0;
	  
	  if( s-k+1 > 0 )
	   val += pow( 2,(s-k+1) ) + 1;
	  if( c > s-k && s-k >= 0 )
	   val += pow( 2,(s-k+1) );
	  
	  if( k == 1 && s < c )
	   val = 2*( pow(2,c) - 1 );
	  else if( k == 1 && s > c )
	   val = pow( 2,s ) + 1;
	  
	  if( k == 1 && s != 0 && s < c )
	    val += 3;
	  
	  
	  
	  printf("%lld\n", val);
	}
}
