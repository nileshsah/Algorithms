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

		
ll dpH[105][105][27] = {0};
ll dpV[105][105][27] = {0};
ll dp[105][105][27] = {0};
ll arr[105][105] = {0};

int main() {
	INPFILE;
	ll n, kk;
	get(n); get(kk);
	char str[105][105] = {0};
	
	FOR(i,1,n)
	 scanf("%s", str[i]+1);
	
	FOR(i,1,n)
	 FOR(j,1,n)
	  arr[i][j] = str[i][j] - 'A';
		
	FOR(i,1,n)
	 FOR(j,1,n) {
	  FOR(k,0,25) {
	   dpH[i][j][k] += dpH[i-1][j][k] + dpH[i][j-1][k];
	   dpV[j][i][k] += dpV[j-1][i][k] + dpV[j][i-1][k];
	   dp[i][j][k]  += dp[i-1][j-1][k];
	  }
	  	dp[i][j][ str[i][j] - 'A' ]++;
		dpH[i][j][ str[i][j] - 'A' ]++;
	 // 	dp[j][i][ str[j][i] - 'A' ]++;

	 }
	 
	 ll ans = 0;
	 
	 FOR(i,1,n)
	  FOR(j,1,n)
	   FOR(x,i,n)
	    FOR(y,j,n) {
	    	ll val = 0;
	     FOR(k,0,25)
	      if( dp[x][y][k] + dp[i-1][j-1][k] - dp[i-1][y][k] - dp[x][j-1][k] > 0 )
	      	 val++;
	     if( val == kk )
	      { ans++;  printf("(%ld,%ld) - (%ld,%ld)\n", i,j,x,y ); }
	 }
	printf("%lld\n", ans);
}

