#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
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
using namespace std;

vector<ll> v[100005], ans;
ll mark[100005] = {0};
ll goal[100005] = {0};
bool explore[100005] = {0};


void dfs( ll x, bool odd, bool even, ll lvl ) {
//	cout << "REC: " << x << " O: " << odd << " E: " << even << " LVL: " << lvl << "\n";
	explore[x] = 1;

	if( ( lvl%2 && odd ) || ( lvl%2 == 0 && even ) ) 
	 mark[x] = !mark[x];
	
	if( mark[x] != goal[x] ) {
	 if( lvl%2 )
	  odd = !odd;
	 else 
	  even = !even;
	 ans.pb(x);
	}
	  
	repVector(v[x]) 
	  if( !explore[*it] ) 
	  	dfs( *it, odd, even, lvl+1 );
	
}

int main() {
//	INPFILE;
	ll n; cin >> n;
	FOR(i,1,n-1) {
		ll x, y;
		cin >> x >> y;
		v[x].pb(y); v[y].pb(x);
	}
	
	FOR(i,1,n)
	 cin >> mark[i];
	FOR(i,1,n)
	 cin >> goal[i];
	 
	dfs( 1, 0, 0, 0 );
	
	cout << ans.size() << "\n";
	repVector(ans)
	 cout << *it << "\n";
			 
}
