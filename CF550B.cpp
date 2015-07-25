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

vector<ll> v;
ll ans = 0, X, l, r, n;

void rec( ll x, ll sum, ll k, ll minx, ll maxx ) {
//	cout << "X: " << x << " SUM: " << sum << " MINX: " << minx << " "
//	     << " MAXX: " << maxx << "\n";
	     
	  if( k == 1 &&sum >= l && sum <= r && maxx - minx >= X && maxx != LONG_MIN )
	    {  ans++; }
	
	  if( x >= n )
	   return;
      if( sum > r )
	   return;

     rec( x+1, sum+v[x], 1, min(minx,v[x]), max(maxx,v[x]) );	  
	    rec( x+1, sum, 0, minx, maxx );
	  
	  
}

int main() {
	cin >> n >> l >> r >> X;
	FOR(i,1,n)
	 { ll x; cin >> x; v.pb(x); }
	
	rec( 0, 0, 0, LONG_MAX, LONG_MIN );	
	cout << ans;
	
}
