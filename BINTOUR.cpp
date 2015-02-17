#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;


int main() {
    int k;
    long long unsigned int count = 0;

    scanf("%d", &k);
    
    
    long int limit = int(pow(2,k));
    if( k == 1 ) {
        cout << "2\n2";
        return 0;
    }
    
    for( long int i = 1; i <= limit; i++ ) {
         count = 1; long int m = 1, j = limit/2;
     while( j!= 1 && i-m > 0) {
      count *= j*int( pow(2,j) )*(i - m );
      j /= 2;
      //count %= 1000000009;
      m++;
     }
    
     cout << count << endl;
   }
   cin >> k;
}
      
           
    
    
