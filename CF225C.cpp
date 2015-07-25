#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
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
#define MOD 1000000007
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll n, m, x, y;
ll hashs[1005] = {0};
ll dots[1005] = {0};
ll dp[2][1005][1005] = {0};
 
ll rec( bool pixel, ll i = 1, ll r = 0 ) {
	if( i >	m && r < x)
	 return INT_MAX;
	else if( i > m )
	  return 0;
	 
	if( dp[pixel][i][r] != -1 )
	  return dp[pixel][i][r];
	 
	if( r == y )
	 return dp[pixel][i][r] = (!pixel)*hashs[i] + pixel*dots[i] + rec( !pixel, i+1, 1 );
	else if( r >= x && m-i+1 >= x )
	 return dp[pixel][i][r] = 
	        min( pixel*hashs[i] + (!pixel)*dots[i] + rec( pixel, i+1, r+1 ), 
	              (!pixel)*hashs[i] + pixel*dots[i] + rec( !pixel, i+1, 1 ) 
			   );
	else if( r < y )
	 return dp[pixel][i][r] = pixel*hashs[i] + (!pixel)*dots[i] + rec( pixel, i+1, r+1 );
	else 
	 return dp[pixel][i][r] = INT_MAX;
}


int main() {
//	INPFILE;
    memset( dp, -1, sizeof dp );
   cin >> n >> m >> x >> y;
   string s[n+1];
   
   FOR(i,1,n) {
    cin >> s[i];
    s[i] = " " + s[i];
   }
     
   FOR(j,1,m)
    FOR(i,1,n)
     if( s[i][j] == '#' )
      hashs[j]++;
     else if( s[i][j] == '.' )
      dots[j]++;
    
   cout << min( rec( 0 ), rec( 1 ) );
}
