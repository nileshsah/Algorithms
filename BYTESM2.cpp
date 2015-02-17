#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <cstring>
#define ll int
#define get(a) scanf("%d", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
using namespace std;

int main() {
    ll t;
    get(t);
    
    while(t--) {
      ll h, w, a[100+5][100+5] = {0}, max = 0, b[100+5][100+5]={0};
      get(h); get(w);
      
      rep(h)
       for( int j = 0; j < w; j++ )
         { get(a[i][j]); b[i][j] = a[i][j]; }
      
      rep(h-1)
       for( int j = 0; j < w; j++ ) {
            
            if( j+1 < w )
                if( b[i+1][j+1] < b[i][j] + a[i+1][j+1] )
                    b[i+1][j+1] = b[i][j] + a[i+1][j+1];
            
            if( j-1 >= 0 )
                if( b[i+1][j-1] < b[i][j] + a[i+1][j-1] )
                    b[i+1][j-1] = b[i][j] + a[i+1][j-1];
            
            if( b[i+1][j] < b[i][j] + a[i+1][j] )
                    b[i+1][j] = b[i][j] + a[i+1][j];
       }
       
       rep(w)
        if( b[h-1][i] > max )
            max = b[h-1][i];
       
       printf("%d\n", max );
    }
}
                    
            
            
            
       
