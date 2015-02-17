#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main() {
	ll dp[105][105] = {0};
	dp[0][0] = 1;
	
	FOR(i,1,100)
	 FOR(j,0,i)
	  FOR(k,0,j)
	   { dp[i][j] += dp[i-1][j-k]; dp[i][j] %= 761238923; }
	
	while(1) {
		ll n; get(n);
		if( n == 0 ) return 0;
		
		printf("%ld\n", dp[n][n]);
	}
	
}
