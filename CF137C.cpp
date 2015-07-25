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
using namespace std;

int main() {
	ll n; cin >> n;
	vector< pair<ll,ll> > v;
	while(n--) {
		ll x, y;
		cin >> x >> y;
		v.pb( mp(x,y) );
	}
	
	sort( all(v) );
	
	pair<ll,ll> p = v[0];
	ll ans = 0;
	
	FOR(i,1,v.size()-1) {
      if( v[i].F > p.F && v[i].S < p.S )
        ans++;
      if( v[i].S > p.S )
        p = v[i];
    }
    
    cout << ans;
}
