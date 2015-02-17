#include <bits/stdc++.h>
#define ll int
#define get(a) scanf("%d", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define max(a,b) ( (a > b) ? a : b )
#define min(a,b) ( (a < b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<long> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

string a, b;
ll k;

ll dp[2005][2005] = {0};

ll rec( ll x, ll y ) {
	if( x >= a.size() )
		return ( b.size() - y )*k;
	if( y >= b.size() )
		return ( a.size() - x )*k;
	
	if( dp[x][y] != 0 )
		return dp[x][y];
		
	ll val = INT_MAX;
	

	val = abs( a[x] - b[y] ) + rec( x+1, y+1 );	
	val = min( val, k + min( rec(x+1,y), rec(x,y+1) ) );
	dp[x][y] = val;
	
	cout << x << " " << y  << " -> " << val << endl;
	return val;
}

ll solve( ) {
	if( a.size() > b.size() )
		swap(a,b);
	
	dp[a.size()][b.size()] = 0;
	
	 FOR(j,0,b.size()+1)
	  dp[a.size()][j] = (b.size()-j)*k;
	 
	 FOR(i,0,a.size()+1)
	  dp[i][b.size()] = (a.size()-i)*k;
	 
	for( ll i = a.size()-1; i >= 0; i-- )
		for( ll j = b.size()-1; j >= 0; j-- ) {
			dp[i][j] = min( k + min( dp[i+1][j] , dp[i][j+1] ), abs(a[i]-b[j]) + dp[i+1][j+1] );
		//	cout << i << " " << j  << " -> " << dp[i][j] << endl;		
		}
		
	return dp[0][0];	
}

int main() {
	char s1[3000], s2[3000];
	scanf("%s %s", &s1, &s2);
	a = string(s1); b = string(s2);
	
	get(k);
	
	printf("%d", solve() );
	
}
