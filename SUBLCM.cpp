#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
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

vector<ll> prime;
vector<ll> factors[1000005];

void sieve() {
	ll N = 1000000;
	bool mark[1000005] = {0};
	ll c = 0;
	
	FOR(i,2,N)
	 if( !mark[i] ) {
	 	for( ll k = i; k <= N; k += i )
	 	 { factors[k].pb(i); mark[k] = 1; }
	 	prime.pb(i);
	 	c++;
	 }
	 
}

ll v[100005] = {0};
ll last[1000005] = {0};

ll calc( ll x ) {
	ll i = 0; ll ptr = v[x], ans = 0;
	vector<ll> &factor = factors[v[x]];;
	
	if( factor.empty() )
	 while( i < prime.size() && prime[i] <= ptr ) {
	  if( ptr%prime[i] == 0 )
		{ factor.pb(prime[i]); ptr /= prime[i]; }
	  i++;
	 }
	 
	repVector(factor) {
	    ans = max( ans, last[*it] ); 
		last[*it] = x;
	  }

	  
	return ans;
}


int main() {
	sieve();
	
	ll t; get(t);	
	while(t--) {
		ll n; get(n);
		memset( last, 0, sizeof last );
		
		FOR(i,1,n)
		 get(v[i]);
		
		ll ans = 0;
		ll dp[100005] = {0};
		
		FOR(i,1,n) {
		 dp[i] = min( dp[i-1]+1, i-calc(i) );
		 ans = max( ans, dp[i] );
		}
		
		printf("%ld\n", ( ans == 1 ) ? -1 : ans );
	//	cout << rec(0) << endl;
	}
}
