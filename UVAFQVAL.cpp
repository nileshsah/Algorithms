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
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define L 2*r
#define R 2*r+1
using namespace std;

struct node {
	ll ans;
	map<ll,ll> m;
	ll l,r;
};

ll v[100000+5];
node tree[4*(100000+5)];

void construct( pair<ll,ll> p, ll r ) {
	node ptr;
	ptr.l = p.first; ptr.r = p.second;
	
	if( p.first == p.second )
	 { ptr.ans = v[p.first]; ptr.m[v[p.first]] = 1; }
	else {
		ll mid = ( p.first + p.second )/2;
		construct( make_pair( p.first, mid ), 2*r );
		construct( make_pair( mid+1, p.second ), 2*r+1 );
		
		ptr.m = tree[L].m;
		ptr.ans = tree[L].ans;
		ll maxcount = tree[L].m[ptr.ans];
		
		for( map<ll,ll>::iterator it = tree[R].m.begin(); it != tree[R].m.end(); it++ ) {
			ptr.m[it->first] += it->second;
			if( ptr.m[it->first] > maxcount )
			 { ptr.ans = it->first; maxcount = ptr.m[it->first]; }
		}
		
	}
	
	//printf(" ROOT: %ld ( %ld , %ld ) = %ld\n", r, ptr.l, ptr.r, ptr.ans );
	tree[r] = ptr;
}

node query( ll x, ll y, ll r ) {
//	cout << tree[r].l << "  " << tree[r].r << endl;
	ll mid = ( tree[r].l + tree[r].r )/2;
	
	if( x <= tree[r].l && tree[r].r <= y )
		return tree[r];
		
	if( y <= mid )
		return query( x, y, 2*r );
	else if( x > mid )
		return query( x,y, 2*r+1 );
	
	node ptr;
	node qr = query( x,y, R );
	node ql = query( x,y, L );
	
	ptr.m = ql.m;
	ptr.ans = ql.ans;
	ll maxcount = ql.m[ptr.ans];
		
	for( map<ll,ll>::iterator it = qr.m.begin(); it != qr.m.end(); it++ ) {
		ptr.m[it->first] += it->second;
		if( ptr.m[it->first] > maxcount )
		 { ptr.ans = it->first; maxcount = ptr.m[it->first]; }
	}
	
	return ptr;

}

int main() {
	while(1) {
		ll n, q;
		get(n);
		
		if( n == 0 )
			break;
		
		get(q);
		
		rep(n)
		 get(v[i]);
		 
		construct( make_pair(1,n), 1);
		
		while(q--) {
			ll x, y;
			get(x); get(y);
			node p = query(x,y,1);
			printf("%ld\n", p.m[p.ans] );
		}
	}
}
