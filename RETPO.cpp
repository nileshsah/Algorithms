#include <iostream>
using namespace std;

int main() {
    long long int t;
    cin >> t;
    while(t--) {
      long long int x, y, sum = 0, temp = 0, m, n;
      cin >> x >> y;
      
      if( x < 0 )
          x = -x;
      if( y < 0 )
          y = -y;
      
      if( x-y > 0 ) {
          m = x-y;
         if( m%2 == 0 ) 
          temp = 2*m;
         else
          temp = 2*m + 1;
         
         sum = y*2 + temp;
      }
      else {
          m = y-x;
         if( m%2 == 0 ) 
          temp = 2*m;
         else
          temp = 2*m - 1;
         
         sum = x*2 + temp;
      }
      
      //cout << m << ":m Temp: " << temp << endl;
      cout << sum << endl;
    }
}
         
      
      
          
