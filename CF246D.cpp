#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%lld", &a);
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
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

ll c[100005] = {0};
vector<ll> v[100005];
set<ll> color[100005];
set<ll> cc;

int main() {
	ll n, m;
	cin >> n >> m;
		
	FOR(i,1,n) {
	 cin >> c[i];
	 cc.insert(c[i]);
	}
		
	while(m--) {
		ll x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	
	
	FOR(i,1,n) 
	 repVector(v[i])
	  if( c[i] != c[*it] )
	   color[ c[i] ].insert( c[*it] );

	
	ll ans = -1, node = 0;
	repVector(cc)
	 if( (ll)color[*it].size() > ans )
	   { ans = color[*it].size(); node = *it; }
	
	
	cout << node;
	  
}
