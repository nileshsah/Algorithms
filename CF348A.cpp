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
using namespace std;

int main() {
	ll n; cin >> n;
	vector<ll> v; ll sum = 0;
	FOR(i,1,n)
	 { ll x; cin >> x; v.pb(x); sum += x; }
	sort( all(v), greater<ll>() );
	
	ll k = n-1, alloc = 0, games = 0;
	alloc = v[0]*(n-1) - v[0]; games += v[0];
	FOR(i,1,n-1)
	 if(  alloc - v[i] < 0 ) {
	    ll k = ( v[i] - alloc )*(n-1);
	    games += ceil(1.0*( v[i] - alloc )/(n-1));
	    alloc += k - v[i];
	 }
	 else
	   alloc -= v[i];
	
	cout << games;		
}
 
