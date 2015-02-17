#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    
    while(t--) {
      long int n, i, a[100000+5], *arr, count = 0;
      arr = new long int[100000+5];
      scanf("%ld", &n);
      arr[0] = 0;
      
      for( i = 0; i <= 100000; i++ )
           arr[i] = 0;
           
      for( i = 0; i < n; i++ ) {
           scanf("%ld", &a[i]);
           arr[ a[i] ]++;
      }
      
      for( i = 1; i <= 100000; i++ )  
           if( arr[i] > 0 ) {
               count++; }
      
      printf("%ld\n", count);
      
      delete arr;
    }
}
      
      
      
