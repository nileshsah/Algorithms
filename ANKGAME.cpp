#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
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
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

#define MOD 1000000007

ll fact[100005] = {0};

void precompute( ) {
	fact[0] = 1;
	FOR(i,1,100001)
	 fact[i] = ( fact[i-1]*i )%MOD;
}

ll store[100005] = {0};

ll modpow( ll x, ll y ) {
	if( store[x] )
	 return store[x];
	ll bk = x;
	x = fact[x];
	ll ans = 1;
	while(y) {
		if(y%2)
		 ans = ( ans * x )%MOD;
		y /= 2;
		x = ( x * x )%MOD;
	}
	return store[bk] = ans;
}

int main() {
	precompute();
	ll t; get(t);
	while(t--) {
		map<ll,ll> m;
		ll n; get(n);
		FOR(i,1,n)
		 { ll x; get(x); m[x]++; }
		
		if( m[1] == n )
		 { printf("%lld\n",m[1]%2); continue; }
		 
		ll ans = fact[n], div = 1;
		repVector(m) 
		 if( it->F != 1 )
		  div = ( div*modpow(it->S,MOD-2) )%MOD;
		
		ans *= modpow( m[1], MOD-2 ); ans %= MOD;
		ans *= div; ans %= MOD;
		
		
		for( int i = 1; i <= m[1]; i += 2 ) {
			ll left = m[1] - i;
			ll val = fact[n-i];
			val *= div; val %= MOD;
			val *= modpow( left,MOD-2);
			val %= MOD;
			
			if( left > 0 ) {
			   ll num = fact[n-i-1];
			   num *= div; num %= MOD;
			   num *= modpow( left-1,MOD-2);
			   num %= MOD;
			   val -= num;
			   val = ( val + 2*MOD )%MOD;
			}
			
			ans -= val;
			while( ans < 0 )
			 ans += MOD;
		}
				
		printf("%lld\n",ans%MOD);
	}
}
