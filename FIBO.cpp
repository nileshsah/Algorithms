#include <iostream>
#define MOD 1000000007
using namespace std;

long int fib[10000] = {0};

long fibo( long int n ) {
     if( fib[n] != 0 )
         return fib[n];
         
     if( n <= 2 )
         return 1;
     else {
        long long  val = ( fibo(n-1)%MOD + fibo(n-2)%MOD )%MOD;
        fib[n] = val;
        return val;
     }
         
}

int main() {
    fib[1] = 1; fib[2] = 1;
    fibo(1000);
    
    int t;
    cin >> t;
    while(t--) {
       long long sum = 0;
       int x, y;
       cin >> x >> y;
       
       for( int i = x; i <= y; i++ )
          { sum += fibo(i); sum %= MOD; }
       cout << sum << endl;
       
    }
    
}

