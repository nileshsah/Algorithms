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

char mark[2005][2005] = {0};

ll dp[2005][2005] = {0};
ll n, m;

ll rec( ll x, ll y ) {
	if( dp[x][y] != -1 )
		return dp[x][y];
	if( x > n || y > m )
		return 1;
	
	ll val = 0;

		
	if( mark[x][y] == mark[x+1][y] )
	  val += rec( x+2, y )*rec( x, y+1 );
	if( mark[x][y] == mark[x][y+1] )
	  val += rec( x, y+2 )*rec( x+1, y );
	
	dp[x][y] = val;
	return val;
}

int main() {
	INPFILE;
	memset( dp, -1, sizeof dp );
	
	cin >> n >> m;
	cin.ignore();
	
	FOR(i,1,n)
	 FOR(j,1,m)
	  cin >> mark[i][j];
	
	if( rec(1,1) != 1 )
		cout << "Not unique\n\n\n";
	 {
		FOR(i,1,n) {
		 FOR(j,1,m)
		  cout << dp[i][j] << " ";
		 cout << "\n";
		}
	}
}
