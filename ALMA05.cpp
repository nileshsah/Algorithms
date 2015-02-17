#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
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
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll arr[35][35] = {0};

ll dp[35][35][35][35] = {0};

ll rec( ll x, ll y, ll xx, ll yy, ll d = 0 ) {
	
	if( x > xx || y > yy )
		return 0;
	
	if( dp[x][y][xx][yy] != -1 )
		return dp[x][y][xx][yy];
		
	d++;	
	ll val = 0;
	
	ll temp;
	
	temp = 0;
	FOR(i,x,xx)
	 temp += arr[i][y]; temp *= d;
	val = max( val, temp + rec( x, y+1, xx, yy, d ) );
	
	temp = 0;
	FOR(i,x,xx)
	 temp += arr[i][yy]; temp *= d;
	val = max( val, temp + rec( x, y, xx, yy-1, d ) );
	
	temp = 0;
	FOR(i,y,yy)
	 temp += arr[x][i]; temp *= d;
	val = max( val, temp + rec( x+1, y, xx, yy, d ) );
	
	temp = 0;
	FOR(i,y,yy)
	 temp += arr[xx][i]; temp *= d;
	val = max( val, temp + rec( x, y, xx-1, yy, d ) );

	
//	printf(" REC: %ld (%ld,%ld) - (%ld,%ld) = %ld \n", d, x, y, xx, yy, val );
	
	dp[x][y][xx][yy] = val;
	return val;
	
}

int main() {
//	INPFILE;
	ll t; get(t);
	while(t--) {
		ll n, m;
		memset( dp, -1, sizeof dp );
		memset( arr, 0, sizeof arr );
		
		get(n); get(m);
		
		FOR(i,1,n)
		 FOR(j,1,m)
		  get(arr[i][j]);
		
		printf("%lld\n", rec( 1,1,n,m ) );
	}
}
