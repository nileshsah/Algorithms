#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
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
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

#define MOD 1000000007

vector<ll> fact[2005];
ll dp[2005][2005] = {0};

int main() {
	ll n, k;
	cin >> k >> n;
	
	FOR(i,1,k)
	 FOR(j,1,i)
	  if( i%j == 0 )
	   fact[i].pb(j);
		
	dp[1][0] = 1;
	
	FOR(i,1,n)
	 FOR(j,1,k)
	  repVector(fact[j])
	   dp[j][i] = ( dp[j][i] + dp[*it][i-1] )%MOD;
	
	ll ans = 0;
	FOR(i,1,k)
	 ans = ( ans + dp[i][n] )%MOD;
	
	cout << ans;
	
}
