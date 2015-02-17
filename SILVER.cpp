#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <cstring>
#define ll int
#define get(a) scanf("%d", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
#define min(a,b) a < b ? a : b
#define absol(a) a >= 0 ? a : -a
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
using namespace std;

long dp[20000+10] = {0};

long rec( ll n ) {
	if( n == 1 )
		return 0;
	if( dp[n] != 0 )
		return dp[n];	
	ll a = n/2;
	ll b = n-a;	
	ll v = min(a,b);
	
	dp[n] = 1 + rec(v);
	return dp[n];
	
}

int main() {
 
  while(1) {
	ll n;
 	get(n);
 	
 	if( n == 0 )  break;
 	printf("%ld\n", rec(n));
 	
 }
}
