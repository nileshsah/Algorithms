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
#define MOD 1000000007
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

char s[55][55];
bool flag = 0;
bool mark[55][55] = {0};

void dfs( ll x, ll y, char c ) {
	if( s[x][y] != c )
		return;
		
	mark[x][y] = 1;
	
	if( s[x+1][y] == c && !mark[x+1][y] )
		dfs( x+1, y, c );
	if( s[x][y+1] == c && !mark[x][y+1] )
		dfs( x, y+1, c );
	if( s[x-1][y] == c && !mark[x-1][y] )
		dfs( x-1, y, c );
	if( s[x][y-1] == c && !mark[x][y-1] )
		dfs( x, y-1, c );	
		
}

int main() {
//	INPFILE;
	ll n, m;
	cin >> n >> m;
	
	FOR(i,1,n)
	 scanf("%s", s[i]+1);
	
	FOR(i,1,n)
	 FOR(j,1,m) {
	 	memset( mark, 0, sizeof mark );
	 	char c = s[i][j];
	 	s[i][j] = '0';
	 	dfs( i+1, j, c );
	 	s[i][j] = c;
	 	if( mark[i][j+1] )
	 		{ cout << "Yes"; return 0; }
	 }
	 
	 cout << "No";
	  
	
}
