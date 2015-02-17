#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll gcd( ll a, ll b ) { return ( ( b == 0 ) ? a : gcd( b, a%b ) ); }
ll lcm( ll a, ll b ) { return a*b/gcd(a,b); }

ll n, m, l, r;
ll ans = 0;

void rec( ll arr[], ll x ) {
				 		 	
	if( x > n ) {
		ll val = 1;
		FOR(i,1,n)
	    	val = lcm( arr[i], val );
		FOR(i,l,r)
		 if( val%i == 0 ) {
		 	/*cout << " VAL: " ;
		 	FOR(i,1,n)
			   cout << arr[i] << " ";
			cout << " LCM: " << val << endl;
			 */ 	ans++;
		 }
		return;
	}
	
	FOR(i,1,m) {
	   arr[x] = i;
	   rec( arr, x+1 );
	}
	 
}

int main() {
		 
	ll t; get(t);
	while(t--) {
		get(n); get(m); get(l); get(r);
		
		ll arr[10000] = {0};
		ans = 0;
		rec( arr, 1 );
		
		
		printf("%lld\n", ans);
		
	}
}
