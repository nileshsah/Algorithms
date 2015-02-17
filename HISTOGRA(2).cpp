#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) scanf("%lld", &a)
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for(vector<int>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) a >= 0 ? a : -a
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define L 2*r
#define R 2*r+1
using namespace std;

struct node {
	ll val;
	ll index;
	ll l, r;
};

node tree[4*(100000+5)], arr[100000+5];
map< pair<ll,ll>, ll > m;

void construct( pair<ll,ll> p, ll r ) {
	node ptr;
	ptr.l = p.first; ptr.r = p.second;
	
	if( p.first == p.second )
	 { ptr.val = arr[p.first].val; ptr.index = arr[p.first].index; }
	else {
		ll mid = ( p.first + p.second )/2;
		construct( make_pair( p.first, mid ), L );
		construct( make_pair( mid+1, p.second ), R );
		
		if( tree[L].val <= tree[R].val )
		 { ptr.val = tree[L].val; ptr.index = tree[L].index; }
		else
		 { ptr.val = tree[R].val; ptr.index = tree[R].index; }	
	}
	
//	cout << ptr.val << " - " << ptr.index << " ROOT: " << r << " RNG: " << ptr.l << " - " << ptr.r << "\n";
	tree[r] = ptr;
}

node query( ll x, ll y, ll r = 1 ) {
	ll mid = ( tree[r].l + tree[r].r )/2;
	
//	cout << "\n QUERY: " << tree[r].l << " " << tree[r].r ;
	if( x <= tree[r].l && tree[r].r <= y )
		return tree[r];
	if( y <= mid )
		return query( x, y, L );
	if( x > mid )
		return query( x, y, R );
	
	node ql = query( x, y, L );
	node qr = query( x, y, R );  
	
	node ptr;
	ptr.l = ql.l; ptr.r = qr.r;
	
	if( ql.val <= qr.val )
	 { ptr.val = ql.val; ptr.index = ql.index; }
	else
	 { ptr.val = qr.val; ptr.index = qr.index; }
	
//	cout << " VAL: " << ptr.val << " - " << ptr.index << endl;
	return ptr;
		
}

ll rec( ll x, ll y, ll n ) {
	if( x > y || y > n || x > n || y < 1 || x < 1 )
		return 0;
	if( !m.empty() && m.find( make_pair(x,y) ) != m.end() )
		return m[ make_pair(x,y) ];
//  cout << " RANGE: " << x << "," << y ;
	node ptr = query( x, y );
//  cout << " MIN: " << ptr.val << " - " << ptr.index << endl ;
	ll ans = y - x + 1;
	ans *= ptr.val;
	
	if( x == y )
		ans = ans;
	else
		ans = max( ans, max( rec(x,ptr.index-1,n) , rec(ptr.index+1,y,n) ) );
	m[ make_pair(x,y) ] = ans;
	return ans;
}

int main() {
	while(1) {
		m.clear();
		ll n; get(n);
		if( n == 0 )
			return 0;
		rep(n)
		 { get(arr[i].val); arr[i].index = i; }
		construct( make_pair(1,n), 1 );		
		
		printf("%lld\n", rec(1,n,n) );		  			
	}
}

