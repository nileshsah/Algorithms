#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
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

ll sum( ll x ) {
	ll val = 0;
	while( x != 0 )
	 { val += x%10; x /= 10; }
	if( val/10 )
	 return sum( val );
	else
	 return val;
}

int main() {
	ll t; cin >> t;
	while(t--) {
	   ll m; cin >> m;
	   ll num = 0;
	   while(m--) {
	   	ll d, len;
	   	cin >> d >> len;
	   	num = sum( d*len + num );
	   }
	   cout << sum(num) << "\n";
	}
}
