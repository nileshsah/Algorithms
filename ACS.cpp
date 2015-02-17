#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSTL(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

ll mat[1235][5679] = {0};

int main() {
	char c;
	ll row[1235], col[5679];
	ll sum = 1;
	
	FOR(i,1,1234)
	 FOR(j,1,5678)
	 	mat[i][j] = sum++;
	
	FOR(i,1,1234)
	  row[i] = col[i] = i; 
	FOR(i,1235,5678)
	  col[i] = i;
	  
	while( scanf("%c", &c) != EOF ) {
		ll x, y;
		if( c == 'R' ) {
			get(x); get(y);
			swap( row[x], row[y] );
		}
		else if( c == 'C' ) {
			get(x); get(y);
			swap( col[x], col[y] );
		}
		else if( c == 'Q' ) {
			get(x); get(y);
			printf("%ld\n", ( row[x] - 1 )*5678 + col[y] );
		}
		else if( c == 'W' ) {
			get(x);
			ll p, q;
			ll r = ( x/5679 ) + 1;
			ll c = x % 5678;
			c = ( c == 0 ) ? 5678 : c;
			for( p = 1; row[p] != r; p++ );
			for( q = 1; col[q] != c; q++ );
			
			printf("%ld %ld\n", p, q);
		}
	}
}
