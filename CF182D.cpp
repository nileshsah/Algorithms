#include <bits/stdc++.h>
#define ll long
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

string a, b;

bool func( string s, ll n ) {
	if( s.size()%n ) return false;
	for( ll i = 0; i < s.size(); i++ )
	 if( s[i] != a[i%n] )
	  return 0;
	return 1;
}

int main() {
	cin >> a >> b;
	ll ans = 0, i = 1;
	string p = a, q = b;
	
	ll minx = min( a.size(), b.size() );
	
	while( i <= minx ) {
		ans += ( func(p,i) && func(q,i) );
		i++;
	}
	
	cout << ans;
}
