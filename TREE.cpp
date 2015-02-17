#include <iostream>
#include <queue>
using namespace std;

struct node {
	int n;
	node *left;
	node *right;
};

class tree {
	node *root;
	node *next;
	int lvl;
public:
	tree() { root = next =  NULL; lvl = INT_MAX; }
	
	void traverse( node *ptr, int level ) {
		if( ptr->right != NULL )
			traverse( ptr->right, level+1 );
		else if( level < lvl )
			{ next = ptr; lvl = level; }
			
		if( ptr->left != NULL )
			traverse( ptr->left, level+1 );
		else if( level < lvl )
			{ next = ptr; lvl = level; }
			
		
	}
	
	void insert( int n ) {
		node *ptr = new node;
		ptr->n = n;
		ptr->left = NULL; ptr->right = NULL; 
		
		if( root == NULL ) 
			root = ptr;
		else {
			lvl = INT_MAX;
			traverse( root, 0 );
			if( next->right == NULL )
				next->right = ptr;
			else
				next->left = ptr;			
		}
	}
	
	void display( queue<node*> q = queue<node*>(), bool check = 0 ) {
		if( check == 0 )
			q.push( root );
		queue<node*> qq;
		cout << "\n";
		
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
};


int main() {
	tree t;
	while(1) {
		int x;
		cout << "\n\nEnter x: "; cin >> x;
		t.insert(x);
		cout << "\n";
		t.display();
		cout << "\n\n";
		t.inOrder();		
	}
	
}
