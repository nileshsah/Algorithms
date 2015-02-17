#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
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

struct node {
	ll val;
	ll l, r;
	ll lazy;
};

node tree[4*(100000)] = {0};

void lazyme( ll r ) {
	if( tree[r].lazy ) {
		tree[r].val += tree[r].lazy;
		tree[R].lazy += tree[r].lazy;
		tree[L].lazy += tree[r].lazy;
		
		tree[r].lazy = 0;
	}
}

void construct( pair<ll,ll> p, ll r = 1 ) {
	node &ptr = tree[r];
	ptr.val = 0;
	ptr.l = p.F; ptr.r = p.S;
	ptr.lazy = 0;

	if( p.F == p.S )
		return;
	else {
		ll mid = (p.F+p.S)/2;
		construct( mp(p.F,mid), L );
		construct( mp(mid+1,p.S), R );
	}
}

void update( ll x, ll y, ll val, ll r = 1 ) {
	ll mid = ( tree[r].l + tree[r].r )/2;
	
	lazyme(r);
	
	if( x > tree[r].r || y < tree[r].l )
		return;
	
	if( tree[r].l >= x && tree[r].r <= y ) {
		tree[r].val += val;
		tree[L].lazy += val;
		tree[R].lazy += val;
		return;
	}
	else {
		update( x, y, val, L );
		update( x, y, val, R );
	}
}

ll query( ll x, ll r = 1 ) {
	lazyme(r);
	
	ll mid = ( tree[r].l + tree[r].r )/2;
	
	if( x == tree[r].r && tree[r].l == x )
		return tree[r].val;	
	if( x > mid )
		return query( x, R );
	if( x <= mid )
		return query( x, L );
}

int main() {
//	INPFILE;
	ll t; get(t);
	while(t--) {
		ll n, u;
		get(n); get(u);
		
		construct( mp(1,n) );
		
		rep(u) {
			ll x, y, k;
			get(x); get(y); get(k);		
			update( x+1, y+1, k );
		}
		
		ll m; get(m);
		rep(m) {
		   ll x; get(x);
		   printf("%ld\n", query(x+1));
		}
		
	}
}
