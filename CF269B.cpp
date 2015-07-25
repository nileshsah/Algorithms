#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main() {
	ll n, m;
	cin >> n >> m;
	
	vector<ll> v;
	FOR(i,1,n) {
		ll x; double y;
		cin >> x >> y;
		v.pb(x);
	}
	
	ll dp[5005] = {0};
	
	FOR(i,0,n-1)
	 FOR(j,0,i-1)
	  if( v[i] >= v[j] ) 
		dp[i] = max( dp[i], dp[j]+1 );
	
	ll ans = 0; 
	FOR(i,1,n)
	 ans = max( ans, dp[i] );
	
	debug(ans);
	cout << n-ans-1;

}
