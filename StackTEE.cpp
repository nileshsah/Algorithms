#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( int i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
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
	int val;
	node *next;
};

class Stack {
	node *front;
	node *rear;
public:
	node *newnode() {
		node *ptr = new node;
		ptr->val = 0; ptr->next = NULL;
		return ptr;
	}
	
	void push( int val ) {
		node *ptr = newnode();
		ptr->val = val;
		
		if( rear == NULL )
			front = rear = ptr;
		else
			{ rear->next = ptr; rear = ptr; }
	}
	
	void pop() {
		if( rear == NULL )
			cout << "Underflow!\n";
		else {
			node *tmp = rear, *it;
			for( it = front; it->next != rear; it = it->next );
			it->next = NULL;
			rear = it;
			delete tmp;
		}
	}
	
	void display() {
		cout << "\n DISPLAY: ";
		for( node *it = front; it->next != NULL; it = it->next )
			cout << it->val << " ";
	}
};

int main() {
	Stack s;
	s.push(20);
	s.push(30);
	s.push(40);
	
	s.display();
}
