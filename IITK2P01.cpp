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


int main() {
	ll t; get(t);
	while(t--) {
		long long n;
		long k;
		get(n); scanf("%ld", &k);
		
		long ans = 0;
		
		if( k == 1 )
		 { printf("%lld\n", n ); continue; }
		
		while( n > 0 ) {
		  ans += n%k;
		  n /= k;
		}
		
		printf("%ld\n", ans);
		
	}
}
