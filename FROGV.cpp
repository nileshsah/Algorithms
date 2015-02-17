#include <iostream>
#include <limits.h>
#include <stdio.h>
using namespace std;
       

void merge( long int *a, long int low, long int mid, long int high ) {
        
     long int i, j, x, y, fa[100005], sa[100005];
     for( i = 0; (i+low) <= mid; i++ )
          fa[i] = a[low+i];
     fa[i] = LONG_MAX;
      
     for( i = 0; (i+mid+1) <= high; i++ )
          sa[i] = a[mid+i+1];
     sa[i] = LONG_MAX;
     
     
     
     x = 0;
     y = 0;
     for( i = low; i <= high; i++ ) {
          if( fa[x] < sa[y] ) {
              a[i] = fa[x];
              x++;
          }
          else {
               a[i] = sa[y];
               y++;
          }
     }
          
}
    
void mergesort( long int *a, long int low, long int high ) {  
     if( low < high ) {
         long int mid = (low+high)/2;
         mergesort( a, low, mid );
         mergesort( a, mid+1, high );
         merge( a, low, mid, high );
     }
}

int binsearch( long int *a, long int n, long int low, long int high ) {
    long int mid = (low+high)/2;
    
    if( high < low )
        return -1;
        
    if( n == a[mid] )
        return mid;

    if( n > a[mid] )
        return binsearch( a, n, mid+1, high );
    else
        return binsearch( a, n, low, mid-1 );
}
 

int main() {
    long int n, k, p, a[100005], b[100005], c[100005], temp, i, j;
    
    scanf("%ld %ld %ld", &n, &k, &p);
    
    for( i = 1; i <= n ; i++ ) {
         scanf("%ld", &temp);
         a[i] = temp;
         b[i] = temp;
    }
    
    mergesort(b, 1, n);
    b[0] = b[1];
    b[n+1] = LONG_MAX;
    
        /*for( i = 1; i <= n ; i++ )
         printf( "%ld ", b[i] );*/
     c[1] = 1;
     long int flag = 1;
     for( j = 2; j <= n; j++ ) {
              if( b[j] - b[j-1] <= k )
                 { c[j] = ++flag; }
              else {
                   flag = 0;
              }
         }
    
    for( i = 0; i < p; i++ ) {
         long int s, e, min, pos1, pos2, max;
         scanf("%ld %ld", &s, &e);
         min = ( a[s] > a[e] ) ? a[e] : a[s];
         max = ( a[s] < a[e] ) ? a[e] : a[s];
         pos1 = binsearch( b, min, 1, n );
         pos2 = binsearch( b, max, 1, n );
         
         
         if( ( c[pos2]-c[pos1] ) == pos2-pos1 )
             printf("Yes\n");
         else
             printf("No\n");
    }
}
         
         
         
    
  
  
