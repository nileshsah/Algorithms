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
	ll sum;
	ll maxL;
	ll maxR;
	ll l, r;	
};


char v[30000+5];
node tree[4 * (30000+5)];

void print( node p ) {
	printf("  [ %ld %ld %ld ] (%ld,%ld)\n", p.maxL, p.sum, p.maxR, p.l, p.r );
}

void construct( pair<ll,ll> p, ll r ) {
	node ptr;
	ptr.l = p.first; ptr.r = p.second;
	ptr.sum = ptr.maxL = ptr.maxR = 0;
	
	if( p.first == p.second ) {
		if( v[p.first] == '(' )
			ptr.sum = ptr.maxL = 1;
		else if( v[p.first] == ')' )
			{ ptr.sum = -1; ptr.maxR = 1; }
	}
	else {
		ll mid = ( p.first + p.second )/2;
		construct( make_pair( p.first, mid ), 2*r );
		construct( make_pair( mid+1, p.second ), 2*r+1 );
		
		ptr.sum = tree[2*r].sum + tree[2*r+1].sum;
		ptr.maxL = tree[2*r].maxL + tree[2*r+1].maxL - tree[2*r+1].maxR;

		if( ptr.maxL < 0 )
			{  ptr.maxL = 0; }
	
		ptr.maxR = tree[2*r].maxR + tree[2*r+1].maxR - tree[2*r].maxL;
		
		if( ptr.maxR < 0 )
			{  ptr.maxR = 0; }
		
		if( ptr.maxR < 0 )
			ptr.maxR = 0;
	}
	
	// cout << "ROOT: " << r; print(ptr);
	tree[r] = ptr;
}

void update( ll x, ll r, node n ) {
	if( tree[r].l == x && tree[r].r == x )
	 { tree[r] = n; return; }
	
	ll mid = ( tree[r].l + tree[r].r )/2;
	if( x <= mid ) 
	   update( x, 2*r, n);
	else if( x > mid )
	   update( x, 2*r+1, n);
	
	node ptr = tree[r];
	ptr.sum = tree[2*r].sum + tree[2*r+1].sum;
	ptr.maxL = tree[2*r].maxL + tree[2*r+1].maxL - tree[2*r+1].maxR;
		if( ptr.maxL < 0 )
			{ ptr.maxL = 0; }
	ptr.maxR = tree[2*r].maxR + tree[2*r+1].maxR - tree[2*r].maxL;	
		if( ptr.maxR < 0 )
			{  ptr.maxR = 0; }
		
		
	//	print(ptr);
			
	tree[r] = ptr;	
}

int main() {
	ll t = 10;
	while(t--) {
		printf("Test %ld:\n", 10-t);
		ll n, m;
		get(n);
		
		scanf("%s", &v);
		
		construct( make_pair( 0, n-1 ), 1 );
		
		get(m);
		while(m--) {
			ll x; get(x);
			if( x == 0 ) {
				if( n%2 == 0 && v[0] != ')' && tree[1].sum == 0 && tree[1].maxR == 0 && tree[1].maxL == 0 )
					printf("YES\n");
				else
					printf("NO\n");
			}
			else {
				node n;
				n.l = n.r = x-1;
				n.maxR = n.maxL = n.sum = 0;
				
				if( v[x-1] == ')' )
					{ v[x-1] = '('; n.sum = n.maxL = 1;  }
				else
				  { v[x-1] = ')'; n.sum = -1; n.maxR = 1;  }
				
				update( x-1, 1, n );
				//printf("%s\n", v);
			}
		}
	}
}
