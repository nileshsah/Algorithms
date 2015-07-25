#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define MOD 1000000007
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

stack< pair<ll,ll> > s;
char maze[505][505];
bool explore[505][505] = {0};

void dfs( ll x, ll y ) {
	if( explore[x][y] )
	 return;
	
	explore[x][y] = 1;
	s.push( mp(x,y) );
	
	if( maze[x+1][y] == '.' )
	  dfs( x+1, y );
	if( maze[x][y+1] == '.' )
	  dfs( x, y+1 );
	if( maze[x-1][y] == '.' )
	  dfs( x-1, y );
	if( maze[x][y-1] == '.' )
	  dfs( x, y-1 );
	 	
}

int main() {
	ll n, m, k;
	cin >> n >> m >> k;
	
	FOR(i,1,n)
	 scanf("%s",maze[i]+1);
	
	FOR(i,1,n)
	 FOR(j,1,m)
	  if( maze[i][j] == '.' && !explore[i][j] )
	    dfs( i, j );
	
	FOR(i,1,k) {
//	  cout << s.top().F << " " << s.top().S << "\n";
	 maze[s.top().F][s.top().S] = 'X';
	 s.pop();
	}
	
	FOR(i,1,n)
	  cout << maze[i]+1 << "\n";
	  	   	
}
