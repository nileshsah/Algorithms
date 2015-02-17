#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) scanf("%lld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector< pair<ll,ll> >::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set< pair< ll, pair<ll,ll> > >::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 10000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

ll powmod( ll a, ll b ) {
	if( b == 1 ) return a;
	if( b == 0 ) return 1;
	
	if( b%2 == 0 ) {
		ll val = powmod(a,b/2);
		val %= MOD;
		val = val*val;
		return val%MOD;
	}
	else {
		ll val = powmod(a,(b-1));
		val %= MOD;
		return (a*val)%MOD;
	}
}

int main() {
	while(1) {
		ll n, k;
		get(n); get(k);
		
		if( n == 0 && k == 0 )	return 0;
		ll ans = 2*powmod(n-1,k) + powmod(n,k);
		ans %= MOD;
		ans += 2*powmod(n-1,n-1) + powmod(n,n);
		ans %= MOD;
		
		printf("%lld\n", ans);
		
	}
}
