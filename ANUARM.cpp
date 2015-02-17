#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) scanf("%lld", &a)
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
#define mp make_pair
using namespace std;

ll gcd( ll a, ll b ) { return ( ( b == 0 ) ? a : gcd( b, a%b ) ); }


int main() {
	ll t; get(t);
	while(t--) {
	  ll n,m;
	  get(n); get(m);
	  vector<ll> v;
	  ll maxx = LONG_MIN, minn = LONG_MAX;
	  
	  rep(m) {
	 	ll x; get(x);
	 	maxx = max( maxx, x );
	 	minn = min( minn, x );
	  }
	  	  
	  rep(n)
	   { printf("%lld ", max( abs(i - minn ), abs( i - maxx ) ) ); }
	  printf("\n");
	}
}
