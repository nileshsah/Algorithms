#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define max(a,b) ( (a > b) ? a : b )
#define min(a,b) ( (a < b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

vector< pair<ll,ll> > v[7];
ll dp[10][1005] = {0};

ll rec( ll r, ll sum ) {
	if( sum < 0 )
		return 0;
	if( r >= 7 )
		return INT_MAX;
	
	if( dp[r][sum] != 0 )
		return dp[r][sum];
	
	ll val = 0;
	
	repVector(v[r])
	  if( sum >= it->F )
	  	val = max( val, min( it->S, rec( r+1, sum - it->F ) ) );
	
	dp[r][sum] = val;
	return val;
}


int main() {
//	INPFILE;
	ll n, T;
	get(n); get(T);
	ll count[7] = {0};
	
	rep(n) {
		ll x, p, q;
		get(x); get(p); get(q);
		v[x].pb(  mp(p,q) );
		count[x]++;	
	}
	
	FOR(i,1,6)
	 if( count[i] == 0 )
	 	{ printf("0"); return 0; }
	
	FOR(i,1,6)
	 sort( all(v[i]) );
	
	ll ans = rec(1,T);
	
	printf("%ld", ans);
	
	
}
