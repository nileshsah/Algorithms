#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define DEBUG(x) cout << "[DEBUG]" << #x << " " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

struct node {
	ll x;
	ll y; 
	ll z;
};

ll parent[105] = {0};

ll find( ll x ) {
	if( parent[x] != x )
		parent[x] = find( parent[x] );
	return parent[x];
}

void join( ll x, ll y ) {
	ll p = find(x);
	ll q = find(y);
	parent[p] = parent[q];
}

ll d;

bool dist( node p, node q ) {
	ll val = ( p.x - q.x )*( p.x - q.x );
	val += ( p.y - q.y )*( p.y - q.y );
	val += ( p.z - q.z )*( p.z - q.z );
	
	
	if( val <= d*d )
		return 1;
	else
		return 0;
}

int main() {
	ll t; get(t);
	while(t--) {
	  ll n;
	  get(n); get(d);
	  
	  vector<node> v;
	  node q;
	  q.x = q.y = q.z = 0;
	  v.pb(q);
	  
	  FOR(i,1,n) {
	  	node p;
	  	get(p.x); get(p.y); get(p.z);
	  	v.pb(p);
	  	parent[i] = i;
	  }
	  
	  FOR(i,1,n)
	   FOR(j,i+1,n)
	    if( dist( v[i], v[j] ) )
	    	join(i,j);
	  
	  set<ll> s;
	  
	  FOR(i,1,n)
	    s.insert( find(i) );
	  
	   cout << s.size() << endl;
	  
	}
}
