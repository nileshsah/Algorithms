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

ll k;

ll fcalc( ll x ) {
	if( x == 0 )
	 return 0;
	if( x%k )
	 return x%k + fcalc( x - x%k );
	else
	 return 2*( fcalc(x-k) + k );
}

ll modpow( ll a, ll b ) {
	if( b == 0 )
	 return 1;
	if( b%2 ) {
	 ll q = modpow( a, (b-1)/2 );
	 q *= q; q %= MOD;
	 return (q*a)%MOD;
	}
	else {
	 ll q = modpow( a, b/2 );
	 return (q*q)%MOD;
	}
}

ll calc( ll x ) {
	if(!x)
	 return 0;
	if( x%k )
	 return x%k + calc( x - x%k );
	 
	ll n = x/k;
	ll p = ( modpow(2,n+1) - 2 + MOD )%MOD;
	p *= k; p %= MOD;
	return p;
}

int main() {

	ll n, m;
	cin >> n >> m >> k;

	multiset<ll> s;
	s.insert( m );
	ll free = n - m ;
	
	ll group = m/(k-1);
	group = min(group,free);
	
	ll ans = 0;
	ans += group*(k-1);
	ans += calc( m - group*(k-1) );
	
	cout << ans;
}
