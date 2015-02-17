#include <iostream>
#include <limits.h>
#include <cstdio>
using namespace std;

int main() {
    long int n; int arr[100000+5] = {0};
    cin >> n;
    long int a, b;
    long int count = 0;
    
    for( int i = 0; i < n; i++ ) {
      cin >> a >> b;
      arr[a] = b;
    }
    
    int flag = 0; int low = INT_MAX;
    
    for( int i = 0; i <= 100000; i++ )
         if(  arr[i] != 0) {         
              if( arr[i] < low )
                  low = arr[i];
              
              if( arr[i] > low )
                {  flag = 1; break; }
    }
             
      
    
    if( flag == 0 && n != 1)
        cout << "Happy Alex";
    else
        cout << "Poor Alex";

}
