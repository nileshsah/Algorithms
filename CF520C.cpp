#include <bits/stdc++.h>
#define ll long long
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
#define MOD 1000000007
using namespace std;

ll modpow( ll x, ll y ) {
	if( y == 0 )
		return 1;
	if( y == 1 )
		return x%MOD;
	if(y%2) {
	  ll p = modpow( x, (y-1)/2 );
	  p *= p; p %= MOD;
	  return ( p * x%MOD )%MOD;
	
	}
	else {
	   ll p = modpow( x, y/2 );
	   return ( p*p )%MOD;
	}
}

int main() {
	ll n; cin >> n;
	string s; cin >> s;
	vector<ll> v(4,0);
		
	FOR(i,0,n-1)
	 if( s[i] == 'A' )
	 	v[0]++;
	 else if( s[i] == 'C' )
	 	v[1]++;
	 else if( s[i] == 'G' )
	 	v[2]++;
	 else if( s[i] == 'T' )
	 	v[3]++;
	
	sort( all(v) );
	reverse( all(v) );
	
	ll p = 1, val = 1;
	while( p < v.size() && v[p] == v[0] )
	  { val++; p++; }
	
	cout << modpow(val,n);
	
}
