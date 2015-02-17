#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) scanf("%lld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector< pair<ll,ll> >::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set< pair< ll, pair<ll,ll> > >::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

int main() {
	ll t;
	get(t);
	
	ll dp[65][10] = {0};
	
	FOR(i,0,10)
	 dp[1][i] = 1;
	
	FOR(k,2,65)
	 FOR(i,0,10) {
	 	ll sum = 0;
	  FOR(j,i,10)
	  	sum += dp[k-1][j];
	  	dp[k][i] = sum;
      }
      
      ll ans[65] = {0};
      
     FOR(n,1,65) 
      FOR(i,0,10)
		  ans[n] += dp[n][i];
	  	
	
	
	while(t--) {
		ll c, n;
		get(c); get(n);
	
		printf("%lld %lld\n", c, ans[n] );
		 
		
	}
}
