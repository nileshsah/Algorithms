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

ll ans = 0;
ll m, n;
string x, y;

ll rec( string s ) {

	if( s.size() > n )
		return 1;
	if( !s.empty() && s.size() >= m ) {
	  string p = s.substr( s.size() - m );
	  if( p > x && p < y )
	  	return 0;
	}
	
	return 1 + rec( s + "A" ) + rec( s + "B" );	 
}

int main() {
	ll t; get(t);
	while(t--) {
		get(n); get(m);
		cin >> x >> y;
		cout << rec("") << endl;
	}
}

