#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%lld", &a);
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
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

ll dp[100005] = {0};

int main() {
	ll n; cin >> n;
	vector<ll> v;
	FOR(i,1,n)
	 { ll x; cin >> x; v.pb(x); }
	
	FOR(i,0,n-1) {
	  ll maxn = 0;
	  for( ll k = 2; k*k <= v[i]; k++ )
	   if( v[i]%k == 0 )
	    maxn = max( maxn, max(dp[k],dp[v[i]/k] ) );
	  for( ll k = 1; k*k <= v[i]; k++ )
	   if( v[i]%k == 0 )
	    dp[k] = dp[v[i]/k] = maxn+1;
	}
	
	ll m = 0;
	FOR(i,0,n-1)
	 { cout << dp[v[i]] << " "; m = max(m,dp[v[i]]); }
	cout << m;
	 
}
