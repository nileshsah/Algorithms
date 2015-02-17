#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) scanf("%lld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector< pair<ll,double> >::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set< pair< ll, pair<ll,ll> > >::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 10000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

int main() {
	ll t, count = 1;
	get(t);
	
	while(t--) {
		ll n; get(n);
		vector<ll> v(n+1,0);
		ll dp[10000+5] = {0};
		
		rep(n) get(v[i+1]);
		
		dp[1] = v[1];
		
		FOR(i,2,n+1)
			dp[i] = max( dp[i-1], v[i]+dp[i-2] );
		printf("Case %lld: %lld\n", count++, dp[n]);
		
	}
}
