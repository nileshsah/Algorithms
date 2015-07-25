#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( auto it = s.begin(); it != s.end(); it++ )
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
#define MOD 1000000009
using namespace std;

struct node {
	ll l, r;
	ll val;
}tree[4*(200000)];

ll arr[200000] = {0};

void construct( pair<ll,ll> p, ll r, ll lvl ) {
	node &ptr = tree[r];
	ptr.l = p.F; ptr.r = p.S;
	
	if( p.F == p.S ) {
		ptr.val = arr[p.F];
	}
	else {
		ll mid = ( p.F + p.S )/2;
		construct( mp(p.F,mid), L, lvl-1 );
		construct( mp(mid+1,p.S), R, lvl-1 );
		
		if( lvl%2 == 0 )
		 ptr.val = (tree[R].val|tree[L].val); 
		else
		 ptr.val = (tree[R].val^tree[L].val); 
	}
	
//	printf(" R: %lld ( %lld, %lld ) = %lld  LVL: %lld\n", r, p.F, p.S, ptr.val, lvl);

}

void update( ll x, ll val, ll r, ll lvl ) {
	node &ptr = tree[r];
	
	if( ptr.l > x || ptr.r < x )
	 return;
	
	if( ptr.l == x && ptr.r == x ) 
	  ptr.val = val;
	else {
		ll mid = ( ptr.l + ptr.r )/2;
		update( x, val, L, lvl-1 );
		update( x, val, R, lvl-1 );
		
		if( (lvl%2) == 0 )
		 ptr.val = (tree[R].val|tree[L].val);
		else
		 ptr.val = (tree[R].val^tree[L].val);
	}
	
//	printf(" R: %lld ( %lld, %lld ) = %lld  LVL: %lld\n", r, ptr.l, ptr.r, ptr.val, lvl);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m;
	cin >> n >> m;
	
	FOR(i,1,pow(2,n))
	 cin >> arr[i];
	
	construct( mp(1,pow(2,n)), 1, n+1  );
	
	while(m--) {
		ll p, val;
		cin >> p >> val;
		
		update( p, val, 1, n+1 );
		cout << tree[1].val << "\n";
	}
	
}
