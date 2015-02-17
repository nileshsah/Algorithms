#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <limits.h>
#include <cstring>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
using namespace std;

ll func( ll n ) {
  ll sum = 0;
  while( n!= 0 )
   { sum += (n%10)*(n%10); n /= 10; }
  return sum;
}

int main() {
    ll n;
    get(n);
    set<ll> v;
    ll count = 1;
    ll sum = func(n);
    bool flag = true;
    
    while( sum != 1 ) {
      count++;
      sum = func(sum);
      if( v.count(sum) != 0 )
       { flag = 0; break; }
      v.insert(sum);
    }
    
    if(flag)
     printf("%ld", count);
    else
     printf("-1");
    
    
           
}
