#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
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

ll ans = 0;
ll h, w;
string str[55];
ll dp[55][55];

bool valid( ll i, ll j ) {
	if( i < 0 || j < 0 )
		return 0;
	if( i >= h || j >= w )
		return 0;
	return 1;
}


int rec( ll i, ll j , char A = 'A', ll c = 1 ) {
	ans = max( ans, c );
	ll val = c;
	
	if( dp[i][j] )
		return dp[i][j];
	
	if( valid(i-1,j-1) && str[i-1][j-1] == A+1 )
		val = max( val, rec(i-1, j-1, A+1, c+1 ) );
	if( valid(i-1,j) && str[i-1][j] == A+1 )
		val = max( val, rec(i-1, j, A+1, c+1 ) );
	if( valid(i+1, j+1) && str[i+1][j+1] == A+1 )
		val = max( val, rec(i+1, j+1, A+1, c+1 ) );
	if( valid(i+1,j) && str[i+1][j] == A+1 )
		val = max( val, rec(i+1, j, A+1, c+1 ) );
	if( valid(i,j+1) && str[i][j+1] == A+1 )
		val = max( val, rec(i, j+1, A+1, c+1 ) );
	if( valid( i, j-1 ) && str[i][j-1] == A+1 )
		val = max( val, rec(i, j-1, A+1, c+1 ) );
	if( valid( i-1, j+1) && str[i-1][j+1] == A+1 )
		val = max( val, rec(i-1, j+1, A+1, c+1 ) );
	if( valid( i+1, j-1 ) && str[i+1][j-1] == A+1 )
		val = max( val, rec(i+1, j-1, A+1, c+1 ) );
	
	dp[i][j] = val;
	return c;
}

int main() {
	ll t = 0;
	while(1) {
		ans = 0;
		get(h); get(w);
		if( h == 0 && w == 0 )
			return 0;
		
		memset( dp, 0, sizeof dp );
		cin.ignore();
		rep(h) { cin >> str[i]; }
		
		FOR(i,0,h)
		 FOR(j,0,w)
		 	if( str[i][j] == 'A' )
		 		rec( i,j );
		printf("Case %ld: %ld\n", ++t, ans);
	}
}
