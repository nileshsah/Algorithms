#include <iostream>
using namespace std;

int main() {
    long long int a[100000+5];
    long int n, i, j, max = 0, temp;
    
    scanf("%ld", &n);
    for( i = 0; i < n; i++ )
         scanf("%lld", &a[i]);
    
    for( i = 0; i < n; i++ )
         for( j = i+1; j < n; j++ ) {
              temp = a[j]&a[i];
              if( temp > max )
                  max = temp;
         }
    
    cout << max;
    cin >> max;
}
              
    
    
