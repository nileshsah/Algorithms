#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
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

queue<ll> q;
vector<ll> v[300005];
ll dp[200005][20] = {0};
bool explore[200005] = {0};
ll N = 3;

void dfs( ll r ) {
	explore[r] = 1;
//	cout << " R: " << r << endl;
	
	FOR(i,1,N)
	 dp[r][i] = i;
	
	 FOR(k,0,v[r].size()-1)
	  if( !explore[v[r][k]] ) {
	  	dfs(v[r][k]);
	  	
	  	FOR(i,1,N) {
	  		ll val = LONG_MAX;
	  	 FOR(j,1,N)
	  	  if( i == j ) continue;
	  	  else val = min( dp[v[r][k]][j], val );
	  	 
	  	 dp[r][i] += val;
	   }
	  	 
	 }
}

int main() {
	INPFILE;
	ll t, w = 1; get(t);
	while(t--) {
		ll n; cin >> n;
		memset( explore, 0, sizeof explore );
		memset( dp, 0, sizeof dp );
		ll x;
		
		FOR(i,1,n) { 
		   cin >> x;
		  if( x != 0 ) {
		   v[x].pb(i); 
		   v[i].pb(x);
		  }
		}
			
		dfs(1);

		
		ll ans = LONG_MAX;
		
		FOR(i,1,N)
		 ans = min( ans, dp[1][i] );
			
		printf("Case #%lld: %lld\n", w++, ans );

		FOR(i,0,n)
		  v[i].clear();
	
	}
}
