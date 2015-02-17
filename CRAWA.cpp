#include <iostream>
#include <cstdio>
using namespace std;

long long int absol( long long int x ) {
     if( x < 0 )
         return -x;
     else
         return x;
}

int main() {
    long int t;
    scanf("%ld", &t);
    while(t--) {
      long long int x, y, temp;
      scanf("%lld %lld", &x, &y);
      
      int flag = 0;
      
      if( x < 0 ) {
          if( absol(x)%2 == 0 && y >= x && y <= -x )
              flag = 1;
      }
      else if( x > 0 ) {
           if( x%2 != 0 && y >= -x+1 && y <= x+1 )
               flag = 1;
      }
      
      if( y > 0 && y%2 == 0 && absol(x) < absol(y) )
          flag = 1;
      
      if( y < 0 && absol(y)%2 == 0 && absol(x) <= absol(y) )
          flag = 1;
     
      if( y == 0 && x == 0 )
          flag = 1;
           
      if( flag == 1 )
          printf("YES\n");
      else
          printf("NO\n");
          
    }
} 
