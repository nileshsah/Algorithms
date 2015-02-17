#include <bits/stdc++.h>
#include <cstdio>
#define ll int
#define get(a) scanf("%d", &a);
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

struct node {
	ll val;
	ll l, r;
	bool lazy;
};


node tree[4*(100000+5)];

inline void lazyme( ll r ) {
	tree[r].lazy = 0;
	tree[L].lazy = !tree[L].lazy;
	tree[R].lazy = !tree[R].lazy;
	
	tree[L].val = tree[L].r - tree[L].l + 1 - tree[L].val;
	tree[R].val = tree[R].r - tree[R].l + 1 - tree[R].val;
}

void construct( pair<ll,ll> p, ll r = 1 ) {
	node ptr;
	ptr.l = p.F; ptr.r = p.S;
	ptr.val = 0; ptr.lazy = 0;
	
	if( p.F != p.S ) {
		ll mid = ( p.F + p.S )/2;
		construct( mp( p.F, mid ), 2*r );
		construct( mp( mid+1, p.S ), 2*r+1 );
	}
	
	tree[r] = ptr;		
}

node query( ll x, ll y, ll r = 1 ) {
	if( tree[r].lazy )
	 lazyme(r);
	 
	ll mid = ( tree[r].l + tree[r].r )/2;
	
	if( tree[r].l >= x && tree[r].r <= y )
		return tree[r];
	if( x > mid )
		return query( x, y, R );
	else if( y <= mid )
		return query( x, y, L );
	
	node qr = query(x,y,R);
	node ql = query(x,y,L);
	
	node ptr;
	ptr.val = qr.val + ql.val;
	
	return ptr;	
}

void update( ll x, ll y, ll r = 1 ) {
	if( tree[r].lazy )
	 lazyme(r);
	
	if( x > tree[r].r || y < tree[r].l )
		return;
		
	if( tree[r].l >= x && tree[r].r <= y ) { 
	 tree[r].val = ( tree[r].r - tree[r].l + 1 ) - tree[r].val;
   	 tree[r].lazy = 1;
   	 return;
    }
	 
	update( x, y, L );
	update( x, y, R );
	
	tree[r].val = tree[L].val + tree[R].val;
	
}


int main() {
	ll n, m;
	get(n); get(m);	
	construct( mp(1,n) );

	rep(m) {
		ll q, x, y;
		get(q); get(x); get(y);
		
		if( q == 0 )
			update( x, y );
		else if( q == 1 )
			printf("%d\n", query(x,y).val );
	}
	
}
