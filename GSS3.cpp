#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for(vector<node*>::iterator it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) a >= 0 ? a : -a
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
using namespace std;

struct node {
	ll best;
	ll maxR;
	ll maxL;
	ll sum;
	ll l;
	ll r;
};

node tree[4*(50000+5)];
ll v[50000+5];

void print( node p ) {
	printf(" [ %ld %ld %ld ] (%ld,%ld)\n", p.maxL, p.best, p.maxR, p.l, p.r );
}

void construct( pair<ll,ll> p, ll r) {
	node ptr;
	ptr.l = p.first; ptr.r = p.second;
	
	if( p.first == p.second ) {
		ptr.maxR = ptr.maxL = ptr.sum = ptr.best = v[p.first];
	}
	else {
		ll mid = ( p.first + p.second )/2;
		construct( make_pair( p.first, mid ), 2*r );
		construct( make_pair( mid+1, p.second ), 2*r+1 );
		
		ptr.maxR = max( tree[2*r+1].maxR, tree[2*r].maxR + tree[2*r+1].sum );
		ptr.maxL = max( tree[2*r].maxL, tree[2*r+1].maxL + tree[2*r].sum );
		ptr.sum = tree[2*r].sum + tree[2*r+1].sum;
		
		ptr.best = max( tree[2*r].best , tree[2*r+1].best );
		ptr.best = max( ptr.best, tree[2*r].maxR + tree[2*r+1].maxL );
	}
	
	tree[r] = ptr;
	//print(ptr);
}

node getSum( ll x, ll y, ll r ) {
	ll mid = tree[r].l + tree[r].r;
	mid /= 2;
	
//	cout << tree[r].l << "  " << tree[r].r << endl;
	
	if( x <= tree[r].l && tree[r].r <= y )
		return tree[r];
	if( y <= mid )
		return getSum( x, y, 2*r );
	if( x > mid )
		return getSum( x, y, 2*r+1);
	
	node ptr;
	node qr = getSum( x,y, 2*r+1 );
	node ql = getSum( x, y, 2*r );
	
	ptr.maxR = max( qr.maxR , ql.maxR + qr.sum );
	ptr.maxL = max( ql.maxL , qr.maxL + ql.sum );
	ptr.sum = ql.sum + qr.sum;
	
	ptr.best = max( ql.best, qr.best );
	ptr.best = max( ptr.best, ql.maxR + qr.maxL );
	
	return ptr;
}

void update( ll x, ll r, node n ) {
	//cout << tree[r].l << "  " << tree[r].r << endl;
	
	if( tree[r].l == x && tree[r].r == x )
		{ tree[r] = n;  return; }

	ll mid = ( tree[r].l + tree[r].r )/2;	
	
	if(  x <= mid )
		update( x, 2*r, n );
	else if( x > mid )
		update( x, 2*r+1, n );
	
	node ptr;
	ptr.r = tree[r].r;
	ptr.l = tree[r].l;
	ptr.maxR = max( tree[2*r+1].maxR, tree[2*r].maxR + tree[2*r+1].sum );
	ptr.maxL = max( tree[2*r].maxL, tree[2*r+1].maxL + tree[2*r].sum );
	ptr.sum = tree[2*r].sum + tree[2*r+1].sum;
	
	ptr.best = max(tree[2*r].best , tree[2*r+1].best );
	ptr.best = max( ptr.best, tree[2*r].maxR + tree[2*r+1].maxL );
	
	//print(ptr);
	
	tree[r] = ptr;
}

int main() {
	ll n, m;
	get(n);
	
	rep(n)
	 get(v[i]);
	
	construct( make_pair(1,n), 1 );
	
	get(m);
	
	while(m--) {
		ll x, y, o;
		get(o); get(x); get(y);
		
		if( o == 1 )
			printf("%ld\n", getSum(x,y,1).best);
		else if( o == 0 ) {
			node n;
			n.l = n.r = x;
			n.best = n.sum = n.maxL = n.maxR = y;
			update( x, 1, n );
		}
	}
}
