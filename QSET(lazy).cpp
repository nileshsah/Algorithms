#include <bits/stdc++.h>
#define ll int
#define get(a) scanf("%d", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;
 
struct node {
	ll num[3];
	ll sum;
	ll lazy;
	ll l, r;
};

void lazyme( ll r );
 
void display( node ptr ) {
	printf(" { %ld %ld } [ %ld %ld %ld ] - %ld \n", ptr.l,ptr.r, ptr.num[0], ptr.num[1], ptr.num[2], ptr.sum);
}
 
node tree[5*(100000+5)];
ll v[100005] = {0};
ll idx[100005] = {0}, n;
ll stree[5*(100000+5)] = {0};

void build( ll a, ll b, ll x, ll y, ll r ) {	
	if( x > b || y < a )
		return;
		
	if( x == y ) {
		stree[r] = idx[x];
	}
	else {
		ll mid = ( x + y )/2;
		build( a, b, x, mid, L );
		build( a, b, mid+1, y, R );
	
		stree[r] = ( stree[L] + stree[R] )%3;
	}
//	cout << " S: " << x << " " << y << " = " << stree[r] << endl;
}

ll sumq( ll a, ll b, ll x, ll y, ll r ) {
	ll mid = ( x + y )/2;
	
	if( x >= a && y <= b )
		return stree[r];
	if( a > mid )
		return sumq( a, b, mid+1, y, R );
	if( b <= mid )
		return sumq( a, b, x, mid, L );
	
	return sumq( a, b, mid+1, y, R ) + sumq( a, b, x, mid, L );

}
 
 
void construct( pair<ll,ll> p, ll r = 1 ) {
	node ptr;
	ptr.l = p.F; ptr.r = p.S;
	ptr.num[0] = ptr.num[1] = ptr.num[2] = ptr.lazy = 0;
	
	
	if( p.S == p.F ) {
		ptr.num[ v[p.F] ] = 1;
	}
	else {
		ll mid = ( p.F + p.S )/2;
		construct( mp(p.F,mid), L );
		construct( mp(mid+1,p.S), R );
		
		FOR(i,0,2)	{
		 ptr.num[i] = tree[L].num[i] + tree[R].num[i];
		}
		
	}
	
	tree[r] = ptr;	
 //  cout << " R: " << r; display(ptr);
}
 
node query( ll x, ll y, ll r = 1 ) {
	 
	 lazyme(r);
	 
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
	 
	ptr.sum = ( ql.sum + qr.sum )%3;			
	FOR(i,0,2)	{
	 ptr.num[i] = ql.num[i] + qr.num[i];
	}
		
			
//	cout << "R: " << r << endl; display(ql); display(qr); display(ptr);
	return ptr;
}


void lazyme( ll r ) {
	
	if( tree[r].lazy != 0 ) {
		ll diff = tree[r].lazy;
		tree[r].lazy = 0;
		
		while( diff < 0 )
		  diff += 3;
		diff %= 3;
			
	
		ll backup[3] = {0};
		FOR(i,0,2)
		 backup[i] = tree[r].num[i];
		
		FOR(i,0,2)
		 tree[r].num[i] = backup[(i-diff+3)%3 ];
		
	//	cout << " LAZY: " << r << " D: " << diff ; display(tree[r]);	
	//	cout << " LAZY[LR]: " << tree[L].lazy << " " << tree[R].lazy << endl;
		if( tree[r].l == tree[r].r )
		  return;
		  
		tree[L].lazy += diff;
		tree[R].lazy += diff;
		
	}
}

void update( ll x, ll diff, ll r = 1 ) {
	
		lazyme(r);

	if(  tree[r].r < x || tree[r].l > n || tree[r].r > n )
		return;
		
		
	 if( tree[r].l >= x && tree[r].r <= n ) {	
			
		ll backup[3] = {0};
		FOR(i,0,2)
		 backup[i] = tree[r].num[i];
		
		FOR(i,0,2)
		 tree[r].num[i] = backup[(i-diff+3)%3 ];
		
		if( tree[r].l == tree[r].r )
			return;
	
		tree[R].lazy += diff;
		tree[L].lazy += diff;
		return;
		 //return lazyme(r);
	}
	else {	
	
	 if( tree[r].l != tree[r].r ) {
		update( x, diff, L );
		update( x, diff, R );
	 }
	 
		lazyme(L); lazyme(R);
		FOR(i,0,2)
		 tree[r].num[i] = tree[L].num[i] + tree[R].num[i];
	}
	
//	cout << " R: " << r; display(tree[r]);	
		
}
 
inline long long getsum( long long x ) {
	return x*(x-1)/2;
}
 
char str[100005];
 
int main() {
 // INPFILE;
	ll  m;
	get(n); get(m);
	
	scanf("%s", &str);
	
	FOR(i,1,n) {
	  v[i] = ( v[i-1] + str[i-1] -'0' )%3;
	  idx[i] = ( str[i-1] - '0' )%3;
	}
	
	build( 1,n, 1,n, 1 );
	construct( mp(0,n), 1 );
		
 
	rep(m) {
	  ll w, x, y;
	  get(w); get(x); get(y);
	  
	  if( w == 1 ) {
	  	ll sum = ( x == 1 ) ? 0 : sumq( 1,x-1, 1,n, 1 );
	  	ll diff = ( y + sum )%3 - ( idx[x] + sum )%3;
//	  	cout << "UP: " << diff << endl;
	  	
	  	idx[x] = y%3;
	  	build( x, x, 1, n, 1 );
	  	update(x,diff);
	  	
	  /*	FOR(i,1,n)
	  	 cout << sumq(1,i,1,n,1) << " ";
	  	cout << endl;
	  	
	  	
	  	
	  	/*str[x-1] = y + '0';
	  	
		FOR(i,1,n) {
		  v[i] = ( v[i-1] + str[i-1] -'0' )%3;
		  idx[i] = ( str[i-1] - '0' )%3;
		}
		
		construct( mp(0,n), 1 );
		*/
		
	
	  }
	  if( w == 2 ) {
		  node q =  query(x-1,y);
		  long long ans = 0;
		  
		  FOR(i,0,2) {
		   ans += getsum(q.num[i]);
		  }
 	//	  cout << " SUM: " << q.sum << endl;
		  printf("%lld\n", ans );
		}
	}
 
	
} 
