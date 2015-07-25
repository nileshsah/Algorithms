#include <bits/stdc++.h>
#define ll long long
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

map<ll,ll> m;

int main() {
//	INPFILE;
	ll k,n; cin >> n >> k;
	m[0] = 0;
	
	FOR(i,1,n) { 
	  ll x; cin >> x;
	  FOR(j,1,k) { 
	    if( m[j*x] == 0 )
	      m[j*x] = j;
	    else
	      m[j*x] = min( m[j*x], j );
	  }
	}
			
	ll q; cin >> q;
	while(q--) {
		ll num; cin >> num;
		ll ans = INT_MAX;
	   repVector(m) {
	   	 if( m.find(num-(it->F)) != m.end() )
	   	  ans = min( ans, it->S + m[num-(it->F)] );
	   }
	   
	   if( ans <= k )
	   	cout << ans << endl;
	   else
	    cout << "-1\n";
	}
}
