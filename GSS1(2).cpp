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
	ll maxR;
	ll maxL;
	ll l;
	ll r;
	ll best;
};

node* tree[4 * 50005];
ll v[50005] = {0};

void construct( ll r, pair<ll,ll> p ) {
		node *ptr = new node;
		ptr->l = p.first; ptr->r = p.second;
		ptr->maxR = 0; ptr->maxL = 0;
		
	//	cout << " ROOT: " << r << " RR: " << p.first << "  " << p.second << " vSize: " << v.size() << endl;
		//getch();
			
		if( p.first == p.second )
		  {  ptr->maxR = ptr->best = ptr->sum =  ptr->maxL = v[p.first]; tree[r] = ptr; }
		else
		 {
		  
		  ll pmid = ( p.first + p.second )/2;
		  
		  construct(  2*r, make_pair( p.first, pmid ) );
		  construct( 2*r+1, make_pair( pmid+1, p.second ) );
		  
		  ptr->sum = tree[2*r]->sum + tree[2*r+1]->sum;
		  ptr->maxR = max( tree[2*r+1]->maxR, tree[2*r]->maxR + tree[2*r+1]->sum );
		  
		  ptr->maxL = max( tree[2*r]->maxL, tree[2*r]->sum + tree[2*r+1]->maxL ) ;
		  
		  ptr->best = max( tree[2*r]->best,  tree[2*r+1]->best  );
		  ptr->best = max( tree[2*r]->maxR + tree[2*r+1]->maxL, ptr->best );
		  tree[r] = ptr;		  
		}
		
		/*node *it = tree[r];
		cout << " [ " << it->maxL << " " << it->best << " " << it->maxR << " ]  ROOT: " << r;
		cout << " -> " << it->l << "  " << it->r << endl;	
		*/
}

node *query( ll x, ll y, ll r ) {
	// cout << " REC: " << x << "  " << y << " IN: " << tree[r]->l << " " << tree[r]->r << endl;
	
	if( tree[r]->l >= x && tree[r]->r <= y 	)
		return tree[r];
	
	ll mid = ( tree[r]->l + tree[r]->r )/2;
	
	if( y <= mid )
		return query(x, y, 2*r );
	if( x > mid )
		return query(x, y, 2*r+1 );
	 
	 node *ql = query(x, y, 2*r );
	 node *qr = query(x, y, 2*r+1 );
	
	 node *ptr = new node;
	 ptr->sum = ql->sum + qr->sum;
	 ptr->maxR = max( qr->maxR, ql->maxR + qr->sum );
	 ptr->maxL = max( ql->maxL, qr->maxL + ql->sum );
	 
	 ptr->best = max( ql->best, qr->best );
	 ptr->best = max( ptr->best, ql->maxR + qr->maxL );
	 
	 return ptr;
}

int main() {
	ll n;
	get(n);
	
	rep(n)
	  get(v[i]);
	
	construct( 1, make_pair(1,n) );
	
	ll m;
	get(m);
	
	while(m--) {
		ll x, y;
		get(x); get(y);
		printf("%ld\n", query(x,y,1)->best);
	}
	
	/*for( int i = 1; i <= 4*n; i++ ) {
	  node *it = tree[i];
	  if( it != NULL )
	  cout << " [ " << it->maxL << " " << it->sum << " " << it->maxR << " ] ";
	}*/
	 
}
