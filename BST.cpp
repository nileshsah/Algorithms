#include <iostream>
#include <queue>
using namespace std;

struct node {
	int n;
	node *left;
	node *right;
};

class tree {
public:
	node *root;
	tree() { root = NULL; }
	
	node *newnode( int n ) {
		node *ptr = new node;
		ptr->n = n;
		ptr->left = ptr->right = NULL; 
		return ptr;
	}
	
	void insert( int n, node* &r ) {

		if( root == NULL )
		 { root = newnode(n); return; }
		 
		if( r == NULL )
		 { r = newnode(n); return; }
		if( n >= r->n )
			return insert(n, r->right );
		else
			return insert(n, r->left );		
	
	}
	
	void display( queue<node*> q = queue<node*>(), bool check = 0 ) {
		if( check == 0 )
			q.push( root );
			
		queue<node*> qq;
		cout << "\n";
		if( q.front() == NULL )
			return;
			
		while( !q.empty() ) {
			cout << q.front()->n << " ";
			if( q.front()->left != NULL )
				qq.push(q.front()->left);
			if( q.front()->right != NULL )
				qq.push(q.front()->right);	
			q.pop();			
		}
		
		if( !qq.empty() )
			display( qq, 1 );
				
	}
	
	void inOrder(node *root = NULL, bool check = 0) {
		if(!check)
			root = this->root;
		
		if( root == NULL ) 
			return;
		else {
			cout << root->n << "  ";
			inOrder( root->left, 1);
			inOrder( root->right, 1);
		}
				
	}
	
	int findmin( node *r ) {
		if( r->left != NULL )
			return findmin( r->left );
		else
			return r->n;
	}
	
	void del( node* &r, int x ) {
		if( root == NULL )
			return;
		if( r->n == x ) {
			if( r->left == NULL && r->right == NULL )
				{ delete r; r = NULL; return; }
			else if( r->left == NULL && r->right != NULL )
			 { node* ptr = r; r = r->right; delete ptr; ptr = NULL; }
			 else if( r->left != NULL && r->right == NULL )
			 { node *ptr = r; r = r->left; delete ptr; ptr = NULL; }
			else {
				int val = findmin(r->right);
				del( r->right, val );
				r->n = val;
			}
		}
		else if( r->n > x )
			return del( r->left, x );
		else if( r->n < x )
			return del( r->right, x );
	}
	
	
};


int main() {
	tree t;
	while(1) {
		int x, c;
		cout << "\n\n1. INSERT \n2. DELETE \n Enter choice: "; cin >> c;
		cout << "Enter x: "; cin >> x;
		if( c == 1 )
		 t.insert(x, t.root );
		else
		 t.del(t.root, x);
		cout << "\n";
		t.display();
		//cout << "\n\n";
		//t.inOrder();		
	}
	
}
