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
#define foo(a,b,c) mp( mp(a,b), c )
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define MOD 1000000007
#define INPFILE freopen("input.in","r",stdin)
using namespace std;


int main() {
	ll t; get(t);
	while(t--) {
	   ll n; get(n);
	   vector<ll> v, idx;
	   ll dp[100005] = {0};
	   
	   FOR(i,1,n)
	    { ll x; get(x); v.pb(x); idx.pb(x); }
	   sort( all(idx) );
	   
	   FOR(i,0,n-1)
	    FOR(j,0,n-1) {
	     dp[j] += abs( idx[j] - v[i] );
	     if( j > 0 )
	      dp[j] = min( dp[j-1], dp[j] );
	 	}
	 	
	// 	cout << dp[n-1] << " ";
	 	
	 	if( dp[n-1]%2 == 0 )
	 	 printf("MOHIT\n");
	 	else
	 	 printf("GFRINED\n");
	
	}
}
