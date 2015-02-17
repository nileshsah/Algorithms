#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <algorithm>
#include <limits.h>
#include <cstring>
#define ll long long
#define get(a) scanf("%lld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define max(a,b) a > b ? a : b
#define pb push_back
#define MOD 1000000007
using namespace std;
 
int main() {
    ll t;
    get(t);
    
    while(t--) {
      ll pos = 1;
      char str[100000+5];
      scanf("%s", &str);
      
      for( ll i = 0; str[i] != '\0'; i++ ) {
           if( str[i] == 'l' ) {
               if( (i+1)%2 != 0 )
                pos = pos*2;
               else
                pos = pos*2 - 1;
           }
           else if( str[i] == 'r' ) {
                 if( (i+1)%2 != 0 )
                pos = (pos+1)*2;
               else
                pos = pos*2 + 1;
           }
          pos %= MOD;          
      }
      printf("%lld\n", pos);
      
    }
}
