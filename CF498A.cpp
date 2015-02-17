#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define max(a,b) ( (a > b) ? a : b )
#define min(a,b) ( (a < b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define INPFILE freopen("input.in","r",stdin)
#define eps 10e-14
using namespace std;

int main() {
//	INPFILE;
	ll x1, y1, x2, y2, m;
	cin >> x1 >> y1 >> x2 >> y2;

	ll ans = 0;
	
	cin >> m;
	rep(m) {
		ll a, b, c;
		cin >> a >> b >> c;
		ll x = ( a*x1 + b*y1 + c ) > 0 ? 1 : -1;
		ll y = ( a*x2 + b*y2 + c ) > 0 ? 1 : -1;
		
		
		
		if( x*y < 0 )
			ans++;
	}
	
	cout << ans;
}
