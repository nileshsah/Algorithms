#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define MOD 1000000007
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll modpow( ll a, ll b, ll mod ) {
	if( b == 0 )
		return 1;
	if( b%2 == 0 ) {
	  ll x = modpow( a, b/2, mod );
	  return (x*x)%mod;
	}
	else {
	  ll x = modpow( a, (b-1)/2, mod );
	  x *= x; x %= mod;
	  return (x*a)%mod;
	}	  
}

int main() {
	ll ten[15] = {0};
	ten[0] = 1;
	FOR(i,1,10)
	 ten[i] = ten[i-1]*10;
	 
	ll t; get(t);
	while(t--) {
		ll n, k;
		get(n); get(k);
		
		long double val = n*log10l(n);
		long double y = val - floor(val);
		long double x = powl(10,y)*ten[k-1];
		
		ll last = modpow(n,n,ten[k]);
		printf("%d ", (int)x );
		
		ll ptr = last, c = 0;
		while( ptr != 0 )
			{ c++; ptr /= 10; }
		FOR(i,1,k-max(c,1LL))
		 printf("0");
		printf("%lld\n", last );
	}
}
