#include <bits/stdc++.h>
#define ll int
#define get(a) scanf("%ld", &a);
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

int main() {
//	INPFILE;
	ll n, s;
	cin >> n >> s;
	
	bool flag = 0;
	ll ans = 0;
	
	FOR(i,1,n) {
		ll x, y;
		cin >> x >> y;
		
		if( x + ceil(1.0*y/100) <= s )
		  flag = 1;
		
		if( x + ceil(1.0*y/100) <= s && y != 0 && 100-y > ans )
			{ flag = 1; ans = 100-y; }
	}
	
	if( !flag )
	 cout << "-1";
	else
	 cout << ans;
}
