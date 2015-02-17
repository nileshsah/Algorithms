#include <iostream>
using namespace std;

int main() {
    long int n;
    int arr[100005], temp[100005], max = 0;
    
    cin >> n;
    
    temp[0] = 0;
    for( int i = 1; i <= n; i++ ) {
         cin >> arr[i];
         
         if( arr[i] != 0 )
             temp[i] = temp[i-1]+1;
         else {
             temp[i] = 0;
             if( temp[i-1] > max )
                 max = temp[i-1];
         }
    }
    
    if( max < temp[n] )
        max = temp[n];
        
    cout << max;
}
    
    
         
    
    
         
    
    
