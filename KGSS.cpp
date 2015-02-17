#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for(vector< pair<ll,ll> >::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set< pair< ll, pair<ll,ll> > >::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 10000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

ll v[100000+5] = {0};

struct node {
	ll val;
	ll max;
	ll min;
	ll l, r;
};

node tree[4*(100000+5)];

void construct( pair<ll,ll> p, ll r ) {
	node ptr;
	ptr.l = p.F; ptr.r = p.S;
	
	if( p.F == p.S )
	 { ptr.val = ptr.max = v[p.F]; ptr.min = 0; }
	else {
		ll mid = (p.F+p.S)/2;
		construct( mp(p.F,mid)  , L );
		construct( mp(mid+1,p.S), R );
		
		vector<ll> temp;
		temp.pb( tree[L].min ); temp.pb( tree[L].max );
		temp.pb( tree[R].min ); temp.pb( tree[R].max );
		sort( all(temp), greater<ll>() );
		
		ptr.max = temp[0]; ptr.min = temp[1];
		ptr.val = ptr.max + ptr.min;
		
	}
//	cout << " ROOT: " << r << " :: " << p.F << "," << p.S << " -- " << ptr.val << endl;
	tree[r] = ptr;
}

void update( ll x, ll y, ll r, ll val ) {
	ll mid = ( tree[r].r + tree[r].l )/2;
	
	if( tree[r].r < x || tree[r].l > y )
		return;
	if( tree[r].r == x && tree[r].l == y )
	 { tree[r].max = tree[r].val = val; tree[r].min = 0; return; }

	update( x, y, L, val );
	update( x, y, R, val );
	
		vector<ll> temp;
		temp.pb( tree[L].min ); temp.pb( tree[L].max );
		temp.pb( tree[R].min ); temp.pb( tree[R].max );
		sort( all(temp), greater<ll>() );
		
		tree[r].max = temp[0]; tree[r].min = temp[1];
		tree[r].val = tree[r].max + tree[r].min;
	
}

node query( ll x, ll y , ll r = 1) {
//	cout << " EX: " << x << " " << y << endl;
//	cout << " Q: " << tree[r].l << " " << tree[r].r << " r: " << r << endl;
	ll mid = ( tree[r].r + tree[r].l )/2;
	
	if( tree[r].l >= x && tree[r].r <= y )
		return tree[r];
	if( x > mid )
		return query( x,y, R );
	if( y <= mid )
		return query( x,y, L );
		
	node ql = query( x,y, L );
	node qr = query( x,y, R );
	
	vector<ll> temp;
	temp.pb( ql.min ); temp.pb( ql.max );
	temp.pb( qr.min ); temp.pb( qr.max );
	sort( all(temp), greater<ll>() );
	
	node ptr;
	ptr.max = temp[0]; ptr.min = temp[1];
	ptr.val = ptr.max + ptr.min;
	
	return ptr;
	
}

int main() {
	ll n; get(n);
	rep(n) get(v[i]);
	
	construct( mp(1,n), 1 );
	
	ll m; get(m);
	while(m--) {
		ll x, y; char q[2];
		scanf("%s", &q);  get(x); get(y);
		
		if( q[0] == 'U' )
		  update( x, x, 1, y );
		else if( q[0] == 'Q' )
		  printf("%ld\n", query(x,y).val );
	}
}
