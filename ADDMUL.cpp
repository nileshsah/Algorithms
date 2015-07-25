#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

#define MOD 1000000007

struct node {
	ll sum;
	ll l, r;
	ll lazyadd;
	ll lazymul;
}tree[8*(100005)];

ll v[100005] = {0};

void display( ll r ) {
	node &p = tree[r];
	printf("R: %lld [ %lld, %lld ] = %lld { %lld, %lld }\n", r, p.l, p.r, p.sum, p.lazyadd, p.lazymul );
}

void construct( pair<ll,ll> p, ll r = 1 ) {
	node &ptr = tree[r];
	ptr.l = p.F; ptr.r = p.S;
	ptr.lazyadd = 0; ptr.lazymul = 1;
	
	if( p.F == p.S )
	  ptr.sum = v[p.F];
	else {
		ll mid = ( p.F + p.S )/2;
		construct( mp(p.F,mid), L );
		construct( mp(mid+1,p.S), R );
		
		ptr.sum = ( tree[L].sum + tree[R].sum )%MOD;
	}
	
	display(r);
}

void lazyme( ll r ) {
	node &ptr = tree[r];
	
	if( ptr.lazymul != 1 ) {
		ll val = ptr.lazymul;
		ptr.sum = ( ptr.sum*val )%MOD;
		tree[L].lazymul = ( tree[L].lazymul*val )%MOD;
		tree[L].lazyadd = ( tree[L].lazyadd*val )%MOD;
		tree[R].lazymul = ( tree[R].lazymul*val )%MOD;
		tree[R].lazyadd = ( tree[R].lazyadd*val )%MOD;
		ptr.lazymul = 1;
	}
	if( ptr.lazyadd ) {
		ll val = ptr.lazyadd;
		ptr.sum = ( ptr.sum + ( ptr.r - ptr.l + 1 )*val )%MOD;
		tree[L].lazyadd = ( tree[L].lazyadd + val )%MOD;
		tree[R].lazyadd = ( tree[R].lazyadd + val )%MOD;
		ptr.lazyadd = 0;
	}
}

void add( ll x, ll y, ll val, ll r = 1 ) {
	node &ptr = tree[r];
	
	lazyme(r);
	
	if( ptr.l > y || ptr.r < x )
	 return;
	 	
	if( ptr.l >= x && ptr.r <= y ) {
		ptr.sum = ( ptr.sum + ( ptr.r - ptr.l + 1 )*val )%MOD;
		tree[L].lazyadd = ( tree[L].lazyadd + val )%MOD;
		tree[R].lazyadd = ( tree[R].lazyadd + val )%MOD;
	}
	else {
		add( x, y, val, L );
		add( x, y, val, R );
		
		ptr.sum = ( tree[L].sum + tree[R].sum )%MOD;
	}
	
//	cout << "ADD: "; display(r);
}

void mul( ll x, ll y, ll val, ll r = 1 ) {
	node &ptr = tree[r];
	
	lazyme(r);
		
	if( ptr.l > y || ptr.r < x )
	 return;
		
	if( ptr.l >= x && ptr.r <= y ) {
		ptr.sum = ( val*ptr.sum )%MOD;
		tree[L].lazymul = ( tree[L].lazymul*val )%MOD;
		tree[L].lazyadd = ( tree[L].lazyadd*val )%MOD;
		tree[R].lazymul = ( tree[R].lazymul*val )%MOD;
		tree[R].lazyadd = ( tree[R].lazyadd*val )%MOD;
	}
	else {
		mul( x, y, val, L );
		mul( x, y, val, R );
		
		ptr.sum = ( tree[L].sum + tree[R].sum )%MOD;
	} 
	
//	cout << "MUL: "; display(r);
}

node query( ll x, ll y, ll r = 1 ) {
	node &ptr = tree[r];
	
	lazyme(r);
	
	ll mid = ( ptr.l + ptr.r )/2;
	
	if( ptr.l >= x && ptr.r <= y )
	 return tree[r];
	
	if( mid < x )
	 return query( x, y, R );
	if( mid >= y )
	 return query( x, y, L );
	
	node p;
	node ql = query( x, y, L );
	node qr = query( x, y, R );
	
	p.sum = ( ql.sum + qr.sum )%MOD;
	p.l = ql.l; p.r = qr.r;
	
	return p;
	
}

int main() {
	ll n, q;
	get(n); get(q);
	
	FOR(i,1,n)
	 get(v[i]);
	construct( mp(1,n) );
	
	while(q--) {
	   ll w, x, y, v;
	   get(w); get(x); get(y);
	   if( w != 4 ) get(v);
	   
	   if( w == 1 ) add( x, y, v );
	   else if( w == 2 ) mul( x, y, v );
	   else if( w == 3 ) { mul( x, y, 0 ); add( x, y, v ); }
	   else if( w == 4 ) printf("%lld\n", query(x,y).sum);
	}
}
