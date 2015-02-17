#include <bits/stdc++.h>
#define ll int
#define get(a) scanf("%d", &a)
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSTL(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( int i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main() {
	ll t; get(t);
	while(t--) {
		ll n; get(n);
		vector<ll> v;
		
		rep(n)
		 { ll x; get(x); v.pb(x); }
		
		sort( all(v) );
		
		bool flag = 0;
		
		FOR(i,1,v.size()-1)
		 if( v[i] == v[i-1] )
		  { flag = 1; break; }
		
		if( flag )
		 printf("NO\n");
		else
		 printf("YES\n");
	}
}
