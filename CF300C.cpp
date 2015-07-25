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
#define MOD 1000000007
using namespace std;

ll fact[1000005] = {0};
ll a, b, n;

ll modpow( ll a, ll b ) {
	if( b == 0 )
	 return 1;
	else if( b%2 ) {
	  ll x = modpow( a, (b-1)/2 );
	  x *= x; x %= MOD;
	  return (x*a)%MOD;
	}
	else {
	  ll x = modpow( a, b/2 );
	  return (x*x)%MOD;	  
	}
}

ll nCr( ll n, ll r ) {
	if( r == 0 )
	 return 1;
	 
	ll k = fact[n];
	k *= modpow( fact[n-r], MOD-2 );
	k %= MOD;
	k *= modpow( fact[r], MOD-2 );
	return k%MOD;
}

bool check( ll num ) {
	while(num) {
	  if( !(num%10 == a || num%10 == b ) )
	  	return 0;
	  num /= 10;
	}
	return 1;
}

int main() {
	
	cin >> a >> b >> n;
	
	fact[0] = 1;
	
	FOR(i,1,n)
	 fact[i] = (fact[i-1]*i)%MOD;
	 
	
	ll sum = a*n, ans = 0;
	FOR(i,0,n) {
	  ll k = sum - i*a + i*b;
	  if( check(k) )
	   { ans += nCr(n,i); ans %= MOD; }
	}
	
	cout << ans;
}
