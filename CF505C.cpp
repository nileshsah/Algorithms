#include <bits/stdc++.h>
#define ll int
#define get(a) scanf("%d", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll v[30005] = {0};
ll dp[500][30005] = {0};
ll maxx = 0;

ll rec( ll l, ll cur ) {
	if( cur > maxx )
	 return 0;
	if( dp[l][cur] != -1 )
		return dp[l][cur];
	
	ll val = v[cur] + max( rec( l, cur+l ), rec( l+1, cur+l+1 ) );
	
	if( l-1 > 0 )
	  val = max( val, v[cur] + rec( l-1, cur+l-1 ) );
	
	dp[l][cur] = val;
//	cout << " REC: " << l << " " << cur << " = " << dp[cur] << endl;
	
	return dp[l][cur];	
}

int main() {
//	INPFILE;
	ll n, d;
	cin >> n >> d;
	
	memset( dp, -1, sizeof dp );
	
	FOR(i,1,n) {
	   ll x; cin >> x;
	   maxx = max(x,maxx);
	   v[x]++;
	}
	
	cout << rec( d, d ) << endl;
}
