#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
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

bool mark[5*1000005] = {0};
ll prime[5*1000005] = {0};
ll dp[5*1000005] = {0};

void sieve() {
	ll N = 5*1000000;
	FOR(i,2,N) {
	  prime[i] = prime[i-1] + !mark[i];
	 if( !mark[i] )
	 	for( ll k = i*i; k <= N; k += i )
	 		mark[k] =1;
	 }
}

int main() {
	
	sieve();
	
	dp[1] = 1;
	FOR(i,2,5*1000000)
	  dp[i] = ( ( 1 + prime[i] )*dp[i-1] )%MOD;
	  
	ll t; get(t);
	while(t--) {
		ll n; get(n);
		printf("%lld\n",dp[n]);
	}
}
