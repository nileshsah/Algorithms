#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<int>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) a >= 0 ? a : -a
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define L 2*r
#define R 2*r+1
using namespace std;


bool dp[1000005] = {0};

int main() {
	ll m, k, l;
	get(k); get(l); get(m);
	
	FOR(i,1,1000003) {
		if( i-1 >= 0 && dp[i-1] == 0 )
			dp[i] = 1;
		if( i-l >= 0 && dp[i-l] == 0 )
			dp[i] = 1;
		if( i-k >= 0 && dp[i-k] == 0 )
			dp[i] = 1;
	}
	
	while(m--) {
		ll n; get(n);
		printf("%c", dp[n] == 1 ? 'A':'B');
	}
}
