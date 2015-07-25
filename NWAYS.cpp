#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
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
#define mod 1000000007
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll dp[1005][1005] = {0};

int main() {
	ll n = 1000;
	dp[0][1] = 1;
	FOR(i,1,n)
	 FOR(j,1,n)
	  dp[i][j] = ( dp[i-1][j] + dp[i][j-1] )%mod;
	
	ll t; get(t);
	while(t--) {
	  ll n, k;
	  get(n); get(k);
	  
	  FOR(i,1,k) { 
	   FOR(j,1,n)
	    cout << dp[k][i] << " ";
	   cout << "\n";
	 }
	  	
	  ll ans = 0;
	  FOR(i,1,n)
	   ans = ( ans + dp[k][i] )%mod;
	  printf("%lld\n",ans);
	}
	
	
	
}
