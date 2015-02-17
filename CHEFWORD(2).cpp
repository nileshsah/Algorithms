#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) scanf("%lld", &a)
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for(vector< pair<ll,ll> >::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set< pair< ll, pair<ll,ll> > >::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<double> >
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

matrix mul( matrix a, matrix b ) {
	matrix c(26, vector<double>(26,0) );
	
	FOR(i,0,25)
	 FOR(j,0,25)
	  FOR(k,0,25) {
	  	c[i][j] += ( a[i][k]*b[k][j] );
	 }
	
	return c;  	
}

matrix fastpow( matrix a, ll n ) {
	matrix I(2, vector<double>(2,0));
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
	ll t; get(t);
	while(t--) {
		ll n, k;
		char str[100];
		get(n); get(k);
		scanf("%s", &str);
		string a(str);
		
		matrix m( 25, vector<double>( 25, 0 ) );
				
		FOR(i,0,25)
		 FOR(j,0,25)
		 	scanf("%lf", &m[i][j]);
		
		m = fastpow( m, k );
		
		double ans = 0;
		
		while(n--) {
			scanf("%s", &str);
			string b(str);
			double tans = 1;
			
			if( a.size() != b.size() ) continue;
			
			FOR(i,0,a.size()-1)
				tans *= m[ a[i] - 'a' ][ b[i] - 'a' ];
			ans += tans;
		}
		
		printf("%lf\n", ans);
		 	
	}
}
