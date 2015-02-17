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
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define foo(a,b,c) mp( mp(a,b), c )
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main() {
	ll n, k;
	get(n); get(k);
	vector<ll> v;
	map<ll,ll> m;
	
	FOR(i,1,n)
	 { ll x; get(x); v.pb(x); m[x]++; }
	
	FOR(i,0,n-1)
	 if( k - v[i] == v[i] && m[v[i]] >= 2 )
	 	{ printf("Yes"); return 0; }
	 else if( k - v[i] != v[i] && m[k-v[i]] > 0 )
	   { printf("Yes"); return 0; }
	
	printf("No");
}
