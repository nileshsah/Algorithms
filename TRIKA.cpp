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
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main() {
//	INPFILE;
	ll n, m, x, y;
	get(n); get(m);
	get(x); get(y);
	
	ll P[50][50];
	matrix dp( n+1, vector<ll>( m+1, 0 ) );

	FOR(i,1,n)
	 FOR(j,1,m) {
	   ll val; get(val);
	   if( i >= x && j >= y )
	   	dp[i][j] = val;
	 }
	 

	FOR(i,x,n)
	 FOR(j,y,m)
	 	if( i == x && j == y )
	 		continue;
	 	else
	 	  dp[i][j] = max( dp[i][j-1] - dp[i][j], dp[i-1][j] - dp[i][j] );
	
	
	if( dp[n][m] < 0 )
		printf("N");
	else
	  printf("Y %ld", dp[n][m]);  
	  
	
}
