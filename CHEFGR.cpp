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

int main() {
	ll t;
	get(t);
	
	while(t--) {
		ll n, m;
		ll a[100+5] = {0};
		get(n); get(m);
		
		ll maxnum = 0, sum = m;
		
		rep(n) {
			get(a[i]);
			sum += a[i];
			maxnum = max( a[i], maxnum );
		}
		
		if( sum%n == 0 && maxnum <= sum/n )
			printf("Yes\n");
		else
			printf("No\n");
	}	
}
