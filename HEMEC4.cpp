#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
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

ll deg[100005] = {0};
vector<ll> v[100005];

int main() {
	ll n, m;
	cin >> n >> m;
	set< pair<ll,ll> > s;
	
	FOR(i,1,m) {
	  ll x, y;
	  cin >> x >> y;
	  v[x].pb(y); v[y].pb(x);
	  deg[x]++; deg[y]++;
	}
	
	FOR(i,1,n)
	 s.insert( mp(deg[i],i) );
	
	ll ans = 0;
	
	while(!s.empty()) {
		ll idx = s.rbegin()->S;
		ll p = s.rbegin()->F;
		s.erase(--s.end());
		if( p == 0 )
		 break;
		ans++;
		repVector(v[idx]) {
			s.erase( mp(deg[*it],*it) );
			deg[*it]--;
			s.insert( mp(deg[*it],*it) );
		}
		
	}
	
	cout << ans;
	
	
}
