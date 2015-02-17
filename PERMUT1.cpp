#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) a >= 0 ? a : -a
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define L 2*r
#define R 2*r+1
using namespace std;

ll dp[15][100] = {0};

ll rec( ll n, ll k ) {
	if( n == 0 )
		return 0;
	if( k == 0 )
		return 1;
	if( dp[n][k] != -1 )
		return dp[n][k];
	ll val = 0;
	
	for( ll i = 0; i < n && k-i >= 0; i++ )
		val += rec(n-1,k-i);
	dp[n][k] = val;
	return dp[n][k];
}

int main() {
  ll d;
  get(d);
  
  memset( dp, -1, sizeof dp );
  rec(12,98);
 
  while(d--) {
	ll n, k;
	get(n); get(k);
	printf("%ld\n",rec(n,k));
 }
	
}
