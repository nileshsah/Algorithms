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

ll prime[10000005] = {0};
bool mark[10000005] = {0};


void sieve( ) {
	ll N = 10000002;
		
	FOR(i,2,N)
	 if( !mark[i] ) 	
	 	for( ll k = i; k <= N; k += i )
	 		{ prime[k]++; mark[k] = 1; }	  
}

int main() {
	INPFILE;
	sieve();
	
	ll t, w = 1; get(t);
	while(t--) {
		
		ll a, b, k, ans = 0;
		cin >> a >> b >> k;
		
		FOR(i,a,b)
		 if( prime[i] == k )
		 	ans++;
		
		printf("Case #%lld: %lld\n", w++, ans );

	}
}
