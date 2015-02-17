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

char str[105][105];
ll hx, hy, dx, dy;
ll ansmin = LONG_MAX;

ll dp[105][105][5] = {0};
ll mark[105][105][6] = {0};

void rec( ll x, ll y, ll dir, ll turn ) {
//	cout << " REC: " << x << " " << y << " - " << dir << " = " << turn << endl;
	if( str[x][y] == 'L' )
		{ ansmin = min( ansmin, turn ); return; }
	if( str[x][y] != 'H' && str[x][y] != '.' )
		return;
	if( mark[x][y][dir] < turn )
		return;
//	if( dp[x][y][dir] != -1 )
//		return dp[x][y][dir];
	mark[x][y][dir] = turn;
	
//	ll ans = 0;
	rec( x+1, y, 0, turn + ( dir != 0 ) ) ;
	rec( x-1, y, 2, turn + ( dir != 2 ) ) ;
	rec( x, y+1, 1, turn + ( dir != 1 ) ) ;
	rec( x, y-1, 3, turn + ( dir != 3 ) ) ;
	
//	dp[x][y][dir] = ans;
//	return ans;	
}

int main() {
//	INPFILE;
	ll r, c;
	get(r); get(c);
	memset( dp, -1, sizeof dp );
	
	FOR(i,1,r)
	 scanf("%s", str[i]+1);
	
	FOR(i,1,r)
	 FOR(j,1,c) {
	   FOR(k,0,3)	
	 	mark[i][j][k] = INT_MAX;
	  if( str[i][j] == 'L' )
	  	dx = i, dy = j;
	  else if( str[i][j] == 'H' )
	  	hx = i, hy = j;
	 }
	rec( hx, hy, 5, 0 );
	cout << max(ansmin-1,0L);
}
