#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define foo(a,b,c) mp( mp(a,b), c )
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main() {
	ll t; get(t);
	while(t--) {
		ll n, x;
		get(n); get(x);
		vector<ll> v;
		v.pb(0);
		
		FOR(i,1,n)
		 { ll q; get(q); v.pb(q); }
		
		ll val[100005] = {0}, ans = 0;
		
		FOR(i,1,n) {
		  val[i] = max( v[i]-x + val[i-1], 0LL );
		  ans = max( val[i], ans );
		}
		
		printf("%lld\n", ans);	 
	}
}
