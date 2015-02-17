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

string a, b;
ll dp[1001][1001]= {0};

ll rec( ll x, ll y ) {
	if( x >= a.size() )
		return 2000;
		
	if( dp[x][y] != -1 )
		return dp[x][y];
			
	ll ans = 1;
			
	FOR(i,y,b.size()-1)
	  if( b[i] == a[x] )
	  	{ ans = min( rec(x+1,y), 1+rec(x+1,i+1) ); break; }
	  	
	dp[x][y] = ans;
	return ans;
	
}

int main() {
	memset( dp, -1, sizeof dp );
	cin >> a >> b;
	printf("%ld", rec(0,0));
}
