#include <iostream>
using namespace std;

struct node {
   int val;
   node *next;
};

class sList {
   node *front;
   node *rear;
public:
   sList() {
      front = NULL;
      rear = NULL;
   }
   
   void insertAtFront( int val ) {
        node *ptr = new node;
        ptr->val = val;
        ptr->next = NULL;
        
        if( front == NULL ) {
            front = ptr;
            rear = ptr;
        }
        else {
          ptr->next = front;
          front = ptr;
        }         
   }
   
   void insertAtRear( int val ) {
        node *ptr = new node;
        ptr->val = val;
        ptr->next = NULL;
        
        if( rear == NULL ) {
            front = ptr;
            rear = ptr;
        }
        else {
          rear->next = ptr;
          rear = ptr;
        }
   }
   
   void del( int val ) {
        for( node *it = front; it != NULL; it = it->next )
            if( it->val == val ) {
                node *t = front;
                
                if( it == front )
                 front = it->next;
                else
                 for( ; t->next != it; t = t->next );
                  t->next = it->next;
            
                if( it->next == NULL )
                 rear = t;
                  
                 delete it; 
                 break;
            }                
   }
   
   void insertBefore( int pos, int val ) {
     for( node *it = front; it != NULL; it = it->next )
        if( it->val == pos ) {
          if( it == front )
            { insertAtFront(val); return; }
          node *t = front;
          for( ; t->next != it; t = t->next );
          node *ptr = new node;
          ptr->val = val;
          ptr->next = it;
          t->next = ptr;
          break;
        }
   }
  
  void display() {
       for( node *it = front; it != NULL; it = it->next )
         cout << it->val << "  ";
        cout << endl;
  }  
  
  void reverse( node* p ) {
  	if( p->next == NULL )
  		front = p;
  	else {
  		reverse(p->next);
  		node *q = p->next;
  		q->next = p;
  		p->next = NULL;
  		
	}
  	
  }	
  
  node* begin() {
  	return front;
 }
 
};


int main() {
    sList adj;
    adj.insertAtFront(10);
    adj.insertAtFront(20);
    adj.insertAtFront(30);
    adj.insertAtRear(50);
    adj.insertAtRear(60);
    adj.insertBefore(20, 100);
    //adj.del(100);
    adj.reverse(  adj.begin() );
    adj.display( );
    
    int n; cin >> n;
}
