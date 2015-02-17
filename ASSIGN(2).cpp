#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) scanf("%lld", &a);
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
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

ll dp[2000000] = {0};


int main() {
	ll t; get(t);
	while(t--) {
		ll n; get(n);
		ll mat[25][25] = {0};
		memset( dp, 0, sizeof dp );
		
		FOR(i,0,n)
		 FOR(j,0,n) {
		 	ll x; get(x);
			mat[i][j] = x;
		 }
		 
		 memset( dp, 0, sizeof dp );
		 
		 ll maxn = 0;
		 FOR(i,0,n)
		  { maxn <<= 1; maxn++; }
		 dp[maxn] = 1;
		 
		 for( ll ptr = maxn-1; ptr >= 0; ptr-- ) {
			ll tmp = ptr;
			ll k = 0;
			while( tmp ) {
				k += (tmp&1);
				tmp /= 2;
			}
			
			FOR(i,0,n)
			  if( mat[k][i] && !( ptr&(1<<i) ) )
			  	dp[ptr] += dp[ ptr | ( 1 << i ) ];		
		 }
		 
		printf("%lld\n", dp[0]);
		 	
	}
}
