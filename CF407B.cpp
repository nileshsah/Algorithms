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

#define MOD 1000000007

ll n; 
ll arr[1005];
ll dp[1005] = {0};

int main() {
	cin >> n;
	FOR(i,1,n) 
	 cin >> arr[i];
	
	FOR(i,1,n) {
	  dp[i] = 1;
	 FOR(j,arr[i],i-1)
	  dp[i] = ( dp[i] + dp[j] + 1 )%MOD;
	}
	
	ll ans = 0;
	FOR(i,1,n)
	 ans = ( ans + dp[i] + 1 )%MOD;
	
	cout << ans;
		
}
