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
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 10000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

ll lca( ll x, ll y ) {
	
	while( min(x,y) != 1 ) {
		if( x > y )
			x /= 2;
		else if( y > x )
			y /= 2;
		else
			return log2(x) + 1;
	}
	
	return 1;
}

int main() {
	ll n; get(n);
	char color = 'b';
	
	rep(n) {
		char str[5];
		scanf("%s", str);
		string opt(str);
		
		if( opt == "Qb" ) {
			ll x, y;
			get(x); get(y);
			
			ll a = log2( max(x,y) ) + 1;
			ll b = log2( min(x,y) ) + 1;
			ll c = lca(x,y);
			
			
			if( ( c%2 == 0 && color == 'b' ) || ( c%2 != 0 && color == 'r' ) ) {
				ll l = a - c + 1;
				ll r = b - c + 1;
				
				printf("%lld\n", l/2 + r/2);
			}
			else {
				ll l = a - c;
				ll r = b - c;
				
				printf("%lld\n", l/2 + r/2 + 1 );
			}
			
		}
		else if( opt == "Qr" ) {
			ll x, y;
			get(x); get(y);
			
			ll a = log2( max(x,y) ) + 1;
			ll b = log2( min(x,y) ) + 1;
			ll c = lca(x,y);
			
			
			if( ( c%2 == 0 && color == 'b' ) || ( c%2 != 0 && color == 'r' ) ) {
				ll l = a - c;
				ll r = b - c;
				
				printf("%lld\n", l/2 + r/2 + 1);
			}
			else {
				ll l = a - c + 1;
				ll r = b - c + 1;
				
				printf("%lld\n", l/2 + r/2 );
			}

		}
		else if( opt == "Qi" ) {
			if( color == 'b' )
				color = 'r';
			else
				color = 'b';
		}
		
		
	}
}
