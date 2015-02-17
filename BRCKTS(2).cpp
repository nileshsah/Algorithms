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
	ll minVal;
};

node tree[4*(30000+5)];
char v[30000+5];

void construct( pair<ll,ll> p, ll r ) {
	node ptr;
	
	if( p.first == p.second )
	 ptr.sum = ptr.minVal = ( v[p.first] == '(' ) ? 1 : -1;
	else {
		ll mid = (p.first + p.second)/2;
		construct( make_pair(p.first,mid), 2*r );
		construct( make_pair(mid+1, p.second), 2*r+1 );
		ptr.sum = tree[2*r].sum + tree[2*r+1].sum;
		ptr.minVal = min( tree[2*r].minVal, tree[2*r].sum + tree[2*r+1].minVal );	
	}
	
	tree[r] = ptr;
}

void update( pair<ll,ll> p, ll r, ll x, node n ) {
	ll mid = ( p.first + p.second )/2;
	
	if( p.first == x && p.second == x )
	 {  tree[r] = n; return; }
	 if( x <= mid )
	 	update( make_pair( p.first, mid ), 2*r, x, n );
	else if( x > mid )
		update( make_pair( mid+1, p.second ), 2*r+1, x, n);
	
	node ptr;
	ptr.sum = tree[2*r].sum + tree[2*r+1].sum;
	ptr.minVal = min( tree[2*r].minVal, tree[2*r].sum + tree[2*r+1].minVal );	
	
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
				if( n%2 == 0 && tree[1].sum == 0 && tree[1].minVal == 0  )
					printf("YES\n");
				else
					printf("NO\n");
			}
			else {
								
				if( v[x-1] == ')' )
					{ v[x-1] = '('; }
				else
				  { v[x-1] = ')';  }
				  
				node ptr;
				ptr.sum = ptr.minVal = ( v[x-1] == '(' ) ? 1 : -1;
			
				update( make_pair( 0, n-1 ), 1, x-1, ptr ); 
				//update( x-1, 1, n );
				//printf("%s\n", v);
			}
		}
	}
}
	

