#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
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
#define MOD 1000000007
using namespace std;

int main() {
	ll t; get(t);
	while(t--) {
		ll n, m;
		get(n); get(m);
		set< pair<ll,ll> > s;
		vector<ll> adj[1005];
		ll degree[1005] = {0};
		
		while(m--) {
			ll a, b;
			get(a); get(b);
			degree[a]++; degree[b]++;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		
		FOR(i,1,n)
		 if( degree[i] > 0 )
		 	s.insert( mp( degree[i], i ) );
		ll ans = 0;
		
		while( !s.empty() ) {
			vector<ll> rem;
			
			repSet(s)
			 if( it->F == 1 )
			    rem.pb(it->S);
			 else if( it->F > 1 )
			 	break;
			
			if( rem.size() == 0 )
				break;
			
			ans++;
			
			for( ll i = 0; i < rem.size(); i++ ) {
				s.erase( mp(degree[rem[i]],rem[i]) );
				
				repVector(adj[rem[i]]) {
				  s.erase( mp(degree[*it],*it) );
				  degree[*it]--;
				  if( degree[*it] > 0 )
				  	s.insert( mp(degree[*it],*it) );
				}
			}
				 
			 rem.clear();
		}
		
		cout << ans << endl;
	}
}
