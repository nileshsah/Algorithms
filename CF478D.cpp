#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define FOR(i,a,b) for( ll i = (a); i <= (b); i++ )
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

#define MOD 1000000007

ll h;
ll dp[200005] = {0};

int main() {
	ll r, g;
	cin >> r >> g;
	
	for( h = 1; h*(h+1)/2 <= (r+g); h++ ); h--; 
	debug(h);
	
	dp[0] = 1;
	FOR(i,1,h)
	 ROF(j,r,i)
	  dp[j] = ( dp[j] + dp[j-i] )%MOD;
	
	ll ans = 0;
	FOR(i,max(0LL,h*(h+1)/2-g),r)
	 ans = (ans+dp[i])%MOD;
	
	cout << ans;
}
