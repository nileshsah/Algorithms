#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define max(a,b) ( (a > b) ? a : b )
#define min(a,b) ( (a < b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<long> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main() {
//	INPFILE;
	ll t; get(t);
	while(t--) {
		ll w, h;
		get(w); get(h);
		
		ll W[205], H[205];
		
		ll n; get(n);
		rep(n)
		 { get(W[i]); get(H[i]); }
		
		
		ll dp[605][605] = {0};
		
		FOR(i,0,h+1)
		 FOR(j,0,w+1)
		  dp[i][j] = i*j;
				
		FOR(i,0,h+1)
		 FOR(j,0,w+1)
		  FOR(k,0,n)
		   if( i-H[k] >= 0 && j-W[k] >= 0)
		    dp[i][j] = min( dp[i][j], min( dp[i-H[k]][j] + dp[H[k]][j-W[k]], dp[i][j-W[k]] + dp[i-H[k]][W[k]] ) );
		
		printf("%ld\n", dp[h][w]);
	}
}
