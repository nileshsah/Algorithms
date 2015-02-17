#include <bits/stdc++.h>
#define ll int
#define get(a) scanf("%d", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
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
	
	while(1) {
		ll n, t;
		get(n); get(t);
		
		if( n == 0 && t == 0 )
			return 0;
		
		ll time[100][100];
		ll toll[100][100];
		
		FOR(i,0,n)
		 FOR(j,0,n)
		  get(time[i][j]);
		
		FOR(i,0,n)
		 FOR(j,0,n)
		  get(toll[i][j]);
		
		matrix dp( t+1, vector<long>(n,INT_MAX/2) );
		
		FOR(i,0,t+1)
		 dp[i][n-1] = 0;
		
		FOR(i,0,t+1)
		 FOR(j,0,n)
		  FOR(k,0,n)
		   if( i - time[j][k] >= 0 )
		   	dp[i][j] = min( dp[i][j], toll[j][k] + dp[i-time[j][k]][k] );
		
		ll idx = t;
		while( idx >= 0 && dp[t][0] == dp[idx][0] )
			idx--;
		
		printf("%d %d\n", dp[t][0], idx+1);
		
	}
}
