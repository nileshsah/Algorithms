#include <iostream>
using namespace std;

struct node {
   int val;
   node *next;
   node *prev;
};

class dList {
    node *front;
    node *rear;
public:
    dList() {
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
              front->prev = ptr;
              ptr->next = front;
              ptr->prev = NULL;
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
            ptr->prev = rear;
            rear = ptr;
         }
    }
    
    void insertAfter( int pos, int val ) {
         for( node *it = front; it != NULL; it = it->next )
           if( it->val == pos ) {
               node *temp = it->next;
               node *ptr = new node;
               ptr->val = val;
               ptr->prev =it;
               ptr->next = it->next;
               (it->next)->prev = ptr;
               it->next = ptr;
               break;
           }
    }   
    
    void del( int val ) {
         for( node *it = front; it != NULL; it = it->next )
              if( it->val == val ) {
                  if( it->next == NULL ) {
                      rear = it->prev;
                      rear->next = NULL;
                  }
                  else if( it->prev == NULL ) {
                     front = it->next;
                  }
                  else {                  
                   (it->prev)->next = it->next;
                   it->next->prev = it->prev;
                  } 
                  delete it;
                  break;
              }
    }
    
    void display() {
        node *it;
        for( it = front; it != NULL; it = it->next )
             cout << it->val << " ";
        cout << endl;
    }
             
    
};

int main() {
    dList adj;
    adj.insertAtFront(10);
    adj.insertAtFront(20);
    adj.insertAtFront(30);
    adj.insertAtRear(50);
    adj.insertAtRear(60);
    adj.del(30);
    adj.insertAfter(20, 100);
    adj.display();
    
    int n; cin >> n;
}
