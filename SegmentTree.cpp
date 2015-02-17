#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define absol(a) a >= 0 ? a : -a
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
using namespace std;

struct node {
	ll n;
	node *left;
	node *right;
};

class SegmentTree {
	node *p;
	ll len;
	vector<ll> arr;
public:	
	ll best;
	
	SegmentTree() {
		len = 0;
		p = NULL;
		best = LONG_MAX;
	}
	
	node *construct( vector<ll> v ) {
		node *q;
		q = new node;
		
		if( len == 0 )
		 { len = v.size(); arr = v; }
		
		if( v.size() == 1 )
		 { q->n = v[0]; q->left = NULL; q->right = NULL; }
		else {
		  ll mid = ( v.size() - 1)/2;
		  (*q).left = construct( vector<ll>( v.begin(), v.begin()+mid+1 ) );
		  (*q).right = construct( vector<ll>( v.begin()+mid+1, v.end() ) );
		  (*q).n = (q->left)->n + (q->right)->n;
		}
		
		p = q;
		return q;
	}
	
	void Display( queue<node*> q ) {
		queue<node*> qq;
		while( !q.empty() ) {
			node *ele = q.front();
			if( ele->left != NULL )
				qq.push(ele->left);
			if( ele->right != NULL )
				qq.push(ele->right);
			q.pop();
			cout << ele->n <<  "  ";		
		}
		cout << endl;
		
		if( !qq.empty() )
		 Display(qq);
	}
	
	void print() {
		queue<node*> q;
		q.push(p);
		Display(q);
		cout << "\n\n\n";
	}
	ll size() {
		return len;
	}
			
	ll getSum( ll x, ll y, node *ptr = NULL, ll start = 1, ll end = -1 ) {
		if( start == 1 && end == -1 )
		  { ptr = p; end = len; }
		  
		if( ptr == NULL )
			return 0;
				
		ll m = (end+start)/2;
		
				
		if( x > end || y < start )
			return 0;
						
		if( x <= start && y >= end ) {
				return ptr->n;			
		}

		cout << " RANGE: " << start << " " << end << endl;
	
		return getSum(x, y, ptr->left, start, m) +
			   getSum(x, y, ptr->right, m+1, end);
	}
	
	int update( ll index, ll val, node *ptr = NULL, ll start = 1, ll end = -1 ) {

		if( start == 1 && end == -1 )
		 { ptr = p; end = len; }
		
		if( ptr == NULL )
			return 0;
		
		cout << ptr->n << " -- " << start << "  " << end << endl;
		ll diff = val - arr[index-1];
		ll mid = (start+end)/2;
		
		if( start > index || end < index )
			return 0;
		else {
			ptr->n += diff;
			update( index, val, ptr->left, start, mid );
			update( index, val, ptr->right, mid+1, end );
		}		
		
	}
	
};

int main() {
	ll n;
	get(n);
	
	vector<ll> v;
	
	rep(n) {
		ll x; get(x);
		v.pb(x);
	}
	
	SegmentTree tree;
	tree.construct(v);
	cout << "\n\n";
	tree.print();
	
	ll m;
	get(m);
	
	while(m--) {
		ll x, y;
		get(x); get(y);
		cout << tree.getSum(x,y) << endl;
		
	}
	
}
