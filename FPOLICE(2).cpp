#include <bits/stdc++.h>
#include <cstdio>
#define ll int
#define get(a) scanf("%d", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
using namespace std;

ll Time[105][105] = {0};
ll risk[105][105] = {0};
ll N, T;

map< ll, pair<ll,ll> > dp;

pair<ll,ll> rec( ll cur = 0, ll r = 0, ll t = 0 ) {
	if( t > T )
		return mp(INT_MAX,INT_MAX);
		
	if( cur == N-1 )
		return mp(r,t);
	
//	if( dp.find(cur) != dp.end() )
//		return mp(r+dp[cur].F,t+dp[cur].S);
	
	pair<ll,ll> val = mp(INT_MAX,INT_MAX), idx;
	
	FOR(i,1,N)
	 if( cur != i ) {
		idx = rec(i,r+risk[cur][i],t+Time[cur][i]);
		val = min( val, idx );
	}
	
	dp[cur] = mp( val.F - r, val.S - t );
	return val; 
}

int main() {
	ll t; get(t);
	while(t--) {
		get(N); get(T);
		dp.clear();
		
		FOR(i,0,N)
		 FOR(j,0,N)
		  get(Time[i][j]);
		
		FOR(i,0,N)
		 FOR(j,0,N)
		  get(risk[i][j]);
		
		rec();
		pair<ll,ll> p = dp[0];
		
		if( p.S > T )
		  printf("-1\n");
		else
		 printf("%d %d\n", p.F, p.S);
		
		
	}
}
