#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define absol(a) a >= 0 ? a : -a
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
using namespace std;

int main() {
	ll n, m;
	get(n); get(m);
	
	ll a[105][105] = {0};
	matrix dp( 105, vector<ll>(105, INT_MAX) );
	
	rep(m+1)
	 dp[0][i] = 0;
		
	FOR(i,1,n)
	 FOR(j,1,m)
	 	get(a[i][j]);
	
    
    FOR(i,1,n)
     FOR(j,1,m)
      dp[i][j] =  a[i][j] +  min( dp[i-1][j] , min( dp[i-1][j-1], dp[i-1][j+1] )  );

	ll small = INT_MAX;
	
	FOR(i,1,m)
	  if( small > dp[n][i] )
		small = dp[n][i];
	
	printf("%ld", small );

}
