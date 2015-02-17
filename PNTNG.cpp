#include <iostream>
using namespace std;

int main() {
    long long unsigned int n, m, h, C[100005], t, c, tcount = 0, mul, cost = 0;
    char *nn, *mm;
    
    C[0] = 0;
    cin >> n >> m >> h;
    
    mul = n*m;
    
    
    for( int i = 0; i < h; i++ ) {
         cin >> t >> c;
         C[c] += t;
         tcount += t;
    }
    
    if( tcount < mul ) {
        cout << "Impossible" << endl;
    }
    else {
         mul = n*m;
         int counter = 1;
         while( mul > 0 ) {
          if( C[counter] < mul ) {
              mul -= C[counter];
              cost += C[counter]*counter;
              counter++;
          }
          else {
               cost += mul*counter;
               mul = 0;
          }
         }
         
         cout << cost << endl;
    }
    
    //cin >> cost;
}
                
       
    
    
    
    
    
