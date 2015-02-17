#include <iostream>
#include <limits.h>
using namespace std; 

int main() {
    long int n, i, t = 1, maxsum = 0;
    cin >> n;
    
    for( i = 1; t > 0; i++ ) {
         t = n/i;
         t = t - i + 1;
         
         if( t > 0 )
          maxsum += t;
    }
    
    cout << maxsum;
    
    system("pause");
}
    
