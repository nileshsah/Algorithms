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

vector< pair<ll,ll> > v[100005];

int main() {
	ll n, m;
	cin >> n >> m;

	while(m--) {
		ll x, y, c;
		cin >> x >> y >> c;
		v[x].pb( mp(c,y) );
		v[y].pb( mp(c,x) );
	}
	ll S;
	cin >> S;
	vector<ll> vec;
	vector<ll> D(n+1,LONG_MAX);
	set< pair<ll,ll> > s;


	FOR(i,1,S)
	 { ll x; cin >> x; D[x] = 0; s.insert( mp(0,x) ); }
	
		  
	  while(!s.empty()) {
	  	 ll ptr = s.begin()->S;
	  	 s.erase(s.begin());
	  	 repVector(v[ptr])
	  	  if( D[it->S] > D[ptr] + it->F ) {
	  	  	  s.erase( mp(D[it->S],it->S) );
	  	  	  D[it->S] = D[ptr] + it->F;
	  	  	  s.insert( mp(D[it->S],it->S) );
		  } 
	  }
	
	
	FOR(i,1,n)
	 cout << D[i] << "\n";
	 
	
}
