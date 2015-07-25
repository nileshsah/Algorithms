#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define MOD 1000000007
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

struct node {
   pair<ll,ll> maxp, minp;
   ll l, r;
}tree[4*(100005)];

pair<ll,ll> max( pair<ll,ll> p, pair<ll,ll> q ) {
	
	if( p.F > q.F )
	  return p;
	else if( p.F == q.F && p.S > q.S )
	 return p;
	else
	 return q;
}

pair<ll,ll> min( pair<ll,ll> p, pair<ll,ll> q ) {
	if( p.F < q.F )
	  return p;
	else if( p.F == q.F && p.S < q.S )
	  return p;
	else
	 return q;
}



pair<ll,ll> arr[100005];

void display( ll r ) {
	cout << "R: " << r << "(" << tree[r].l << "," << tree[r].r << ") "
	     << "MAXP: ( " << tree[r].maxp.F << "," << tree[r].maxp.S
	     << ")  MINP: (" << tree[r].minp.F << "," << tree[r].minp.S << "\n";
}

void construct( ll r, pair<ll,ll> p ) {
	node &ptr = tree[r];
	ptr.l = p.F; ptr.r = p.S;
	
	if( p.F == p.S ) {
		ptr.maxp = ptr.minp = arr[p.F];
	}
	else {
		ll mid = ( p.F + p.S )/2;
		construct( L, mp(p.F,mid) );
		construct( R, mp(mid+1,p.S) );
		
		ptr.maxp = max( tree[L].maxp, tree[R].maxp );
		ptr.minp = min( tree[L].minp, tree[R].minp );
	}
	
	display(r);
}

node query( ll x, ll y, ll r = 1 ) {
	display(r);
	 ll mid = ( tree[r].l + tree[r].r )/2;
	 	 
	 if( tree[r].l >= x && tree[r].r <= y )
	 	return tree[r];
	 if( x > mid )
	 	return query( x,y,R );
	 if( y <= mid )
		return query(x,y,L);
	 
	 node qr = query(x,y,R);
	 node ql = query(x,y,L);
	 node ptr;
	 
	 ptr.l = ql.l; ptr.r = qr.r;
	 
	 ptr.maxp = max( qr.maxp, ql.maxp );
	 ptr.minp = min( qr.minp, ql.minp );
	 
	 
	 	cout << "PTR: ( " << ptr.maxp.F << " " << ptr.maxp.S << " ) (" 
	     << ptr.minp.first << " " << ptr.minp.S << "\n";
	return ptr;
	 
	 
	 
}

void update( ll x, ll r , node n ) {
//	cout << "UPD: "; display(x);
	if( tree[r].r < x || tree[r].l > x )
	  return;
	ll mid = ( tree[r].l + tree[r].r )/2;
	
	if( tree[r].l == x && tree[r].r == x )
	 { tree[r] = n; return; }
	
	if( x <= mid )
	  update( x, L, n);
	else if( x > mid )
	 update( x, R, n );
	
	node &ptr = tree[r];
	ptr.maxp = max( tree[L].maxp, tree[R].maxp );
	ptr.minp = min( tree[L].minp, tree[R].minp );
	
}

int main() {
	INPFILE;
	ll n; get(n);
	FOR(i,1,n) {
		ll x, y;
		get(x); get(y);
		arr[i].F = x; arr[i].S = y;
	}
	
	construct( 1, mp(1,n) );
	
	ll m; get(m);
	while(m--) {
		char c; ll i, x, y;
		cin >> c;
		if( c == 'U' ) {
			get(i); get(x); get(y);
			i++;
			node ptr;
			ptr.l = ptr.r = i;
			ptr.maxp = ptr.minp = mp(x,y);
			update( i, 1, ptr );
		}
		else if( c == 'Q' ) {
			get(x); get(y);
			x++; y++;
			node ptr = query( x, y, 1 );
			printf("%lld\n", abs(ptr.maxp.F-ptr.minp.F) + abs(ptr.maxp.S-ptr.minp.S) );
		}
	}
}
