#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
#define min(a,b) a < b ? a : b
#define absol(a) a >= 0 ? a : -a
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
using namespace std;

struct node {
	int val;
	node *r;
	node *l;
};

class tree {
 public:
	node *root = NULL;
 	
	void insert( int val, node *&r ) {
		if( r == NULL )
		 { r = new node; r->val = val; r->l = r->r = NULL; }
		else if( val >= r->val )
			return insert( val, r->r );
		else 
		    return insert( val, r->l );
	}
	
	bool search( int val, node *r ) {
		if( r == NULL )
			return false;
		if( r->val == val )
			return true;
		else if( r->val < val )
			return search( val, r->r );
		else if( r->val > val )
			return search( val, r->l );
	}
	
	int findMAX( node *r ) {
		while( r->r != NULL )
			r = r->r;
		return r->val;
	}
	
	void del( int val, node *&r ) {
		if( r->val > val )
			del( val, r->l );
		else if( r->val < val )
			del( val, r->r );
		else {
			if( r->r == NULL && r->l == NULL )
			  {  delete r; r = NULL; }
			else if( r->r == NULL && r->l != NULL )
			 { node *temp = r; r = r->l; delete temp; }
			else if( r->r != NULL && r->l == NULL )
			 { node *temp = r; r = r->r; delete temp; }
			else if( r->r != NULL && r->l != NULL )
			 { int n = findMAX( r->l );  del( n, r->l ); r->val = n; }		
		}
	}
	
	void display( queue<node*> q ) {
		
		cout << "\n";
		queue<node*> qq;
		
		while(!q.empty()) {
			if( q.front() == NULL ) continue;
			 cout << q.front()->val << "  ";
			if( q.front()->l != NULL )
				qq.push( q.front()->l );
			if( q.front()->r != NULL )
				qq.push( q.front()->r );
			q.pop();			
		}
		
		if( !qq.empty() )
			display(qq);
	}
	
};

int main() {
	tree t;
	
	t.insert(10, t.root);
	t.insert(5, t.root);
	t.insert(20, t.root);
	t.insert(7, t.root);
	t.insert(1, t.root);
	t.insert(18,t.root);
	t.insert(22, t.root);
	
	cout<< " MAX: " << t.findMAX(t.root->l) << endl;

	t.del(10, t.root);
	
	cout << t.search(10,t.root);

	cout << "\n\n\n";
	queue<node*> q; q.push(t.root);
	t.display(q);
}
