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

ll parent[100005] = {0};

ll find( ll x ) {
	if( parent[x] != x )
	  parent[x] = find( parent[x] );
	return parent[x];
}

void join( ll x, ll y ) {
	ll p = find(x);
	ll q = find(y);
	parent[p] = q;
}

int main() {
//	INPFILE;
	ll n, q;
	get(n); get(q);
	
	FOR(i,1,n)
	 parent[i] = i;
	
	while(q--) {
		ll w, x, y;
		get(w); get(x); get(y);
		
		if( w == 0 ) {
			join(x,y);
		}
		else if( w == 1 ) {
			if( find(x) == find(y) )
				printf("Yes\n");
			else
				printf("No\n");
		}
		
	}
	
	
}
