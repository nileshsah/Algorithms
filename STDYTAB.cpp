#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( auto it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
#define MOD 1000000000
#define foo pair< pair<ll,ll>, ll >
using namespace std;

ll dp[2005][2005] = {0};
ll sum[2005][2005] = {0};
ll arr[2005][2005] = {0};

int main() {
	FOR(i,1,2000) {
	 dp[0][i] = 1;
	 sum[0][i] += sum[0][i-1] + 1;
	}
	
	FOR(i,1,2000)
	 FOR(j,1,2000) {
	  dp[i][j] = sum[i-1][j]%MOD;
	  sum[i][j] = ( sum[i][j-1] + dp[i][j] )%MOD;
	}
	
	
	ll t; get(t);
	while(t--) {
		ll n, m;
		get(n); get(m);
		ll ans = 0, sum = 0;
		
		FOR(i,0,m)
		 arr[0][i] = 1;
		
		FOR(i,1,n)
		 FOR(j,0,m) {
		  arr[i][j] = ( dp[j][m]*arr[i-1][j] )%MOD;
		  if( j-1 >= 0 )
		   arr[i][j] += arr[i][j-1];
		  arr[i][j] %= MOD;
		 }
		 		  
		printf("%lld\n", arr[n][m]);
	}
}
