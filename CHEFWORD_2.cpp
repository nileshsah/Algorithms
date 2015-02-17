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

matrix I(26, vector<double>(26,0));


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
	FOR(i,0,25)
	 I[i][i] = 1;
	 
	ll t; get(t);

	matrix m( 26, vector<double>( 26, 0 ) );
					
	while(t--) {
		ll n, k;
		char str[100];
		get(n); get(k);
		scanf("%s", &str);
		string a(str);
		
		FOR(i,0,25)
		 FOR(j,0,25)
		 	scanf("%lf", &m[i][j]);
		
		m = fastpow( m, k );
		
		double ans = 0;
		ll cc = 0, nn = n;
		
		set<string> s;
		
		while(n--) {
		  scanf("%s", &str);
		  string b(str);
		
		  if( a.size() != b.size() ) continue;
			
		  s.insert(b);
		}
		
		for( set<string>::iterator it = s.begin(); it != s.end(); it++ ) {
			double tans = 1;
			
			string b = *it;
					
			FOR(i,0,a.size()-1)
				tans *= m[ a[i] - 'a' ][ b[i] - 'a' ];
			//cout << "BTW: " << tans << endl;
			ans += tans;
		}
			
		printf("%lf\n", ans);
		 	
	}
}
