#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 1; i <= n; i++ )
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

int main() {
	ll t;
	get(t);
	
	while(t--) {
		ll n, a[100000+5] = {0};
		get(n);
		
		long long sum = 0;
		
		rep(n) {
			get(a[i]);
			sum += abs( a[i-1] );
			a[i] += a[i-1];	
		}
		
		printf("%lld\n", sum);
		
	}
}
