#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll n, m;
char str[205][205];
ll dp[205][205][2] = {0};

ll dfs( ll x, ll y, bool dir = 0 ) {
  if( x > n || y > m || x <= 0 || y <= 0 || str[x][y] == '#' )
  	return 0;
  	
  if( dp[x][y][dir] != -1 )
  	return dp[x][y][dir];
  	
  ll val = 0, ans = 0;
  if( str[x][y] == 'T' )
  	val = 1;
  ans = val;
  
  if(!dir) {
	if( str[x][y+1] == 'T' || str[x][y+1] == '0' )
  		ans = max( ans, val + dfs( x, y+1 ) );
  	if( str[x+1][y] == 'T' || str[x+1][y] == '0' )
  		ans = max( ans, val + dfs( x+1, y, 1 ) );
  }
  else {
  	if( str[x][y-1] == 'T' || str[x][y-1] == '0' )
  		ans = max( ans, val + dfs( x, y-1, 1 ) );
  	if( str[x+1][y] == 'T' || str[x+1][y] == '0' )
  		ans = max( ans, val + dfs( x+1, y ) );
  }
  
  dp[x][y][dir] = ans;
  return ans;
  
}

int main() {
//	INPFILE;
	ll t; get(t);
	while(t--) {
		get(n); get(m);
		memset( dp, -1, sizeof dp );
		
		FOR(i,1,n)
		 scanf("%s", str[i]+1);

		printf("%ld\n",dfs(1,1));
	}
}
