#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) scanf("%lld", &a)
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

int main() {
	ll t;
	get(t);
	ll c = 1;
	
	while(t--) {
		ll n; get(n);
		vector<ll> v(n,0);
		ll sum = 0;
		ll m = 0;
		
		rep(n) {
		 get(v[i]);
		 sum += v[i];
		 
		 if( sum < 0 )
		 	m = min( m , sum );
		}
				
		printf("Scenario #%lld: %lld\n", c++, 1-m );
		
	}
}
