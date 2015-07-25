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
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main() {
	ll fib[1005] = {0};
	ll ways[100005] = {0};
	fib[1] = 1; fib[2] = 1;
	ll i = 3;
	
	while(1) {
	  ll x = fib[i-2] + fib[i-1];
	  if( x > 100000 )
		 break;
	  fib[i++] = x;
	  ways[x] = 1;
	}

	ll n = i-1;
	
	FOR(i,1,100000) {
	  if( ways[i] ==  0 )
		ways[i] = LONG_MAX;
	 FOR(j,1,n) {
	  if( fib[j] > i )
	  	break;
	  ways[i] = min( ways[i], 1+ways[i-fib[j]] );
	 }
	}
	
	ways[0] = 1;
	
	ll t; get(t);
	while(t--) {
		ll x; get(x);
		printf("%ld\n", ways[x]);
	}
}
