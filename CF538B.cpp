#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
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
#define MOD 1000000007
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll genx( ll n ) {
	bool match = 1;
	ll val = 0, c = 0;

	while(n) {
		val *= 10;
		val += n%10;
		n /= 10;
		c++;
	}
	
//	debug(val);
	
	ll p = 0;
	
	while( c > 0 ) {
	  ll cur = val%10;
	  p *= 10;

	   if( 1 <= cur )
	   { match = 0; p++; }
	  val /= 10;
	  c--;
	}
	
	return p;
}

int main() {
	ll n; cin >> n;
	vector<ll> v;
	
	while(n) {
	  ll p = genx(n);
//	  debug(n); debug(p);
	   v.pb(p); n -= p;
	}
	
	cout << v.size() << "\n";
	repVector(v)
	 cout << (*it) << " ";
}
