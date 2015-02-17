#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
     long int n, a[10004], b[10004], i;
     scanf("%ld", &n);
     
     for( i = 1; i <= n; i++ ) {
          scanf("%ld", &a[i]);
          b[i] = i;
     }
     
     long int q, m, x, y, z;
     scanf("%ld", &q);
     
     for( i = 0; i < q; i++ ) {
          scanf("%ld %ld", &m, &x);
          
          if( m == 0 ) {
              scanf("%ld", &y);
              
              if( b[x] == b[y] )
                  printf("Invalid query!\n");
              else if( a[x] > a[y] ) {
                for( z = 1; z <= n; z++ )
                     if( b[z] == b[y] )
                          b[y] = b[x];
              }
              else if( a[x] < a[y] ) {
                 for( z = 1; z <= n; z++ )
                     if( b[z] == b[x] )
                          b[x] = b[y];
              }
          }
          else {
               printf("%ld\n", b[x]);
          }
      }      
          
    }
}
     
    
