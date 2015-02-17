#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) scanf("%lld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<int>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
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

ll dp[1000005] = {0};
bool arr[1000000+6] = {0};

void alice() {
	ll n = 1000000+5;
	
	FOR(i,2,n+1) {
		if( arr[i] == 1 )
			continue;
		for( ll k = i*i; k <= n; k += i )
			arr[k] = 1;
	}
	
	FOR(i,2,n+1) {
		dp[i] = dp[i-1];
		if(!arr[i])
	 	  dp[i]++;
	}

}

int main() {
	alice();
	
	ll t;
	get(t);
	
	while(t--) {
		ll n;
		get(n);
		
		printf("%lld\n", n - dp[n-1] - 1);
	}
}
