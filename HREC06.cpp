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
	ll val;
	ll l, r;
	pair<ll,ll> lazy;
}tree[16*(100005)];

void display( ll r, node p ) {
//   printf(" R: %lld - [ %lld, %lld ] = %lld\n", r, p.l, p.r, p.val );
}

ll gs[100005] = {0};
ll series[100005] = {0};

ll getsum( ll y ) {
	if(gs[y])
	 return gs[y];
	 
	ll val = y*(y+1)*(y+2)/3;
	while( val >= MOD )
	 val -= MOD;
	return gs[y] = val;
}

ll range( ll x, ll y ) {
	return series[y] - series[x-1];
}

void construct( pair<ll,ll> p, ll r = 1 ) {
	node &ptr = tree[r];
	ptr.l = p.F; ptr.r = p.S;
	ptr.lazy = mp(-1,-1);
	
	if( p.F == p.S )
	 ptr.val = 0;
	else {
		ll mid = ( p.F + p.S )/2;
		construct( mp( p.F, mid ), L );
		construct( mp( mid+1, p.S ), R );
		
		ptr.val = 0;
	}
	
	display(r,ptr);
}

void lazyme( ll r ) {
	node &ptr = tree[r];
	
	if( ptr.lazy != mp(-1LL,-1LL) ) {
	   pair<ll,ll> p = ptr.lazy;
	   ptr.lazy = mp(-1,-1);
	   if( !( ptr.l > p.S || ptr.r < p.F ) ) {
	      ll x = max( p.F, ptr.l );
	      ll y = min( p.S, ptr.r );
	      
	      ptr.val += range( abs(p.F - x) + 1, abs(y - p.F) + 1 );
	      ptr.val %= MOD;
	      if( !( tree[L].l > p.S || tree[L].r < p.F ) )
	       { lazyme(L); tree[L].lazy = p; }
	      if( !( tree[R].l > p.S || tree[R].r < p.F ) )
	       { lazyme(R); tree[R].lazy = p; }
	   }
	}
}

node query( ll x, ll y, ll r = 1 ) {
	lazyme(r);
	
	display(r,tree[r]);
	ll mid = ( tree[r].l + tree[r].r )/2;
	
	if( tree[r].l >= x && tree[r].r <= y )
		return tree[r];
	if( mid >= y )
	 return query( x, y, L );
	if( mid < x )
	 return query( x, y, R );
	
	node ptr;
	node ql = query( x, y, L );
	node qr = query( x, y, R );
	
	ptr.val = ( ql.val + qr.val )%MOD;
	ptr.l = ql.l; ptr.r = qr.r;
	return ptr;
}

void update( ll x, ll y, ll r = 1 ) {
		
	if( tree[r].l > y || tree[r].r < x )
	 return;
	
	tree[r].lazy = mp(x,y);
	lazyme(r);
	
//	cout << " UPD: "; display(r,tree[r]);
}


int main() {
  //  INPFILE;
  	ll n, q;
	get(n); get(q);
	construct( mp(1,n) );
	
	FOR(i,1,n)
	 series[i] = ( series[i-1] + i*(i+1) )%MOD;
	
	while(q--) {
	   ll p, x, y;
	   get(p); get(x); get(y);
	   
	   if( p == 1 )
	    update( x, y );
	   else
	    printf("%lld\n",query( x, y ).val);
	}
}
