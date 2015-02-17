#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

void merge(  int *a, long int low, long int mid, long int high ) {
        
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
    
void mergesort(  int *a, long int low, long int high ) {  
     if( low < high ) {
         long int mid = (low+high)/2;
         mergesort( a, low, mid );
         mergesort( a, mid+1, high );
         merge( a, low, mid, high );
     }
}

int main() {
    char str[1000+5];
    long int k; int a[1000+5];
    int w[125];
    
    cin.getline( str, 1005 );
    cin >> k;
    
    int max = 0;
    
    for( int i = 97; i <= 122; i++ ) {
         cin >> w[i];
         
         if( w[i] > max )
             max = w[i];
    }
    
    int i, len;
    
    for(  i =0; str[i] != '\0'; i++ )
         a[i] = w[ str[i] ];
    
    len = i;
    mergesort( a, 0, i-1 );
    
    long long int sum = 0, form = 1;
    
    for( i = 0;  i < len; i++ )
         sum += a[i]*(i+1);
    
    len++;
    
    form = 2*len*k + k*k - k;
    form *= max;
    form /= 2;
     
    sum += form;
    
    cout << sum;
}
