#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) scanf("%lld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
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
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

int main() {
	ll count = 1;
	
  while(1) {
	ll n; get(n);	
	if( n == -1 ) return 0;
	
	printf("Case %d:\n", count++);
	stack<ll> v, vv;
	
	rep(n+1)
	 { ll x; get(x); vv.push(x); }
	
	ll m; get(m);
	
	rep(m) {
		v = vv;
		ll x; get(x);
		ll xx = 1, ans = 0;
		while(!v.empty())
		 { ans += v.top()*xx; v.pop(); xx *= x; }
		printf("%lld\n", ans );
	}
	
  }
}
