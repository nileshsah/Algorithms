#include <iostream>
using namespace std;

int main() {
    long int arr[10] = { 0, 0, 6, 69, 405, 1725, 6027, 18312, 50016 };
    
    int t;
    cin >> t;
    while(t--) {
      long int n;
      cin >> n;
      
       for( int i = 0; i <= 8; i++ ) {
           n = n - arr[i];
           
           if( n <= 0 )
            {   cout << i << endl; break; }
      }
    }
}
               
           
           
    
