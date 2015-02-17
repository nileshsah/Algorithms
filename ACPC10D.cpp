#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) a >= 0 ? a : -a
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
using namespace std;

int main() {
  ll count = 1;
  while(1) {
	ll n;
	get(n);
	
	if( n == 0 )
		break;
	
	matrix v( n+1, vector<ll>(5,0) );
	matrix dp( n+1, vector<ll>(5,INT_MAX) );
	
	FOR(i,1,n)
	 FOR(j,1,3)
	   get(v[i][j]);
		
	dp[1][1] = v[1][2];
	dp[1][2] = v[1][2];
	dp[1][3] = v[1][2] + v[1][3];
	
	
	FOR(i,2,n) 
	 FOR(j,1,3) 
	 	dp[i][j] = v[i][j] + min( dp[i-1][j] , min( dp[i-1][j+1], min( dp[i][j-1], dp[i-1][j-1] ) ) );

	
	printf("%ld. %ld\n", count++, dp[n][2] );
 }
		 		
}
