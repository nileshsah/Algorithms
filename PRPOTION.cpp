#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) a >= 0 ? a : -a
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000009
using namespace std;

int main() {
	ll t;
	get(t);
	
	while(t--) {
		ll R, G, B, M;
		get(R); get(G); get(B); get(M);
		ll maxR = 0, maxG = 0, maxB = 0;
		ll sumR = 0, sumG = 0, sumB = 0;
		ll divR = 1, divG = 1, divB = 1;
		
		rep(R) {
			ll x; get(x);
			maxR = max( maxR, x );			
		}
		rep(G) {
			ll x; get(x);
			maxG = max( maxG, x );			
		}
		rep(B) {
			ll x; get(x);
			maxB = max( maxB, x );			
		}
		
		ll ans = LONG_MAX;
		ans = min( ans, max( maxR, max( maxB, maxG ) ) );
		
		FOR(i,1,M) {
			if( maxR >= maxG && maxR >= maxB )
			 { maxR /= 2;  }
			else if( maxG >= maxR && maxG >= maxB )
			 { maxG /= 2;  }
			else if( maxB >= maxG && maxB >= maxR )
			 { maxB /= 2; }
			
			ans = min( ans, max( maxR, max( maxB, maxG ) ) );
		}
		
		
		printf("%ld\n", ans);
			
	}
}
