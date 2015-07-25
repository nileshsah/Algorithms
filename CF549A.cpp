#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
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
#define MOD 1000000000
#define foo pair< pair<ll,ll>, ll >
using namespace std;

int main() {
	ll n, m;
	cin >> n >> m;
	
	char str[n+1][m+1];
	
	FOR(i,1,n)
	 FOR(j,1,m)
	  cin >> str[i][j];
	
	ll ans = 0;
	
	FOR(i,1,n-1)
	 FOR(j,1,m-1) {
	   string s;
	   s.pb( str[i][j] );
	   s.pb( str[i][j+1] );
	   s.pb( str[i+1][j] );
	   s.pb( str[i+1][j+1] );
	   sort( all(s) );
	   if( s == "acef" )
	    ans++;
	 }
	  
	  cout << ans;
}

