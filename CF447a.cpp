#include <iostream>
using namespace std;

int main() {
    int n, p; int a[300+5], b[300+5] = {0};
    cin >> p >> n;
    
    
    for( int i = 0; i < n; i++ )
         cin >> a[i];
    
    for( int i = 0; i < n; i++ ) {
         if( b[ a[i]%p ] != 0 )
            { cout << ++i; return 0; }
         else
             b[ a[i]%p ] = 1;
    }
    
    cout << "-1";

}
