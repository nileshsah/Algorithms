#include <bits/stdc++.h>
#define ll int
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

bool mark[305][305] = {0};

long long C( long long x ) {
	return x*(x-1)*(x-2)/6;
}	

int main() {
	BOOST;
	ll n; cin >> n;
	vector< pair<ll,ll> > v;
	vector<ll> X[205], Y[205];
	FOR(i,1,n) {
		ll x, y;
		cin >> x >> y;
		v.pb( mp(x,y) );
		mark[x+100][y+100] = 1;
		X[x+100].pb(y); Y[y+100].pb(x);
	}
	
	long long ans = C(n);
	
	FOR(i,0,n-1) {
		mark[v[i].F+100][v[i].S+100] = 0;
	 FOR(j,i+1,n-1) {
	 	mark[v[j].F+100][v[j].S+100] = 0;
	  FOR(k,0,200) {
	  	ll x = k - 100;
	  	if( v[i].S == v[j].S )
	  	 { ans -= C(Y[v[i].S+100].size()); Y[v[i].S+100].clear(); break; }
	  	if( v[i].F == v[j].F )
	  	 { ans -= C(X[v[i].F+100].size()); X[v[i].F+100].clear(); break; }
	    
	    if( ( v[j].S - v[i].S )*( x - v[i].F )%( v[j].F - v[i].F ) == 0 ) {
		   ll y = ( v[j].S - v[i].S )*( x - v[i].F )/( v[j].F - v[i].F ) + v[i].S;
		   if( y+100 >= 0 && y+100 <= 200 && mark[x+100][y+100] )
		    //{ cout << " R: " << i << " " << j << " - " << x << " " << y << "\n"; ans--; }
			ans--;
		}
	   } 	   
	 }
	 
	 FOR(j,i+1,n-1)
	  mark[v[j].F+100][v[j].S+100] = 1; 
	}
	
	cout << ans;
	   
}
