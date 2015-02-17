#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
#define min(a,b) a < b ? a : b
#define absol(a) a >= 0 ? a : -a
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
using namespace std;

matrix mul( matrix a, matrix b ) {
	matrix c(2, vector<ll>(2,0) );
	
	FOR(i,0,2)
	 FOR(j,0,2)
	  FOR(k,0,2) {
	  	c[i][j] += ( a[i][k]*b[k][j] )%MOD;
	 	c[i][j] %= MOD;
	 }
	
	return c;  	
}

matrix fastpow( matrix a, ll n ) {
	matrix I(2, vector<ll>(2,0));
	I[0][0] = 1; I[0][1] = 0; I[1][0] = 0; I[1][1] = 1;
	if( n == 0 )
		return I;
	if( n == 1 )
		return a;
	if( n%2 == 0 )
		return fastpow( mul(a,a), n/2 );
	else
		return mul( a, fastpow( mul(a,a), (n-1)/2 ) );		
}

int main() {
	matrix v(2, vector<ll>(2,0));
	v[0][0] = 0; v[0][1] = 1; v[1][0] = 1; v[1][1] = 1;
	
	ll t;
	get(t);
	while(t--) {
		ll x, y;
		get(x); get(y);
		matrix temp = fastpow( v, y+1 );
		matrix sub = fastpow( v, x );
		ll ans = (temp[1][1]-sub[1][1]);
		if( ans < 0 )
			ans += MOD;
		printf("%lld\n", ans );
	}
}
