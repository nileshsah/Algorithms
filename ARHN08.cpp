#include <bits/stdc++.h>
#define ll long long
#define get(a) cin >> a;
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<string>::iterator it = s.begin(); it != s.end(); it++ )
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
#define INF LONG_MAX
using namespace std;

int main() {
	ll n; get(n);
	
	ll dp[20][20] = {0};
	
	FOR(i,1,n)
	 dp[1][i] = 1;
//	dp[1][1] = 1;
	
	FOR(i,2,n) {				 
	 FOR(j,1,n) {
	  FOR(k,1,j)
	   dp[i][j] += dp[i-1][k];
//	  cout << dp[i][j] << " ";
	 }
	 
//	 cout << endl;
	}
	
	ll ans = 0;
	FOR(i,1,n)
	 ans += dp[n][i];
	
	cout << ans;
	  
}
