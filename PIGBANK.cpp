#include <iostream>
#include <vector>
#include <algorithm>
#define get(a) scanf("%ld", &a)
#define ll long
using namespace std;

int main() {
    long int t;
    get(t);
        
    while(t--) {
       ll e, f, n;
       get(e); get(f);  
       ll amt = f - e;
    
      vector< pair<ll,ll> > v;
    
      get(n);
      while(n--) {
        ll x, y;
        get(x); get(y);
        pair<ll,ll> p;
        p.first = y;
        p.second = x;
        v.push_back(p);
      }
      
      sort(v.begin(), v.end());
      
      ll a[10000] = {0};
      for( ll i = 1; i <= amt; i++ ) {
           vector< pair<ll,ll> >::iterator it = v.begin();
           for( ;it != v.end(); it++ ) {
                if( it->first > i )
                    break;
                //if( i%(it->second) == 0 )
                  //  a[i] = (it->first)*( i%(it->second) );
                  if( i - (it->first) < 0  )
                      continue;
                  if( a[i - (it->first) ] == 0 && (i - (it->first)) != 0 )
                      continue;
                      
                ll num = it->second + a[ i - (it->first) ];
                if( num < a[i] || a[i] == 0 )
                    a[i] = num;
           }
      }
      
           if( a[amt] == 0 )
               printf("This is impossible.\n");
           else
               printf("The minimum amount of money in the piggy-bank is %ld.\n", a[amt]);
    }
}
      
                
                
                
           
           
      
      
      
      
      
    
    
