#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define llu long long unsigned
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSTL(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
#define INF 8000000
using namespace std;

ll dp[1005][25][85] = {0};
		 
	
int main() {
	ll t; get(t);
	while(t--) {
		ll O, N;
		get(O); get(N);
		
		ll m; get(m);
		ll n[1005] = {0}, o[1005] = {0}, w[1005] = {0};
		rep(m)
		 { get(o[i]); get(n[i]); get(w[i]);  }
		 
		 FOR(j,0,O)
		  	FOR(k,0,N)
		  	  dp[0][j][k] = INF;
		 dp[0][0][0] = 0;
		 
		 ll bestO[1005] = {0}, bestN[1005] = {0};
		 
		 FOR(i,0,1001)
		  { bestO[i] = INF; bestN[i] = INF; }
		 
		 FOR(i,1,m)
		  FOR(j,0,O)
		  	FOR(k,0,N)
		  	  dp[i][j][k] = min( dp[i-1][j][k], dp[i-1][max(0,j-o[i])][max(0,k-n[i])] + w[i] );
		
		 printf("%ld\n", dp[m][O][N]);
		
	}
}
