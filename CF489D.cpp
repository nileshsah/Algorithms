#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( auto it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) ;//cout << "[DEBUG] " << #x << " = " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

bool adj[3005][3005] = {0};
vector<ll> v[3005];

int main() {
	BOOST;
	ll n, m;
	cin >> n >> m;
	
	while(m--) {
	   ll x, y;
	   cin >> x >> y;
	   adj[x][y] = 1;
	   v[x].pb(y);
	}
	
	ll ans = 0;
	
	FOR(i,1,n)
	 FOR(j,1,n) {
	  if( i == j )
	   continue;
	  ll num = 0;
	  repVector(v[i])
	   if( adj[*it][j] )
		 num++;
	  ans += max(0LL,num*(num-1)/2);
	 }
	 
	cout << ans;
	
}
