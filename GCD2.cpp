#include <iostream>
#include <cstring>
#define ll long
#define get(a) scanf("%ld", &a)
using namespace std;

ll gcd( ll a, ll b ) {
   if( b == 0 )
       return a;
   else
       return gcd( b, a%b );
}

int main() {
    ll t;
    get(t);
    
    while(t--) {
      ll a; char b[300]; ll rem = 0;
      get(a); scanf("%s", &b);
      
      if( a == 0 )
       { printf("%s\n",b); continue; }
      
      for( ll i = 0; i < strlen(b); i++ )
       rem = ( rem*10 + b[i] - '0' )%a;

            
      printf("%ld\n", gcd( a, rem ) );
        
    }
}
