#include <bits/stdc++.h>
#define ll int
#define get(a) scanf("%d", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define max(a,b) ( (a > b) ? a : b )
#define min(a,b) ( (a < b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll gcd( ll a, ll b ) {
   if( b == 0 )
       return a;
   else
       return gcd( b, a%b );
}

int main() {
//	INPFILE;
	ll t; get(t);
	while(t--) {
		ll n, q;
		get(n); get(q);
		vector<ll> v(n+1), L(n+1), R(n+1);
		
		rep(n) get(v[i]);
		
		L[1] = v[1];
		R[n] = v[n];
	
		FOR(i,1,n) {
		 L[i] = gcd( v[i], L[i-1] );
  		 R[n-i] = gcd( v[n-i], R[n-i+1] );
  	   }
			
		
		rep(q) {
			ll x, y;
			get(x); get(y);
			ll ans;
			if( x == 1 )
			  ans = R[y+1];
			else if( y == n )
			  ans = L[x-1];
			else
			  ans = gcd( L[x-1], R[y+1] );
			
			printf("%d\n", ans );
		}
		
	}
}
