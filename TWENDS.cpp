#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define llu long long unsigned
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSTL(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

vector<ll> v;


ll dp[1005][1005];

ll rec( ll start, ll end, ll r = 0 ) {
	if( start > end )
		return 0;
				
	ll val = 0;
	
	if( r == 1 ) {
		if( v[start] >= v[end] )
			rec( start+1, end );
		else
			rec( start, end-1 );
	}
	else {
	  if( dp[start][end] != 0 )
		return dp[start][end];
	  else
		val = max( v[start] + rec( start+1, end, 1), v[end] + rec( start, end-1, 1 ) );	
	  dp[start][end] = val;
	  return val;	
	}
}
		 
	
int main() {
	ll t = 1;
	while(1) {
		ll n, sum = 0; get(n);
		if( n == 0 )
			return 0;
		
		memset( dp, 0, sizeof dp );
		v.clear();
		rep(n)
	     { ll x; get(x); v.pb(x); sum += x; }

		ll q = rec( 0, v.size()-1 );
		
		printf("In game %ld, the greedy strategy might lose by as many as %ld points.\n", t++, 2*q-sum ); 
		
		
	}
}
