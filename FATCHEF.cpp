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
#define MOD 1000000009
#define L 2*r
#define R 2*r+1
using namespace std;

int main() {
	ll t;
	get(t);
	
	while(t--) {
		ll n, m;
		get(n); get(m);
		vector< pair<ll,char> > v;
		vector<ll> mul;
		v.pb( make_pair(0,'*') );
		
		rep(m) {
		  char c[2]; ll x;
		  scanf("%s", &c); get(x);
		  v.pb( make_pair(x,c[0]) );
		}
		
		sort( all(v) );
		long long sum = 1;
		
		FOR(i,1,v.size()-2) {
			pair<ll,char> p1 = v[i], p2 = v[i+1];
		
			ll ans;
			
			if( p1.second == p2.second )
				ans = 1;
			else if( p2.first - p1.first - 1 == n-m ) {
				ans = 1;
			}
			else  {
				ans = p2.first - p1.first;
			}
				
			sum *= ans;
			sum %= MOD;						
		}
		
		
		printf("%lld\n", sum);
		
	}
}
