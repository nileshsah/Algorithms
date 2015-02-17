#include <iostream>
#include <stack>
#define get(a) scanf("%d", &a);
using namespace std;

int main() {
    int t;
    while(1) {
       get(t);
       
       if(t == 0 )
            break;
       
       int a[1000+5] = {0};
       stack<int> s;
       s.push(-1);
       
       for( int i = 0; i < t; i++ )
            get(a[i]);
       a[t] = -1;
       
       int j = 0; int flag = 0;
       
       for( int i = 1; i <= t; i++ ) {
            //cout << i << " j:" << j << endl;
            
            if( j > t )
                { printf("no\n"); flag = 1; break; }
            if( s.top() == i )
                 s.pop();
            else if( a[j] == i )
               { j++; continue; } 
            else
              { s.push(a[j]); j++; i--; }
            
       }
       
       if(!flag)
                printf("yes\n");
    }
}
       
                
       
