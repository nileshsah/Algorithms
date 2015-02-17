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
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define max(a,b) a > b ? a : b
#define pb push_back
#define MOD 1000000007
using namespace std;
 
ll a[1000000+6] = {0};

int main() {
    ll n, m;
    get(n); get(m);
    
    for( ll i = 0; i < n; i++ )
         get(a[i]);
    
    ll start = 0; ll end = n-1;
    
    while(m--) {
         char c; ll d;
         scanf(" %c %ld", &c, &d);
         
         if( c == 'R' ) {
             d--;
             printf("%ld\n", a[(start+d)%n]);
         }
         else if( c == 'C' ) {
              start += d;
              end += d;
              start %= n;
              end %= n;
         }
          else if( c == 'A' ) {
              start -= d;
              end -= d;
              
              start = start >= 0 ? start : n + start;
              end = end >= 0 ? end : n + end;
              start %= n;
              end %= n;
         }
         
        // for( ll i = 0; i < n; i++ )
          //  cout << a[(start+i)%n] << "  ";
         //cout << endl;
    } 
}
