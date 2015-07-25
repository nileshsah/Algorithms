#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( auto it = s.begin(); it != s.end(); it++ )
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
#define MOD 1000000009
using namespace std;

int main() {
	ll n; cin >> n;
	vector<ll> v;
	FOR(i,1,n)
	 { ll x; cin >> x; v.pb(x); }
	sort( all(v) );
	
	if( n == 1 && v[0] == 1 )
	 cout << "2";
	else
	 cout << "1 ";
	 
	FOR(i,1,n-1)
	 if( i == n-1 && v[i] == v[i-1] && v[i] == 1 )
	  cout << "2";
	 else
	  cout << min( v[i], v[i-1] ) << " ";
	
		
}
