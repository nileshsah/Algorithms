#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) scanf("%lld", &a)
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
  ll sum;
  ll l,r;
};

node tree[4*(100000+5)];

void construct( pair<ll,ll> p, ll r ) {
	node ptr;
	ptr.l = p.F; ptr.r = p.S;

	if( p.F == p.S )
	{ ptr.sum = v[p.F]; }
   else {
   	 ll mid = (p.F + p.S)/2;
     construct( mp(p.F,mid), L );
     construct( mp(mid+1,p.S), R );
     
     ptr.sum = tree[L].sum + tree[R].sum;
   }
   
   //cout << " TREE: " << p.F <<"," << p.S << "  VAL: " << ptr.sum << endl;
   tree[r] = ptr;
   
}

void update( ll loc, ll val, ll r = 1 ) {
	
	if( tree[r].l > loc || tree[r].r < loc )
		return;
		
	if( tree[r].l == loc && tree[r].r == loc )
		{ tree[r].sum = val; return; }
	
	update( loc, val, L );
	update( loc, val, R );
	
	tree[r].sum = tree[L].sum + tree[R].sum;
	
}

node query( ll x, ll y, ll r = 1 ) {
	ll mid = ( tree[r].l + tree[r].r )/2;
	
	if( tree[r].l >= x && tree[r].r <= y )
		return tree[r];
		
	if( y <= mid )
		return query( x, y, L );
	if( x > mid )
		return query( x, y, R );
	
	node qr = query( x, y, L );
	node ql = query( x, y, R );
	
	node ptr;
	ptr.sum = qr.sum + ql.sum;
	
	//cout << " QUERY: " << x << " " << y << " -> " << ptr.sum << endl;
	return ptr;
}


int main() {
	ll n; get(n);
	rep(n) get(v[i]);	
	
	vector< pair<ll,ll> > func;
	func.pb( mp(0,0) );
	
	rep(n) {
		ll x, y;
		get(x); get(y);
		func.pb( mp( min(x,y), max(x,y) ) );
	}
	
	construct( mp(1,n), 1 );
	
	ll q; get(q);
	
	while(q--) {
		ll p, x, y;
		get(p); get(x); get(y);
		ll ans = 0;
		
		if( p == 1 )
		 update( x, y );
		else if( p == 2 ) {
		 FOR(i,x,y)
		  ans += query( func[i].F, func[i].S ).sum;
		  //printf(" ANS: %lld, %lld : %lld\n", func[i].F, func[i].S, query( func[i].F, func[i].S ).sum);
		 printf("%lld\n", ans);
		}
	}
	
		
}
