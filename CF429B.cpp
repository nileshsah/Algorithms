#include <bits/stdc++.h>
#define ll long long
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

ll arr[1005][1005] = {0};
ll dp1[1005][1005] = {0};
ll dp2[1005][1005] = {0};
ll dp3[1005][1005] = {0};
ll dp4[1005][1005] = {0};
  

int main() {
	ll n, m;
	cin >> n >> m;
	
	FOR(i,1,n)
	 FOR(j,1,m)
	  cin >> arr[i][j];
   
  
   FOR(i,1,n)
    FOR(j,1,m)
     dp1[i][j] = arr[i][j] + max( dp1[i-1][j], dp1[i][j-1] );
   
   ROF(i,n,1)
    ROF(j,m,1)
     dp2[i][j] = arr[i][j] + max( dp2[i+1][j], dp2[i][j+1] );
   
   ROF(i,n,1)
    FOR(j,1,m)
     dp3[i][j] = arr[i][j] + max( dp3[i+1][j], dp3[i][j-1] );
   
   FOR(i,1,n)
    ROF(j,m,1)
     dp4[i][j] = arr[i][j] + max( dp4[i-1][j], dp4[i][j+1] );
   
   ll ans = 0;
   FOR(i,2,n-1)
    FOR(j,2,m-1) {
     ans = max( ans, dp1[i-1][j] + dp2[i+1][j] + dp3[i][j-1] + dp4[i][j+1] );
     ans = max( ans, dp1[i][j-1] + dp2[i][j+1] + dp3[i+1][j] + dp4[i-1][j] );
	}
  cout << ans;	
}
