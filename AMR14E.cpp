#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a)
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSTL(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( int i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

vector<ll> prime;
ll arr[40000] = {0};
ll N = 32000;

void sieve() {
	bool mark[32000] = {0};
	ll c = 0;
	
	FOR(i,2,N)
	 if( !mark[i] ) {
	 	prime.pb(i);
	 	arr[i] = arr[i-1] + 1;
	 	for( ll k = i*i; k <= N; k += i )
	 		mark[k] = 1;
	 }
	 else
	  { arr[i] = arr[i-1]; }
}

vector< pair<ll,ll> > factorize( ll n ) {
	vector< pair<ll,ll> > v;
	
	for( ll i = 0; prime[i] <= sqrt(n); i++ )
		if( n%prime[i] == 0 ) {
			ll temp = n; ll p = 0;
			while( temp%prime[i] == 0 )
			 { p++; temp /= prime[i]; }
			v.pb( mp( prime[i], p ) );
		}
	
	return v;		
}

long long intlog(double base, double x) {
    return (long long)(log(x) / log(base));
}

ll modpow(ll base,ll exp){
	ll ans=1;
	while(exp){
		if(exp%2) ans=ans*base;
		base=base*base;
		exp/=2;
	}
	return ans;
}


int main() {
	sieve();
	ll t; get(t);
	while(t--) {
		ll a, b;
		get(a); get(b);
		
		ll ans = 0;
		
		for( ll i = 0; prime[i] <= (b) && i < prime.size(); i++ )
		  FOR(j,0,prime.size()-1) {
			ll x = modpow(prime[i], prime[j]-1);
			if( x > b ) break;	
			if( x < a ) continue;	
			ans++;	
			// ans += arr[min(b/x,N)] - arr[a/x]; 
			// cout << " X: " << x << " ANS: " << ans << endl;
		  }
		 
		
		
		printf("%lld\n", ans);
		
	}
	
}
