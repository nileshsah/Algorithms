#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define MOD 1000000007
#define INPFILE freopen("input.in","r",stdin)
using namespace std;



int main() {
   ll n, k, d;
   cin >> n >> k >> d;
   
   ll dp[105][2] = {0};
 
   dp[0][0] = dp[0][1] = 1;

   FOR(i,1,n)
    FOR(j,0,i-1)
     if( i - j > 0 && i - j < d ) {
      dp[i][0] += dp[j][0];
      dp[i][0] %= MOD;
  	 }
  	 

   FOR(i,1,n)
    FOR(j,0,i-1)
     if( i - j > 0 && i - j <= k ) {
      dp[i][1] += dp[j][1];
      dp[i][1] %= MOD;
	 }
		
//	debug(dp[n][0]); debug(dp[n][1]);
   cout << ( dp[n][1] - dp[n][0] + MOD )%MOD;
   
}
