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
#define MOD 1000000007
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll cost[100005] = {0};
ll parent[100005] = {0};
bool cycle[100005] = {0};
bool visit[100005] = {0};
vector<ll> v[100005];

ll find( ll x ) {
	if( parent[x] == x )
		return x;
	else
	   parent[x] = find( parent[x] );
}

void join( ll x, ll y ) {
	ll p = find(x);
	ll q = find(y);
	parent[p] = parent[q];
}

vector<ll> s;
void dfs( ll x ) {
//	debug(x);		  
	cycle[x] = 1;
	
	repVector(v[x])
	 if( cycle[*it] ) 
	  while(!s.empty()) {
	    if( s.back() == *it )
	      break;
	    join(*it,s.back());
	    s.pop_back();
	 }
	 else {
	   s.pb(*it);
	   dfs(*it);
	}
	
	cycle[x] = 0;
	visit[x] = 1;
}

int main() {
//	INPFILE;
	ios_base::sync_with_stdio(false);
	ll n; cin >> n;
	ll group[100005] = {0};
	
	FOR(i,1,n) {
	 cin >> cost[i];
	 parent[i] = i;
	 group[i] = LLONG_MAX;
	}	
	
	ll m; cin >> m;
	while(m--) {
		ll x, y;
		cin >> x >> y;
		v[x].pb(y);
	}
	
	FOR(i,1,n)
	 if( !visit[i] ) {
	  memset( cycle, 0, sizeof cycle );
	  s.clear();
	  dfs(i);
	 }
	

	FOR(i,1,n)
	 group[ find(i) ] = min( group[ find(i) ], cost[i] );
	
/*	FOR(i,1,n)
	 cout << find(i) << " ";
	cout << "\n";
*/
	
	ll val = 1, sum = 0;
	ll mul[100005] = {0};
	FOR(i,1,n) {
	 if( cost[i] == group[ find(i) ] )
	   mul[ find(i) ]++;
	 if( group[i] != LLONG_MAX )
	  sum += group[i];
	}
	
	FOR(i,1,n)
	 if( group[i] != LLONG_MAX )
	  val = ( val*mul[i] )%MOD;
	
	cout << sum << " " << val;
	 	
}
