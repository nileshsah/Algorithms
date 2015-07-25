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

int main() {
	ll n; cin >> n;
	vector<ll> v;
	FOR(i,1,n)
	 { ll x; cin >> x; v.pb(x); }
	
	vector<ll> p = v;
	sort( all(p) );
	
	if( p == v )
	 { cout << "YES"; return 0; }
	
	ll x = -1, y = -1;
	
	FOR(i,0,n-1)
	 if( v[i] != p[i] )
	  if( x == -1 )
	    x = i;
	  else 
	    y = i;
	
	if( x == -1 || y == -1 )
	 { cout << "NO"; return 0; }
	
	swap(v[x],v[y]);
	
	if( v == p )
	 cout << "YES";
	else
	 cout << "NO";
	
}
