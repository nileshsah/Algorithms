#include <bits/stdc++.h>
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
#define MOD 1000000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

ll v[100000+5] = {0};

struct node {
	ll val, maxL, maxR;
	ll l, r;
};

node tree[4*(100000+5)];

void construct( pair<ll,ll> p, ll r = 1 ) {
	node ptr;
	ptr.l = p.F; ptr.r = p.S;
	
	if( p.F == p.S ) {
		ptr.val = ptr.maxL = ptr.maxR = 1;
	}
	else {
		ll mid = ( p.F + p.S )/2;
		construct( mp(p.F,mid), L );
		construct( mp(mid+1,p.S), R );
		
		if( v[mid] == v[mid+1] ) {
			ptr.maxL = tree[L].maxL + tree[R].maxL*( v[p.F] == v[mid] );
			ptr.maxR = tree[R].maxR + tree[L].maxR*( v[mid+1] == v[p.S] );
			ll temp = tree[R].maxL + tree[L].maxR;
			ptr.val = max( temp, max( tree[R].val, tree[L].val ) );
		}
		else {
			ptr.val = max( tree[R].val, tree[L].val );
			ptr.maxL = tree[L].maxL;
			ptr.maxR = tree[R].maxR;
		}
		
	}
	
	tree[r] = ptr;
//	printf(" R: %d (%d,%d) [%d %d %d]\n", r, p.F,p.S,ptr.maxL,ptr.val,ptr.maxR);
	
}


node query( ll x, ll y, ll r = 1 ) {
	ll mid = ( tree[r].l + tree[r].r )/2;
	
	if( tree[r].l >= x && tree[r].r <= y )
		return tree[r];
	if( x > mid )
		return query(x,y,R);
	else if( y <= mid )
		return query(x,y,L);
	
	node qr = query(x,y,R);
	node ql = query(x,y,L);
	node ptr;
	
		if( v[mid] == v[mid+1] ) {
			ptr.maxL = ql.maxL + qr.maxL*( v[tree[r].l] == v[mid] );
			ptr.maxR = qr.maxR + ql.maxR*( v[mid+1] == v[tree[r].r] );
			ll temp = qr.maxL + ql.maxR;
			ptr.val = max( temp, max( qr.val, ql.val ) );
		}
		else {
			ptr.val = max( qr.val, ql.val );
			ptr.maxL = ql.maxL;
			ptr.maxR = qr.maxR;
		}
	
	return ptr;	
}

int main() {
	while(1) {
		ll n, m;
		get(n); if( n == 0 ) return 0;
		get(m);
		
		rep(n) get(v[i]);
	
		construct( mp(1,n) );
		
		rep(m) {
			ll x, y;
			get(x); get(y);
			printf("%d\n", query(x,y).val);
		}
	}
}

