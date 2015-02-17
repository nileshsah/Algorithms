#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define foo(a,b,c) mp( mp(a,b), c )
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

bool mark[1005][1005] = {0};
ll dp[1005][1005] = {0};

int main() {
	ll n, m, p;
	get(m); get(n); get(p);
	
	dp[1][1] = 1;
	
	FOR(i,1,p) {
	  ll x, y;
	  get(x); get(y);
	  mark[x][y] = 1;
	  dp[x][y] = 0;
	}
	
	FOR(i,1,m)
	 FOR(j,1,n)
	  if( !mark[i][j] && dp[i][j] == 0 )
	   dp[i][j] = ( dp[i-1][j] + dp[i][j-1] )%MOD;
	
	printf("%ld", ( mark[m][n] == 0 ) ? dp[m][n] : 0 );
}
