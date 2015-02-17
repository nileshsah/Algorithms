#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define mod 1000000007
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll modpow(ll base,ll exp, ll MOD ){
	ll ans=1;
	while(exp){
		if(exp%2) ans=ans*base%MOD;
		base=base*base%MOD;
		exp/=2;
	}
	if(ans<0) ans+=MOD;
	return ans;
}


int main() {
	ll t; get(t);
	while(t--) {
		ll k, n;
		get(k); get(n);
		
		if( n == 1 )
		 printf("1\n");
		else if( n == 2 )
		 printf("%lld\n", k );
		 else {
		 	ll val = modpow( 2, n-3, mod-1 );
		 	ll ans = modpow( k, val, mod );
		 	printf("%lld\n", ans);
		 }
		
	}
}
