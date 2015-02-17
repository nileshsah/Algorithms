#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define llu long long unsigned
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSTL(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

vector<ll> prime;
bool bit[10000000+5] = {0};

void sieve( ll n ) {
	FOR(i,2,n)
	  if( bit[i] != 1 ) {
	  	prime.pb(i);
	  	for( ll j = i*i; j <= n; j += i )
	  	  bit[j] = 1;
	  }
}

ll modInverse( ll a )
{
     if ( a < 2 ) return 1;
 
     int b = MOD-2;
     ll ans, y;
     
     for ( ans=1, y=a; b>0; b>>=1 ) {
         if( b&1 ) ans = (ans*y)%MOD;
         y = (y*y)%MOD;
     }
     
     return ans;  
}

ll modPow(llu a, ll x, llu p = MOD) {
    if( x < 0 )
    	return 0;
    if( x == 1 )
    	return a%p;
    llu res = 1;
    while(x > 0) {
        if( x % 2 != 0) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        x /= 2;
    }
    return res%p;
}

ll rec( ll m, ll n ) {
	if( n == 0 )
		return 0;
	if( n == 1 )
		return 1;
		
	ll ans = 0;
	FOR(i,1,m)
	  ans += m*rec(m,n-1);
	return ans;
}

int main() {
	ll m = 3; ll n = 2 ;
	sieve( 10000 );
	ll ans =  1;
	ll ptr = 0;
		cout << "IN\n";

	while( prime[ptr] <= m ) {
		cout << prime[ptr] << " : ";
		ll val =  m*modInverse( prime[ptr] ); 
		cout << " TMP: " << val;
		val %= MOD;
		val = modPow(val,n);
		val = 1 - val;
		if( val < 0 )
			val += MOD;
		ans *= val;
		ans %= MOD;
		ptr++;
		cout << val << " INV: " << modInverse(prime[ptr-1]) << endl;
	}
	
	ans += modPow(m,n);
	
	cout << ans;
}
