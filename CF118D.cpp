#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( auto it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) ;//cout << "[DEBUG] " << #x << " = " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

#define MOD 100000000

ll n1, n2, k1, k2;
ll dp[105][105][11][11];

ll rec( ll x, ll y, ll xx, ll yy  ) {
	if( dp[x][y][xx][yy] != -1 )
	 return dp[x][y][xx][yy];
	if( y > n2 || x > n1 )
	 return dp[x][y][xx][yy] = 0;
	if( y == n2 && x == n1 )
	 return dp[x][y][xx][yy] = 1;
	if( xx == k1 )
	 return dp[x][y][xx][yy] = rec( x, y+1, 0, 1 )%MOD;
	if( yy == k2 )
	 return dp[x][y][xx][yy] = rec( x+1, y, 1, 0 )%MOD;
	return dp[x][y][xx][yy] = ( rec( x+1, y, xx+1, 0 ) + rec( x, y+1, 0, yy+1 ) )%MOD;
}

int main() {
	memset( dp, -1, sizeof dp );
	cin >> n1 >> n2 >> k1 >> k2;
	cout << rec( 0, 0, 0, 0 )%MOD;
}
