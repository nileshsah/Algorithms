#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define MOD 1000000007
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

vector<ll> v[25];
matrix adj( 25, vector<ll>(25,INT_MAX) );
ll n;

bool mark[25][1050000] = {0};
ll dp[25][1050000] = {0};

ll rec( ll x, ll bit ) {
	if( bit == (1LL<<(n+1))-2 )
		return 0;
	if( dp[x][bit] != 0 )
		return dp[x][bit];
		
	if( mark[x][bit] )
		return INT_MAX;
	mark[x][bit] = 1;
		
	ll ans = INT_MAX;
	
	  
	  repVector(v[x]) {
		ll ptr = *it;
	//	if( (bit&(1LL<<ptr)) ) continue;
		ans = min( ans, adj[x][ptr] + rec( ptr, (bit|(1LL<<ptr)) ) ); 
	}
	
//	printf(" REC: %lld - %lld = %lld\n", x, bit, ans );
	dp[x][bit] = ans;
	return ans;
}

int main() {
	get(n);
	
	FOR(i,1,n-1) {
		ll x, y, c;
		get(x); get(y); get(c);
		if( c < adj[x][y] )
		  adj[x][y] = adj[y][x] = c;
		v[x].pb(y); v[y].pb(x);
	}
	
	FOR(k,1,n)
	 FOR(i,1,n)
	  FOR(j,1,n)
	   if( adj[i][k] + adj[k][j] < adj[i][j] )
	    adj[i][j] = adj[i][k] + adj[k][j];
	
/*	FOR(i,1,n) {
	 FOR(j,1,n)
	  cout << adj[i][j] << " ";
	  cout << endl;
	 }
*/
	
	cout << rec(1,2);
	
	
}
