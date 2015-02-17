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

int main() {
	ll t;
	get(t);
	
	while(t--) {
		ll x, y;
		get(x); get(y);
		ll final = x%y;
		final %= 4;
		
		if( x == 1 )
			final = 1;
		else if( y == 1 )
			final = 2;
			
		if( final == 0 )
			printf("U");
		else if( final == 1 )
			printf("R");
		else if( final == 2 )
			printf("D");
		else if( final == 3 )
			printf("L");
		printf("\n");
		
	}
}
