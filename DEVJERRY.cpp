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

ll n, sx, sy, ex, ey, bx, by;
bool explore[25][25] = {0};
ll dp[25][25] = {0};

ll solve( ) {
	set< pair< ll, pair<ll,ll> > > s;
	s.insert( mp( 0, mp(sx,sy) ) );
	while(1) {
	  if( s.begin()->S == mp(ex,ey) )
	  	return s.begin()->F;
	 if( s.begin()->S == mp(bx,by) )
	  { s.erase(s.begin()); continue; }
	  pair<ll,ll> p = s.begin()->S;
	  ll cost = s.begin()->F;
	  
	  if( p.F + 1 <= n )
	   s.insert( mp( cost+1, mp(p.first+1,p.second) ) );
	  if( p.S + 1 <= n )
	   s.insert( mp( cost+1, mp(p.first,p.second+1) ) );
	  if( p.F - 1 >= 1 )
	   s.insert( mp( cost+1, mp(p.first-1,p.second) ) );
	  if( p.S - 1 >= 1 )
	   s.insert( mp( cost+1, mp(p.first,p.second-1) ) );

	  s.erase(s.begin());

	}
}

int main() {
	ll t; cin >> t;
	while(t--) {
		cin >> n >> sx >> sy >> ex >> ey >> bx >> by;
		memset( dp, -1, sizeof dp );
		memset( explore, 0, sizeof explore );
		explore[bx][by] = 1;
		cout << solve() << "\n";
	}
}
