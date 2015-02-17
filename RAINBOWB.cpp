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
 
ll a[1000000+6] = {0};

int main() {
  ll num; ll sum = 0, temp = 0;
  get(num);
  
  ll n = num - 12;
  
  for( ll i = 1; ; i++ ) {
       if( n - i < 0 )
           break;
       if( (n - i)%2 != 0 )
           continue;
      
       ll l =( n - i )/2;
       
     
      // temp += ( ( (5+l) )*( (4+l) )*( (3+l) )*( (2+l) )*( (1+l) ) )/120;
     
       ll ans = 1;  int div[6] = {0};
       for( int j = 1; j <= 5; j++ ) {
          ll term = (j+l);
          
          while( div[2] < 3 && term%2 == 0 )
           { term = term/2; div[2]++; }
          if( !div[3] && term%3 == 0 )
           { term = term/3; div[3] = 1; }
          if( !div[5] && term%5 == 0 )
           { term = term/5; div[5] = 1; }
          
          ans = ans*term;
          ans %= MOD;
           
       }
       
       sum += ans;             
       sum %= MOD;
  }
  
  printf("%lld", sum);
  cin >> sum;   
}
