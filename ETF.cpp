#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a);


bool arr[1000000+5];
ll a[1000000+5] = {0};
int main() {
    for( ll i = 2; i <= 1000000; i++ ) {
         if( ::arr[i] == 0 ) {
             for( ll j = 1; j*i <= 1000000; j++ ) { 
              ::arr[i*j] = 1;
               if( a[i*j] == 0 )
                   a[i*j] = i*j;
              a[i*j] = ( a[i*j] - a[i*j]/i );
             }
         }
    }
    
    a[0] = 0;
    a[1] = 1;
    
    ll t; 
    get(t);
    
    while(t--) {
      ll n;
      get(n);
      
      //std::cout << a[n] << "\n";
      printf("%ld\n", a[n]);
    }
}
      
              
      
      
     
