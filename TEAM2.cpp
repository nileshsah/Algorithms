#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
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

int main() {
	ll x1, x2, y1, y2, t = 1;
	while( scanf("%lld %lld %lld %lld", &x1, &y1 ,&x2, &y2) != -1  ) {
		ll ans = x1 + x2;
		ans = max( ans, x1 + y1 );
		ans = max( ans, x2 + y1 );
		ans = max( ans, y2 + y1 );
		ans = max( ans, x1 + y2 );
		ans = max( ans, x2 + y2 );
			
		printf("Case %lld: %lld\n", t++, ans );
	}
}
