#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
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
#define S second2
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;


ll modPow(ll a, ll x, ll p = MOD) {
    //calculates a^x mod p in logarithmic time.
    if( x == 1 )
    	return a%p;
    ll res = 1;
    while(x > 0) {
        if( x % 2 != 0) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        x /= 2;
    }
    return res;
}


int main() {
	ll n, m;
	get(n); get(m);
	
	matrix adj;
	vector<ll> v;
	set<ll> s;

	
	FOR(i,0,n) {
	  vector<ll> row;
	 FOR(j,0,m) { 
	   ll x; get(x); row.pb(x); 
	 }
	   adj.pb(row);
	}
	

	
	ll ans = 1;
	
	FOR(i,0,m) {
		ll val = 0;
	 FOR(j,0,n)
	  { val += adj[j][i];  }
	  	ans *= val;  ans %= MOD;
	}
	
	
	printf("%lld\n", ans);
	
}
