#include <bits/stdc++.h>
#define ll int
#define get(a) scanf("%d", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
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
	ll t, w = 1; get(t);
	while(t--) {
		ll d, s;
		get(d); get(s);
		
		double ans, val = 9.806*d/(s*s);
				
		if( val > 1.0 )
		  {  printf("Scenario #%d: -1\n", w++); continue; }
		else
		  ans = ( 180*asin(val) )/(4*acos(0.0));
		
		printf("Scenario #%d: %0.2lf\n", w++, ans);
	}
}
