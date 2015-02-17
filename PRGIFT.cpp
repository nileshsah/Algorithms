#include <iostream>
#include <cstdio>
using namespace std;


int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
      int n, k, count = 0;
      scanf("%d %d", &n, &k);
      
      for( int i = 0; i < n; i++ ) {
           int num;
           scanf("%d", &num);
           if( num%2 == 0 ) 
               count++;
      }
      
      if( k == 0 && n-count != 0 )
          printf("YES\n");
      else if( k == 0 && n-count == 0 )
           printf("NO\n");
      else if( count >= k )
          printf("YES\n");
      else
          printf("NO\n");
    }
}
           
      
      
