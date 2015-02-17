#include <iostream>
#include <vector>
#define ll long unsigned 
using namespace std;

long unsigned int v[1000000] = {0};


 
ll int rec( ll int n ) {
     if( n == 0 )
      return 0;
     
     if( n < 1000000 && ::v[n] != 0 )
         return ::v[n];
     
     ll a = n/2; ll b = n/3; ll c = n/4;
     a = rec(a) > a ? rec(a) : a;
     b = rec(b) > b ? rec(b) : b;
     c = rec(c) > c ? rec(c) : c;

     ll m = ( a+b+c ) > n ? ( a+b+c ): n;
     //m = m > n ? m : n;
     
     if( n < 1000000 )
         ::v[n] = m;
     return m;

}
     
     
     
int main() {
    int t = 10;
    
    while(t--) {
      ll n;
      cin >> n;
      cout << rec(n) << endl;
    }
}
