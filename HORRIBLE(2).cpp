#include <bits/stdc++.h>
#include <cstdio>
#define ll long long unsigned
#define get(a) cin >> a
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

ll tree[4*100000+5] = {0};
ll lazy[4*100000+5] = {0};

void update( pair<ll,ll> p, ll x, ll y, ll r, ll val ) {
	ll mid = p.F + p.S; mid /= 2;
		
	if( lazy[r] != 0 ) {
		tree[r] += lazy[r];
		if( p.F != p.S ) { 
		  lazy[R] += ( lazy[r]/(p.S-p.F+1) )*(p.S-mid);
		  lazy[L] += ( lazy[r]/(p.S-p.F+1) )*(mid-p.F+1);
		 }
		lazy[r] = 0;
	}
	
		
	if( p.S < x || p.F > y )
		return;
	
	if( p.F >= x && p.S <= y ) { 
	 	 if( p.F == p.S )
			tree[r] += val;
		 else {
	  		tree[r] += val*(p.S-p.F+1); 
	  		lazy[L] += val*(mid-p.F+1);
	  		lazy[R] += val*(p.S-mid);
//	  		cout << " LB: " << p.F << " " << p.S << " -> ";
//	  		cout << tree[r] << "\n";
			return;
		}
    }
	else {
		update( mp( p.F, mid ), x, y, 2*r, val );
		update( mp( mid+1, p.S ), x, y, 2*r+1, val );
		
	 	tree[r] = tree[L] + tree[R];
	}
//	cout << " RB: " << p.F << " " << p.S << " -> ";
//	cout << tree[r] << "\n";
	
}

ll query( pair<ll,ll> p, ll x, ll y, ll r ) {
	ll mid = ( p.F + p.S )/2; 
	
	if( lazy[r] != 0 ) {
		tree[r] += lazy[r];
		if( p.F != p.S ) { 
		  lazy[R] += ( lazy[r]/(p.S-p.F+1) )*(p.S-mid);
		  lazy[L] += ( lazy[r]/(p.S-p.F+1) )*(mid-p.F+1);
		 }
		lazy[r] = 0;
	}
	
//	cout << " Q: " << p.F << " " << p.S << "  " << tree[r] << endl;
	
	
	
	if( p.F >= x && p.S <= y )
		return tree[r];
	if( x > mid )
		return query( mp( mid+1, p.S ), x, y, R );
	if( mid >= y )
		return query( mp( p.F, mid ), x, y, L );
	
	ll qr = query( mp( mid+1, p.S ), x, y, R );
	ll ql = query( mp( p.F, mid ), x, y, L );
	
	return qr + ql;
}

int main() {
	ll t;
	get(t);
	
	while(t--) {
		memset( tree, 0, sizeof tree );
		memset( lazy, 0, sizeof lazy );
		
		ll n, c;
		get(n); get(c);
		
		rep(c) {
			ll x, p, q, val;
			get(x); get(p); get(q);
			
			if( x == 1 )
			 cout << query( mp(1,n), p,q, 1 )  << endl;
			else if( x == 0 ) {
				get(val);
				update( mp(1,n), p,q,1,val );
			}	
		}
	}
	
}
