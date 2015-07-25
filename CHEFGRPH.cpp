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
#define gc getchar
#define pc(x) putchar(x);
using namespace std;
 
ll n, m, k;
#define Q 100000000
ll store[Q] = {0};
 
ll modpow(ll base,ll exp){
	if( exp == 0 )
		return 1;
	if( exp < 0 )
		return 1;
	if( exp < Q && store[exp] != 0 )
		return store[exp];
		
	ll ans=1;
	while(exp){
		if(exp%2) ans=ans*base%MOD;
		base=base*base%MOD;
		exp/=2;
	}
	if(ans<0) ans+=MOD;
	if( exp < Q ) store[exp] = ans;
	return ans;
}
 
vector< pair< pair<ll,ll> ,pair<ll,ll> > > v, y;
ll ans = 0;
ll dp[60005] = {0};
  
int main() {
	INPFILE;
	get(n); get(m); get(k);
	
	ans += modpow(m,n);
	
	FOR(i,1,k) {
		ll x1, m1, y1, m2;
		get(x1); get(m1); get(y1); get(m2);
		v.pb( mp( mp(y1,m2), mp(x1,m1) ) );
	}
	
	sort( all(v) );
	
	for( ll i = 0; i < k; i++ ) {

/*	  for( ll j = i-1; j >= 0; j-- )
	   if(  v[i].S.F > v[j].F.F || v[i].S == v[j].F ){ 
	     dp[i] += dp[j]*modpow(m,v[i].S.F-v[j].F.F-1);
	     break;
	   }
	*/
	   ll j = i-1;
	   if( j >= 0 ) {
	   	if( v[i].F.F == n+1 || v[j].S.F == 0 )
		  dp[i] += modpow(m,v[i].F.F-v[j].F.F-1)*dp[j];
		else
		  dp[i] += modpow(m,v[i].F.F-v[j].F.F)*dp[j];
		  
	     while( j >= 0 && v[i].S < v[j].F ) j--;
	    cout << " I2: " << i << " J : " << j << endl;

		 if( j >= 0 ) 
		  dp[i] += dp[j]*modpow(m,v[i].S.F-v[j].F.F-1);
	   }
	
		
		dp[i] += modpow( m, max(0LL,v[i].S.F-1) ); 
		dp[i] %= MOD;
	cout << " VAL: " << i << " " << dp[i] << endl;
//		ans += ( modpow(m,n-v[i].F.F)*dp[i] )%MOD;
	}
	
	ll i = k-1;
	ans += ( max(1LL,modpow(m,n-v[i].F.F))*dp[i] )%MOD;
	
	cout << ans%MOD;
	
} 
