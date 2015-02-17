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
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll n, m;

ll modpow(ll base,ll exp){
	ll ans=1;
	while(exp){
		if(exp%2) ans=ans*base%MOD;
		base=base*base%MOD;
		exp/=2;
	}
	if(ans<0) ans+=MOD;
	return ans;
}

vector<ll> fact[1005];

void sieve( ) {
	ll N = 1000;
	bool mark[1005] = {0};
	
	for( ll i = 2; i <= 1000; i++ ) {
		if( !mark[i] )
		 for( ll k = i; k <= N; k += i ) {
		 	ll q = 1, r = k;
		 	while(  r%i == 0 )
		 	 { q *= i; r /= i; }
		 	fact[k].pb(q);
		 	mark[k] = 1;
		 }
	}
}

matrix mul( matrix a, matrix b ) {
	ll len = a.size()-1;
	matrix c(len+1, vector<ll>(len+1,0) );

	FOR(i,0,len)
	 FOR(j,0,len)
	  FOR(k,0,len) {
	  	c[i][j] += ( a[i][k]*b[k][j] )%MOD;
	 	c[i][j] %= MOD;
	 }
	
	return c;  	
}

matrix fastpow( matrix a, ll n ) {
	matrix I(2, vector<ll>(2,0));
	I[0][0] = 1; I[0][1] = 0; I[1][0] = 0; I[1][1] = 1;
	if( n == 0 )
		return I;
	if( n == 1 )
		return a;
	if( n%2 == 0 )
		return fastpow( mul(a,a), n/2 );
	else
		return mul( a, fastpow( mul(a,a), (n-1)/2 ) );		
}

ll rec( ll x ) {
	
/*	cout << " FACT: ";
	FOR(j,0,fact[x].size()-1)
		cout << fact[x][j] << " ";
	cout << "\n";
*/
	
	ll bit[64] = {0};
	
	FOR(i,1,m) {
		ll val = 0;
	if( !fact[x].empty() )	
	 FOR(j,0,fact[x].size()-1)
	 	if( i%fact[x][j] == 0 )
	 		val += pow(2,j);
	 bit[val]++;
	}
	
	ll end = pow(2,fact[x].size()) - 1;
	matrix dp( end+1, vector<ll>(end+1,0) );
	
	FOR(i,0,end)
	 FOR(j,0,i)
	  FOR(k,0,end)
	   	dp[i][j] += ( (j|k) == i )*bit[k];
	
	dp = fastpow( dp, n );
	
	FOR(i,0,end) {
	 FOR(j,0,end)
	  cout << dp[i][j] << " ";
	 cout << endl;
	}

	return dp[end][0];
	
}

ll gcd( ll a, ll b ) { return ( ( b == 0 ) ? a : gcd( b, a%b ) ); }
ll lcm( ll a, ll b ) { return a*b/gcd(a,b); }

int main() {
	sieve();
	ll t; get(t);
	while(t--) {
		ll  l, r;
		get(n); get(m); get(l); get(r);
		ll ans = 0;
		
		FOR(i,l,r) {
		 ans += rec(i); ans %= MOD;
		}
		
		printf("%lld\n", ans%MOD);
		
	}
}
