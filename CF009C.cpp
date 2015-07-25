#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( auto it = s.begin(); it != s.end(); it++ )
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
	ll k = 0, p = n;
	vector<ll> v;
	while( p != 0 )
	 { v.pb(p%10); p /= 10; k++; }
	ll ans = 1LL<<k;
	
	ans--;
	
//	debug(ans);
	reverse( all(v) );
	
	FOR(i,0,v.size()-1)
	 if( v[i] > 1 )
	   break;
	 else if( v[i] == 0 )
	  ans -= 1LL<<(v.size()-i-1);
	 
	
	cout << ans;
	
}
