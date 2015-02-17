#include <iostream>
using namespace std;

int main() {
    long int n, i, max = 1;
    long long unsigned int a[100000+5];
    int b[100000+5] = {0}, c[100000+5] = {0}, d[100000+5] = {0};
    
    cin >> n;
    
    for( i = 0; i < n; i++ )
         cin >> a[i];
        
    int flag = 0;
    b[0] = 1;
    
    for( i = 1; i < n; i++ ) {
         if( a[i] > a[i-1] )
             b[i] = b[i-1] + 1;
         else
             b[i] = 1;
    }
    
    b[n] = -1;
    
    for( i = 0; i < n; i++ )
         cout << b[i] << " ";
    cout << endl;
    
    max = 1; int count = 0;
    
    if( b[1] == 1 )
     { if( a[1] == 1 )
       c[0] = 1; count++; i = 2; }
     else
         i = 0;
         
    for( ; i < n; i++ ) {
         if( b[i] == 1 ) {
            c[count] = b[i-1];
            count++;
            
            if( b[i-1] > 1 && b[i+1] > 1 )
                if( a[i+1] - a[i-1] <= 1 )
                  {  c[count] = 0; count++; }
         }
    }
    
    c[count] = b[n-1];
    count++;
    
    for( i = 0; i < count; i++ )
         cout << c[i] << " ";
    cout << endl;
    
    max = 0;
    for( i = 0; i < count-1; i++ ) {
         d[i] = c[i]+c[i+1];
         if( d[i] > max )
          max = d[i];
    }
    
    cout << max;
    cin >> n;
}
    
             
             
         
         
             
             
             
             
             
         
