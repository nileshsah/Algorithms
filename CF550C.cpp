#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( auto it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll dp[105][5] = {0};

ll lcs( string s, string p, ll x, ll y ) {
	if( dp[x][y] != -1 )
	 return dp[x][y];
	 
	if( x >= s.size() || y >= p.size() )
	  return dp[x][y] = 0;
	if( s[x] == p[y] )
	  return dp[x][y] = 1 + lcs( s, p, x+1, y+1 );
	else 
	  return dp[x][y] = max( lcs( s, p, x+1, y ), lcs( s, p, x, y+1 ) );
}

string foo( ll x ) {
	if( x == 0 )
	 return "0";
	 
	string s;
	while(x) {
	  s.pb(x%10+'0');
	  x /= 10;
	}
	reverse( all(s) );
	return s;
}

int main() {
	string s; cin >> s;
	
	FOR(i,0,124) {
		string p = foo(i*8);
		memset( dp, -1, sizeof dp );
	  if( lcs( s, p, 0, 0 ) == p.size() ) {
	   cout << "YES\n" << p;
	   return 0;
	  }
	}
	
	cout << "NO";
	
}
