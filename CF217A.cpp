#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
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

ll parent[1005] = {0};

ll find( ll n ) {
	if( parent[n] == n )
	 return n;
	else
	 return parent[n] = find( parent[n] );
}

void join( ll x, ll y ) {
	ll p = find(x);
	ll q = find(y);
	parent[p] = parent[q];
}


int main() {
	ll n; cin >> n;
	vector< pair<ll,ll> > v;
	
	FOR(i,0,n)
	 parent[i] = i;
	
	FOR(i,1,n) {
	  ll x, y;
	  cin >> x >> y;
	  v.pb( mp(x,y) ); 
	}
	
	FOR(i,0,n-1)
	 FOR(j,i+1,n-1)
	  if( v[i].F == v[j].F || v[i].S == v[j].S )
	   join( i, j );
	
	set<ll> idx;
	
	FOR(i,0,n-1)
	 idx.insert( find(i) );
	
	cout << idx.size()-1;
	  
}
