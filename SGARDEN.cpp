#include <iostream>
#include <stdio.h>
#define MOD 1000000007
using namespace std;

long long unsigned int findGCD (long long unsigned int a, long long unsigned int b) {
    long long unsigned int c, a1 = a, b1 = b;
    do {
        c = a % b;
        if (c > 0) {
            a = b;
            b = c;
        }
    } while (c != 0);
    return b;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
     long int n, a[100005], c[100005], i;
     scanf("%ld", &n);
     
     for( i = 1; i <= n; i++ ) {
          scanf("%ld", &a[i]);
          c[i] = 0;
     }
     
     c[0] = 0;
     for( i = 1; i <= n; i++ ) {
         long int flag = 0, j = 0, follow = i;
      
      if( c[i] == 0 )
       while(1) {
         j++;
         follow = a[follow];
         //cout << follow << ":follow flag:" << flag << "\n";
         if( follow == i )
             flag++;
         if( flag == 2 )
             break;
             
         c[follow] = j - c[follow];
       }
      
      }
      
            
      long long unsigned int lcm = c[1], temp;
     
      for( i = 1; i <= n; i++ ) {
           temp = lcm*c[i];
           lcm = temp/findGCD( lcm, c[i] );
           //cout << c[i] << " LCM: " << lcm << endl;
           
      }
      
      cout << lcm%MOD << endl;
          
   }
}
         
          
          
     
     
     
     
